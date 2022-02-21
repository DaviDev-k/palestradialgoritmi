#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void explore(int y, int x, const vector<vector<char>> &map, vector<vector<bool>> &visited, int &G) {
	visited[y][x] = true;
	if (map[y][x] == 'G') { G++; }
	bool sense = false;
	for (int i = 0; i < 4; i++) {
		if (map[y + dy[i]][x + dx[i]] == 'T') { sense = true; }
	}
	if (!sense) {
		for (int i = 0; i < 4; i++) {
			if (!visited[y + dy[i]][x + dx[i]] && map[y + dy[i]][x + dx[i]] != '#') {
				explore(y + dy[i], x + dx[i], map, visited, G);
			}
		}
	}
}

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	int W, H;
	cin >> W >> H;
	vector<vector<char>> map(H, vector<char>(W));
	vector<vector<bool>> visited(H, vector<bool>(W, false));
	int px, py;
	getchar();
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			map[y][x] = (char) getchar();
			if (map[y][x] == 'P') {
				px = x;
				py = y;
			}
		}
		getchar();
	}
	int G = 0;
	explore(py, px, map, visited, G);
	cout << G << endl;
	return 0;
}
