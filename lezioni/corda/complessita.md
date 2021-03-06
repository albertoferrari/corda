title: Progetto Corda
subtitle: Alberto Ferrari
figure: images/corda/corda.jpg

---
title: Complessità degli algoritmi (cenni) 
class: segue dark

---
title: Testo di riferimento 

> Dispense del Corso di  Algoritmi e Strutture Dati
Marco Bernardo - Edoardo Bontà
Università degli Studi di Urbino “Carlo Bo”
Facoltà di Scienze e Tecnologie
Corso di Laurea in Informatica Applicata
 
---

title: Algoritmi
figure: images/corda/al_k.png

- Matematico persiano Muhammad al-Khwarizmi (IX secolo)
- Un algoritmo è una *sequenza finita di passi* interpretabili da un esecutore
- L’esecuzione di un algoritmo potrebbe richiedere un *tempo non necessariamente finito*
- Un algoritmo *non* deve necessariamente essere espresso in un *linguaggio di programmazione*
- L’algoritmo si trova ad un livello di astrazione più alto rispetto ad ogni programma che lo implementa
 
---

title: Problema delle 12 monete
figure: images/corda/bilancia.png

- Abbiamo 12 monete che sembrano identiche ma non lo sono. Una di esse ha un peso diverso dalle altre ma non sappiamo qual è e neppure se è più pesante o più leggera delle altre.
- Dobbiamo scoprire qual è la moneta di peso diverso, con 3 pesate comparative utilizzando una bilancia a due piatti.
 
---

title: Algoritmo delle 12 monete
class: large-image

![](images/corda/12_monete.png)

---

title: Classificazione degli algoritmi

- Algoritmi *sequenziali*: eseguono un solo passo alla volta
- Algoritmi paralleli: possono eseguire più passi per volta
<hr>
- Algoritmi *deterministici*: ad ogni punto di scelta, intraprendono una sola via determinata dalla valutazione di un’espressione
- Algoritmi probabilistici: ad ogni punto di scelta, intraprendono una sola via determinata a caso
- Algoritmi non deterministici: ad ogni punto di scelta, esplorano tutte le vie contemporaneamente
 
---

title: Problemi e algoritmi
figure: images/corda/cerca.png

