#include <bits/stdc++.h>

using namespace std;

void scan(int &n);

void print(int n);

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	int T;
	scan(T);
	while (T--) {
		int n, m, l;
		int ret = 0;
		scan(n);
		scan(m);
		scan(l);
		vector<list<int>> D(n + 1);
		for (int i = 0; i < m; i++) {
			int x, y;
			scan(x);
			scan(y);
			D[x].push_back(y);
		}
		vector<bool> drop(n + 1, false);
		for (int i = 0; i < l; i++) {
			stack<int> S;
			int k;
			scan(k);
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
		print(ret);
		putchar('\n');
	}
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
