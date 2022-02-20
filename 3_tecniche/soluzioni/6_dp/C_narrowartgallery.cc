// https://open.kattis.com/problems/narrowartgallery

#include <bits/stdc++.h>

using namespace std;

int max(const vector<int> &v) { return *max_element(v.begin(), v.end()); }

enum {
	L, R, BOTH
};


/*
 * IDEA: per ogni coppia di sale della galleria sono possibili tre opzioni:
 *  0. si tiene solo la sala di sinistra e si chiude quella di destra:
 *  1. si tiene solo la sala di destra e si chiude quella di sinistra;
 *  2. si tengono entrambe le sale.
 *
 * Per coppie successive di sale non sono possibili le combinazioni 0-1 e 1-0, in quanto ostacolerebbero il passaggio.
 * L'opzione 2 invece non è vincolante in nessuna combinazione.
 *
 * L'obiettivo è quello di massimizzare il valore delle sale; per fare ciò, per ogni riga si calcolano i valori massimi
 * ottenibili con ciascuna delle tre opzioni, fissato il numero delle sale già chiuse:
 *  0. somma il valore della stanza di sinistra al maggiore fra il massimo valore ottenibile nella riga precedente
 *     che si conclude con l'opzione 0 e quello con 2; inoltre si incrementa di 1 il numero di stanze chiuse;
 *  1. come 0, ma somma la sala destra al maggiore fra 1 e 2;
 *  2. somma i valori di entrambe le sale al maggiore fra le tre opzioni della riga precedente.
 * 
 * SOLUZIONE: il risultato sarà il maggiore fra i tre valori calcolati per l'ultima riga.
 *
 *                { 0                                     n = 0
 *  DP[n][k][c] = { r[n][c] + max(DP[n-1][k-1][c],        c = L ∨ c = R
 *                {               DP[n-1][k-1][BOTH])
 *                { r[n][L] + r[n][R] + max(DP[n-1][k])   c = BOTH
 *
 * NOTE: è possibile ridurre la dimensione spaziale della tabella DP da [N+1][K+1][3] a [2][2][3], poiché ad ogni passo
 * si ispezionano soltanto gli indici {n, n - 1} e {k, k + 1}; per facilità di comprensione non è riportata questa
 * soluzione, la cui implementazione è lasciata come esercizio al lettore.
 * Anche in questo caso memoization non porta miglioramenti in quanto è necessario risolvere ogni sottoproblema.
 *
 */


int main(int argc, char **argv) {
	
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	
	int N, K;
	cin >> N >> K;
	
	do {
		vector<vector<int>> r(N + 1, vector<int>(2));  // valori delle sale
		vector<vector<vector<int>>> DP(N + 1, vector<vector<int>>(K + 1, vector<int>(3)));
		for (int n = 1; n <= N; n++) {
			cin >> r[n][L] >> r[n][R];
			for (int k = 0; k < min(n, K + 1); k++) {
				if (k < K) {
					for (auto c: {L, R}) {
						DP[n][k + 1][c] = r[n][c] + max(DP[n - 1][k][c], DP[n - 1][k][BOTH]);
					}
				}
				DP[n][k][BOTH] = r[n][L] + r[n][R] + max(DP[n - 1][k]);
			}
		}
		cout << max(DP[N][K]) << endl;
		cin >> N >> K;
	} while (N > 0);
	
	return 0;
}
