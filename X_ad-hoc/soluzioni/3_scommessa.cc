#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	int N;
	fin >> N;
	vector<int> C(N);
	for (int i = 0; i < N; i++) { fin >> C[i]; }
	
	// par_dis[0][i] conta i numeri pari dall'inizio di C_0 a C_i (compreso)
	// par_dis[1][i] conta i numeri dispari
	vector <vector<int>> par_dis(2, vector<int>(N));
	par_dis[C[0] % 2][0] = 1;
	for (int i = 1; i < N; i++) {
		par_dis[C[i] % 2][i] = par_dis[C[i] % 2][i - 1] + 1;
		par_dis[(C[i] + 1) % 2][i] = par_dis[(C[i] + 1) % 2][i - 1];
	}
	
	// Un numero può rimanere spaiato se e solo se
	//  1. è pari &&
	//  2. i sottoinsiemi di numeri che lo precedono e quelli che lo seguono
	//     sono formati dallo stesso numero di pari e dispari
	vector<int> single;
	for (int i = 0; i < N; i++) {
		if (C[i] % 2 == 0
		    && (par_dis[0][i - 1] == par_dis[1][i - 1])
		    && (par_dis[0][N - 1] - par_dis[0][i] == par_dis[1][N - 1] - par_dis[1][i])) {
			single.push_back(C[i]);
		}
	}
	fout << single.size() << endl;
	for (auto &s: single) { fout << s << " "; }
	
	fin.close();
	fout.close();
	return 0;
}
