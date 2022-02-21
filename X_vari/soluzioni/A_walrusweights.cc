#include <bits/stdc++.h>

#define GOAL 1000

using namespace std;

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	
	int N;
	cin >> N;
	vector<int> W(N);
	for (int w = 0; w < N; w++) { cin >> W[w]; }
	
	vector<bool> DP(2 * GOAL, false);
	DP[0] = true;
	bool raised = false;
	for (auto &w: W) {
		for (int i = (2 * GOAL) - w; i >= 0; i--) {
			if (DP[i]) { DP[i + w] = true; }
		}
	}
	
	for (int w = 0; !raised && w < GOAL; w++) {
		if (DP[GOAL + w]) {
			cout << GOAL + w << endl;
			raised = true;
		} else if (DP[GOAL - w]) {
			cout << GOAL - w << endl;
			raised = true;
		}
	}

	return 0;
}
