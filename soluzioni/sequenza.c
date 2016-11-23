/*
 Esempio permutazioni
*/
#include <stdio.h>
#include <math.h>

void printCifre(unsigned val, unsigned base) {
    unsigned cifra;
    unsigned cifre[10];
    unsigned i;
    for (i=0;i<10;i++)
        cifre[i] = 0;
    int pos;
    for (pos = base-1; pos>=0; --pos) {
        cifra = val % base;
        cifre[pos] = cifra;
        val = val / base;
    }
    for (pos=0;pos<base;++pos)
        printf("%u ",cifre[pos]);
    printf("\n");
}

int main(void)
{
    unsigned n;
    printf("Permutazioni n valori (n<10) \n");
    printf("Inserisci il valore di n: ");
    scanf("%u",&n);
    unsigned vmax;      //valore massimo
    vmax = pow(n,n);
    unsigned i;
    for (i=0; i<vmax; ++i)
        printCifre(i,n);


    return 0;
}

