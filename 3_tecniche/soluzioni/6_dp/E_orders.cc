#include <bits/stdc++.h>

using namespace std;

enum {
	OKK,  // spesa precisa
	AMB,  // ambiguo
	IMP,  // impossibile
	NIL   // non calcolato
};

void scan(int &n);

void print(int n);

void print(string s);


/*
 * IDEA: il problema è una variazione dello zaino senza limiti in cui peso e profitto coincidono. Ogni sottoproblema
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
 *  - almeno uno AMB → AMB  (i, s) è risolto da una soluzione ambigua
 *  - entrambi OKK   → AMB  esistono due combinazioni valide che risolvono (i, s)
 *  - solo uno OKK   → OKK  esiste una sola combinazione valida che risolve (i, s)
 *  - entrambi IMP   → IMP  non esiste alcuna combinazione valida che risolve (i, s)
 *
 * SOLUZIONE: la soluzione del problema decisionale (OKK, AMB o IMP) per un dato input (N, s) può essere immediatamente
 * trovata nella rispettiva cella della tabella DP; nel caso di esito OKK è necessario ricostruire la soluzione.
 *
 *             { OKK  (DP[i][s-C[i]] = OKK ⩒ DP[i-1][s] = OKK) ∨ (s = 0)
 *  DP[i][s] = { AMB  (DP[i][s-C[i]] = AMB ∨ DP[i-1][s] = AMB) ∨ (DP[i][s-C[i]] = OKK ∧ DP[i-1][s] = OKK)
 *             { IMP  (DP[i][s-C[i]] = IMP ∧ DP[i-1][s] = IMP) ∨ (i ≤ 0) ∨ (s < 0)
 */


int memo(int i, int s, const vector<int> &C, vector<vector<int>> &DP) {
	
	if (s < 0)           { return IMP;            }  // out of range
	if (DP[i][s] != NIL) { return DP[i][s];       }  // memoized
	if (i == 0)          { return DP[i][s] = IMP; }  // base: nessun piatto
	if (s == 0)          { return DP[i][s] = OKK; }  // base: resto preciso
	
	int taken = memo(i, s - C[i], C, DP);
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


int main(int argc, char **argv) {
	
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	
	int N, M;
	scan(N);
	vector<int> C(N + 1);
	for (int n = 1; n <= N; n++) { scan(C[n]); }
	scan(M);
	vector<int> S(M);
	for (int m = 0; m < M; m++) { scan(S[m]); }
	
	// Si utilizza un'unica tabella DP, di dimensione pari al massimo valore di `S`
	int max_s = *max_element(S.begin(), S.end());
	vector<vector<int>> DP(N + 1, vector<int>(max_s + 1, NIL));
	stack<int> sol;
	
	for (auto &s: S) {
		memo(N, s, C, DP);  // memoization permette di calcolare solo i sottoproblemi necessari, senza ripetizioni
		switch (DP[N][s]) {
			case OKK:
				solution(N, s, C, DP, sol);
				while (!sol.empty()) {
					print(sol.top());
					print(" ");
					sol.pop();
				}
				break;
			case AMB:
				print("Ambiguous");
				break;
			case IMP:
				print("Impossible");
				break;
		}
		print("\n");
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


void scan(int &n) {
	n = 0;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) { c = getchar(); }
	for (; !feof(stdin) && c >= '0' && c <= '9'; c = getchar()) { n = n * 10 + c - '0'; }
}

void print(int n) {
	if (n == 0) {
		putchar('0');
		return;
	}
	string s;
	while (n > 0) {
		s += (n % 10) + '0';
		n /= 10;
	}
	for (int i = s.length() - 1; i >= 0; i--) { putchar(s[i]); }
}

void print(string s) {
	for (int i = 0; s[i] != 0; i++) { putchar(s[i]); }
}

