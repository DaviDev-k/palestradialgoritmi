#include <bits/stdc++.h>

using namespace std;


int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }  // usage: a.out <input_file>
	
	int N, S, R;
	bitset<12> damaged;   // 12 perché le squadre sono numerate da 1 a 10;
	bitset<12> reserves;  // 0 e 11 servono da cornice per evitare out-of-bound.
	
	cin >> N >> S >> R;
	
	// memorizza le squadre il cui kayak è danneggiato
	for (int i = 1; i <= S; i++) {
		int s;
		cin >> s;
		damaged.set(s);
	}
	
	// memorizza le squadre che possono prestare un kayak
	for (int i = 1; i <= R; i++) {
		int r;
		cin >> r;
		
		// se il kayak è danneggiato e hanno la riserva, allora non hanno bisogno
		// di farsi prestare un kayak, ma non possono nemmeno prestarlo ad altri
		damaged.test(r) ? damaged.reset(r) : reserves.set(r);
	}
	
	// le squadre che hanno kayak in avanzo provano a prestarlo alla squadra precedente;
	// se non gli serve lo "prestano" alla successiva.
	for (int i = 1; i <= N; i++) {
		if (reserves.test(i)) {
			damaged.test(i - 1) ? damaged.reset(i - 1) : damaged.reset(i + 1);
		}
	}
	
	// stampa il numero di squadre i cui kayak danneggiati non sono stati sostituiti
	cout << damaged.count() << endl;
	
	return 0;
}
