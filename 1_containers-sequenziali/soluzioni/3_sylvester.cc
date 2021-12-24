// https://open.kattis.com/problems/sylvester

#include <bits/stdc++.h>

#define EXPLAIN true  // spiegazione grafica, da mettere false se si vuole sottoporre questa soluzione

using namespace std;


void scan(unsigned long long &n);

void print(string s);

void print(int n);

int main(int argc, char **argv) {
	if (argc > 1) { (void) !freopen(argv[1], "r", stdin); }  // usage: a.out <input_file>
	
	unsigned long long test;
	scan(test);
	
	for (int i = 0; i < test; i++) {
		
		unsigned long long n, x, y, w, h;
		scan(n);  // dimensione matrice completa finale
		scan(x);  // inizio sottomatrice
		scan(y);  // inizio sottomatrice
		scan(w);  // dimensione sottomatrice
		scan(h);  // dimensione sottomatrice
		
		unsigned long long level = 0;       // livello dell'iterazione (2^level == dimensione matrice)
		unsigned long long x1 = 0, y1 = 0;  // vertice "iniziale" della sottomatrice nella vecchia matrice
		unsigned long long x2 = 0, y2 = 0;  // vertice "finale" della sottomatrice nella vecchia matrice
		unsigned long long w1, h1;          // dimensioni della matrice attuale
		unsigned long long wn = n, hn = n;  // dimensioni effettive della matrice finale progressivamente ritagliata
		
		
		/*
		 * La matrice tridimensionale `H` memorizza due matrici di dimensione diversa che rappresentano le matrici
		 * di Hadamard del livello attuale (H[now]) e del livello precedente (H[!now]). Ciò permette di risparmiare
		 * memoria dato che non è necessario mantenere informazioni sulle matrici precedenti.
		 * La variabile booleana `now` alterna valori 0 e 1 ad ogni iterazione, permettendo dunque di ciclare fra di
		 * essi con l'operatore `!` (not).
		 */
		bool now = 0;
		vector < vector < vector < int > > > H(2);  // [now, y, x]
		H[now] = {{1}};  // matrice di Hadamard di dimensione 1
		
		/*
		 * L'idea dell'algoritmo è quella di partire dalla matrice di dimensione 1×1 e progressivamente "fare zoom"
		 * (decrease and conquer) ed espandere le celle che nel livello successivo conterranno la porzione ricercata.
		 * Ad ogni iterazione verrà dunque sviluppata soltanto la porzione di matrice desiderata e ignorato il resto.
		 * Ciò permette di ridurre notevolmente lo spazio di ricerca, che in questo problema deve essere limitato per
		 * questioni di spazio di memorizzazione, piuttosto che di tempo di esecuzione.
		 */
		do {
			level++;                                 // incrementa il livello
			now = !now;                              // inverti la variabile now
			h1 = 2 * (y2 - y1 + 1);                  // altezza della nuova matrice
			w1 = 2 * (x2 - x1 + 1);                  // larghezza della nuova matrice
			H[now].resize(h1);                       // ridimensiona la matrice (height = h1)
			for (auto &v: H[now]) { v.resize(w1); }  // ridimensiona la matrice (width = w1)
			
			/*
			 * Riempi la matrice attuale, che ha dimensione doppia rispetto alla precedente H[!now], in modo che ogni
			 * cella H[!now][y][x] venga "espansa" in una matrice di Hadamard di dimensione 2×2, moltiplicata per il
			 * valore (segno) di H[!now][y][x].
			 */
			for (int r = 0; r < h1; r += 2) {                 // itera sulle righe della matrice attuale
				for (int c = 0; c < w1; c += 2) {             // itera sulle colonne della matrice attuale
					int s = H[!now][y1 + r / 2][x1 + c / 2];  // segno della cella da "espandere"
					H[now][r + 0][c + 0] = +1 * s;
					H[now][r + 0][c + 1] = +1 * s;            // costruisci la nuova matrice di dimensione 2×2
					H[now][r + 1][c + 0] = +1 * s;
					H[now][r + 1][c + 1] = -1 * s;
				}
			}
			
			y1 = (y * h1) / hn;                 // posizione iniziale della sottomatrice da cercare nella vecchia
			x1 = (x * w1) / wn;
			y2 = ((y + h - 1) * h1) / hn;       // posizione finale della sottomatrice da cercare nella vecchia
			x2 = ((x + w - 1) * w1) / wn;
			y -= (y1 * hn) / h1;                // ritaglia la porzione della matrice finale che non verrà considerata
			x -= (x1 * wn) / w1;
			hn *= (double) (y2 - y1 + 1) / h1;  // dimensione della matrice finale progressivamente ritagliata
			wn *= (double) (x2 - x1 + 1) / w1;

#if EXPLAIN
			{
				for (int r = 0; r < h1 + (y2 + 1 == h1); r++) {
					if (r >= y1 && r <= y2 + 1) {
						int c = 0;
						for (; c < x1; c++) { print("    "); }
						if (r == y1) {
							print(" ┌──");
						} else if (r == y2 + 1) {
							print(" └──");
						} else {
							print(" │  ");
						}
						for (; c < x2; c++) { print((r == y1 || r == y2 + 1) ? "────" : "    "); }
						if (r == y1) {
							print("─┐");
						} else if (r == y2 + 1) {
							print("─┘");
						} else {
							print(" │");
						}
					}
					if (r < h1) {
						putchar('\n');
						for (int c = 0; c < w1 + (x2 + 1 == w1); c++) {
							if ((c == x1 || c == x2 + 1) && (r >= y1 && r <= y2)) {
								print(" │ ");
							} else {
								print("   ");
							}
							if (c < w1) { print(H[now][r][c] == 1 ? "█" : "░"); }
						}
						putchar('\n');
					}
				}
				print("\n\n");
			}
#endif
		
		} while ((1ull << level) < n);
		/* Ripeti finché non si raggiunge la dimensione richiesta ((dimensione = 2^level) < n) */
		
		/* Stampa la sottomatrice con vertice in (x1, y1) e dimensione (w, h) */
		for (int r = y1; r < y1 + h; r++) {
			putchar(' ');
			for (int c = x1; c < x1 + w; c++) { print(H[now][r][c] == 1 ? " 1 " : "-1 "); }
			putchar('\n');
		}
		print("\n\n");
		
	}
	
	return 0;
}


