title: Progetto Corda
subtitle: Alberto Ferrari
figure: images/corda/corda.jpg

---
title: Soluzione esercizi
class: segue dark

---
title: Permutazioni (1)

- *Permutazioni*
    - Scrivere un programma in linguaggio C che stampi tutte le permutazioni ottenibili combinando le 4 lettere ‘A’, ‘B’, ‘C’, ‘D’.

code: C

        #include <stdio.h>
        int main() {
          char a[4] = {'A','B','C','D'};
          int i1,i2,i3,i4;
          for (i1=0;i1<4;i1++)
              for (i2=0;i2<4;i2++)
                  for (i3=0;i3<4;i3++)
                      for (i4=0;i4<4;i4++)
                          if(i1!=i2 && i1!=i3 && i1!=i4 &&i2!=i3 && i2!=i4 &&i3!=i4)
                              printf("%C%C%C%C\n",a[i1],a[i2],a[i3],a[i4]);
          return 0;
        }

---
title: Permutazioni (2)

code: C

      int allDifferent(int v[],int n){
        for (int i=0;i<n-1;i++)
          for (int j=i+1;j<n;j++)
              if (v[i]==v[j]) return 0;
        return 1;
      }

      int main(void) {
        char a[4] = {'A','B','C','D'}; int p[4];
        for (p[0]=0;p[0]<4;p[0]++)
          for (p[1]=0;p[1]<4;p[1]++)
              for (p[2]=0;p[2]<4;p[2]++)
                  for (p[3]=0;p[3]<4;p[3]++)
                      if(allDifferent(p,4))
                          printf("%C%C%C%C\n",a[p[0]],a[p[1]],a[p[2]],a[p[3]]);
        return 0;
      }

---
title: Permutazioni (3)

code: C

      void elabora(char v[],int n){ //Elabora (stampa) l'array v di n elementi
        for(int i=0;i<n;i++)  printf("%c ",v[i]);
        printf("\n");
      }
      void scambia(char v[],int x, int y){ //scambia elementi x e y di v
        int temp = v[x]; v[x] = v[y]; v[y] = temp;
      }
      // Permutazioni dell'array v di n elementi: scambia v[pos] coi precedenti
      void permuta(char v[],int pos,int n){
        if(pos>0) {
          for (int k=pos;k>=0;k--){
              scambia(v,k,pos); permuta(v,pos-1,n); scambia(v,k,pos);
          }
        } else  elabora(v,n);
      }
      int main(void) {
        char a[DIM] = {'A','B','C','D'};
        permuta(a,DIM-1,DIM);
      }

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
title: Numeri semiprimi (soluzione)

