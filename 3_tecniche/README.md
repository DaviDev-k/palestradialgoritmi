# Capitolo 3: tecniche algoritmiche

### Slides

1. [Introduzione](http://disi.unitn.it/~montreso/asd/slides/00-introcorso.pdf "Montresor")
2. [Divide-et-impera](http://disi.unitn.it/~montreso/asd/slides/12-divide.pdf "Montresor")
3. [Programmazione dinamica 1](http://disi.unitn.it/~montreso/asd/slides/13-pd1.pdf "Montresor")
4. [Programmazione dinamica 2](http://disi.unitn.it/~montreso/asd/slides/13-pd2.pdf "Montresor")
5. [Programmazione dinamica 3](http://disi.unitn.it/~montreso/asd/slides/13-pd3.pdf "Montresor")



### Approfondimenti

Merge sort (divide-et-impera)
- [Video esplicativo](https://www.youtube.com/watch?v=JSceec-wEyw)
- [Descrizione dell'algoritmo](https://www.geeksforgeeks.org/merge-sort/)


## Programmazione dinamica
### Domande
1. Qual è la dimensione della tabella?
2. Dove si trova la soluzione del problema?
3. Con quali valori deve essere riempita la tabella?
4. Quali scelte posso fare per ogni sottoproblema?
5. Da quali celle dipende un sottoproblema?
6. \[Come ricostruire la soluzione?\]

### Fasi di risoluzione (non sono in ordine stretto)
1. \[Tradurre il problema in modo che sia trattabile con DP\]
2. Trovare i casi base
3. Definire i sottoproblemi, a partire dai casi base
4. Capire quale "scelta" debba essere fatta per ogni sottoproblema (e.g. prendo o non prendo?)
5. Inferire il problema generale dai sottoproblemi (equazione di ricorrenza)
6. Trovare il valore della soluzione nella tabella DP
7. \[Ricostruire la soluzione\]


### Problemi della settimana

1. [minato](https://training.olinfo.it/#/task/minato/statement "oii") - Classico
2. [discesa](https://training.olinfo.it/#/task/discesa/statement "oii") - OII territoriali 2016
3. [sommelier](https://training.olinfo.it/#/task/sommelier/statement "oii") - OII territoriali 2014
4. [sushi](https://training.olinfo.it/#/task/preoii_sushi/statement "oii") - Pre OII 2020
5. [pickup](https://training.olinfo.it/#/task/ois_pickup/statement "oii") - OIS 2022
6. [marcel](https://training.olinfo.it/#/task/ois_marcel/statement "oii") - OIS 2020

**Kattis**
1. [muzicari](https://open.kattis.com/problems/muzicari "kattis") - Croatian Open Competition 2008
2. [heritage](https://open.kattis.com/problems/heritage "kattis") - IDI Open 2016
3. [narrowartgallery](https://open.kattis.com/problems/narrowartgallery "kattis") - 2014 ICPC North America Qualifier
4. [solitaire](https://open.kattis.com/problems/solitaire "kattis") - GCPC 2013
5. [orders](https://open.kattis.com/problems/orders "kattis") - KTH Challenge 2012
6. [treasurediving](https://open.kattis.com/problems/treasurediving "kattis") - GCPC 2012
7. [rollercoasterfun](https://open.kattis.com/problems/rollercoasterfun "kattis") - GCPC 2012
