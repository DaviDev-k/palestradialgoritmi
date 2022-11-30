## Discesa

```
           ⎧ +∞                    t < 0
           ⎪ t                     i = 0
DP[i][t] = ⎨ 0                     t = 0
           ⎪ min(DP[i-1][t-d[i]],  altrimenti
           ⎩     DP[i-1][t])
```
