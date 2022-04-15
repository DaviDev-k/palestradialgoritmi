#include <bits/stdc++.h>

#define MAXN 10005

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;

int n, t;
set<int> s;
priority_queue <ii> pq;

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t;
	for (int i = 0; i < t; i++) {
		s.insert(i);
	}
	int ci, ti;
	for (int i = 0; i < n; i++) {
		cin >> ci >> ti;
		pq.push({ci, ti});
	}
	int res = 0;
	while (!pq.empty() && !s.empty()) {
		ii v = pq.top();
		pq.pop();
		auto it = s.lower_bound(v.second);
		if ((*it) == v.second) {
			res+= v.first;
			s.erase(it);
			}
		else{
			if(it != s.begin()){
				it--;
				res+=v.first;
				s.erase(it);
			}
		}
//		cout << v.first << " " << v.second << " ->" << res << " - " << (*it) << endl;
	}
	cout << res << endl;
	
	return 0;
}