code: C

      unsigned primo(unsigned n) { // Ritorna true(1) se n è primo
        if (n < 2) return 0;
        for (unsigned divisore = 2; divisore * divisore <= Q; ++divisore)
          if (Q % divisore == 0)  return 0;
        return 1;
      }
      unsigned trova_D(unsigned n) { // Ritorna il più piccolo divisore primo di n
      for (unsigned d = 2; d <= n; ++d)
        if (N % D == 0) return D;
      }
      int main() {
        FILE *fin = fopen("input.txt", "r"); FILE *fout = fopen("output.txt", "w");
        unsigned n;        fscanf(fin, "%u", &n);
        unsigned d = trova_D(n);
        if (primo(n/d))  fprintf(fout, "%u %u",D,N/D);
        else   fprintf(fout, "%d",-1);
        fclose(fin);   fclose(fout);
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
title: Numeri primi sexy (soluzione)

code: C

      #include <stdio.h>
      #define MAX 100

      unsigned primo(unsigned n) { ... }

      int main(void)
      {
          for (unsigned i=0; i<MAX-6; ++i)
              if(primo(i) && primo(i+6))
                  printf("(%u,%u)\n",i,i+6);
      }
---
title: Goldbach
figure: images/corda/Goldbach.jpg

- La congettura di *Goldbach* è uno dei più vecchi problemi irrisolti nella teoria dei numeri.
- Essa afferma che ogni numero pari maggiore di 2 può essere scritto come somma di due numeri primi
(che possono essere anche uguali).
- Scrivere un programma che riceve un numero intero pari *n* e visualizza la coppia di numeri primi
 *p1* e *p2* tali che **p1+p2 = n**

---
title: Goldbach (soluzione)

code: C

      unsigned primo(unsigned n) { ... }

      int main() {
          unsigned n;
          printf("Inserisci un numero pari maggiore di 2: ");
          scanf ("%u",&n);
          if (n<2 || n%2==1)
              return 1;
          unsigned a;     //possibile argomento della somma
          for(a=n/2; a>0; --a)
              if(primo(a) && primo(n-a))
                  printf("%u = %u + %u \n",n,a,n-a);
          return 0;
      }
---
title: Goldbach debole

- La congettura debole di *Goldbach* asserisce che tutti i numeri dispari maggiori di 7
possono essere scritti come somma di tre primi.
- Scrivere un programma che riceve un numero intero dispari *n* e visualizza 3 numeri primi
 *p1*, *p2*, *p3* tali che **p1+p2+p3 = n** ...
    - oppure confuta la congettura debole di Goldbach :)

---
title: Goldbach debole (soluzione)

code: C

      unsigned a2,a3; //secondo e terzo argomento della somma
      // True se esistono due primi la cui somma è n (memorizza in a2 e a3)
      int somma (unsigned n) {
          for(unsigned a=n/2; a>0; --a)
              if(primo(a) && primo(n-a)) {
                  a2 = a;  a3 = n-a;  return 1;
              }
          return 0;
      }
      int main() {
          unsigned n;   printf("Inserisci un numero dispari maggiore di 7: ");
          scanf ("%u",&n);     if (n<7 || n%2==0)  return 1;
          for(unsigned a=n/2; a>0; --a)
              if(primo(a) && somma(n-a)) {
                  printf("%u = %u + %u + %u\n",n,a,a2,a3);
                  return 0;
              }
          printf("La congettura debole di Goldbach non e' soddisfatta per %u\n", n);
      }
---
title: Olimpiadi Informatica(Lo struzzo Simone) 

- Lo struzzo S si sposta solo nelle direzioni degli assi cardinali. Ogni suo passo misura 1 metro. Scrivere un programma che, data una sequenza di spostamenti, misuri la distanza fra il punto di partenza e il punto di arrivo
- Dati di *input*
    - Il file *input.txt* contiene la sequenza degli spostamenti. E' costituito da un'unica riga di testo, contenente una sequenza di S, N, E, O (cSud, Nord, Est, Ovest). La sequenza è terminata da un \*.
    - Esempio NNESO\* dice che Simone si sposta di due metri a Nord, poi di un metro verso Est, poi di un metro verso Sud, e quindi di un metro a Ovest.
- Dati di *output*
    - Il file output.txt deve contenere un'unica riga. Su questa riga dovrà comparire il numero intero corrispondente al *quadrato della distanza*.
- Assunzioni
    - Il numero complessivo di spostamenti contenuti nel file di input è <= 100000.

---

title: Lo struzzo Simone (soluzione)

code: C

    #include <stdio.h>
    int main() {
        FILE *fin = fopen("input.txt", "r");
        FILE *fout = fopen("output.txt", "w");
        char input[100000]; int i = 0, ns = 0, eo = 0;
        fscanf(fin, "%s", input);
        while (input[i] != '*') {
            switch (input[i]) {
                case 'N': ns++; break;
                case 'S': ns--; break;
                case 'E': eo++; break;
                case 'O': eo--; break;
            }
            i++;
        }
        fprintf(fout, "%d", ns*ns + eo*eo);
        fclose(fin); fclose(fout);
        return 0;
    }
 
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
