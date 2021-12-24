// https://open.kattis.com/problems/deduplicatingfiles

#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int lines;
	cin >> lines;
	while (lines != 0) {
		vector <vector<int>> hash(256);
		vector <string> files(lines, "");
		int uni = 0, col = 0;
		getchar();
		for (int i = 0; i < lines; i++) {
			char c, h = 0;
			while ((c = getchar()) != '\n') {
				h ^= c;
				files[i] += c;
			}
			files[i] += '\0';
			bool unique = true;
			for (int j = 0; j < hash[h].size(); j++) {
				if (files[i] == files[hash[h][j]]) {
					unique = false;
				} else {
					col++;
				}
			}
			hash[h].push_back(i);
			if (unique) {
				uni++;
			}
		}
		cout << uni << " " << col << endl;
		cin >> lines;
	}
	return 0;
}


