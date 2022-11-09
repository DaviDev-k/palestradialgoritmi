// https://training.olinfo.it/#/task/itoi_trap/statement

#include <bits/stdc++.h>

using namespace std;

// input data
int N, L;

int main() {
	cin >> N >> L;
	vector<string> first_song_vec;       // vettore di parole della prima canzone, necessario per manterle in ordine
	unordered_set<string> first_song;    // set delle parole della prima canzone, utile per verificarne la presenza
	unordered_set<string> other_song;    // parole di ogni altra canzone che appaiono anche nella prima (other_song ⊆ first_song)
	unordered_multiset<string> counter;  // contatore del numero di altre canzoni in cui appare ogni parola della prima
	
	for (int i = 0; i < N; i++) {
		int M;
		cin >> M;
		other_song.clear();  // ripulisci le parole della nuova canzone
		for (int j = 0; j < M; j++) {
			string s;
			cin >> s;
			if (i == 0) {  // se è la prima canzone, memorizza le sue parole
				first_song_vec.push_back(s);
				first_song.insert(s);
			} else {
				// Se la parola letta è presente nella prima canzone e non è ancora stata incontrata nella
				// canzone attuale, allora "incrementa" il contatore delle canzoni per tale parola
				if (first_song.count(s) > 0 && other_song.count(s) == 0) {
					other_song.insert(s);  // evita che la stessa parola venga contata più volte
					counter.insert(s);     // "incrementa" il contatore
				}
			}
		}
	}
	
	// Stampa il contatore nell'ordine della prima canzone
	for (auto &s: first_song_vec) { cout << counter.count(s) << " "; }
	
	return 0;
}


/*
 * NOTE:
 *
 * - Se non è richiesto di mantenere le stringhe in ordine alfabetico è quasi sempre conveniente l'utilizzo di
 *   contenitori unordered
 *
 * - counter è memorizzato come un unordered_multiset<string>, ma potrebbe essere sostituito da una
 *   unordered_map<string, int>, dove counter[word] viene incrementato manualmente all'occorrenza (vedi 2_trending.cc)
 *
 */
