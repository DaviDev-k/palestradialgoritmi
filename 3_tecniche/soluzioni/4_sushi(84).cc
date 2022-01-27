#include <bits/stdc++.h>

#define DEBUG 0

using namespace std;


// Struttura che memorizza il vettore delle ripetizioni e la ripetizione massima
struct Entry {
	
	vector<int> count;  // conteggio dei piatti
	int max;            // massima ripetizione
	
	// Inizializza al vettore di dimensione `size`, riempito di valori 0
	Entry(int size) {
		count = vector<int>(size, 0);
		max = 0;
	}
	
};


// Ritorna una copia di `v` alla quale vengono aggiunti `k` piatti `i`
Entry take(const Entry &v, const vector<int> &A, int i, int k) {
	Entry u(A.size());
	u.count = v.count;
	u.count[i] += k;  // prendi `k` piatti `i`
	u.max = max(v.max, u.count[i]);
	return u;
}


// Ritorna `true` se `v` ha ripetizione massima inferiore di `u` e se ha somma `b`
bool lower(Entry &v, const Entry &u, int i, int k) {
	return (u.max == 0 || max(v.max, v.count[i] + k) < u.max);  // `u` non è mai stato computato, oppure `v < u`
}


// Ritorna `true` se `v` ha somma `b`
bool check(const Entry &v, const vector<int> &A, int i, int k, int b) {
	return (v.max != 0 || k * A[i] == b);  // `v` è già stato computato in precedenza, oppure ha somma `b`
}


// Funzione principale, invocata dal grader
int sushi(int N, int B, vector<int> A) {
	
	/* Sia `DP` una tablella di programmazione dinamica di `N` righe e `B+1` colonne.
	 * `DP[i][b]` contiene il vettore della combinazione minima dei primi `i` piatti e con somma pari a `b`.
	 * Tuttavia è possibile comprimere la tabella `DP[N][B+1]` in sole 2 righe, poiché durante la costruzione
	 * riga per riga della tabella, alla i-esima riga viene consultata soltanto la riga i-1.
	 */
	vector <vector<Entry>> DP(2, vector<Entry>(B + 1, Entry(N)));  // DP[2][B+1]
	
	bool now = 0;
	for (int i = 0; i < N; i++, now = !now) {  // aggiorna `now`
		for (int b = 0; b <= B; b++) {
			
			/* Scorrere la riga `DP[!now]` per valori di `j` tali per cui `(b - j) % A[i] == 0`.
			 * Così facendo si considerano solo le celle `DP[!now][j]` precedentemente calcolate, tali per cui è
			 * possibile aggiungere `k` piatti `i` e mantenere il resto pari a 0.
			 */
			int offset = b % A[i];  // valore iniziale dell'iterazione
			int step = A[i];        // passo dell'iterazione
			int max_k = b / A[i];   // numero massimo di piatti `i` che possono essere comprati con `b` soldi
			
			for (int j = offset, k = max_k; j <= b; j += step, k--) {
				if (lower(DP[!now][j], DP[now][b], i, k)      // `v` ha ripetizione massima inferiore di `u`
				    && check(DP[!now][j], A, i, k, b)) {      // `v` ha somma pari a `b`
					DP[now][b] = take(DP[!now][j], A, i, k);  // prendi `k` piatti `i`
				}
			}
		}
	}
	
	return (DP[!now][B].max > 0) ? DP[!now][B].max : -1;
}


#if DEBUG

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int N, B;
	cin >> N >> B;
	vector<int> A(N);
	for (int i = 0; i < N; i++) { cin >> A[i]; }
	cout << sushi(N, B, A);
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
