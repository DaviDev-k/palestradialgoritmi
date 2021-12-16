#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	
	int N;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> N;
	
	const string P[3] = {"", "[O]", "[OOOO]"};  // tipi di piastrelle
	int count1 = N;                             // contatore di valori 1 nel vettore v
	vector<int> v(N, 1);                        /* vettore di valori 1 e 2;
                                                 * una coppia di valori 2 adiacenti forma una piastrella da 2 */
	
	for (int i = 0; i < N; i++) { fout << P[v[i]]; }  // stampa la prima combinazione: tutte p. da 1
	fout << endl;
	while (((N % 2 == 0) && (count1 > 0)) ||                   // se N pari, termina quando sono tutte p. da 2
	       ((N % 2 == 1) && (count1 > 1 || v.back() != 1))) {  /* se N dispari, termina quando c'è una sola p.
															    * da 1 in ultima posizione */
		bool go = true;                                // false quando si effettua un cambiamento in una combinazione
		for (int i = N - 1; go && i > 0; i -= v[i]) {  // procedi a ritroso, avanza di 2 passi se la p. è da 2
			if (v[i] == 1 && v[i - 1] == 1) {          // se p. attuale e p. a sx sono da 1, cambiale in una da 2
				v[i] = v[i - 1] = 2;
				count1 -= 2;
				go = false;
			} else if (v[i] == 2 && v[i - 2] == 1) {   // se p. attuale è 2 e p. a sx è 1, invertile
				v[i] = 1;
				v[i - 2] = 2;
				for (i++; i < N; i++) {                // rendi 1 tutte le piastrelle a dx
					if (v[i] == 2) {
						v[i] = 1;
						count1++;
					}
				}
				go = false;
			}
		}
		for (int i = 0; i < N; i += v[i]) { fout << P[v[i]]; }  // stampa la combinazione attuale
		fout << endl;
	}
	fin.close();
	fout.close();
	return 0;
}

