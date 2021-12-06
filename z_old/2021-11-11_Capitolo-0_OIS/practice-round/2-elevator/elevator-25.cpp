#include <iostream>

#define MAXN 100000
#define MAXQ 100000
#define MAXF 200000

using namespace std;

// Input data
int N, Q;
int F[MAXN], P[MAXQ], V[MAXQ];

int main() {
	
	// Input
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> F[i]; }
	cin >> Q;
	for (int i = 0; i < Q; i++) { cin >> P[i] >> V[i]; }
	
	// Algoritmo, per ogni test Q[j]
	for (int j = 0; j < Q; j++) {
		
		F[P[j]] = V[j];             // cambia un piano
		int count[MAXF + 1] = {0};  // conteggio piani inizializzato a 0
		count[F[0]]++;              // conta piano di partenza
		int min, max;               // piano minimo e massimo, per iterazione finale
		min = max = F[0];           // inizializza al piano di partenza
		
		// Analizza ogni spostamento
		for (int i = 1; i < N; i++) {
			
			// Aggiorna minimo e massimo in base al piano cambiato
			if (F[i] < min) { min = F[i]; }
			if (F[i] > max) { max = F[i]; }
			
			// Sali o scendi e conta,
			if (F[i] > F[i - 1]) {
				for (int p = F[i - 1] + 1; p <= F[i]; p++) { count[p]++; }
			} else {
				for (int p = F[i - 1] - 1; p >= F[i]; p--) { count[p]++; }
			}
			
		}
		
		// Risultati
		int piano = 0, volte = 0;
		for (int i = min; i <= max; i++) {  // scorri il conteggio
			if (count[i] > volte) {         // aggiorna i risultati
				volte = count[i];
				piano = i;
			}
		}
		cout << piano << " " << volte << endl;
		
	}
	
	return 0;
}