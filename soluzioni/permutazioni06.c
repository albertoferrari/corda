/*
 Letto da tastiera un numero N>1,
 stampa tutte le permutazioni degli N valori nell’intervallo [1..N]
*/
#include <stdio.h>
#define MAXEL 10


// Stampa array di n elementi
void print(int v[],unsigned n)
{
    for(unsigned i=0;i<n;i++)
        printf("%d | ",v[i]);
    printf("\n");
}

// permutazioni degli elementi del vettore vect
// di n elementi a partire dall'elemento e e successivi
void perm(int vect[],unsigned n,unsigned e)
{
    if(e==n){                       // ultimo elemento
        print(vect,n);              // stampa array
        return;                     // fine ricorsione
    }

    for(unsigned i=e;i<n;++i){          // per ogni elemento da e ai successivi
        int t[MAXEL];                  // vettore d'appoggio
        for(unsigned ti=0;ti<e;ti++)    // copio tutti gli elementi precedenti e
            t[ti] = vect[ti];
        t[e] = vect[i];                 // imposto elemento e
        unsigned t1 = e+1;
        for (unsigned j=e;j<n;j++){     // imposto elementi successivi
            if(j!=i){
                t[t1]=vect[j];
                t1++;
            }
        }
        perm(t,n,e+1);
    }
}

int main() {
    unsigned n;
    printf("Inserire valore intero maggiore di 1 e minore di %d",MAXEL);
    do
        scanf("%u",&n);
    while (n<1 || n>MAXEL);
    int v[MAXEL];
    for (int i=0;i<n;++i)
        v[i]=i+1;
    perm(v,n,0);
    return 0;
}
