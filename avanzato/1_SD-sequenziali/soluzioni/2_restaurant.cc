// https://open.kattis.com/problems/restaurant

#include <bits/stdc++.h>

using namespace std;


void scan(int &n);

void scan(string &s);

void print(int n);

void print(string s);

void println(int n);

void println(string s);


int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen("input.txt", "r", stdin); }  // reindirizza lo standard input da file
	
	int N;
	scan(N);
	
	while (N != 0) {
		
		char ord;
		int qnt;
		int S1 = 0, S2 = 0;
		
		for (int i = 0; i < N; i++) {
			ord = getchar();
			scan(qnt);
			if (ord == 'D') {
				print("DROP 1 ");
				println(qnt);
				S1 += qnt;
			} else {
				while (qnt > 0) {
					if (S2 == 0) {
						print("MOVE 1->2 ");
						println(S1);
						S2 = S1;
						S1 = 0;
					}
					print("TAKE 2 ");
					if (qnt < S2) {
						println(qnt);
						S2 -= qnt;
						qnt = 0;
					} else {
						println(S2);
						qnt -= S2;
						S2 = 0;
					}
				}
			}
		}
		putchar('\n');
		scan(N);
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
