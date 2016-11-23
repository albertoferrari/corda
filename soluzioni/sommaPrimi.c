/*
 * La congettura di Goldbach è uno dei più vecchi problemi irrisolti nella teoria dei numeri.
 * Essa afferma che ogni numero pari maggiore di 2 può essere scritto come somma di due numeri primi
 * (che possono essere anche uguali).
 * Ricevere un numero intero pari n e visualizzare la coppia di numeri primi p1 e p2 tali che
 * p1+p2 = n
*/

#include <stdio.h>

// Ritorna true se n è primo, false altrimenti
unsigned primo(unsigned n) {
    if (n < 2)
        return 0;
    for (unsigned divisore = 2; divisore * divisore <= n; ++divisore)
        if (n % divisore == 0)
            return 0;
    return 1;
}

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
