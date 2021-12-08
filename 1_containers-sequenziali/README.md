# Capitolo 1: [containers sequenziali](https://docs.google.com/presentation/d/1rLoEcHL2Za4xDP3VjZ7F9eZ1TYg0vjgwFEV6lehK-IQ/edit?usp=sharing)


## Problemi della settimana

1. [deque](https://www.hackerrank.com/challenges/deque-stl/problem?isFullScreen=true "hackerrank") - HackerRank (`deque`)
2. [restaurant](https://open.kattis.com/problems/restaurant "kattis") - SWERK 2009 (pile)
3. [sylvester](https://open.kattis.com/problems/sylvester "kattis") - Norwegian/Swedish Championships 2004 (`vector` multidimensionali)
  
   - **Sottoproblemi alternativi**
    
     - Stampare le prime 5 matrici Hadamard
     - Stampare le prime 5 matrici Hadamard, senza mai accedere direttamente ai loro elementi tramite `operator[]`
    
   - **Note implementative** (**_SPOILER!_**)
  
     > - Utilizzare il tipo più adatto per le variabili, in modo che possano contenere valori di input molto grandi (2^62)
     > - Le potenze di 2 possono essere eseguite in modo veloce ed elegante con il binary left shift
     >   - `1ull << esp` == 2^esp
     >   - `1ull` specifica che il valore `1` deve essere trattato come `unsigned long long`
     > - Il metodo `std::vector.insert(it pos, it first, it last)` può essere utilizzato per appendere un vettore ad un altro vettore
     >   - e.g. `A.insert(A.begin(), B.begin(), B.end();` inserisce tutti gli elementi di `B` alla fine di `A`
     > - Parole chiave: ricerca binaria, bisezione



## Bonus

Hai risolto tutti i problemi della settimana e fremi dalla voglia di farne altri?

Ce ne sono centinaia che ti aspettano! Invia una mail e ti saranno suggeriti quelli più adatti :)



## Soluzioni

Le soluzioni saranno presentate durante il prossimo incontro e caricate in questa cartella.
