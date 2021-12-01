# Capitolo 1: strutture dati sequenziali

## Problemi della settimana

- [deque](https://www.hackerrank.com/challenges/deque-stl/problem?isFullScreen=true "hackerrank")
- [restaurant](https://open.kattis.com/problems/restaurant "kattis")
- [sylvester](https://open.kattis.com/problems/sylvester "kattis")
  
  - <u>Problemi alternativi</u>:
    
    - Stampare le prime 5 matrici Hadamard
    - Stampare le prime 5 matrici Hadamard, senza mai accedere direttamente ai loro elementi tramite `operator[]` ​[^:bulb:1]
    
  - <u>Note implementative</u>:
  
    - Utilizzare il tipo più adatto per le variabili, in modo che possano contenere valori di input molto grandi ($2^{62}$)
    - Le potenze di $2$ possono essere eseguite in modo veloce ed elegante con il binary left shift
      - `1ull << esp` $\equiv 2^{\rm esp}$
      - `1ull` specifica che il valore `1` deve essere trattato come `unsigned long long`


[^:bulb:1]:er ew w
