#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	
	int T, N;
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		
		cout << "Case #" << t << ":\n";
		cin >> N;
		vector<int> S(N);
		int tot = 0;
		for (auto &s: S) {
			cin >> s;
			tot += s;
		}
		
		vector<bitset<20>> set(tot + 1, bitset<20>());
		int equal = -1;
		for (int i = 0; equal < 0 && i < N; i++) {
			for (int j = tot - S[i]; equal < 0 && j >= 0; j--) {
				if (set[j].any() || j == 0) {
					if (set[j + S[i]].any()) {
						for (int k = 0; k < N; k++) {
							if (set[j + S[i]][k]) { cout << S[k] << " "; }
						}
						cout << endl;
						equal = j + S[i];
					}
					set[j + S[i]] = set[j];
					set[j + S[i]][i] = true;
				}
			}
		}
		
		if (equal >= 0) {
			for (int j = 0; j < N; j++) {
				if (set[equal][j]) { cout << S[j] << " "; }
			}
		} else {
			cout << "Impossible";
		}
		cout << endl;
	}
	return 0;
}
