// https://open.kattis.com/problems/trendingtopic

#include <bits/stdc++.h>

using namespace std;

void scan(int &n);

bool scan(string &s);

void scantag(string &s);

void print(int n);

void print(string s);

string order(int n, const string &s) {
	string snum = "", str = "";
	while (n > 0) {
		snum += (n % 10) + '0';
		n /= 10;
	}
	for (int i = 0; i < 8 - snum.length(); i++) {
		str += '0';
	}
	for (int pos = snum.length() - 1; pos >= 0; pos--) {
		str += snum[pos];
	}
	for (char c: s) {
		str += 'z' - c;
	}
	for (int i = str.length(); i < 20; i++) {
		str += 'z';
	}
	return str;
}

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen("input.txt", "r", stdin); }
	
	deque<unordered_map<string, int>> days;
	unordered_map<string, int> week;
	string tag, str;
	int top;
	
	while (!feof(stdin)) {
		scantag(tag);
		if (tag == "text") {
			if (days.size() == 7) {
				for (auto &word: days.front()) {
					week[word.first] -= word.second;
					if (week[word.first] <= 0) {
						week.erase(word.first);
					}
				}
				days.pop_front();
			}
			days.push_back({});
			scan(str);
			if (str[0] == '>') { str.erase(0, 1); }
			bool is_tag = false;
			while (!is_tag) {
				if (str.length() >= 4) {
					days.back()[str]++;
					week[str]++;
				}
				is_tag = scan(str);
				if (is_tag && str.length() >= 4) {
					days.back()[str]++;
					week[str]++;
				}
			}
		} else if (tag == "top") {
			scan(top);
			priority_queue < pair < string, pair < string, int>>> pq;
			for (auto &word: week) {
				pq.push({order(word.second, word.first), {word.first, word.second}});
			}
			print("<top ");
			print(top);
			print(">\n");
			bool go = true;
			int i = 0;
			int min = pq.top().second.second;
			while (!pq.empty() && go) {
				print(pq.top().second.first);
				putchar(' ');
				print(pq.top().second.second);
				putchar('\n');
				i++;
				pq.pop();
				if (i < top) {
					min = pq.top().second.second;
				} else {
					go = (pq.top().second.second >= min);
				}
			}
			print("</top>\n");
		}
		while (!feof(stdin) && getchar() != '<');
	}
	
	return 0;
}


void scan(int &n) {
	n = 0;
	char c = getchar();
	while (c < '0' || c > '9') { c = getchar(); }
	for (; c >= '0' && c <= '9'; c = getchar()) {
		n = n * 10 + c - '0';
	}
}

bool scan(string &s) {
	s = "";
	char c = getchar();
	while (c == ' ' || c == '\n' || c == '\t') { c = getchar(); }
	for (; c != ' ' && c != '\n' && c != '\t' && c != '<'; c = getchar()) {
		s += c;
	}
	return c == '<';
}

void scantag(string &s) {
	s = "";
	char c = getchar();
	while (c == ' ' || c == '\n' || c == '\t') { c = getchar(); }
	if (c == '<') {
		c = getchar();
		while (c == ' ' || c == '\n' || c == '\t') { c = getchar(); }
	}
	for (; c != ' ' && c != '\n' && c != '\t' && c != '>'; c = getchar()) {
		s += c;
	}
}

void print(int n) {
	string snum;
	if (n == 0) { snum = "0"; }
	while (n > 0) {
		snum += (n % 10) + '0';
		n /= 10;
	}
	for (int pos = snum.length() - 1; pos >= 0; pos--) {
		putchar(snum[pos]);
	}
}

void print(string s) {
	for (int i = 0; s[i] != 0; i++) {
		putchar(s[i]);
	}
}
