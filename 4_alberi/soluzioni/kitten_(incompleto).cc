#include <bits/stdc++.h>

using namespace std;

char scan(int &n) {
	n = 0;
	bool neg = false;
	char c = getchar();
	while (!(c == '-' || (c >= '0' && c <= '9'))) { c = getchar(); }
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; !feof(stdin) && c >= '0' && c <= '9'; c = getchar()) {
		n = n * 10 + c - '0';
	}
	if (neg) { n *= -1; }
	return c;
}

int main() {
	unordered_map<int, list<int>> T;
	int K;
	char c;
	int n = 0, m;
	c = scan(K);
	
	unordered_set<int> children;  // ogni nodo che possiede un padre
	set<int> roots;               // radici di ogni sottoalbero (esclude le foglie)
	
	// Lettura dell'input e popolazione dell'albero
	while (n != -1) {
		c = scan(n);                 // n: primo numero della riga
		if (n != -1) {
			roots.insert(n);         // aggiungi il nodo interno al set
			// T[n] = new list();    // inserisce la chiave del nodo
			while (c != '\n') {
				c = scan(m);         // m: figlio di n; c: blank char
				T[n].push_front(m);  // inserisce figlio m
				children.insert(m);  // aggiungi il nodo figlio al set
			}
		}
	}
	
	cout << endl << endl << endl;
	
	// unordered_set perché permette la ricerca delle chiavi in tempo costante
	// set perché permette l'iterazione
	int root = -1;
	for (auto it = roots.begin(); root == -1 && it != roots.end(); it++) {
		if (children.count(*it) == 0) { root = *it; }
	}
	
	cout << root << endl;
	
	return 0;
}


