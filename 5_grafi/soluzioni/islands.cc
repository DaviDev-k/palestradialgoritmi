#include <cstdio>

using namespace std;

enum {
    WATER,
    LAND
};

class MergeFindSet {
public:
    int parent[1000000];

    // Constructor to initialize the merge-find set
    MergeFindSet(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find the representative (root) of the set containing x
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Merge the sets containing x and y
    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            parent[py] = px;
        }
    }

    // Check if x and y belong to the same set
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};


int main() {
    int R, C;
    scanf("%d%d", &R, &C);  // leggi R e C
    
    // la mappa delle isole può essere rappresentata in una matrice di sole due righe,
    // dato che per ogni cella si interrogano solo la cella sopra e quella a sinistra.
    int M[2][1002];
    for (int i = 0; i < C + 2; i++) { M[0][i] = LAND; }
    M[1][0] = LAND;
    
    MergeFindSet mfs(R * C + 1);
    
    int id = 1;     // id dell'isola
    int count = 0;  // conteggio delle isole
    bool now = 1;   // riga attuale della matrice
    
    const int MAX_SIZE = 1 << 21;     // MAX_SIZE = 2 ^ 21
    char *input = new char[MAX_SIZE];  // stringa di MAX_SIZE caratteri
    fread(input, 1, MAX_SIZE, stdin);  // legge tutto l'input
    
    int cursor = 0;  // posizione della lettura dell'input
    for (int r = 1; r < R + 2; r++) {
        for (int c = 1; c < C + 2; c++) {
            
            if (r <= R && c <= C) {  // se non siamo su un bordo
                
                // legge il prossimo carattere '0' o '1' dell'input
                char cell;
                do {
            	    cell = input[cursor++];
                } while (cell != '0' && cell != '1');
                
                // se la cella è acqua, annotalo nella matrice e passa alla successiva
                if (cell == '0') {
                    M[now][c] = WATER;
                    continue;
                }
            }
			
            int prev_r = M[!now][c];     // cella sopra
            int prev_c = M[now][c - 1];  // cella sinistra
            if (prev_r == WATER && prev_c == WATER) {  // se sono entrambe acqua, assegna una nuova isola
                M[now][c] = ++id;
                count++;
            } else {  // altrimenti assegna l'isola corretta
                bool one_is_water = (prev_r == WATER || prev_c == WATER);
                int prev_id = one_is_water ? prev_r + prev_c : prev_c;
                M[now][c] = mfs.find(prev_id);
                if (!one_is_water && !mfs.same(prev_r, prev_c)) {  // se gli id non corrispondono unisci le isole
                    mfs.merge(prev_r, prev_c);
                    count--;
                }
            }
        }
        now = !now;  // aggiorna la riga corrente
    }
    printf("%d", count);
    return 0;
}
