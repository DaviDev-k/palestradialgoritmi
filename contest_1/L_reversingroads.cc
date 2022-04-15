// https://open.kattis.com/contests/i6uudu
// https://open.kattis.com/problems/reversingroads

#include <bits/stdc++.h>

using namespace std;

// DFS che restituisce `true` se sono stati visitati tutti i nodi, `false` altrimenti
bool dfs(vector<vector<int>> G, int m) {
	vector<bool> visited(m);
	int visited_count = 0;  // contatore dei nodi visitati
	stack<int> S;
	S.push(0);
	while (!S.empty()) {
		int u = S.top();
		S.pop();
		if (!visited[u]) {
			visited[u] = true;
			visited_count++;  // incrementa il numero di strade visitate
			for (auto &v: G[u]) {
				if (v != -1) { S.push(v); }  // ignora gli archi esclusi
			}
		}
	}
	return visited_count == m;
}

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int m, n;  // #città, #strade (notazione invertita!)
	int a, b;  // estremi della strada
	
	for (int test = 1; cin >> m >> n; test++) {  // ripeti finché `cin` non fallisce (EOF - End Of File)
		
		vector<vector<int>> G(m), Gt(m);         // grafo originale, grafo trasposto
		vector<pair<int, int>> idx(n), idxt(n);  // memorizza la posizione della strada i-esima nella lista di adiacenza
		
		for (int s = 0; s < n; s++) {
			cin >> a >> b;
			idx[s] = {a, G[a].size()};    // posizione della strada `s` in `G`
			idxt[s] = {b, Gt[b].size()};  // posizione della strada `s` in `Gt`
			G[a].push_back(b);            // inserisci `a-b` in `G`
			Gt[b].push_back(a);           // inserisci `b-a` in `Gt`
		}
		
		bool valid = false;
		a = -1, b = -1;  // estremi della strada da invertire
		
		for (int s = -1; s < n && !valid; s++) {  // `s` indica la strada da invertire, `s = -1` non inverte nulla
			
			// Inverti la strada `a-b` in `G` e `Gt`
			if (s >= 0) {
				a = idx[s].first;            // inizio strada `s`
				b = idxt[s].first;           // fine strada `s`
				G[a][idx[s].second] = -1;    // escludi la strada `a-b` in `G`
				Gt[b][idxt[s].second] = -1;  // escludi la strada `b-a` in `Gt`
				G[b].push_back(a);           // aggiungi la strada invertita `b-a` in `G`
				Gt[a].push_back(b);          // aggiungi la strada invertita `a-b` in `Gt`
			}
			
			/*
			 * `dfs(vector<vector<int> G, int m)` restituisce `true` se è possibile visitare tutti gli `m` nodi del
			 * grafo diretto a partire dal nodo iniziale `0` (che coincide in entrambi i grafi `G` e `Gt` trasposto),
			 * `false` altrimenti.
			 *
			 * Il problema consiste nel verificare se il grafo `G` è fortemente connesso, che significa (come richiesto
			 * dal problema) che ogni nodo sia raggiungibile da qualsiasi altro nodo.
			 *
			 * Il primo termine `dfs(G, m)` dell'espressione è banale: se dal nodo `0` non posso raggiungere tutti gli
			 * altri `m-1` nodi, allora il grafo non è f.c..
			 * Il secondo termine `dfs(Gt, m)` è meno intuitivo: `dfs(G, m)` può restituire `true` in diversi casi in
			 * cui il grafo `G` non è f.c. (e.g. dfs eseguita a partire dalla radice di un albero), perciò è necessario
			 * verificare che ogni nodo di `G` raggiunga il nodo `0`. Questo è possibile sfruttando il grafo trasposto
			 * `Gt` ed eseguendo la dfs su di esso a partire dal nodo `0`.
			 */
			valid = dfs(G, m) && dfs(Gt, m);
			
			// Ripristina la strada invertita se non si è trovata la soluzione
			if (s >= 0 && !valid) {
				G[a][idx[s].second] = b;    // ripristina la strada esclusa
				Gt[b][idxt[s].second] = a;  // ripristina la strada esclusa
				G[b].pop_back();            // elimina la strada invertita
				Gt[a].pop_back();           // elimina la strada invertita
			}
		}
		
		cout << "Case " << test << ": ";
		if (valid) {
			if (a == -1) { cout << "valid"; }  // grafo fortemente connesso senza inversioni
			else { cout << a << " " << b; }    // grafo fortemente connesso invertendo `a-b`
		} else {
			cout << "invalid";                 // non è possibile connettere il grafo con una inversione
		}
		cout << endl;
	}
	
	return 0;
}
