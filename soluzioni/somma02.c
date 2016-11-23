/*
 * Legge da tastiera un numero 1<N≤100 e chieda all’utente N numeri nell’intervallo [0..100].
 * Una volta acquisiti gli N numeri, il programma chiede all’utente un numero S intero e indica se
 * esiste una combinazione degli N numeri letti che ha somma S.
 * Ad esempio, per N=5, se l’utente immette 1, 10, 4, 5, 6 e sceglie S=10, il programma stampa:
 * Esiste una combinazione di numeri che ha somma 10.
 * Sempre per N=5, se l’utente immette 1, 10, 4, 5, 6 e sceglie S=13, il programma stampa:
 * Non esiste una combinazione di numeri che ha somma 13.
*/

#include <stdio.h>
#include <math.h>
#define N 100

/* return 1 se la somma di un sottinsieme di val di n elementi = s */
int sommaSottoInsiemi(int val[], int n, int s){
    int i,j,p,sum;
    int max;
    max = pow(2,n);             // numero di sottinsiemi
    for (i=1;i<max;i++) {
        j=i;                    // numero relativo al sottinsieme (rappresentazione binaria)
        p=0;                    // indice elemento insieme
        sum = 0;
        while (j>0) {
            if (j%2 == 1)       // bit a 1
                sum+=val[p];
            j = j/2;
            p++;
        }
        if (sum == s) {
            j=i;                    // numero relativo al sottinsieme (rappresentazione binaria)
            p=0;                    // indice elemento insieme
            while (j>0) {
                if (j%2 == 1)       // bit a 1
                    printf("(%d)",val[p]);
                j = j/2;
                p++;
            }
            printf("\n");
            return 1;
        }
    }
    return 0;
}


int main(void)
{
    int n;          // numero valori
    int val[N];   // valori in input
    int s;          // somma
    int i;

    printf("Numero valori: ");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("val %d = ",i);
        scanf("%d",&val[i]);
    }

    printf("Somma: ");
    scanf("%d",&s);

    if (sommaSottoInsiemi(val,n,s))
       printf("Esiste");
    else
        printf("Non esiste");
    printf(" una combinazione dei numeri che ha somma %d\n",s);
    return 0;
}

