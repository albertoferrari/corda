/*
 * Esempio di soluzione di un problema di soddisfacimento vincoli
 * "Assegnare un valore numerico a ogni lettera in modo che sia soddisfatta la condizione:
 * COCA + COLA = OASIS
 * valori delle variabili tutti diversi
 * intervallo dei valori 0..9
 * O diverso da 0
*/

#include <stdio.h>
#define DIM 6		// numero variabili
#define MAXVAL 9	// valori 0..9

int valVar[DIM]; 	// rappresentano le variabili C, A, L, S, I, O
char nomeVar[DIM] = {'C','A','L','S','I','O'};

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
    int c,a,l,s,i,o;    // valori assegnati alle variabili
    int r1,r2,r3;       // riporti
    c = valVar[0]; a = valVar[1]; l = valVar[2]; s = valVar[3]; i = valVar[4]; o = valVar[5];
    if (o==0)   // O ≠ 0
        return 0;
    if (!tuttiDiversi()) // C≠O≠A≠L≠S≠I
        return 0;
    if (s != (a + a) % 10)
        return 0;
    r1 = (a + a) / 10;
    if (i != (r1 + c + l) % 10)
        return 0;
    r2 = (r1 + c + l) / 10;
    if (s != (r2 + o + o) % 10)
        return 0;
    r3 = (r2 + o + o) / 10;
    if (a != (r3 + c + c) % 10)
        return 0;
    if (o != (r3 + c + c) / 10)
        return 0;
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
    return 0;
}

