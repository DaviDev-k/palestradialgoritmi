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
        int px = find(x), py = find(y);
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

    size_t _;
    int R, C;
    _ = scanf("%d%d", &R, &C);
    
    int M[2][1002];
    for (int i = 0; i < C + 2; i++) { M[0][i] = LAND; }
    M[1][0] = LAND;
    
    MergeFindSet mfs(R * C + 1);
    
    int id = 1;
    int count = 0;
    bool now = 1;
    
    const int MAX_SIZE = 1 << 21;
    char *line = new char[MAX_SIZE];
    _ = fread(line, 1, MAX_SIZE, stdin);
    
    int i = 0;
    for (int r = 1; r < R + 2; r++) {
        for (int c = 1; c < C + 2; c++) {
            
            if (r <= R && c <= C) {
                char cell;
                do {
            	    cell = line[i++];
                } while (cell != '0' && cell != '1');
                
                if (cell == '0') {
                    M[now][c] = WATER;
                    continue;
                }
			}
			
            int prev_r = M[!now][c];
            int prev_c = M[now][c - 1];
            if (prev_r == WATER && prev_c == WATER) {
                M[now][c] = ++id;
                count++;
            } else {
                bool water = prev_r == WATER || prev_c == WATER;
                int prev_id = water ? prev_r + prev_c : prev_c;
                M[now][c] = mfs.find(prev_id);
                if (!water && !mfs.same(prev_r, prev_c)) {
                    mfs.merge(prev_r, prev_c);
                    count--;
                }
            }
        }
        now = !now;
    }
    printf("%d", count);
    return 0;
}
