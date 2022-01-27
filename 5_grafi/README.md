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

1. [...](https://training.olinfo.it/#/task//statement "oii") - Coming soon
