#include <bits/stdc++.h>

using namespace std;

void scan(int &n);

void scan(string &s);

void print(int n);

void printzero(int n);

void print(string s);

void println(int n);

void println(string s);

int tot;
const string jam = "welcome to code jam";
const int jaml = jam.length();
string line;
int linel;

void rec(int l, int j) {
	if (j == jaml) {
		tot++;
	} else {
		for (; l <= linel - jaml + j; l++) {
			if (line[l] == jam[j]) {
				rec(l + 1, j + 1);
			}
		}
	}
}

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	
	bitset<256> jams;
	for (int i = 0; i < jaml; i++) {
		jams.set(jam[i]);
	}
	
	int T;
	scan(T);
	
	for (int test = 0; test < T; test++) {
		tot = 0;
		scan(line);
		if (line.length() >= jaml) {
			if (line.find('w') != line.npos) {
				line.erase(0, line.find('w'));
				if (line.find('m') != line.npos) {
					while (line.back() != 'm') { line.pop_back(); }
					for (int i = 0; i < line.length(); i++) {
						if (!jams.test(line[i])) {
							line.erase(i--, 1);
						}
					}
				} else {
					line = "";
				}
			} else {
				line = "";
			}
			linel = line.length();
			
			if (linel >= jaml) {
				rec(0, 0);
			}
		}
		
		print("Case #");
		print(test + 1);
		print(": ");
		printzero(tot);
	}
	return 0;
}


void scan(int &n) {
	n = 0;
	bool neg = false;
	char c = getchar();
	while (!(c == '-' || (c >= '0' && c <= '9'))) { c = getchar(); }
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; c >= '0' && c <= '9'; c = getchar()) {
		n = n * 10 + c - '0';
	}
	if (neg) { n *= -1; }
}

void scan(string &s) {
	s = "";
	char c = getchar();
	for (; c != '\n'; c = getchar()) {
		s += c;
	}
}

void print(int n) {
	if (n == 0) {
		putchar('0');
		return;
	}
	if (n < 0) {
		putchar('-');
		n *= -1;
	}
	string s;
	while (n > 0) {
		s += (n % 10) + '0';
		n /= 10;
	}
	for (int i = s.length() - 1; i >= 0; i--) {
		putchar(s[i]);
	}
}

void printzero(int n) {
	if (n == 0) {
		print("0000\n");
		return;
	}
	string s;
	while (n > 0) {
		s += (n % 10) + '0';
		n /= 10;
	}
	for (int i = 0; i < 4 - (int) s.length(); i++) {
		putchar('0');
	}
	for (int i = min(s.length(), 4lu) - 1; i >= 0; i--) {
		putchar(s[i]);
	}
	putchar('\n');
}

void print(string s) {
	for (int i = 0; s[i] != 0; i++) {
		putchar(s[i]);
	}
}

void println(int n) {
	print(n);
	putchar('\n');
}

void println(string s) {
	print(s);
	putchar('\n');
}
