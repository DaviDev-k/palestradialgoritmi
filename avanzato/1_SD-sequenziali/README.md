# Capitolo 1: strutture dati sequenziali

## Problemi della settimana

- [deque](https://www.hackerrank.com/challenges/deque-stl/problem?isFullScreen=true "hackerrank") (`deque`)
- [restaurant](https://open.kattis.com/problems/restaurant "kattis") (pile)
- [sylvester](https://open.kattis.com/problems/sylvester "kattis") (`vector`)
  
  - <u>Sottoproblemi alternativi</u>:
    
    - Stampare le prime 5 matrici Hadamard
    - Stampare le prime 5 matrici Hadamard, senza mai accedere direttamente ai loro elementi tramite `operator[]` [^2?]
    
  - <u>Note implementative</u>:
  
    - Utilizzare il tipo più adatto per le variabili, in modo che possano contenere valori di input molto grandi (2^62)
    - Le potenze di 2 possono essere eseguite in modo veloce ed elegante con il binary left shift
      - `1ull << esp` == 2^esp
      - `1ull` specifica che il valore `1` deve essere trattato come `unsigned long long`
      - il metodo `std::vector.insert(it pos, it first, it last)` può essere utilizzato per appendere un vettore ad un altro vettore
        - e.g. `A.insert(A.begin(), B.begin(), B.end();` inserisce tutti gli elementi di `B` alla fine di `A`
