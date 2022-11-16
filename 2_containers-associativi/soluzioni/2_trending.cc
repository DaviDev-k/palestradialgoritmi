// https://training.olinfo.it/#/task/ois_trending/statement

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }
	
	int N, T;  // input data (N > T)
	cin >> N;  // numero di topic
	cin >> T;  // finestra di tempo
	
	string new_topic, old_topic;  // nomi dei topic
	
	deque<string> q;                              // coda dei trending topics degli ultimi T secondi
	unordered_map<string, int> counter;           // contatore delle occorrenze di ogni topic presente nella coda
	map<int, set<string>, greater<int>> buckets;  // associa il set di topic con lo stesso conteggio al conteggio stesso
	
	// buckets[count] = {t | counter[t] == count}  (tutti i topics con conteggio uguale a `count`)
	// buckets mantiene gli interi in ordine decrescente e le stringhe in ordine crescente
	
	// Inserisci i primi T topics
	for (int i = 0; i < T; i++) {
		cin >> new_topic;
		counter[new_topic]++;    // incrementa il conteggio per il topic `new_topic`, inseriscilo se non presente
		q.push_back(new_topic);  // aggiungi `new_topic` nella coda temporale
	}
	for (auto &t: q) { buckets[counter[t]].insert(t); }  // aggiungi `t` al bucket con chiave il conteggio di `t`
	
	for (int i = T; i <= N; i++) {  // fai avanzare la finestra per ognuno dei rimanenti N - T topics
		
		// map e set ordinati: dei topic con la maggiore occorrenza, stampane il "minore" (ordine alfabetico)
		cout << *(buckets.begin()->second.begin()) << endl;  // prima stringa del primo set
		
		// Rimuovi topic vecchio
		old_topic = q.front();                              // topic più vecchio
		buckets[counter[old_topic]].erase(old_topic);       // rimuovi `t` dal bucket del suo conteggio
		if (buckets[counter[old_topic]].empty()) {
			buckets.erase(counter[old_topic]);              // ripulisci il bucket se vuoto
		}
		counter[old_topic]--;                               // decrementa il conteggio di `t`
		if (counter[old_topic] > 0) {
			buckets[counter[old_topic]].insert(old_topic);  // sposta `old_topic` nel bucket del suo conteggio, se ancora presente nella coda
		} else {
			counter.erase(t);                               // rimuovi `t` da counter se non più nella coda
		}
		
		// Aggiungi topic nuovo
		cin >> new_topic;
		if (counter[new_topic] > 0) {  // se `new_topic` era già presente nella coda, rimuovilo dal bucket del suo conteggio
			buckets[counter[new_topic]].erase(new_topic);
			if (buckets[counter[new_topic]].empty()) { buckets.erase(counter[new_topic]); }
		}
		counter[new_topic]++;                           // incrementa il conteggio di `new_topic`
		buckets[counter[new_topic]].insert(new_topic);  // inserisci `new_topic` nel bucket del suo nuovo conteggio
		q.push_back(new_topic);                         // inserisci `new_topic` in coda a `q`
		q.pop_front();                                  // rimuovi il topic più vecchio dalla coda
	}
}


/*
 * NOTE:
 *
 * - In questo problema, a differenza di 1_trap.cc, viene utilizzata una mappa per contare le occorrenze, poiché un
 *   multiset non permetterebbe la rimozione di una singola chiave, ma le eliminerebbe tutte
 *
 * - `begin()` è un iterator, ovvero un puntatore ad un dato dello stesso tipo dei valori contenuti nella collection a
 *   cui si riferisce; essendo un puntatore, per accedere al valore puntato bisogna dereferenziarlo con l'operatore `*`;
 *   similmente l'operatore `->` serve per accedere al campo di un puntotore, che altrimenti andrebbe dereferenziato:
 *   pointer->field == *(pointer).field (riga 43)
 *
 * - `q` è memorizzato come deque invece che come queue per permetterne l'iterazione
 *
 */
