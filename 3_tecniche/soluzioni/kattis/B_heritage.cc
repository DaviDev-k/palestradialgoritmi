// https://open.kattis.com/problems/heritage

#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;


/*
 * IDEA: una sottostringa `w` di `W` composta dalle prime `l` lettere può essere formata nei seguenti modi:
 *  - la sottostringa `w` stessa, con `dict[w]` significati;
 *  - la concatenazione di una parola del dizionario `s_dict` che termina alla fine di `w` con la sottostringa `s_dp`
 *    formata dai restanti caratteri; i significati di `w` sono dunque `dict[s_dict]` moltiplicati per tutti i
 *    significati che può assumere `s_dp`, ovvero la somma dei prodotti delle combinazioni di parole che formano `s_dp`.
 *
 * Si definisce una tabella DP, tale che `DP[l]` contiene il numero di significati che può assumere la parola composta
 * dai primi `l` caratteri di `W`.
 *
 *          {                l-1
 *  DP[l] = { dict[W[0:l]] +  ∑  DP[i] * dict[W[i:l]]
 *          {                i=1
 *
 * NOTE: in questo caso memoization non è utile dato che è necessario calcolare tutti i sottoproblemi.
 */

int main(int argc, char **argv) {
	
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	
	int N;
	string W;
	unordered_map<string, long long unsigned> dict;
	cin >> N >> W;
	
	for (int i = 0; i < N; i++) {
		string w;
		cin >> w;
		cin >> dict[w];
	}
	
	unsigned int len = W.length();
	vector<long long unsigned> DP(len + 1);
	
	for (int l = 1; l <= len; l++) {  // procedere per lunghezze crescenti
		string w = W.substr(0, l);    // sottostringa formata dai primi `l` caratteri di `W`
		
		// inizializza `DP[l]` al numero di significati di `w`, 0 se non presente in `dict`
		DP[l] = (dict.count(w) > 0) ? dict[w] : 0;
		for (int i = 1; i < l; i++) {  // `j` taglia `w` in due sottostringhe non vuote
			string s_dict = w.substr(i, l - i);
			
			// è necessario utilizzare il modulo per non eccedere la capacità massima di long long unsigned
			if (dict.count(s_dict) > 0) {
				DP[l] += (DP[i] * dict[s_dict]) % MOD;  // equazione di ricorrenza
				DP[l] %= MOD;
			}
		}
	}
	
	cout << DP[len] << endl;  // il risultato è il numero di significati della parola intera, lunga `W.lenght()`
	
	return 0;
}
