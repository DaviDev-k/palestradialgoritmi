#include <bits/stdc++.h>

#define DEBUG 1

using namespace std;

typedef vector <vector<vector < int>>>
vector3i;

int sum(const vector<int> &A, const vector<int> &v) {
	int sum = 0;
	for (int i = 0; i < A.size(); i++) { sum += A[i] * v[i]; }
	return sum;
}

vector<int> take(const vector<int> &v, int i, int k) {
	vector<int> u(v);  // costruttore di copia
	u[i] += k;
	return u;
}

int max_elem(const vector<int> &v) {
	return *max_element(v.begin(), v.end());
}

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

vector<int> sushi_rec(const vector<int> &A, int N, int B, int n, int b, vector3i &DP) {
	if (n <= 0 || b <= 0) { return vector<int>(N, 0); }  // casi base
	if (DP[n][b][0] == -1) {                             // cella non calcolata → ricorsione
		int i = n - 1;                                   // indice del piatto attuale
		for (int j = b % A[i], k = b / A[i]; j <= b; j += A[i], k--) {
			DP[n][b] = lower(DP[n][b],
			                  lower(take(sushi_rec(A, N, B, n - 1, j, DP), i, k),
			                        take(sushi_rec(A, N, B, n, j - A[i], DP), i, k), A, b), A, b);
		}
	}
	return DP[n][b];  // cella già calcolata o appena calcolata
}

int sushi(int N, int B, vector<int> A) {
	
	/* Si costruisce una tabella DP tridimensionale, che può essere vista come una semplice matrice bidimensionale,
	 * con N+1 righe (una per ogni piatto) e B+2 colonne (i soldi rimanenti), le cui celle contengono vettori di
	 * lunghezza N, che rappresentano il conteggio di ogni piatto. Se il vettore contiene solo valori 0, allora non
	 * esiste una combinazione di piatti il cui prezzo totale sia esattamente B.
	 * La prima riga e la prima colonna rappresentano i casi base. Nella pratica sono utili per "coronare" la matrice
	 * di valori 0, in modo da gestire alla stessa maniera tutte le altre celle interne.
	 */
	vector3i DP(N + 1, vector < vector < int >> (B + 1, vector<int>(N, -1)));  // DP[N+1][B+2][N]
//	vector <vector<int>> DP2(N + 1, vector<int>(B + 1, 0));
	
	vector<int> ret = sushi_rec(A, N, B, N, B, DP);


#if DEBUG  // stampa tabella DP
	for (int n = 1; n <= N; n++) {
		for (int b = 1; b <= B; b++) {
			for (int j = 0; j < N; j++) {
				if (DP[n][b][j] >= 0) { cout << DP[n][b][j] << ","; }
				else { cout << "-,"; }
			}
			cout << "\b \t";
		}
		cout << endl << endl;
	}
#endif
	
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
