/*
 * La congettura debole di Goldbach asserisce che tutti i numeri dispari maggiori di 7
 * possono essere scritti come somma di tre primi.
 * Ricevere un numero n dispari > 7 e visualizzare 3 numeri primi p1,p2,p3
 * tali che n = p1+p2+p3
*/

#include <stdio.h>

unsigned a2,a3; //secondo e terzo argomento della somma

// Ritorna true se n è primo, false altrimenti
unsigned primo(unsigned n) {
    if (n < 2)
        return 0;
    for (unsigned divisore = 2; divisore * divisore <= n; ++divisore)
        if (n % divisore == 0)
            return 0;
    return 1;
}

// Ritorna true se esistono due numeri primi la cui somma è n
// Memorizza i due numeri primi in a2 e a3
int somma (unsigned n) {
    unsigned a;     //possibile argomento della somma
    for(a=n/2; a>0; --a)
        if(primo(a) && primo(n-a)) {
            a2 = a;
            a3 = n-a;
            return 1;
        }
    return 0;
}

int main() {
    unsigned n;
    printf("Inserisci un numero dispari maggiore di 7: ");
    scanf ("%u",&n);
    if (n<7 || n%2==0)
        return 1;
    unsigned a;     //possibile argomento della somma
    for(a=n/2; a>0; --a)
        if(primo(a) && somma(n-a)) {
            printf("%u = %u + %u + %u\n",n,a,a2,a3);
            return 0;
        }
    printf("La congettura debole di Goldbach non e' soddisfatta per %u\n", n);
    return 0;
}
