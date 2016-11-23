#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/timeb.h>

int ricerca_lineare(long int a[], int n, long int valore);
int ricerca_binaria(long int a[], int n, long int valore);
void ritardo();

int main()
{
    int n = 50000;
    long int a[n];
    int cont;
    long int valore;
    int indice;
    struct timeb start,end;



    a[0] = 0;
    for(cont = 1; cont < n; cont++)
        a[cont] = a[cont - 1] + (rand() % 10);

    /* Caso Ottimo */
    /* Ricerca Lineare*/
    valore = a[0];
    ftime(&start);
    indice = ricerca_lineare(a, n, valore);
    ftime(&end);

    printf("Ricerca Lineare - Valore: %ld \n", valore);
    printf("Caso Ottimo: %d (indice)\n", indice);
    printf("start.time     = %ld (seconds)", start.time);
    printf(" - start.millitm  = %d (mlliseconds)\n", start.millitm);
    printf("end.time       = %ld (seconds)", end.time);
    printf(" - end.millitm    = %d (mlliseconds)\n", end.millitm);

    /* Ricerca Binaria */
    valore = a[(n-1)/2];
    ftime(&start);
    indice = ricerca_binaria(a, n, valore);
    ftime(&end);

    printf("Ricerca Binaria - Valore: %ld \n", valore);
    printf("Caso Ottimo: %d (indice)\n", indice);
    printf("start.time     = %ld (seconds)", start.time);
    printf(" - start.millitm  = %d (mlliseconds)\n", start.millitm);
    printf("end.time       = %ld (seconds)", end.time);
    printf(" - end.millitm    = %d (mlliseconds)\n", end.millitm);


    /* Caso Medio */
    /* Ricerca Lineare*/
    valore = a[(n-1)/2];
    ftime(&start);
    indice = ricerca_lineare(a, n, valore);
    ftime(&end);

    printf("Ricerca Lineare - Valore: %ld \n", valore);
    printf("Caso Medio: %d (indice)\n", indice);
    printf("start.time     = %ld (seconds)", start.time);
    printf(" - start.millitm  = %d (mlliseconds)\n", start.millitm);
    printf("end.time       = %ld (seconds)", end.time);
    printf(" - end.millitm    = %d (mlliseconds)\n", end.millitm);

    /* Ricerca Binaria */
    valore = a[(n - 1)/128];
    ftime(&start);
    indice = ricerca_binaria(a, n, valore);
    ftime(&end);

    printf("Ricerca Binaria - Valore: %ld \n", valore);
    printf("Caso Medio: %d (indice)\n", indice);
    printf("start.time     = %ld (seconds)", start.time);
    printf(" - start.millitm  = %d (mlliseconds)\n", start.millitm);
    printf("end.time       = %ld (seconds)", end.time);
    printf(" - end.millitm    = %d (mlliseconds)\n", end.millitm);

    /* Caso Pessimo */
    /* Ricerca Lineare*/
    valore = -1;
    ftime(&start);
    indice = ricerca_lineare(a, n, valore);
    ftime(&end);

    printf("Ricerca Lineare - Valore: %ld \n", valore);
    printf("Caso Pessimo: %d (indice)\n", indice);
    printf("start.time     = %ld (seconds)", start.time);
    printf(" - start.millitm  = %d (mlliseconds)\n", start.millitm);
    printf("end.time       = %ld (seconds)", end.time);
    printf(" - end.millitm    = %d (mlliseconds)\n", end.millitm);

    /* Ricerca Binaria */
    valore = -1;
    ftime(&start);
    indice = ricerca_binaria(a, n, valore);
    ftime(&end);

    printf("Ricerca Binaria - Valore: %ld \n", valore);
    printf("Caso Pessimo: %d (indice)\n", indice);
    printf("start.time     = %ld (seconds)", start.time);
    printf(" - start.millitm  = %d (mlliseconds)\n", start.millitm);
    printf("end.time       = %ld (seconds)", end.time);
    printf(" - end.millitm    = %d (mlliseconds)\n", end.millitm);

    return 0;
}

int ricerca_lineare(long int a[], int n, long int valore)
{
    int cont;

    for(cont = 0; cont < n; cont++)
    {
        ritardo();
        if(a[cont] == valore)
            return cont;
    }

    return -1;
}

int ricerca_binaria(long int a[], int n, long int valore)
{
    int first = 0,
        last = n - 1,
        middle;

    while(last >= first)
    {
        middle = ((first + last) / 2);
        printf("\n *** indice middle %d, valore middle %ld\n", middle, a[middle]);
        ritardo();

        if(a[middle] == valore)
        {
            return middle;
        }
        else
        {
            if(a[middle] < valore)
                first = middle + 1;
            else
                last = middle - 1;
        }
    }

    return -1;
}

void ritardo()
{
    int i, j;

    for(i = 0; i < 1000; i++)
    {
        for(j = 0; j < 100; j++)
            ;
    }
}
