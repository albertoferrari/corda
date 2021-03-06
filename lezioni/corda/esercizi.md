title: Progetto Corda
subtitle: Alberto Ferrari
figure: images/corda/corda.jpg

---
title: Esercizi
class: segue dark

---

title: Esercizi (1)

- *12 monete*
    - Abbiamo 12 monete che sembrano identiche ma non lo sono. Una di esse ha un peso diverso dalle altre ma non sappiamo qual è e neppure se è più pesante o più leggera delle altre.
    Dobbiamo scoprire qual è la moneta di peso diverso, con 3 pesate comparative utilizzando una bilancia a due piatti 
    - Scrivere un programma che implementa l’algoritmo presentato per risolvere il problema delle 12 monete
    - Scrivere una seconda versione dell’algoritmo in cui si pesano solamente 2 monete per volta
- *Permutazioni*
    - Scrivere un programma in linguaggio C che stampi tutte le permutazioni ottenibili combinando le 4 lettere ‘A’, ‘B’, ‘C’, ‘D’.
    - Segue un possibile output atteso del programma.ABCD BACD CABD DABCABDC BADC CADB DACB ACBD BCAD CBAD DBAC ACDB BCDA CBDA DBCA ADBC BDAC CDAB DCAB ADCB BDCA CDBA DCBA
 
---
title: Numeri semiprimi

- Un numero **semiprimo** è un intero ≥ 2 che si fattorizza come prodotto di due numeri *primi*
(non necessariamente distinti).
- Esempi di semiprimi:
    - 15, prodotto di 3 e 5.
    - 169, prodotto di 13 e 13.
- Scrivere un programma che verifichi se un numero N è semiprimo.
    - Dati di input: il file *input.txt* contiene l’unico intero N , di cui si vuole verificare la semiprimalità.
    - Dati di output: il file *output.txt* contiene:
        - I due primi che fattorizzano N , stampati su un’unica riga, in ordine non-decrescente, se N è semiprimo.
        - L’unico intero −1 se N non è semiprimo.

---
title: Esempio input - output

code: C

    #include <stdio.h>
    int main() {
        FILE *fin = fopen("input.txt", "r");
        FILE *fout = fopen("output.txt", "w");
        unsigned n;
        fscanf(fin, "%u", &n);
        ...  
        fprintf(fout, "%d", ….);
        fclose(fin);
        fclose(fout);
        return 0;
    }

---
title: Numeri primi sexy

- In matematica due numeri primi si dicono *sexy* quando la loro differenza è uguale a sei,
ovvero formano coppie di tipo:
    - **( p , p + 6 )**
- Il nome di queste coppie di numeri primi deriva dalla parola latina sex (ovvero sei).
- Scrivere un programma che visualizza tutte le coppie di numeri sexy (p1,p2)
con p1<100 e p2<100
---
title: Goldbach
figure: images/corda/Goldbach.jpg

- La congettura di *Goldbach* è uno dei più vecchi problemi irrisolti nella teoria dei numeri.
- Essa afferma che ogni numero pari maggiore di 2 può essere scritto come somma di due numeri primi
(che possono essere anche uguali).
- Scrivere un programma che riceve un numero intero pari *n* e visualizza la coppia di numeri primi
 *p1* e *p2* tali che **p1+p2 = n**

---
title: Goldbach debole

- La congettura debole di *Goldbach* asserisce che tutti i numeri dispari maggiori di 7
possono essere scritti come somma di tre primi.
- Scrivere un programma che riceve un numero intero dispari *n* e visualizza 3 numeri primi
 *p1*, *p2*, *p3* tali che **p1+p2+p3 = n** ...
    - oppure confuta la congettura debole di Goldbach :)

---
title: Olimpiadi Informatica(Lo struzzo Simone) 

- Lo struzzo Simone si sposta solo nelle direzioni dei quattro assi cardinali. Ogni suo passo misura 1 metro.
- Scrivere un programma che, data una sequenza di spostamenti, misuri il quadrato della distanza fra il punto di partenza e il punto di arrivo
- Dati di *input*
    - Il file *input.txt* contiene la sequenza degli spostamenti. E' costituito da un'unica riga di testo, contenente una sequenza di S, N, E, O (Sud, Nord, Est, Ovest). La sequenza è terminata da un \*.
    - Esempio NNESO\* = 2 metri a Nord, poi 1 metro a Est, poi 1 metro a Sud, e 1 metro a Ovest.
- Dati di *output*
    - Il file output.txt deve contenere un'unica riga. Su questa riga dovrà comparire il numero intero corrispondente al *quadrato della distanza*.
- Assunzioni
    - Il numero di spostamenti nel file di input è <= 100000.
---

title: Esempio input - output

code: C

    #include <stdio.h>
    int main() {
        FILE *fin = fopen("input.txt", "r");
        FILE *fout = fopen("output.txt", "w");
        char input[100000];
        fscanf(fin, "%s", input);
        while (input[i] != '*') {
            ...
        }
        fprintf(fout, "%d", ….);
        fclose(fin);
        fclose(fout);
        return 0;
    }

---

title: Olimpiadi Informatica (La biblioteca degli smemorati) 

- La biblioteca ha qualche problema nello stabilire da quanto tempo gli utenti tengono i libri. - Scrivere un programma che, prese in input due date del 2015, stabilisca quanti giorni intercorrono tra le due date.
- Dati di input
    - Il file input.txt è formato da una riga che contiene la data iniziale e la data finale del prestito. La riga contiene quattro interi: la prima coppia specifica la data iniziale, la seconda la data finale. Ogni data è formata da due numeri: il giorno del mese e il numero del mese.
- Dati di output
    - Il file output.txt deve contenere un'unica riga: il numero intero corrispondente ai giorni che intercorrono tra le due date in input.
- Assunzioni
    - La seconda data non precede mai la prima.
    - Il numero di giorni considerato non comprende quello iniziale 
