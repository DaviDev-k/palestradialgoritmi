/*
 * La differenza con la soluzione da 25 punti è che questa è più veloce
 * perché non ricalcola le tratte non modificate fra un test e l'altro
 * 
 * Anche l'implementazione è leggermente più complessa,
 * quindi si consiglia prima di capire bene la soluzione da 25
 * 
 */


#include <iostream>

#define MAXN 100000
#define MAXQ 100000
#define MAXF 200000

using namespace std;

// Input data
int N, Q;
int F[MAXN], P[MAXQ], V[MAXQ];

// My data (qui è permesso usare variabili globali per semplificarne l'utilizzo nelle funzioni)
int minP, maxP;             // piano minimo e massimo, per calcolo risultato
int count[MAXF + 1] = {0};  // conteggio piani inizializzato a 0


// Percorre una tratta e incremente i piani visitati
void inc(int start, int end) {
	// Sali o scendi e conta
	if (end > start) {
		for (int i = start + 1; i <= end; i++) { count[i]++; }
	} else {
		for (int i = start - 1; i >= end; i--) { count[i]++; }
	}
}

// Percorre una tratta e decrementa i piani visitati
void dec(int start, int end) {
	// Sali o scendi e conta
	if (end > start) {
		for (int i = start + 1; i <= end; i++) { count[i]--; }
	} else {
		for (int i = start - 1; i >= end; i--) { count[i]--; }
	}
}


void printResult() {
	int piano = 0, volte = 0;
	for (int i = minP; i <= maxP; i++) {  // scorri il conteggio dei piani visitati nel dato test
		if (count[i] > volte) {  // aggiorna i risultati
			volte = count[i];
			piano = i;
		}
	}
	cout << piano << " " << volte << endl;
}


int main() {
	
	// Input
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> F[i]; }
	cin >> Q;
	for (int i = 0; i < Q; i++) { cin >> P[i] >> V[i]; }


// ↓↓↓ Algoritmo ↓↓↓

// Per prima cosa si contano i piani visitati durante il primo test
	
	F[P[0]] = V[0];      // cambia un piano
	count[F[0]]++;       // conta piano di partenza (la prima tratta è l'unica in cui si contano entrambi gli estremi)
	minP = maxP = F[0];  // inizializza al piano di partenza
	
	// Analizza ogni tratta
	for (int i = 1; i < N; i++) {
		if (F[i] < minP) { minP = F[i]; }  // aggiorna minimo
		if (F[i] > maxP) { maxP = F[i]; }  // aggiorna massimo
		inc(F[i - 1], F[i]);               // conta i piani visitati in una tratta
	}
	
	// Calcola e stampa il risultato
	printResult();


// Poi si passa ai test successivi:
//   il conteggio varierà solo per le due tratte
//   che finiscono e iniziano con il piano cambiato
	
	// Analizza i test successivi
	for (int j = 1; j < Q; j++) {
		
		int idx = P[j];      // indice del piano modificato ("alias" per migliorare la leggibilità)
		int oldP = F[idx];   // memorizza il vecchio piano
		F[idx] = V[j];       // cambia il piano
		
		// Aggiorna minimo e massimo, se cambiati
		if (minP == oldP || maxP == oldP) {  // se il vecchio piano era min o max
			for (int i = 0; i < N; i++) {
				if (F[i] < minP) { minP = F[i]; }
				if (F[i] > maxP) { maxP = F[i]; }
			}
		} else {  // se il nuovo piano è min o max
			if (V[j] < minP) { minP = V[j]; }
			if (V[j] > maxP) { maxP = V[j]; }
		}
		
		// Riduci il conteggio dei piani della tratta del test precedente
		// Aumenta il conteggio dei piani delle tratte modificate
		if (idx == 0) {               // cambia il piano di partenza
			count[oldP]--;
			count[F[0]]++;
		} else {                      // non cambia il piano di partenza
			dec(F[idx - 1], oldP);
			inc(F[idx - 1], F[idx]);
		}
		if (idx != N - 1) {           // non cambia il piano di arrivo
			dec(oldP, F[idx + 1]);
			inc(F[idx], F[idx + 1]);
		}
		
		printResult();
		
	}
	
	return 0;
}
