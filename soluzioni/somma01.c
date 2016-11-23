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
#define N 100

/* riempie array b con n-1 elementi di a tranne elemento di indice i */
void fill(int b[], int a[], int n, int i){
    int j,k = 0;
    for (j=0;j<n;j++)
        if (j!=i) {
            b[k]=a[j];
            k++;
        }
}

/* return 1 se la somma di alcuni elementi di v = s */
int ugualeSomma(int v[],int n,int s){
    int i,j,somma=0;
    int subvet[N];
    if (n==0)                   // array vuoto -> nessuna soluzione
        return 0;
    for(i=0;i<n;i++) {
        if (v[i]==s)            // il singolo elemento = somma -> soluzione
            return 1;
        else
            if (v[i]<s) {
                fill(subvet,v,n,i);     // riempe array subvet con elementi diversi da elemento con indice i
                if (ugualeSomma(subvet,n-1,s-v[i])) // somma di alcuni altri elementi = somma - questo elemento -> soluzione
                    return 1;
            }
    }
    return 0;                   // non trovata soluzione
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
    getchar();

    printf("Somma: ");
    scanf("%d",&s);

    if (ugualeSomma(val,n,s))
       printf("Esiste");
    else
        printf("Non esiste");
    printf(" una combinazione dei numeri che ha somma %d\n",s);
    return 0;
}

