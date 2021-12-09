#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	
	int N;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> N;
	vector<int> v(N, 1);
	int count1 = N;
	const string P[3] = {"", "[O]", "[OOOO]"};
	
	for (int i = 0; i < N; i += v[i]) { fout << P[v[i]]; }
	fout << endl;
	while ((N % 2 == 0 && count1 > 0) || (N % 2 == 1 && (count1 > 1 || v.back() != 1))) {
		bool go = true;
		for (int i = N - 1; go && i > 0; i -= v[i]) {
			if (v[i] == 1 && v[i - 1] == 1) {
				v[i] = v[i - 1] = 2;
				count1 -= 2;
				go = false;
			} else if (v[i] == 2 && v[i - 2] == 1) {
				v[i] = 1;
				v[i - 2] = 2;
				for (i++; i < N; i++) {
					if (v[i] == 2) {
						v[i] = v[i + 1] = 1;
						i++;
						count1 += 2;
					}
				}
				go = false;
			}
		}
		for (int i = 0; i < N; i += v[i]) { fout << P[v[i]]; }
		fout << endl;
	}
	fin.close();
	fout.close();
	return 0;
}

