#include <bits/stdc++.h>

using namespace std;

void scan(int &n);

void scan(string &s);

void print(int n);

void print(string s);

void println(int n);

void println(string s);


int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }  // usage: a.out <input_file>
	
	int N, S, R;
	bitset<12> Ss;
	bitset<12> Rs;
	scan(N);
	scan(S);
	scan(R);
	for (int i = 1; i <= S; i++) {
		int s;
		scan(s);
		Ss.set(s);
	}
	for (int i = 1; i <= R; i++) {
		int r;
		scan(r);
		if (Ss.test(r)) { Ss.reset(r); }
		else { Rs.set(r); }
	}
	for (int i = 1; i <= N; i++) {
		if (Rs.test(i)) {
			if (i - 1 >= 1 && Ss.test(i - 1)) {
				Ss.reset(i - 1);
			} else if (i + 1 <= N && Ss.test(i + 1)) {
				Ss.reset(i + 1);
			}
		}
	}
	println(Ss.count());
	
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
	while (c == ' ' || c == '\n' || c == '\t') { c = getchar(); }
	for (; c != ' ' && c != '\n' && c != '\t'; c = getchar()) {
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