/*
 * NOTE:
 *
 * - L'utilizzo di variabili booleane che ciclano fra valori 0 e 1 con l'operatore `!` è molto più pratico rispetto
 *   all'utilizzo di variabili intere con l'operatore `%`
 *
 * - Nelle divisioni fra interi bisogna ricordarsi di fare casting ad un tipo floating point (righe 81 e 82)
 *
 */

/*

 Dato l'input `1 16 3 3 6 4`, l'algoritmo effettua le seguenti espansioni progressive.
 Si noti che la matrice di ogni livello (intera, non riquadrata) ha dimensioni doppie della precedente riquadrata.
 
 ┌───────┐
 │ █   █ │
 └───────┘
   █   ░


 ┌───────────┐
 │ █   █   █ │ █
 │           │
 │ █   ░   █ │ ░
 └───────────┘


   █   █   █   █   █   █
     ┌───────────────┐
   █ │ ░   █   ░   █ │ ░
     │               │
   █ │ █   ░   ░   █ │ █
     │               │
   █ │ ░   ░   █   █ │ ░
     └───────────────┘


   ░   ░   █   █   ░   ░   █   █
     ┌───────────────────────┐
   ░ │ █   █   ░   ░   █   █ │ ░
     │                       │
   █ │ █   ░   ░   ░   ░   █ │ █
     │                       │
   █ │ ░   ░   █   ░   █   █ │ ░
     │                       │
   ░ │ ░   ░   ░   █   █   █ │ █
     └───────────────────────┘
   ░   █   ░   █   █   ░   █   ░


  1  1 -1 -1  1  1
  1 -1 -1 -1 -1  1
 -1 -1  1 -1  1  1
 -1 -1 -1  1  1  1

*/






void scan(unsigned long long &n) {
	n = 0;
	bool neg = false;
	char c = getchar();
	while (!(c == '-' || (c >= '0' && c <= '9'))) { c = getchar(); }
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; c >= '0' && c <= '9'; c = getchar()) {
		n = n * 10 + (unsigned long long) (c - '0');
	}
	if (neg) { n *= -1; }
}

void print(string s) {
	for (int i = 0; s[i] != 0; i++) { putchar(s[i]); }
}

void print(int n) {
	if (n == 0) {
		putchar('0');
		return;
	}
	if (n < 0) {
		putchar('-');
		n *= -1;
	}
	string s;
	while (n > 0) {
		s += (n % 10) + '0';
		n /= 10;
	}
	for (int i = s.length() - 1; i >= 0; i--) {
		putchar(s[i]);
	}
}

//   1  1  1  1  1  1  1  1
//   1 -1  1 -1  1 -1  1 -1
//   1  1 -1 -1  1  1 -1 -1
//   1 -1 -1  1  1 -1 -1  1
//   1  1  1  1 -1 -1 -1 -1
//   1 -1  1 -1 -1  1 -1  1
//   1  1 -1 -1 -1 -1  1  1
//   1 -1 -1  1 -1  1  1 -1