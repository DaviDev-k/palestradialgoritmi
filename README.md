# Palestra di Algoritmi 2021/22 - Corso avanzato

![Logo OII](https://training.olinfo.it/custom_images/logo.png)

### Links
- Slides
  - [Google Drive](https://drive.google.com/drive/folders/1zmcOQGUHOV4aRfvshf2CeAuu3Rq6FYgl?usp=sharing)
- Allenamenti
  - [Portale OII](https://training.olinfo.it/)
  - [Kattis](https://open.kattis.com/problems)
  - [HackerRank](https://www.hackerrank.com/domains/cpp)
- Materiali
  - [Syllabus OIS](https://drive.google.com/file/d/1OtnM0ZHVpS-A5x0wCB6K685bHZHYfWQQ/view?usp=sharing)
  - [Guida OII Prof. Bugatti](http://www.imparando.net/sito/olimpiadi_di_informatica/guida_sesta_edizione.pdf)
  - [Guida geeksforGeeks](https://www.geeksforgeeks.org/c-plus-plus)
  - [Guida html.it](https://www.html.it/guide/guida-c2/)
  - [Sito Prof. Montresor](http://cricca.disi.unitn.it/montresor/teaching/asd/materiale/)

### Introduzione

Il Dipartimento di [Ingegneria e Scienze dell’Informazione (DISI)](https://www.disi.unitn.it/) dell'Università degli
Studi di Trento propone un percorso di allenamento per le Olimpiadi di Informatica per l’a.s. 2021-2022.

Questo percorso di allenamento ha molteplici obiettivi:

* far conoscere agli studenti lo studio degli algoritmi come uno degli argomenti fondamentali dell’informatica;
* allargare la platea degli studenti che partecipano alle gare delle Olimpiadi dell’Informatica (singole e di gruppo);
* dare agli studenti eccellenti una marcia in più nella risoluzione dei problemi, fornendo un più ampio insiemi di
  nozioni di base nel campo delle strutture dati e dell’algoritmica.

### Allenamenti

Questa repository sarà il contenitore di tutte le attività che verranno proposte dai vari tutor, ad ogni incontro
troverete link ad esercizi da svolgere (fonte: correttore delle olimpiadi), codice delle soluzioni, spiegazione delle
soluzioni e alcune note teoriche o di programmazione.

### Utility

```c++
// funzione per leggere da input una stringa compresa fra due caratteri di spaziatura
// aggiorna la stringa passata per riferimento e restituisce l'ultimo carattere letto

char scan(string &s) {
	s = "";
	char c = getchar();
	while (c == ' ' || c == '\n' || c == '\t') { c = getchar(); }
	for (; c != ' ' && c != '\n' && c != '\t'; c = getchar()) {
		s += c;
	}
	s += '\0';
	return c;
}
```

### Contatti
Davide Vecchi
- Mail: [davide.vecchi@studenti.unitn.it](mailto:davide.vecchi@studenti.unitn.it)
- Telegram: [davide2e3](https://t.me/davide2e3)
- GitHub: [davidevecchi](https://github.com/davidevecchi)
