#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	int T;
	cin >> T;
	while (T--) {
		int n, m, l;
		int ret = 0;
		cin >> n >> m >> l;
		vector<list<int>> D(n + 1);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			D[x].push_back(y);
		}
		vector<bool> drop(n + 1, false);
		for (int i = 0; i < l; i++) {
			stack<int> S;
			int k;
			cin >> k;
			if (!drop[k]) { S.push(k); }
			drop[k] = true;
			while (!S.empty()) {
				ret++;
				k = S.top();
				S.pop();
				while (!D[k].empty()) {
					if (!drop[D[k].back()]) { S.push(D[k].back()); }
					drop[D[k].back()] = true;
					D[k].pop_back();
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}
