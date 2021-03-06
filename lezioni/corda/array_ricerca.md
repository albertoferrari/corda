title: Progetto Corda
subtitle: Alberto Ferrari
figure: images/corda/corda.jpg

---
title: Array (visita e ricerca) 
class: segue dark

---
title: Array

- Struttura *statica omogenea*
    - non in tutti i linguaggi … array dinamici
- *Accesso diretto* a ogni elemento attraverso l’indice (complessità dell’accesso *O(1)* )
 
---

title: Algoritmo di visita

- Percorrere *una e una sola volta* tutti gli elementi
- Es. stampa array
 
---

title: visita

code: C

    void visita_array(int a[], int n)
    {   int i;
       for (i = 0; i < n; i++)
          elabora(a[i]);
    }

>se elabora ha complessità x passi la complessità dell’algoritmo risulta = 1+n(1+x+1)+1 = (x+2)n+2 = O(n)
 
---

title: Ricerca

- Stabilire se un valore è *presente* all’interno dell’array restituendo l’indice dell’elemento o -1 se non presente
 
---

title: Es1 - Algoritmo di ricerca lineare

- Scrivere l’algoritmo di *ricerca lineare* di un elemento in un array *non ordinato*

code: C

    int ricerca_lineare(int a[], int n, int valore)

- Calcolare la complessità computazionale
    - nel caso ottimo, pessimo e medio
- Definire la classe di complessità asintotica nel caso medio
 
---

title: Es2 - Algoritmo di ricerca binaria

- Scrivere l’algoritmo di *ricerca binaria* di un elemento in un array *ordinato*

code: C

    int ricerca_binaria(int a[], int n, int valore)

- Calcolare la complessità computazionale
    - nel caso ottimo, pessimo e medio
- Definire la classe di complessità asintotica nel caso medio

---

title: Complessità computazionale e tempo di esecuzione 

- Fare una *misurazione empirica* della complessità temporale dei due algoritmi realizzando un programma che genera in modo casuale un array ordinato poi testa le due funzioni e calcola i tempi di risposta nel caso ottimo medio e pessimo
- Utilizzare un numero elevato di elementi per l’array 

---

title: Esempio - calcolo tempo C

code: C

    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h> int main(void) {
    	time_t now,future;
    	time(&now);
    	long i,j;
    	for(i=0;i<1000000;i++)
    		for(j=0;j<1000;j++)
    			;
    	time(&future);
    	double seconds = difftime(future, now);
    	printf("%.f seconds passed\n", seconds); 
      return EXIT_SUCCESS;
    } 

---

title: Esempio - numero casuale in C

code: C

    #include <time.h>
    #include <stdlib.h>
    #include <stdio.h> int main(void) {
    	int n;    
    	srand(time(NULL));    
    	n = rand() % 100 + 1;    
    	printf("%d \n",n);
      return EXIT_SUCCESS;
    }  
