#include <bits/stdc++.h>

using namespace std;

void scan(int &n);

void scan(string &s);

void print(int n);

void print(string s);

void println(int n);

void println(string s);


void sssp(const vector<list<pair<int, int>>> &G, int s, vector<int> &d) {
	priority_queue <pair<int, int>> Q;
	fill(d.begin(), d.end(), INT_MAX);
	Q.push({0, s});
	d[s] = 0;
	while (!Q.empty()) {
		int u = Q.top().second;
		Q.pop();
		for (auto &e: G[u]) {
			int l = e.first;
			int v = e.second;
			if (d[u] + l < d[v]) {
				d[v] = d[u] + l;
				Q.push({d[v], v});
			}
		}
	}
}


int tsp(const vector<list<pair<int, int>>> &G, int u, int air_left, vector<int> &visited, int &max) {
	visited[u]++;
	for (auto &e: G[u]) {
		int l = e.first;
		int v = e.second;
		if (v != 0) {
			if (l + G[v].front().first <= air_left) {  // w(u, v) + w(v, 0)
				tsp(G, v, air_left - l + G[v].front().first, visited, max);
			} else {
			}
		}
	}
	return 0;
}


int main(int argc, char **argv) {
	
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	
	int T;
	scan(T);
	for (int test = 0; test < T; test++) {
		int N, M;
		scan(N);
		scan(M);
		vector<list<pair<int, int>>> G(N);
		for (int m = 0; m < M; m++) {
			int a, b, l;
			scan(a);
			scan(b);
			scan(l);
			G[a].push_back({l, b});
			G[b].push_back({l, a});
		}
		int I;
		scan(I);
		deque<int> P(I + 1);
		bool idol_zero = false;
		for (int i = 1; i < P.size(); i++) {
			scan(P[i]);
			if (P[i] == 0) {
				idol_zero = true;
				i--;
				P.pop_back();
			}
		}
		int A;
		scan(A);
		
		vector<vector<int>> d(P.size(), vector<int>(N));
		vector<list<pair<int, int>>> G1(1);
		for (int i = 0; i < P.size(); i++) {
			if (!G1.back().empty()) { G1.emplace_back(); }
			sssp(G, P[i], d[i]);
			for (int j = 0; j < P.size(); j++) {
				if (i != j && d[i][P[j]] < INT_MAX) {
					G1.back().push_back({d[i][P[j]], j});
				}
			}
		}
		if (G1.back().empty()) { G1.pop_back(); }
		
		vector<int> visited(G1.size(), 0);
//		tsp(G1, 0, A, visited);
//		cout << tsp(G1, src, A) - idol_zero << endl;

#if 1
		int i = 0;
		for (auto &u: G1) {
			cout << char('A' + P[i++]) << ": ";
			for (auto &v: u) {
				cout << char('A' + P[v.second]) << v.first << " ";
			}
			cout << endl;
		}
#endif

//		for (auto &dd: d) { cout << dd << " "; }
		cout << endl;
	}
	
	
	return 0;
}


void scan(int &n) {
	n = 0;
	bool neg = false;
	char c = getchar();
	while (!(c == '-' || (c >= '0' && c <= '9'))) { c = getchar(); }
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; !feof(stdin) && c >= '0' && c <= '9'; c = getchar()) {
		n = n * 10 + c - '0';
	}
	if (neg) { n *= -1; }
}

void scan(string &s) {
	s = "";
	char c = getchar();
	while (c == ' ' || c == '\n' || c == '\t') { c = getchar(); }
	for (; !feof(stdin) && c != ' ' && c != '\n' && c != '\t'; c = getchar()) {
		s += c;
	}
}

void print(int n) {
	if (n == 0) {
		putchar('0');
		return;
	}
	if (n < 0) {
		putchar('-');
		n *= -1;
	}
	string s;
	while (n > 0) {
		s += (n % 10) + '0';
		n /= 10;
	}
	for (int i = s.length() - 1; i >= 0; i--) {
		putchar(s[i]);
	}
}

void print(string s) {
	for (int i = 0; s[i] != 0; i++) {
		putchar(s[i]);
	}
}

void println(int n) {
	print(n);
	putchar('\n');
}

void println(string s) {
	print(s);
	putchar('\n');
}
