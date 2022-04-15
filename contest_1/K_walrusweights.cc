// https://open.kattis.com/contests/i6uudu
// https://open.kattis.com/problems/walrusweights

#include <bits/stdc++.h>

#define GOAL 1000

using namespace std;

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	vector<int> W(N);
	for (auto &w: W) { cin >> w; }
	
	bitset<2 * GOAL> DP(false);  // bitset delle somme realizzabili
	DP[0] = true;                // caso base: la somma nulla è sempre realizzabile
	
	// IDEA: se è possibile ottenere la somma `DP[i]` senza il peso `w`, allora anche `DP[i + w]` è realizzabile
	for (auto &w: W) {                               // scorri tutti i pesi
		for (int i = (2 * GOAL) - w;
		     i >= 0; i--) {  // ripercorri a ritroso tutte le somme possibili per evitare ripetizioni
			if (DP[i]) { DP[i + w] = true; }         // aggiungi il peso `w` ad una somma già realizzata
		}
	}
	
	// Scorri il vettore delle somme possibili: parti da GOAL e procedi verso gli estemi dell'intervallo [0, 2*GOAL]
	// La variabile `diff` rappresenta la differenza fra GOAL e i due pesi in analisi `GOAL+diff` e `GOAL-diff`
	// Si verificano così le somme dando precedenza a quelle più vicine a GOAL e in caso di parità a quella maggiore
	bool raised = false;  // ferma l'iterazione quando si trova la somma migliore
	for (int diff = 0; !raised && diff < GOAL; diff++) {
		if (DP[GOAL + diff]) {
			cout << GOAL + diff << endl;
			raised = true;
		} else if (DP[GOAL - diff]) {
			cout << GOAL - diff << endl;
			raised = true;
		}
	}
	
	return 0;
}
