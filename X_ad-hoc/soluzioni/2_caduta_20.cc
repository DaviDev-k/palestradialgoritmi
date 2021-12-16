#include <bits/stdc++.h>

using namespace std;

typedef enum {
	OK,
	RISOLTO,
	IMPOSSIBILE
} stato_t;

typedef struct {
	int domino1;
	int domino2;
} coppia_t;

stato_t correggi(int N, int altezze[], coppia_t *scambio) {
	vector<bool> reach(N);
	reach[0] = true;
	int max = altezze[N - 1];
	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j < altezze[i]; j++) {
			if (i + j < N) { reach[i + j] = true; }
		}
		if (altezze[i] > max) { max = altezze[i]; }
	}
	vector<int> non_reach;
	for (int i = 0; i < N; i++) {
		if (!reach[i]) { non_reach.push_back(i); }
	}
	if (non_reach.empty()) { return OK; }
	if (non_reach.back() - non_reach.front() > max - 1) { return IMPOSSIBILE; }
	return IMPOSSIBILE;
}