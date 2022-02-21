#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<long long int> rank(N);
		for (auto &r: rank) {
			string _;
			cin >> _ >> r;
		}
		sort(rank.begin(), rank.end());
		long long int sum = 0;
		for (int i = 0; i < N; i++) { sum += abs(rank[i] - (i + 1)); }
		cout << sum << endl;
	}
	return 0;
}
