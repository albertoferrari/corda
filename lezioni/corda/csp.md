title: Progetto Corda
subtitle: Alberto Ferrari
figure: images/corda/corda.jpg

---
title: Problemi di soddisfacimento di vincoli
subtitle: CSP (Constraint Satisfaction Problem)
class: segue dark

---
title: Caratteristiche

- I problemi di siddisfacimento di vincoli sono caratterizzati da:
    - un insieme di *variabili* che possono assumere valori in un certo *dominio*
    - un insieme di *vincoli* che devono essere rispettati dai valori delle variabili
 
---

title: Un esempio

- Un problema di *criptoaritmetica*:


> Assegnare un valore numerico a ogni lettera in modo che sia soddisfatta  
> la condizione:
<br>
>COCA + COLA = OASIS
<br>
>C≠O≠A≠L≠S≠I
<br>
>C,A,L,S,I in [0..9] e O in [1..9]
 
---

title: Una prima soluzione all'esempio (1)

code: c

    /* genera tutte le combinazioni di valori delle variabili
    se i vincoli sono soddifatti stampa la soluzione */  
    void generaValori(int indice){
        int i;
        if (indice == DIM) {		//DIM dimensione array valVar
            if(vincoliSoddisfatti())
                stampaSoluzione();
        }
        else
            for(i=0;i<=MAXVAL;i++) {		//ogni variabile ha valore 0..MAXVAL
                valVar[indice]=i;
                generaValori(indice+1);
            }
    }
    int main(void) {
        generaValori(0);
        return 0;
    }
 
---

title: Una prima soluzione all'esempio (2)

code: c

    /* return 1 se tutti i vincoli sono soddisfatti */
    int vincoliSoddisfatti(){
      int c,a,l,s,i,o;    // valori assegnati alle variabili
      int r1,r2,r3;       // riporti
      c = valVar[0]; a = valVar[1]; l = valVar[2]; s = valVar[3];
      i = valVar[4]; o = valVar[5];
      if (o==0)   return 0;
      if (!tuttiDiversi())   return 0;
      if (s != (a + a) % 10)    return 0;
      r1 = (a + a) / 10;
      if (i != (r1 + c + l) % 10)   return 0;
      r2 = (r1 + c + l) / 10;
      if (s != (r2 + o + o) % 10)   return 0;
      r3 = (r2 + o + o) / 10;
      if (a != (r3 + c + c) % 10)   return 0;
      if (o != (r3 + c + c) / 10)   return 0;
      return 1;
    }
 
---

title: Valutazione alternativa dei vincoli

code: c

    /* return 1 se tutti i vincoli sono soddisfatti */
    int vincoliSoddisfatti(){
      int c,a,l,s,i,o;
      int coca,cola,oasis;
      c = valVar[0]; a = valVar[1]; l = valVar[2]; s = valVar[3];
      i = valVar[4]; o = valVar[5];
      if (o==0)   return 0;
      if (!tuttiDiversi()) return 0;
      coca = c*1000 + o*100 + c*10 + a;
      cola = c*1000 + o*100 + l*10 + a;
      oasis = o*10000 + a*1000 + s*100 + i*10 + s;
      if (!(coca+cola==oasis)) // COCA + COLA = OASIS
          return 0;
      return 1;
    }
 
 
---

title: esercizio

- Prendendo a modello la soluzione all'esercizio precedente risolvere il seguente problem:
    - Assegnare un valore numerico a ogni lettera in modo che sia soddisfatta la condizione:
      - DUE + UNO = TRE
    - valori delle variabili tutti diversi
    - intervallo dei valori 0..9
    - D,U,T  diversi da 0
 
---

title: Proviamo a migliorare la soluzione

- *Contare* il numero di valori generati complessivamente nelle soluzioni precedenti
- *Verificare* se è possibile evitare di generare tutte le combinazioni di valori
- *Contare* il numero di valori generati nella nuova soluzione
 
---

title: Problema delle 8 regine

- Posizionare otto regine su una scacchiera 8x8 in modo che nessuna di esse possa catturarne un'altra.
- Nessuna regina deve avere una colonna, riga o diagonale in comune con un'altra regina.
<br>
- Il problema è un esempio del più generale problema delle n regine su una scacchiera n × n

[Wikipedia](https://it.wikipedia.org/wiki/Rompicapo_delle_otto_regine)
 
