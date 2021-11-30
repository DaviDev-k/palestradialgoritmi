#include <iostream>

#define MAXN 100000
#define MAXQ 100000
#define MAXF 200000

using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

int max(int a, int b, int c) {
	return max(max(a, b), c);
}

int min(int a, int b, int c) {
	return min(min(a, b), c);
}

bool isBetween(int n, int a, int b) {
	return (n >= min(a, b) && n <= max(a, b));
}

// Input data
int N, Q;
int F[MAXN], P[MAXQ], V[MAXQ];

int main() {
	
	// Input
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> F[i]; }
	cin >> Q;
	for (int i = 0; i < Q; i++) { cin >> P[i] >> V[i]; }
	
	// Inizializza variabili
	F[P[0]] = V[0];             // cambia un piano
	int count[MAXF + 1] = {0};  // conteggio piani inizializzato a 0
	count[F[0]]++;              // conta piano di partenza
	int minP, maxP;               // piano minimo e massimo, per iterazione finale
	minP = maxP = F[0];           // inizializza al piano di partenza
	
	// Primo conteggio, per ogni spostamento F[i-1] → F[i]
	for (int i = 1; i < N; i++) {
		
		// Aggiorna minimo e massimo
		minP = min(minP, F[i]);
		maxP = max(maxP, F[i]);
		
		// Sali o scendi e conta
		if (F[i] > F[i - 1]) {
			for (int p = F[i - 1] + 1; p <= F[i]; p++) { count[p]++; }
		} else {
			for (int p = F[i - 1] - 1; p >= F[i]; p--) { count[p]++; }
		}
		
	}
	
	// Primo risultato
	int piano = 0, volte = 0;
	for (int i = minP; i <= maxP; i++) {  // scorri il conteggio
		if (count[i] > volte) {         // aggiorna i risultati
			volte = count[i];
			piano = i;
		}
	}
	cout << piano << " " << volte << endl;
	
	for (int j = 1; j < Q; j++) {   // ripeti per ogni test Q[j]
		
		int i = P[j];
		int M = F[i];
		
		if (i > 0 && i < N - 1) {  // non è modificato il piano di partenza o di arrivo
			int A = F[i - 1], B = F[i + 1];
			if (V[j] > max(A, M, B)) {
				for (int k = max(A, M, B); k < V[j]; k++) { count[k]++; }
				count[V[j]]++;
			} else if (V[j] < min(A, M, B)) {
				for (int k = min(A, M, B); k > V[j]; k--) { count[k]++; }
				count[V[j]]++;
			} else if (M > max(A, B)) {
				for (int k = max(V[j], A, B); k < M; k++) { count[k] -= 2; }
				count[M]--;
			} else if (M < min(A, B)) {
				for (int k = min(V[j], A, B); k > M; k--) { count[k] -= 2; }
				count[M]--;
			}
		} else {
			int adj = F[(i == 0) ? 1 : N - 2];  // piano adiacente
			if (isBetween(V[j], M, adj)) {
				if (V[j] > M) {
					for (int k = M; k < V[j]; k++) { count[k]--; }
				} else {
					for (int k = M; k > V[j]; k--) { count[k]--; }
				}
			} else {
				if (V[j] > M) {
					for (int k = V[j]; k > M; k--) { count[k]++; }
				} else {
					for (int k = V[j]; k < M; k++) { count[k]++; }
				}
			}
		}
		
		F[i] = V[j];
		minP = min(minP, V[j]);
		maxP = max(maxP, V[j]);
		
		int piano = 0, volte = 0;
		for (int i = minP; i <= maxP; i++) {  // scorri il conteggio
			if (count[i] > volte) {         // aggiorna i risultati
				volte = count[i];
				piano = i;
			}
		}
		cout << piano << " " << volte << endl;
		
	}
	
	return 0;
}
/*
5
4 2 6 1 7
5
0 3
3 4
1 1
4 2
2 5
 */