#include <bits/stdc++.h>

using namespace std;

// Legge da stdin un intero per riferimento e restituisce il carattere successivo all'ultima cifra
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
	int K;
	char c;
	int parent = 0, child;
	c = scan(K);
	
	unordered_map<int, int> child_parent;  // associa a ogni nodo il suo padre
	set<int> roots;                   // radici di ogni sottoalbero (esclude le foglie)
	
	// Lettura dell'input e popolazione dell'albero
	while (parent != -1) {
		c = scan(parent);                      // primo numero della riga
		if (parent != -1) {
			while (c != '\n') {                // leggi fino a fine riga
				c = scan(child);               // child: figlio di parent; c: blank char
				child_parent[child] = parent;  // aggiungi il nodo figlio al set
			}
		}
	}
	
	int k;
	for (k = K; child_parent.count(k) > 0; k = child_parent[k]) {
		cout << k << " ";
	}
	cout << k;
	
	return 0;
}


