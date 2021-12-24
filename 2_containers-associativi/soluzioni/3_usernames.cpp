// https://training.olinfo.it/#/task/ois_usernames/statement

#include <bits/stdc++.h>

using namespace std;

/* Funzione che mappa un carattere nel range [0-36) */
int char_to_int(char c) {
	if (c >= 'a' && c <= 'z') { return c - 'a'; }  // lettera: indice alfabetico
	return (c - '0' + ('z' - 'a' + 1));   // cifra: numero stesso convertito in intero e sommato all'indice di 'z'
}

int main() {
	ifstream fin("input.txt", ios::in);
	ofstream fout("output.txt", ios::out);
	
	int N;
	fin >> N;
	vector <string> U(N);
	for (int i = 0; i < N; i++) { fin >> U[i]; }
	
	/* Per ogni username genera il bitset dei suoi caratteri */
	vector <bitset<('z' - 'a') + ('9' - '0') + 2>> bs(N);  // bitset di dimensione 36 (26 lettere + 10 cifre)
	for (int i = 0; i < N; i++) {
		for (auto c: U[i]) {            // scorri i caratteri della stringa `U[i]`
			bs[i].set(char_to_int(c));  // "inserisci" `c` nel bitset del relativo username
		}
	}
	
	/* Confronta ogni coppia di username e incrementa il contatore se uno è sottoinsieme dell'altro */
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i != j) && ((bs[i] & bs[j]) == bs[i])) { count++; }  // incrementa `count` se `bs[i]` ⊆ `bs[j]`
			/*
			 * (i != j)                    evita di confrontare un username con se stesso
			 *
			 * ((bs[i] & bs[j]) == bs[i])  fa bitwise-and dei due set per ottenere l'intersezione
			 *                             e poi la confronta con il primo set (Si ⊆ Sj ⟺ (Si = Si ∩ Sj))
			 */
		}
	}
	
	fout << count;
	
	fin.close();
	fout.close();
	return 0;
}

/*
 * NOTE
 *
 * - Per scorrere i caratteri di una stringa è molto pratica la sintassi `for (auto c: str)` (riga 25)
 *
 * - L'utilizzo del bitset in questo caso è estremamente efficace per calcolare l'intersezione in modo efficiente
 *
 */