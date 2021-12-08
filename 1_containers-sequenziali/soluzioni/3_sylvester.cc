// https://open.kattis.com/problems/sylvester

#include <bits/stdc++.h>

using namespace std;


void scan(unsigned long long &n);

void print(int n);


int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }  // usage: a.out <input_file>
	
	unsigned long long N;
	scan(N);
	
	for (int i = 0; i < N; i++) {
		
		unsigned long long n, x, y, w, h;
		scan(n);
		scan(x);
		scan(y);
		scan(w);
		scan(h);
		
		vector < vector < vector < int > > > H1(2);  // n, y, x
		H1[0] = {{1}};
		
		unsigned long long it = 0;
		unsigned long long x1 = 0, y1 = 0, x2, y2, w1 = 2, h1 = 2;
		unsigned long long nx = n, ny = n;
		bool now = 0;
		
		do {
			it++;
			now = !now;
			H1[now].clear();
			H1[now].resize(h1);
			for (auto &v: H1[now]) { v.resize(w1); }
			for (int r = 0; r < h1; r += 2) {
				for (int c = 0; c < w1; c += 2) {
					int s = H1[!now][y1 + r / 2][x1 + c / 2];
					H1[now][r + 0][c + 0] = 1 * s;
					H1[now][r + 0][c + 1] = 1 * s;
					H1[now][r + 1][c + 0] = 1 * s;
					H1[now][r + 1][c + 1] = -1 * s;
				}
			}
			y1 = (y * h1) / ny;
			x1 = (x * w1) / nx;
			y2 = ((y + h - 1) * h1) / ny;
			x2 = ((x + w - 1) * w1) / nx;
			y -= y1 * (ny / h1);
			x -= x1 * (nx / w1);
			ny *= (double) (y2 - y1 + 1) / (double) h1;
			nx *= (double) (x2 - x1 + 1) / (double) w1;
			h1 = 2 * (y2 - y1 + 1);
			w1 = 2 * (x2 - x1 + 1);
		} while ((1ull << it) < n);
		
		for (int r = y1; r < y1 + h; r++) {
			for (int c = x1; c < x1 + w; c++) {
				print(H1[now][r][c]);
				putchar(' ');
			}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}


void scan(unsigned long long &n) {
	n = 0;
	bool neg = false;
	char c = getchar();
	while (!(c == '-' || (c >= '0' && c <= '9'))) { c = getchar(); }
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; c >= '0' && c <= '9'; c = getchar()) {
		n = n * 10 + (unsigned long long) (c - '0');
	}
	if (neg) { n *= -1; }
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
