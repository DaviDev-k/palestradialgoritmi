// https://open.kattis.com/problems/restaurant

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen("input.txt", "r", stdin); }  // reindirizza lo standard input da file
	
	int N;
	cin >> N;
	
	while (N != 0) {
		
		int qnt;
		int S1 = 0, S2 = 0;
		
		for (int i = 0; i < N; i++) {
			string cmd;
			cin >> cmd;
			cin >> qnt;
			if (cmd == "DROP") {
				cout << "DROP 1 " << qnt << endl;
				S1 += qnt;
			} else {
				while (qnt > 0) {
					if (S2 == 0) {
						cout << "MOVE 1->2 " <<	S1 << endl;
						S2 = S1;
						S1 = 0;
					}
					cout << "TAKE 2 ";
					if (qnt < S2) {
						cout << qnt << endl;
						S2 -= qnt;
						qnt = 0;
					} else {
						cout << S2 << endl;
						qnt -= S2;
						S2 = 0;
					}
				}
			}
		}
		cout << endl;
		cin >> N;
	}
	return 0;
}
