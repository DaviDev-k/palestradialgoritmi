#include <bits/stdc++.h>

#define MAXN 10005

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;


int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int mask_l = 1, mask_r = 1;
	mask_l <<= 31;
	int n, m = 0;
	cin >> n;
	while (!(n & mask_l)) { n <<= 1;
	}
	for (int i = 0; i < 32; i++) {
		m <<= 1;
		m |= (n & mask_r);
		n >>= 1;
	}
	cout << m << endl;
	
	
	return 0;
}