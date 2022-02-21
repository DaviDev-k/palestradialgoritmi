#include <bits/stdc++.h>

#define MAX_AB 300

using namespace std;

int sum_digits(int n) {
	int sum = 0;
	int mul = 1;
	while (n > 0) {
		if (n % 10 == 0) { mul = -1; }
		sum += n % 10;
		n = n / 10;
	}
	return sum * mul;
}

//vector<int> last_digits(int n, int digits = 4) {
//	vector<int> ret(digits);
//	for (int i = 0; i < digits; i++) {
//		ret[i] = n % 10;
//		n = n / 10;
//	}
//	return ret;
//}

int main() {
	ifstream cin("input.txt");
//	ofstream cout("output.txt");
	
	int A, B;
	long long K;
	
	cin >> A >> B >> K;
	
	vector<int> DP(1000, -1);
	for (int i = 0; i < DP.size(); i++) { DP[i] = sum_digits(i + A); }
	
	int r;  // ultime 3 cifre
	int sum_r, sum_l = 0;  // somma delle ultime 3 cifre e delle restanti
	bool zero_r, zero_l = false;  // il numero attuale contiene zeri
	long long n = 0;
	int count_zero = 0;
	for (long long k = 0; k < K;) {
		r = n % 1000;
		zero_r = (DP[r] < 0) || (n + A >= 1000 && r + A < 100);
		sum_r = abs(DP[r]);
		if (r + A >= 1000) {
			sum_r--;  // sottrai la cifra delle migliaia
			sum_l++;  // sottrai la cifra delle migliaia
			int c, m = n / 1000;
			do {
				c = m % 10;
				m /= 10;
				if (c == 9) {
					count_zero++;
					sum_l -= 9;
				} else if (c == 0) {
					count_zero--;
				}
			} while (c == 9);
			zero_l = (count_zero > 0);
//			int sum = sum_digits(n / 1000);
//			zero_l = (sum < 0);
//			sum_l = abs(sum);
		}
		if (!(zero_l || zero_r) && sum_l + sum_r == B) { k++; }
		n += A;
//		cout << n << "\t" << (zero_l || zero_r) << "\t" << sum_l << " + " << sum_r << " = " << sum_l + sum_r << "\t"
//		     << k << endl;
	}
	
	cout << n << endl;
	
	return 0;
}



/*
void reverse(string &s) {
	reverse(s.begin(), s.end());
}

string operator-(string a, string b) {
	if (b.length() > a.length()) { return ""; }
	vector<int> c(a.length());  // riporto (carry)
	int i = 0;
	string r;
	for (; i < b.length(); i++) {
		if (c[i] + a[i] < b[i]) {
			int j = i;
			do {
				c[j] = 10;
				j++;
				if (j == a.length()) { return ""; }
			} while (a[j] == '0');
			a[j]--;
		}
		r += '0' + (c[i] + a[i] - b[i]);
	}
	for (; i < a.length() && a[i] > '0'; i++) { r += a[i]; }
	for (i = r.length() - 1; i > 0 && r[i] == '0'; i--);
	r.resize(i + 1);
	return r;
}

string operator+(string a, string b) {
	vector<int> c(max(a.length(), b.length()) + 1);  // riporto (carry)
	string r;
	for (int i = 0; i < c.size(); i++) {
		int ai = (i < a.length()) ? a[i] - '0' : 0;
		int bi = (i < b.length()) ? b[i] - '0' : 0;
		r += '0' + (c[i] + ai + bi) % 10;
		c[i + 1] = (c[i] + ai + bi >= 10) ? 1 : 0;
	}
	if (r[r.length() - 1] == '0') { r.resize(r.length() - 1); }
	return r;
}

string operator-(string a, int b) {
	string bs = to_string(b);
	reverse(bs);
	return a - bs;
}

string operator+(string a, int b) {
	string bs = to_string(b);
	reverse(bs);
	return a + bs;
}

int mod(string a, int b) {
	string bs = to_string(b);
	reverse(bs);
	string c;
	while ((c = a - bs) != "") { a = c; }
	return stoi(a);
}

string next_mul(string a, int A, int B) {
	string As = to_string(A);
	reverse(As);
	int sum;
	bool zero;
	do {
		a = a + As;
		sum = 0;
		zero = false;
		for (int i = 0; !zero && i < a.length(); i++) {
			zero = a[i] == '0';
			sum += a[i] - '0';
		}
	} while (sum != B || zero);
	return a;
}

string first_mul(string a, int A, int B) {
	int m = mod(a, A);
	if (m == 0) { return a; }
	string As = to_string(A);
	reverse(As);
	a = a + (A - m);
	int sum;
	bool zero, first = true;
	do {
		if (first) { first = false; }
		else { a = a + As; }
		sum = 0;
		zero = false;
		for (int i = 0; !zero && i < a.length(); i++) {
			zero = a[i] == '0';
			sum += a[i] - '0';
		}
	} while (sum != B || zero);
	return a;
}


int main() {
//	ifstream cin("input.txt");
//	ofstream cout("output.txt");
	
	int A, B;
	long long K;
	string answer;
	
	cin >> A >> B >> K;
	
	string first_sum(B / 9, '9');
	if (B % 9 > 0) { first_sum += '0' + B % 9; }
	
	string mul = first_mul(first_sum, A, B);
	
	for (int i = 1; i < K; i++) {
		mul = next_mul(mul, A, B);
	}
	
	reverse(mul);
	cout << mul << endl; // print the result

//	string a;
//	int b, c;
//	cin >> a >> b;
//	reverse(a);
//	reverse(b);
//	c = mod(a, b);
//	reverse(c);
//	cout << c << endl;

	return 0;
}
*/

/*

  9  3^2
 18  3^2 2
 27  3^3
 36  3^2 2^2
 45  3^2 5
 54  3^3 2
 63  3^2 7
 72  3^2 2^3
 81  3^4
117  3^2 13
126  3^2 2 7
 
 */