#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	unordered_set<string> S;
	string s, sl;
	do {
		char c = getchar();
		if (c != ' ' && c != '\n' && !feof(stdin)) {
			s += c;
			sl += (c <= 'Z') ? c - 'A' + 'a' : c;
		} else {
			if (S.count(sl) > 0) {
				putchar('.');
			} else {
				S.insert(sl);
				for (char ch: s) { putchar(ch); }
			}
			putchar(' ');
			s.clear();
			sl.clear();
		}
	} while (!feof(stdin));
	return 0;
}
