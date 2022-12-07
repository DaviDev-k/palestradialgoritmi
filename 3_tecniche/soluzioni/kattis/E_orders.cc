#include <bits/stdc++.h>

using namespace std;

enum {
	OKK,  // spesa precisa
	AMB,  // ambiguo
	IMP,  // impossibile
	NIL   // non calcolato
};


/*
 * IDEA: il problema è una variante dello zaino senza limiti in cui peso e profitto coincidono. Ogni sottoproblema
 * (dato dai primi `i` piatti e dall'importo `s`) può avere tre esiti:
 *  - OKK (precisa)      se esiste una e una sola combinazione di piatti la cui somma sia `s`
 *  - AMB (ambigua)      se esiste più di una combinazione di piatti la cui somma sia `s`
 *  - IMP (impossibile)  se non esiste alcuna combinazione di piatti la cui somma sia `s`
 *
 * Ogni sottoproblema (i, s) dipende da due sottoproblemi:
 *  - (i, s-C[i])  si prende il piatto `i`, dunque si sottrae il suo costo dalla spesa residua e si lascia la
 *                 possibilità di acquistarlo nuovamente;
 *  - (i-1, s)     non si prende il piatto `i`, dunque si esclude la possibilità di prendere ulteriori piatti `i` e la
 *                 spesa residua rimane inalterata
 *
 * A seconda dell'esito dei sottoproblemi (i, s-C[i]) e (i-1, s), possono verificarsi 4 possibili esiti per (i, s):
 *  - almeno uno AMB → AMB :  (i, s) è risolto da una soluzione ambigua
 *  - entrambi OKK   → AMB :  esistono due combinazioni valide che risolvono (i, s)
 *  - solo uno OKK   → OKK :  esiste una sola combinazione valida che risolve (i, s)
 *  - entrambi IMP   → IMP :  non esiste alcuna combinazione valida che risolve (i, s)
 *
 * SOLUZIONE: la soluzione del problema decisionale (OKK, AMB o IMP) per un dato input (N, s) può essere immediatamente
 * trovata nella rispettiva cella della tabella DP[N][S]; nel caso di esito OKK è necessario ricostruire la soluzione.
 *
 *             ⎧ OKK   (DP[i][s-C[i]] = OKK ⩒ DP[i-1][s] = OKK) ∨ (s = 0)
 *  DP[i][s] = ⎨ AMB   (DP[i][s-C[i]] = AMB ∨ DP[i-1][s] = AMB) ∨ (DP[i][s-C[i]] = OKK ∧ DP[i-1][s] = OKK)
 *             ⎩ IMP   (DP[i][s-C[i]] = IMP ∧ DP[i-1][s] = IMP) ∨ (i ≤ 0) ∨ (s < 0)
 */


int memo(int i, int s, const vector<int> &C, vector<vector<int>> &DP) {
	
	if (s < 0)           { return IMP;      }  // out of range
	if (i == 0)          { return IMP;      }  // base: nessun piatto
	if (s == 0)          { return OKK;      }  // base: resto preciso
	if (DP[i][s] != NIL) { return DP[i][s]; }  // memoized
	
	int taken     = memo(i, s - C[i], C, DP);
	int not_taken = memo(i - 1, s, C, DP);
	
	if ((taken == AMB || not_taken == AMB) ||
	    (taken == OKK && not_taken == OKK)) {
		return DP[i][s] = AMB;
	}
	
	if ((taken == OKK) != (not_taken == OKK)) {  // xor
		return DP[i][s] = OKK;
	}
	
	return DP[i][s] = IMP;
}


void solution(int i, int s, const vector<int> &C, const vector<vector<int>> &DP, stack<int> &sol) {
	while (s > 0) {       // ripeti finché non viene utilizzato tutto l'importo
		if (DP[i - 1][s] == OKK) {
			i--;          // escludi il piatto `i`
		} else {
			sol.push(i);  // prendi il piatto `i`
			s -= C[i];    // sottrai il suo costo alla spesa rimanente
		}
	}
}


void print_and_clear_stack(stack<int> &sol) {
	while (!sol.empty()) {
		cout << sol.top() << " ";
		sol.pop();
	}
}


int main(int argc, char **argv) {
	
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	
	int N, M;
	
	cin >> N;
	vector<int> C(N + 1);
	for (int n = 1; n <= N; n++) { cin >> C[n]; }
	
	cin >> M;
	vector<int> S(M);
	for (int m = 0; m < M; m++) { cin >> S[m]; }
	
	// Si utilizza un'unica tabella DP per tutti i test case, di dimensione pari al massimo valore di `S`
	int max_s = *max_element(S.begin(), S.end());
	vector<vector<int>> DP(N + 1, vector<int>(max_s + 1, NIL));
	
	stack<int> sol;
	
	for (auto &s: S) {
		memo(N, s, C, DP);
		switch (DP[N][s]) {
			case OKK:
				solution(N, s, C, DP, sol);
				print_and_clear_stack(sol);
				break;
			case AMB:
				cout << "Ambiguous";
				break;
			case IMP:
				cout << "Impossible";
				break;
		}
		cout << endl;
	}

#if 0
	cout << endl;
	for (auto &i: DP) {
		for (auto &s: i) { cout << s << " "; }
		cout << endl;
	}
#endif
	
	return 0;
}
