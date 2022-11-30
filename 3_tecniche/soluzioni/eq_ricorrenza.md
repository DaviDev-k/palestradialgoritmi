## [minato](https://training.olinfo.it/#/task/minato/statement "oii")
```
           ⎧ 0                         i < 1 ∨ j < 1
DP[i][j] = ⎨ 1                         i = 1 ∧ j = 1
           ⎪ 0                         A[i][j] = '+'
           ⎩ DP[i-1][j] + DP[i][j-1]   A[i][j] = '*'
```
Si risolve riempiendo la matrice DP riga per riga a partire dalla cella `(1,1)`.


## [discesa](https://training.olinfo.it/#/task/discesa/statement "oii")
```
           ⎧ -1                           j < i
DP[i][j] = ⎨ A[i][j]                      i = H
           ⎪ A[i][j] + max(DP[i+1][j],    altrimenti
           ⎩               DP[i+1][j+1]
```
Si risolve riempiendo il triangolo inferiore della matrice DP a partire dalla base (casi base con `i = H`) e poi si risale bottom-up riga per riga.



## [sommelier](https://training.olinfo.it/#/task/sommelier/statement "oii")
```
            ⎧ 0                              i < 1
DP[sn][i] = ⎨ max(DP[SI][i-1], DP[NO][i-1]   sn = NO
            ⎩ i + DP[SI][lastWine(i)]        sn = SI

int lastWine(int i) {
    int x;
    for(x = i - 2; x > 0 || A[x] > A[i]; x--);
    return x;
}
```
Si risolve riempiendo le due righe della tabella DP da sinistra a destra.

La funzione `lastWine(i)` serve a trovare l'ultimo vino che si è potuto bere prima di `i` nel caso in cui si decida di bere `i` (serve a rispettare il vincolo della gradazione alcolica crescente).
