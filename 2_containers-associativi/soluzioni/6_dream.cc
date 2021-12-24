// https://open.kattis.com/problems/dream

#include <vector>
#include <array>
#include <unordered_map>
#include <string>

using namespace std;

void fastscan(int &n) {
	char c;
	n = 0;
	c = getchar();
	for (; c >= '0' && c <= '9'; c = getchar()) {
		n = n * 10 + c - '0';
	}
}

struct Hash {
	size_t operator()(const string &str) const {
		size_t h = 0;
		for (char c : str) {
			h = h * 1717 + c;
		}
		return h;
	}
};

int main(int argc, char **argv) {
	
	int N;
	fastscan(N);
	
	int r, k, E = 0;
	char eds, c;
	string event;
	vector<string> events(N);
	unordered_map<string, int> happened;
	
	for (int i = 0; i < N; i++) {
		eds = getchar();
		getchar();
		switch (eds) {
			case 'E':
				event = "";
				while ((c = getchar()) != '\n') { event += c; }
				happened[event] = E;
				events[E++] = event;
				break;
			case 'D':
				fastscan(r);
				for (; r > 0; r--) { happened.erase(events[--E]); }
				break;
			case 'S':
				fastscan(k);
				int must = -1, mustnt = N;
				bool error = false;
				int j;
				for (j = 0; !error && j < k; j++) {
					bool neg = false;
					c = getchar();
					event = "";
					if (c == '!') { neg = true; }
					else { event += c; }
					while ((c = getchar()) != ' ' && c != '\n') { event += c; }
					unordered_map<string, int>::iterator found = happened.find(event);
					if (neg) {
						if (found != happened.end()) {
							if (found->second > must) {
								mustnt = min(mustnt, found->second);
							} else {
								error = true;
							}
						}
					} else {
						if (found != happened.end()) {
							if (found->second < mustnt) {
								must = max(must, found->second);
							} else {
								error = true;
							}
						} else {
							error = true;
						}
					}
				}
				if (j < k) { while (getchar() != '\n'); }
				if (error) {
					putchar('P');
					putchar('l');
					putchar('o');
					putchar('t');
					putchar(' ');
					putchar('E');
					putchar('r');
					putchar('r');
					putchar('o');
					putchar('r');
				} else if (mustnt == N) {
					putchar('Y');
					putchar('e');
					putchar('s');
				} else {
					int dream = happened.size() - mustnt;
					string str;
					while (dream > 0) {
						str += '0' + (dream % 10);
						dream /= 10;
					}
					for (int i = str.length() - 1; i >= 0; i--) {
						putchar(str[i]);
					}
					putchar(' ');
					putchar('J');
					putchar('u');
					putchar('s');
					putchar('t');
					putchar(' ');
					putchar('A');
					putchar(' ');
					putchar('D');
					putchar('r');
					putchar('e');
					putchar('a');
					putchar('m');
				}
				putchar('\n');
				break;
		}
	}
	
	return 0;
}
