// https://open.kattis.com/contests/i6uudu
// https://open.kattis.com/problems/nikola

#include <bits/stdc++.h>

using namespace std;

enum {
	ND = INT_MAX - 1,  // non si usa -1 perché falserebbe il calcolo del minimo}
	INF = INT_MAX
};

int memo(int pos, int jump, int N, const vector<int> &fees, vector<vector<int>> &DP) {
	if (pos == 0 && jump == 0) { return DP[pos][jump] = 0; }               // caso base: partenza
	if (pos < 0 || pos >= N || jump < 1 || jump >= N - 1) { return INF; }  // limiti: fuori dalla griglia di gioco
	if (DP[pos][jump] != ND) { return DP[pos][jump]; }                     // memoized
	int from_back = memo(pos - jump, jump - 1, N, fees, DP);               // arriva da un salto in avanti
	int from_forth = memo(pos + jump, jump, N, fees, DP);                  // arriva da un salto all'indietro
	DP[pos][jump] = min(from_back, from_forth);                            // scegli il salto conveniete
	if (DP[pos][jump] != INF) DP[pos][jump] += fees[pos];                  // avoid overflow && somma il costo attuale
	return DP[pos][jump];
}

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	vector<int> fees(N);
	for (auto &f: fees) { cin >> f; }
	
	vector<vector<int>> DP(N, vector<int>(N - 1, ND));  // (pos, last_jump)
	for (int j = 1; j < N - 1; j++) { DP[N - 1][j] = memo(N - 1, j, N, fees, DP); }
	cout << *min_element(DP[N - 1].begin(), DP[N - 1].end()) << endl;
	return 0;
}

