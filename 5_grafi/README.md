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
