#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
	
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	
	int N, K;
	cin >> N >> K;
	vector<int> NK(K + 1);
	
	for (int k = 0; k <= K; k++) {
		NK[k] = pow(N, k);
	}
	
	vector <vector<bool>> M(N, vector<bool>(N));
	vector <vector<bool>> MK(NK[K], vector<bool>(NK[K]));
	getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			M[i][j] = (getchar() == '.');
		}
		getchar();
	}
	
	for (int k = 0; k < K; k++) {
		double f = (double) N / (double) NK[K - k];
		for (int i = 0; i < NK[K]; i++) {
			for (int j = 0; j < NK[K]; j++) {
				if (k == 0 || MK[i][j]) {
					MK[i][j] = M[(i % NK[K - k]) * f][(j % NK[K - k]) * f];
				}
			}
		}
	}

	for (int i = 0; i < NK[K]; i++) {
		for (int j = 0; j < NK[K]; j++) {
			putchar(MK[i][j] ? '.' : '*');
		}
		putchar('\n');
	}
	return 0;
}