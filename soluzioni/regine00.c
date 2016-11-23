/*
 * N regine
*/
#include <stdio.h>
#define N 4             // Dimensione scacchiera

int queen[N];           // casella occupata dalla regina
int row[N];             // riga regina
int col[N];             // colonna regina
int diNOSE[N];          // diagonale Nord Ovest Sud Est
int diNESO[N];          // diagonale Nord Est Sud Ovest
int nSol = 0;           // numero soluzioni
int nAss = 0;           // numero di assegnamenti

/* return 1 se gli n elmenti di v sono tutti diversi */
int tuttiDiversi(int v[], int n){
    int i,j;
    for (i=0;i<n-1;i++)
        for (j=i+1;j<n;j++)
            if (v[i]==v[j])
                return 0;
    return 1;
}

/* return 1 se tutti i vincoli sono soddisfatti */
int vincoliSoddisfatti(){
    if (!tuttiDiversi(row,N))
        return 0;
    if (!tuttiDiversi(col,N))
        return 0;
    if (!tuttiDiversi(diNOSE,N))
        return 0;
    if (!tuttiDiversi(diNESO,N))
        return 0;
    return 1;
}

void stampaSoluzione(){
    int r,c;
    nSol++;
    printf("Soluzione N.ro %d ************\n",nSol);
    for (r=0;r<N;r++) {
        for (c=0;c<N;c++)
            if (presente(r,c))
                printf("* ");
            else
                printf("- ");
        printf("\n");
    }
}

/* return 1 se e' presente una regina in riga r e colonna c */
int presente(int r, int c){
    int q;
    for (q=0;q<N;q++)
        if (row[q]==r && col[q]==c)
            return 1;
    return 0;
}

/* Genera il valore della regina */
void generaValori(int r){
    int i;
    if (r == N) {
        if(vincoliSoddisfatti())
            stampaSoluzione();
    }
    else
        for(i=0;i<N*N;i++) {
            queen[r] = i;
            row[r] = i / N;
            col[r] = i % N;
            diNOSE[r] = col[r] - row[r];
            diNESO[r] = col[r] - (N - row[r]);
            nAss++;
            generaValori(r+1);
        }
}


int main(void)
{
    generaValori(0);
    printf("N.ro assegnamenti %d\n",nAss);
    return 0;
}

