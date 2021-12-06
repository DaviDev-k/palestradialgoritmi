// https://open.kattis.com/problems/sylvester

#include <bits/stdc++.h>

#define MAX_SIZE 6

using namespace std;

void print(string s);

int main(int argc, char **argv) {
	
	vector < vector < vector < vector < int >> >> H(2);  // +/-, n, y, x
	H[0].resize(MAX_SIZE);
	H[1].resize(MAX_SIZE);
	H[0][0].push_back(vector<int>(1, 1));
	H[1][0].push_back(vector<int>(1, -1));
	for (int i = 1; i < MAX_SIZE; i++) {           // dimensioni
		int l = (1 << (i - 1));                    // dimensione precedente
		H[0][i].resize(2 * l);
		H[1][i].resize(2 * l);
		for (int k = 0; k < 2; k++) {              // blocchi di righe
			for (int y = 0; y < l; y++) {          // righe di un blocco
				for (int x = 0; x < 2; x++) {      // blocchi di colonne
					for (int h = 0; h < 2; h++) {  // pos e neg
						H[h][i][y + k * l].insert(
								H[h][i][y + k * l].end(),
								H[h ^ (x & k)][i - 1][y].begin(),
								H[h ^ (x & k)][i - 1][y].end());
					}
				}
			}
		}
	}
	
	for (int i = 0; i < 5; i++) {
		for (int y = 0; y < (1 << i); y++) {
			for (int k = 0; k < 2; k++) {
				for (auto &n: H[k][i][y]) {
					print(n == 1 ? " 1 " : "-1 ");
				}
				print("    ");
			}
			putchar('\n');
		}
		putchar('\n');
	}
}


void print(string s) {
	for (int i = 0; s[i] != 0; i++) {
		putchar(s[i]);
	}
}
