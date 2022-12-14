#include <bits/stdc++.h>

using namespace std;

// Legge da stdin un intero per riferimento e restituisce il carattere successivo all'ultima cifra
char scan(int &n) {
	n = 0;
	bool neg = false;
	char c = getchar();
	while (!(c == '-' || (c >= '0' && c <= '9'))) { c = getchar(); }
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; !feof(stdin) && c >= '0' && c <= '9'; c = getchar()) {
		n = n * 10 + c - '0';
	}
	if (neg) { n *= -1; }
	return c;
}

int main() {
	int K;
	char c;
	int n = 0, m;
	c = scan(K);
	
	unordered_map<int, list<int>> T;  // albero memorizzato come dizionario (nodo -> lista di figli)
	unordered_set<int> children;      // ogni nodo che possiede un padre
	set<int> roots;                   // radici di ogni sottoalbero (esclude le foglie)
	
	// Lettura dell'input e popolazione dell'albero
	while (n != -1) {
		c = scan(n);                 // n: primo numero della riga
		if (n != -1) {
			roots.insert(n);         // aggiungi il nodo interno al set
			while (c != '\n') {      // leggi fino a fine riga
				c = scan(m);         // m: figlio di n; c: blank char
				T[n].push_front(m);  // inserisce figlio m di n
				children.insert(m);  // aggiungi il nodo figlio al set
			}
		}
	}
	
	// La radice è quel nodo che:
	//  - è radice di un sottoalbero (root ∈ roots)
	//  - non è figlio di nessun nodo (root ∉ children)
	// Essa può essere trovata effettuando la differenza fra i due set (root ∉ roots \ children)
	//  - roots è un set perché permette l'iterazione
	//  - children è un unordered_set perché permette la ricerca in tempo costante
	int root = -1;  // indice della radice
	for (auto it = roots.begin(); root == -1 && it != roots.end(); it++) {
		if (children.count(*it) == 0) { root = *it; }
	}
	
	// Informazione di debug
	cout << endl << root << endl;
	
	
	/* Implementare DFS/BFS */
	
	
	return 0;
}


