#include <bits/stdc++.h>

#define DEBUG 0

using namespace std;

// Alias per vettore tridimensionale di interi
typedef vector<vector<vector<int>>> vector3i;

// Calcola la spesa totale, dato un vettore `v` contenente il conteggio di ciascun piatto
int sum(const vector<int> &A, const vector<int> &v) {
	int sum = 0;
	for (int i = 0; i < A.size(); i++) { sum += A[i] * v[i]; }
	return sum;
}

// Ritorna una copia di `v` alla quale vengono aggiunti `k` piatti `i`
vector<int> take(const vector<int> &v, int i, int k) {
	vector<int> u(v);  // costruttore di copia
	u[i] += k;
	return u;
}

// Wrapper per `max_element`
int max_elem(const vector<int> &v) {
	return *max_element(v.begin(), v.end());
}

// Dati due vettori `u` e `v`, ritorna quello avente somma `b` e con il minor numero di ripetizioni
vector<int> lower(const vector<int> &u, const vector<int> &v, const vector<int> &A, int b) {
	int max_u = max_elem(u);
	int max_v = max_elem(v);
	int sum_u = sum(A, u);
	int sum_v = sum(A, v);
	if (sum_u == b && sum_v == b) { return (max_u < max_v) ? u : v; }
	if (sum_u == b) { return u; }
	if (sum_v == b) { return v; }
	return vector<int>(v.size(), 0);
}

// Funzione ricorsiva con memoization
vector<int> sushi_rec(const vector<int> &A, int i, int b, vector3i &DP) {
	
	// Casi base
	if (i < 0 || b <= 0) { return vector<int>(A.size(), 0); }
	
	// Cella non calcolata e ricorsione
	if (DP[i][b][0] == -1) {
		
		/* Scorrere la riga `DP[i]` per valori di `j` tali per cui `(b - j) % A[i] == 0`.
		 * Così facendo si considerano solo le celle `DP[i-1][j]` precedentemente calcolate, tali per cui è
		 * possibile aggiungere `k` piatti `i` e mantenere il resto pari a 0.
		 */
		for (int j = b % A[i], k = b / A[i]; j <= b; j += A[i], k--) {
			DP[i][b] = lower(DP[i][b], take(sushi_rec(A, i - 1, j, DP), i, k), A, b);
		}
	}
	
	return DP[i][b];  // cella già calcolata o appena calcolata
}

int sushi(int N, int B, vector<int> A) {
	
	/* Si costruisce una tabella DP tridimensionale, che può essere vista come una matrice bidimensionale,
	 * con N+1 righe (una per ogni piatto) e B+2 colonne (i soldi rimanenti), le cui celle contengono vettori di
	 * lunghezza N, rappresentanti il conteggio di ogni piatto.
	 * Se il vettore contiene solo valori
	 *  ·  0: non esiste una combinazione di piatti il cui prezzo totale sia esattamente B
	 *  · -1: la cella non è ancora stata calcolata
	 */
	vector3i DP(N, vector<vector<int>>(B + 1, vector<int>(N, -1)));  // DP[N][B+2][N]
	vector<int> ret = sushi_rec(A, N - 1, B, DP);
	int ret_max = max_elem(ret);
	return (ret_max > 0) ? ret_max : -1;
}


#if DEBUG
																														
int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int N, B;
	cin >> N >> B;
	vector<int> A(N);
	for (int i = 0; i < N; i++) { cin >> A[i]; }
	cout << sushi(N, B, A) << endl;
	return 0;
}

#endif


/*
 
   B →
 A
 ↓    |   0   1   2   3   4   5   6   7   8   9  10  11  12
   ---+-----------------------------------------------------
    2 | 000 000 001 000 002 000 003 000 004 000 005 000 006
      |
    4 | 000 000 001 000 010 000 011 000 020 000 021 000 022
      |
    6 | 000 000 001 000 010 000 100 000 101 000 110 000 111
      |                         011
 
 */
