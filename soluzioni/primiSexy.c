/*
 * Due numeri primi si dicono *sexy* quando la loro differenza è uguale a sei,
 * ovvero formano coppie di tipo: ( p , p + 6 )
 * Il nome di queste coppie di numeri primi deriva dalla parola latina sex (ovvero sei).
 * Visualizza tutte le coppie di numeri sexy (p1,p2) con p2<100
*/

#include <stdio.h>
#define MAX 100

// Ritorna true se n è primo, false altrimenti
unsigned primo(unsigned n) {
    if (n < 2)
        return 0;
    for (unsigned divisore = 2; divisore * divisore <= n; ++divisore)
        if (n % divisore == 0)
            return 0;
    return 1;
}

int main(void)
{
    for (unsigned i=0; i<MAX-6; ++i)
        if(primo(i) && primo(i+6))
            printf("(%u,%u)\n",i,i+6);
}

