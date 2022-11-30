## [discesa](https://training.olinfo.it/#/task/discesa/statement "oii")

Si risolve riempiendo il triangolo inferiore della matrice DP a partire dalla base (casi base con i = H) e poi risalendo bottom-up riga per riga.

```
           ⎧ -1                          j < i
DP[i][j] = ⎨ A[i][j]                     i = H
           ⎪ A[i][j] + max(DP[i+1][j],   altrimenti
           ⎩               DP[i+1][j+1]
```


## [sommelier](https://training.olinfo.it/#/task/sommelier/statement "oii")
```
           ⎧ +∞                    t < 0
           ⎪ t                     i = 0
DP[i][t] = ⎨ 0                     t = 0
           ⎪ min(DP[i-1][t-d[i]],  altrimenti
           ⎩     DP[i-1][t])
```

## [minato](https://training.olinfo.it/#/task/minato/statement "oii")