- Dato un problema, possono esistere più algoritmi che sono *corretti* rispetto ad esso
- … e un numero illimitato di algoritmi errati :(
<hr>
- Gli algoritmi corretti  possono essere confrontati rispetto alla loro *complessità* o *efficienza computazionale*
 
---

title: Complessità di un algoritmo rispetto all'uso di risorse 

- L’algoritmo viene valutato in base alle risorse utilizzate durante la sua esecuzione:
    - *Tempo di calcolo*
    - Spazio di memoria (risorsa riusabile)
    - Banda trasmissiva (risorsa riusabile)
 
---

title: Domanda
class: large-image

![](images/corda/domanda.png)

- Esiste sempre un algoritmo risolutivo di un problema?
 
---

title: Problemi decidibili e indecidibili 

- Problema *decidibile*
    - se esiste un algoritmo che produce la soluzione in tempo finito per ogni istanza dei dati di ingresso del problema
- Problema *indecidibile*
    - se non esiste nessun algoritmo che produce la soluzione in tempo finito per ogni istanza dei dati di ingresso del problema
 
---
title: Problemi trattabili e intrattabili

- Problemi *intrattabili*
    - non sono risolvibili in tempo polinomiale nemmeno da un algoritmo non deterministico
- Problemi *trattabili*
    - Si dividono in due categorie
      - **P** - insieme dei problemi risolvibili in tempo polinomiale da un algoritmo *deterministico*
      - **NP** - insieme dei problemi risolvibili in tempo polinomiale da un algoritmo *non deterministico*
 
---

title: Complessità temporale 

- Confronto fra algoritmi che risolvono lo stesso problema
- Si valuta il *tempo di esecuzione* (in numero di passi) in modo indipendente dalla tecnologia dell’esecutore
- Il tempo è espresso in funzione della *dimensione dei dati in ingresso* **T(n)**
- Per confrontare le funzioni tempo ottenute per i vari algoritmi si considerano le *funzioni asintotiche*
 

---

title: Funzione asintotica 

- Data la funzione polinomiale **f(n)** che rappresenta il tempo di esecuzione dell’algoritmo al variare della dimensione n dei dati di input
- La *funzione asintotica* ignora le costanti moltiplicative e i termini non dominanti al crescere di n
    - Es
    - f(n) = 3x<sup>4</sup> +6x<sup>2</sup> + 10
    - funzione asintotica = x<sup>4</sup>
 
---
title: Casi

- Il tempo di esecuzione può essere calcolato in caso
    - *pessimo* – dati d’ingresso che massimizzano il tempo di esecuzione
    - *ottimo* – dati d’ingresso che minimizzano il tempo di esecuzione
    - *medio* – somma dei tempi pesata in base alla loro probabilità
 
---

title: Classi di complessità asintotica 
class: large-image

![](images/corda/complessita.png)

---

title: Algoritmi non ricorsivi

- Calcolo della complessità
- Vengono in pratica “contate” le operazioni eseguite

---

title: Calcolo della complessità di algoritmi non ricorsivi 

- Il tempo di esecuzione di un’istruzione di *assegnamento* che non contenga chiamate a funzioni è *1*
- Il tempo di esecuzione di una chiamata ad una *funzione* è *1 + il tempo di esecuzione della funzione*
- Il tempo di esecuzione di un’istruzione di *selezione* è il tempo di *valutazione dell’espressione + il tempo massimo* fra il tempo di esecuzione del ramo then e del ramo else
- Il tempo di esecuzione di un’istruzione di *ciclo* è dato dal tempo di *valutazione della condizione + il tempo di esecuzione del corpo del ciclo moltiplicato per il numero di volte in cui questo viene eseguito*  

---

title: Esempio - fattoriale

code: C

    int fattoriale(int n) {
      int fatt, i;
      fatt = 1;
      for (i = 2; i <= n; i++)
        fatt  = fatt * i;
      return(fatt);
    }

> T(n) = 1 + (n-1)(1+1+1)+1 = 3n – 1 = O(n)
 
---

title: Esercizio - 1

- Scrivere l’algoritmo di ricerca del *valore minimo* in un array di n elementi
- Calcolare la complessità computazionale
- Definire la classe di complessità asintotica

---

title: Esercizio - 2

- Scrivere l’algoritmo che ricerca il *valore x* in un array di n elementi e ritorna l’indice della prima occorrenza dell’elemento o -1 se non è presente
- Calcolare la complessità nel caso
    - ottimo
    - pessimo
    - medio
 
---

title: Complessità computazionale

- Confrontare algoritmi corretti che risolvono lo stesso problema, allo scopo di scegliere quello migliore in relazione a uno o più parametri di valutazione

---

title: Valutazione con un parametro
figure: images/corda/fast.png


- Se si ha a disposizione un solo parametro per valutare un algoritmo, per esempio il tempo d’esecuzione, è semplice la scelta: il più *veloce*.
- Ogni altra caratteristica non viene considerata.

---

title: Valutazione con più parametri

- Nel caso di due parametri normalmente si considera
    - il **tempo**
      - *numero di passi* (istruzioni) che occorrono per produrre il risultato finale.
      - Passi e non secondi o millisecondi perché il tempo varia al variare delle potenzialità del calcolatore.
    - lo **spazio**
      - occupazione di memoria

---

title: Durata delle istruzioni
figure: images/corda/durata_istruzioni.png

- Le istruzioni non hanno tutte lo stesso tempo di esecuzione.
- Il tempo di esecuzione di un algoritmo è una somma pesata delle istruzioni:

---

title: Efficienza

- L’approssimazione di una funzione con una funzione asintotica è molto utile per semplificare i calcoli
- La notazione asintotica di una funzione descrive il comportamento in modo semplificato, ignorando dettagli della formula
- Esempio: per valori sufficientemente alti di x il comportamento della funzione f(x) = x<sup>2</sup> – 3x + 1 è approssimabile con la funzione f(x) = x<sup>2</sup>

---

title: Misura dell'efficienza

- Per un algoritmo con un input di dimensione n, possiamo definirne l’efficienza dicendo che
    - “l’algoritmo per calcolare il risultato finale impiega al più f(n) passi”
    - “l’algoritmo ha complessità f(n)”
 
---

title: Terminologia (1)

- *O* (O grande) equivale al simbolo *<=*
    - Corrisponde a “al più come”
    - “la complessità dell’algoritmo è O(f(n))” equivale a “il tempo d’esecuzione dell’algoritmo è minore o uguale a f(n)”
- *o* (o piccolo) equivale al simbolo *<*
    - “la complessità dell’algoritmo è o(f(n))” equivale a “il tempo d’esecuzione dell’algoritmo è strettamente minore a  f(n)”
- *Θ* (teta) corrispondente al simbolo *=*
    - “la complessità dell’algoritmo è Θ(f(n))” equivale a “il tempo d’esecuzione dell’algoritmo è uguale a f(n)”
 
---

title: Terminilogia (2)

- *Ω* (omega grande) equivale al simbolo *>=*
    - “la complessità dell’algoritmo è Ω(f(n))” equivale a dire “il tempo d’esecuzione dell’algoritmo è maggiore o guale a f(n)”
- *ω* (omega piccolo) equivale al simbolo *>*
    - “la complessità dell’algoritmo è ω(f(n))” equivale a dire“il tempo d’esecuzione dell’algoritmo è strettamente maggiore di f(n)”

---

title: Complessità computazionale temporale

- La complessità computazionale temporale di un algoritmo è la quantità di *tempo* necessaria per produrre il risultato finale
- La complessità si esprime sotto forma di una *funzione* matematica che mette in relazione il *tempo* di esecuzione di un algoritmo con la *dimensione dei dati di input*
- Il caso peggiore per un algoritmo è il caso in cui questo, per generare il risultato, impiega più tempo
 
---

title: Complessità

- In molti casi la complessità è legata al tipo o al *numero* dei dati di input
    - Ad esempio la ricerca di un valore in un vettore ordinato dipende dalla dimensione del vettore
- La complessità può dipendere anche dalla *disposizione* e dal tipo di dati
    - Sempre nell’algoritmo di ricerca in un vettore ordinato avremo il caso:
      - Ottimo
      - Pessimo
      - Medio 
 
---

title: Tipi di complessità

- lineare
- logaritmica
- quadratica
- esponenziale
- fattoriale
 
---

title: Lineare
figure: images/corda/lineare.png

- l’algoritmo ha complessità *O(n)*
- Esempio:
    - algoritmo di *ricerca sequenziale* di un elemento in un array
 
---

title: Logaritmica
figure: images/corda/logaritmica.png

- Esempio *ricerca dicotomica* in un array
- La ricerca dicotomica ha complessità *O(log2(n))*

---

title: Quadratica
figure: images/corda/quadratica.png

- Un esempio è l’algoritmo di ordinamento *bubblesort* eseguito su un array di elementi
- l’algoritmo ha complessità *O(n<sup>2</sup>)*

---

title: Esponenziale
figure: images/corda/esponenziale.png

- l’algoritmo della *Torre di Hanoi* ha complessità Ω(2<sup>n</sup>)
- La Torre di Hanoi è un rompicapo matematico composto da tre paletti e un certo numero di dischi di grandezza decrescente, che possono essere infilati in uno qualsiasi dei paletti.
- Il gioco inizia con tutti i dischi incolonnati su un paletto in ordine decrescente, in modo da formare un cono.
- Lo scopo è portare tutti dischi sull’ultimo paletto, potendo spostare solo un disco alla volta e potendo mettere un disco solo su uno più grande, mai su uno più piccolo

---

title: Torre di Hanoi
class: large-image

![](images/corda/hanoi.gif)
 
---

title: Fattoriale
figure: images/corda/fattoriale.png

- E’ quella che cresce più velocemente rispetto a tutte le precedenti.
- Esempio: algoritmo che calcola tutti gli *anagrammi* di una parola di n lettere distinte.
la complessità di un tale algoritmo è *Θ(n!)*

---

title: logaritmica < lineare < quadratica < esponenziale < fattoriale 
class: large-image

![](images/corda/orders.svg)

---

title: Confronto
class: large-image

![](images/corda/confronto.png)

 
