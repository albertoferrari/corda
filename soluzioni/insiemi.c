/*
 * Scrivere un programma in linguaggio C che richieda all’utente N numeri tra 1 e N, poi ne chieda altri N (sempre tra 1 e
N) e verifichi che l’insieme formato dai primi N (senza che i numeri vengano ripetuti più volte) sia uguale all’insieme dei
secondi N (senza che i numeri vengano ripetuti più volte).
*/
#include <stdio.h>
#define N 10

/* return 1 se insiemi v1 e v2 contengono gli stessi elementi (senza ripetizione */
int insiemiUguali(int v1[],int v2[]){
    int b1[N+1];    // presenza elementi primo insieme
    int b2[N+1];    // presenza elementi secondo insieme
    int i;
    for (i=0;i<N;i++) { // inizializzazione
        b1[i] = 0;
        b2[i] = 0;
    }
    for (i=0;i<N;i++) {
        b1[v1[i]] = 1;  // valore presente nel primo insieme
        b2[v2[i]] = 1;  // valore presente nel secondo insieme
    }

    // ***********for debug
    printf("Primo insieme:\n");
    for (i=0;i<N;i++) {
        if (b1[i])
            printf("(%d)",i);
    }
    printf("\nSecondo insieme:\n");
    for (i=0;i<N;i++) {
        if (b2[i])
            printf("(%d)",i);
    }
    printf("\n");
    // ********************

    for (i=0;i<N;i++) {
        if (b1[i] != b2[i])
            return 0;
    }
    return 1;
}

int main(void)
{
    int v1[N] = {2,5,2,8,1,9,10,2,8,3};
    int v2[N] = {5,8,3,7,10,3,8,9,1,3};
    int v3[N] = {3,2,8,3,1,9,5,10,8,3};

    if (insiemiUguali(v1,v2))
        printf("Insiemi uguali\n");
    else
        printf("Insiemi diversi\n");

    printf("\n\n");

    if (insiemiUguali(v1,v3))
        printf("Insiemi uguali\n");
    else
        printf("Insiemi diversi\n");

    return 0;
}

