/*
 * Legge un numero 1<N≤100 da tastiera e stampa tutti i sottoinsiemi
 * dell’insieme S=[1..N] diversi dall’insieme vuoto e da S.
*/
#include <stdio.h>
#include <math.h>
#define N 101

/* Stampa sottinsiemi di val di n elementi (escluso vuoto e val)*/
void stampaSottoInsiemi(int val[], int n){
    int i,j,p;
    int max;
    max = pow(2,n);             // Numero di sottinsiemi di un insieme di n elementi
    for (i=0;i<max-1;i++) {     // tutti i sottinsiemi tranne l'insieme completo
        j=i;                    // "numero" del sottinsieme da cui ottenere la rappresentazione binaria
        p=0;                    // indice dell'elemento dell'insieme
        while (j>0) {
            if (j%2 == 1)
                printf("(%d)",val[p]);  // bit p-esimo a 1 -> elemento appartiene al sottinsieme
            j = j/2;
            p++;                        // passaggio al bit successivo
        }
        printf("\n");
    }
}

int main(){
    int i,n;
    int val[N];         // valori
    printf("N (1<N<=100): ");
    scanf("%d",&n);
    // carica array
    for (i=0;i<n;i++) {     // inserimento dei valori nell'insieme
        val[i] = i+1;
    }
    stampaSottoInsiemi(val, n);
    return 0;
}
