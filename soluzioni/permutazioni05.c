/*
 Stampa tutte le permutazioni ottenibili combinando le 4 lettere
 ‘A’, ‘B’, ‘C’, ‘D’.
*/
#include <stdio.h>
#define MAXEL 4


// Stampa array di n elementi
void print(char v[],unsigned n)
{
    for(unsigned i=0;i<n;i++)
        printf("%c | ",v[i]);
    printf("\n");
}

// permutazioni degli elementi del vettore vect
// di n elementi a partire dall'elemento e e successivi
void perm(char vect[],unsigned n,unsigned e)
{
    if(e==n){                       // ultimo elemento
        print(vect,n);              // stampa array
        return;                     // fine ricorsione
    }

    for(unsigned i=e;i<n;++i){          // per ogni elemento da e ai successivi
        char t[MAXEL];                  // vettore d'appoggio
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
    char v[4] = {'A','B','C','D'};
    perm(v,4,0);
    return 0;
}
