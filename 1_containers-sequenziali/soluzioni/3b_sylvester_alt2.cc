// https://open.kattis.com/problems/sylvester

#include <bits/stdc++.h>

#define EXPLAIN true  // spiegazione grafica


using namespace std;

void print(string s);

const int MAX_LEVEL = 5;


int main(int argc, char **argv) {  // specifica da riga di comando il livello massimo desiderato, MAX_LEVEL altrinenti
	
	int L = MAX_LEVEL;                    // livello massimo
	if (argc > 1) { L = atoi(argv[1]); }  // leggi da riga di comando
	
	/*
	 * H è una matrice a 4 dimensioni i cui indici (H[s][l][y][x]) indicano rispettivamente:
	 *  s) segno della matrice (0 positivo, 1 negativo)
	 *  l) livello della matrice H[s] (l ∈ [0, L])
	 *  y) riga della matrice H[s][l]
	 *  x) colonna della matrice  H[s][l]
	 *
	 * L'obiettivo è quello di non accedere mai direttamente agli elementi di `H` con il quarto operatore `[x]`
	 */
	vector < vector < vector < vector < int > > > > H(2);
	H[0].resize(L + 1);       // crea spazio per L matrici positive
	H[1].resize(L + 1);       // crea spazio per L matrici negative
	H[0][0].push_back({+1});  // matrice positiva di livello 0 (1×1)
	H[1][0].push_back({-1});  // matrice negativa di livello 0 (1×1)
	
	for (int l = 1; l <= L; l++) {  // scorri i livelli
		int d = (1 << (l - 1));     // dimensione della matrice precedente (d = 2^(l - 1))
		H[0][l].resize(2 * d);      // ridimensiona matrice positiva alla dimensione attuale
		H[1][l].resize(2 * d);      // ridimensiona matrice negativa alla dimensione attuale
		
		for (int s1 = 0; s1 < 2; s1++) {  // segno della matrice attuale
			/*
			 * Riempi le 4 partizioni di celle della matrice attuale (positiva/negativa di livello `l`), utilizzando la
			 * costruzione di Sylvester; by e bx possono assumere i valori {0, 1}, le cui 4 combinazioni specificano
			 * quale delle 4 partizioni viene costruita
			 */
			for (int by = 0; by < 2; by++) {          // blocchi di righe (prima e seconda metà della matrice attuale)
				for (int y = 0; y < d; y++) {         // scorri le righe di un blocco
					for (int bx = 0; bx < 2; bx++) {  // blocchi di colonne (prima e seconda metà della matrice attuale)
						
						/*
						 * Per ogni metà di riga di un dato blocco della matrice attuale, inserisci l'intera riga `y`
						 * della matrice precedente, avente segno corrispondente al blocco in analisi:
						 *  · H[1][l - 1][y] se è il blocco in basso a destra (by == 1 && bx == 1)
						 *  · H[0][l - 1][y] altrimenti
						 */
						
						int s0 = s1 ^ (by & bx);  // segno della matrice del livello precedente che deve essere inserita
						/*
						 *   (by & bx) == 1  <-->  by == 1 && bx == 1
						 *   `1` solo per il blocco in basso a destra
						 *
						 *   s1 ^ (by & bx) == { 0   se s1 == (by & bx)
						 *                     { 1   se s1 != (by & bx)
						 *   `s1` inverte il valore di `(by & bx)`
						 */
						
						/* insert() qui è usato per appendere un container alla fine di un altro */
						H[s1][l][y + by * d].insert(         // In che container inserire? Riga `y+by*d` di `H[s1][l]`
								H[s1][l][y + by * d].end(),  // In quale posizione? Alla fine della riga
								H[s0][l - 1][y].begin(),     // Cosa inserire? Riga `y` di `H[s0][l - 1]`, dall'inizio
								H[s0][l - 1][y].end()        // Fino a dove? Fino alla fine di `H[s0][l - 1][y]`
						);

#if EXPLAIN
						for (int r = 0; r < 2 * d; r++) {
							for (auto &h: H[s1][l][r]) { cout << (h == 1 ? " 1 " : "-1 "); }
							for (int c = 0; c < 2 * d - H[s1][l][r].size(); c++) { cout << " · "; }
							if (r == y + by * d) {
								cout << "   H[" << s0 << "][" << l - 1 << "][" << y << "] → "
								     << "H[" << s1 << "][" << l << "][" << r << "]"
								     << "[" << bx * d << "-" << (bx + 1) * d - 1 << "]";
							}
							cout << endl;
						}
						cout << endl;
#endif
					}
				}
			}
		}
	}
	
	putchar('\n');
	for (int l = 0; l <= L; l++) {
		for (int y = 0; y < (1 << l); y++) {
			for (int s = 0; s < 2; s++) {
				for (auto &h: H[s][l][y]) { print(h == 1 ? "██" : "░░"); }
				print("      ");
			}
			putchar('\n');
		}
		putchar('\n');
	}
}


void print(string s) {
	for (int i = 0; s[i] != 0; i++) { putchar(s[i]); }
}


/*

 SPIEGAZIONE GRAFICA
 
 Date le due matrici H[0][1] e H[1][1] di dimensione 2×2, si costruisca la matrice H[0][2] di dimensione 4×4
 
          ╷
  H[0][1] │ H[1][1]
 ─────────┼─────────
    1  1  │  -1 -1
    1 -1  │  -1  1
          ╵
 
 
 Costruzione di H[0][2], effettuata copiando righe intere di H[0/1][1] in H[0][2]
 
  1  1  ·  ·    H[0][1][0] → H[0][2][0][0-1]
  ·  ·  ·  ·
  ·  ·  ·  ·
  ·  ·  ·  ·
  
  1  1  1  1    H[0][1][0] → H[0][2][0][2-3]
  ·  ·  ·  ·
  ·  ·  ·  ·
  ·  ·  ·  ·
  
  1  1  1  1
  1 -1  ·  ·    H[0][1][1] → H[0][2][1][0-1]
  ·  ·  ·  ·
  ·  ·  ·  ·
  
  1  1  1  1
  1 -1  1 -1    H[0][1][1] → H[0][2][1][2-3]
  ·  ·  ·  ·
  ·  ·  ·  ·
  
  1  1  1  1
  1 -1  1 -1
  1  1  ·  ·    H[0][1][0] → H[0][2][2][0-1]
  ·  ·  ·  ·
  
  1  1  1  1
  1 -1  1 -1
  1  1 -1 -1    H[1][1][0] → H[0][2][2][2-3]
  ·  ·  ·  ·
  
  1  1  1  1
  1 -1  1 -1
  1  1 -1 -1
  1 -1  ·  ·    H[0][1][1] → H[0][2][3][0-1]
  
  1  1  1  1
  1 -1  1 -1
  1  1 -1 -1
  1 -1 -1  1    H[1][1][1] → H[0][2][3][2-3]

 */