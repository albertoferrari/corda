/*
 * Esempio di soluzione di un problema di soddisfacimento vincoli
 * "Assegnare un valore numerico a ogni lettera in modo che sia soddisfatta la condizione:
 * COCA + COLA = OASIS
 * valori delle variabili tutti diversi
 * intervallo dei valori 0..9
 * O diverso da 0
*/

#include <stdio.h>
#define DIM 7		// numero variabili
#define MAXVAL 9	// valori 0..9

int valVar[DIM]; 	// rappresentano le variabili C, A, L, S, I, O
char nomeVar[DIM] = {'D','U','E','N','O','T','R'};
int numeroSoluzioni = 0;
/* return 1 se valVar contiene valori tutti diversi */
int tuttiDiversi(){
    int i,j;
    for (i=0;i<DIM-1;i++)
        for (j=i+1;j<DIM;j++)
            if (valVar[i]==valVar[j])
                return 0;
    return 1;
}

/* return 1 se tutti i vincoli sono soddisfatti */
int vincoliSoddisfatti(){
    int d,u,e,n,o,t,r;    // valori assegnati alle variabili
    int r1,r2;       // riporti
    d = valVar[0]; u = valVar[1]; e = valVar[2]; n = valVar[3]; o = valVar[4]; t = valVar[5], r =valVar[6];
    if (d==0 || u==0 || t==0)   // D,U,T ≠ 0
        return 0;
    if (!tuttiDiversi()) // C≠O≠A≠L≠S≠I
        return 0;
    if (e != (e + o) % 10)
        return 0;
    r1 = (e + o) / 10;
    if (r != (r1 + u + n) % 10)
        return 0;
    r2 = (r1 + u + n) / 10;
    if (t != (r2 + d + u) % 10)
        return 0;
    numeroSoluzioni++;
    return 1;
}

/* stampa una soluzione trovata */
void stampaSoluzione(){
    int i;
    for (i=0;i<DIM;i++)
        printf("'%c' = %d  ", nomeVar[i],valVar[i]);
    printf("\n");
}

/* genera tutte le combinazioni di valori delle variabili
 * se i vincoli sono soddifatti stampa la soluzione */
void generaValori(int indice){
    int i;
    if (indice == DIM) {
        if(vincoliSoddisfatti())
            stampaSoluzione();
    }
    else
        for(i=0;i<=MAXVAL;i++) {
            valVar[indice]=i;
            generaValori(indice+1);
        }
}

int main(void)
{
    generaValori(0);
    printf("soluzioni trovate >> %d",numeroSoluzioni);
    return 0;
}

