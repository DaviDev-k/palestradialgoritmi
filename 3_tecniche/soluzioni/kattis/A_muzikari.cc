// https://open.kattis.com/contests/kzhiwr/problems/muzicari

#include <bits/stdc++.h>

using namespace std;


/*
 * IDEA: dato che non possono essere assenti più di due musicisti alla volta, il problema può essere tradotto così:
 * trovare due sequenze di intervalli non sovrapposti, tali che ciascun intervallo compare una e una sola volta in
 * una sola delle due sequenze.
 * Considerando ciò, il problema può essere ulteriormente semplificato: trovare la sequenza massimale di intervalli
 * non sovrapposti, la cui somma sia inferiore a T; la seconda sequenza, formata dagli elementi rimanenti, sarà
 * inferiore alla prima (dato che è massimale) e dunque anche a T.
 * È possibile risolvere questo problema con programmazione dinamica.
 * Qui sono proposte due soluzioni differenti che utilizzano memoization.
 *
 */

/*
 * NOTE: per riempire la tabella e contemporaneamente restituire il valore è stata usata le seguente sintassi
 * `return DP[i][t] = x;`
 * Essa sfrutta il fatto che operator= restituisce un valore di ritorno, oltre ad effettuare l'assegnamento.
 *
 */


/*
 * VERSIONE 0
 * DP[i][t] contiene il tempo residuo che non può essere occupato dal sottoinsieme massimale dei primi i intervalli,
 * la cui durata complessiva sia inferiore a t; se DP[i][t] == 0 significa che esiste un tale sottoinsieme che riempie
 * perfettamente il lasso di tempo t.
 * L'obiettivo è riempire il più possibile il lasso di tempo t, ovvero minimizzare il tempo residuo, da cui dipende la
 * scelta di prendere o no l'intervallo i.
 *
 *            ⎧ +∞                    t < 0
 *            ⎪ t                     i = 0
 * DP[i][t] = ⎨ 0                     t = 0
 *            ⎪ min(DP[i-1][t-d[i]],  altrimenti
 *            ⎩     DP[i-1][t])
 */

int memo0(int i, int t, const vector<int> &d, vector<vector<int>> &DP) {
	if (t < 0)         { return INT_MAX;      }  // out of range (primo caso da controllare)
	if (i == 0)        { return DP[i][t] = t; }  // base: no musician
	if (t == 0)        { return DP[i][t] = 0; }  // base: no time left
	if (DP[i][t] >= 0) { return DP[i][t];     }  // memoized
	
	int not_taken = memo0(i - 1, t,        d, DP);
	int taken     = memo0(i - 1, t - d[i], d, DP);
	
	return DP[i][t] = min(taken, not_taken);
}


/*
 * VERSIONE 1
 * Questa versione non è altro che la soluzione del problema dello zaino, in cui peso e profitto coincidono.
 *
 *             ⎧ -∞                           t < 0
 *  DP[i][t] = ⎨ 0                            i = 0 ∨ t = 0
 *             ⎪ max(DP[i-1][t-d[i]] + d[i],  altrimenti
 *             ⎩     DP[i-1][t])
 */

int memo1(int i, int t, const vector<int> &d, vector<vector<int>> &DP) {
	if (t < 0)            { return -INT_MAX;     }  // out of range (primo caso da controllare)
	if (i == 0 || t == 0) { return DP[i][t] = 0; }  // base: no musician or no time left
	if (DP[i][t] >= 0)    { return DP[i][t];     }  // memoized
	
	int not_taken = memo1(i - 1, t,        d, DP);         // DP[i - 1][t]
	int taken     = memo1(i - 1, t - d[i], d, DP) + d[i];  // DP[i - 1][t - d[i]]
	
	return DP[i][t] = max(taken, not_taken);
}


/*
 * RICOSTRUIRE LA SOLUZIONE
 *  0. Inizializzare due contatori t1 e t2, che specificano l'orario di inizio degli intervalli delle due sequenze.
 *  1. Partire dalla cella DP[N][T] (in basso a destra) e ripetere per ogni intervallo.
 *  2. Verificare se l'intervallo attuale è stato preso (sequenza 1) oppure no (sequenza 2).
 *    - Questa è l'unica istruzione differente fra le due versioni.
 *  3. Assegnare il tempo d'inizio all'intervallo attuale e incrementare tale contatore della durata dell'intervallo.
 *  4. Se è stato preso, decrementare il contatore t (tempo residuo) della durata dell'intervallo.
 *
 */

void solution0(int i, int t, const vector<int> &d, const vector<vector<int>> &DP, vector<int> &sol) {
	int t1 = 0, t2 = 0;
	for (; i > 0; i--) {
		if (DP[i - 1][t - d[i]] < DP[i - 1][t]) {  // taken
			sol[i] = t1;
			t1 += d[i];
			t -= d[i];
		} else {  // not-taken
			sol[i] = t2;
			t2 += d[i];
		}
	}
}

void solution1(int i, int t, const vector<int> &d, const vector<vector<int>> &DP, vector<int> &sol) {
	int T = t;
	int t1 = 0, t2 = 0;
	for (; i > 0; i--) {
		if (DP[i - 1][t - d[i]] + d[i] > DP[i - 1][t] && t1 + d[i] <= T) {  // taken
			t -= d[i];
			sol[i] = t1;
			t1 += d[i];
		} else {  // not-taken
			sol[i] = t2;
			t2 += d[i];
		}
	}
}


int main(int argc, char **argv) {
	
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	
	int T, N;  // tempo totale, numero di musicisti
	cin >> T >> N;
	
	vector<int> d(N + 1);  // vettore delle durate degli intervalli (1-based)
	for (int i = 1; i <= N; i++) { cin >> d[i]; }
	
	vector<vector<int>> DP(N + 1, vector<int>(T + 1, -1));  // tabella DP
	memo0(N, T, d, DP);
	
	vector<int> sol(N + 1);  // vettore dei tempi di inizio degli intervalli (1-based)
	solution0(N, T, d, DP, sol);
	
	for (int i = 1; i <= N; i++) { cout << sol[i] << " "; }

#if 0
	cout << endl;
	for (int i = 0; i <= N; i++) {
		for (int t = 0; t <= T; t++) {
			cout << (DP[i][t] >= 0 && DP[i][t] < 10 ? " " : "") << DP[i][t] << "  ";
		}
		cout << endl;
	}
#endif
	
	cout << endl;
	return 0;
}


/*
 
      0  1  2  3  4  5  6  7  8  9 10
-  0  0  1  2  3  4  5  6  7  8  9 10
7  1  0  1  2  3  4  5  6  0  1  2  3
5  2  0  1  2  3  4  0  1  0  1  2  3
1  3  0  0  1  2  3  0  0  0  0  1  2
2  4  0  0  0  0  1  0  0  0  0  0  0
3  5  0  0  0  0  0  0  0  0  0  0  0

*/
