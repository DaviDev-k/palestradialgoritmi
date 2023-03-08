# Capitolo 4: Grafi

### Slides

- [Grafi](http://disi.unitn.it/~montreso/asd/slides/09-grafi.pdf "Montresor")



### Note

Esempio di adiacenza per grafo pesato
```c++
vector<list<pair<int, float>>> adj(n);  // n := numero di nodi

// (u) --w--> (v)
// adj[u].front.first = v;   // nodo
// adj[u].front.second = w;  // peso

// (0) <--3-- (1) --4--> (2)
adj[1] = {{0, 3}, {2, 4}};
```


### Problemi della settimana

1. [police2](https://training.olinfo.it/#/task/ois_police2/statement "oii") - OIS
2. [islands](https://training.olinfo.it/#/task/ois_islands/statement "oii") - OIS
3. [rainstorm](https://training.olinfo.it/#/task/ois_rainstorm/statement "oii") - OIS
4. [money](https://training.olinfo.it/#/task/ois_money/statement "oii") - OIS
5. [airstrike](https://training.olinfo.it/#/task/ois_airstrike/statement "oii") - OIS
6. [police5](https://training.olinfo.it/#/task/ois_police5/statement "oii") - OIS
7. [trip](https://training.olinfo.it/#/task/ois_trip/statement "oii") - OIS

#### Kattis contest
- [Kattis contest](https://open.kattis.com/contests/z4dra4/problems)
- https://open.kattis.com/contests/ng74qc


1. https://open.kattis.com/problems/reachableroads
2. https://open.kattis.com/problems/squarepegs
3. https://open.kattis.com/problems/moneymatters
4. https://open.kattis.com/problems/molekule
5. https://open.kattis.com/problems/pianolessons
6. https://open.kattis.com/problems/programmingtutors

```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> M(R + 1, vector<int>(C + 1, INT_MAX));
    
    int id = 0;
    int count = 0;
    int cell;
    vector<int> merge;
    merge.push_back(0);
    
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> cell;
            if (cell != 0) {
                int prev_r = M[r - 1][c];
                int prev_c = M[r][c - 1];
                int min_prev = prev_r < prev_c ? prev_r : prev_c;
                if (r == 1 || c == 1 || r == R || c == C) {
                    M[r][c] = -1;
                    if (prev_r != INT_MAX) {
                        merge[prev_r] = -1;
                        count--;
                    } else if (prev_c != INT_MAX) {
                        merge[prev_c] = -1;
                        count--;
                    }
                } else {
                    if (min_prev == INT_MAX) {
                        id++;
                        count++;
                        M[r][c] = id;
                        merge.push_back(id);
                    } else {
                        M[r][c] = min_prev != -1 && min_prev != INT_MAX ? merge[min_prev] : min_prev;
                        if (prev_r != min_prev && prev_r != INT_MAX) {
                            merge[prev_r] = min_prev;
                            count--;
                        } else if (prev_c != min_prev && prev_c != INT_MAX) {
                            merge[prev_c] = min_prev;
                            count--;
                        }
                    }
                }
            }
        }
    }
    
    cout << count;
    
    
    return 0;
}
```
