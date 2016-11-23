/*
 * N regine
*/
#include <stdio.h>
#define N 12             // Dimensione scacchiera

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

/* return 1 se tutti i vincoli sono soddisfatti nei primi n elementi dell'array*/
int vincoliSoddisfatti(int n){
    if (!tuttiDiversi(col,n))
        return 0;
    if (!tuttiDiversi(diNOSE,n))
        return 0;
    if (!tuttiDiversi(diNESO,n))
        return 0;
    return 1;
}

void stampaSoluzione(){
    int r,c;
    nSol++;
    printf("Soluzione N.ro %d ************\n",nSol);
    for (r=0;r<N;r++) {
        for (c=0;c<N;c++)
            if (c == col[r])
                printf("* ");
            else
                printf("- ");
        printf("\n");
    }

}

/* Genera il valore della regina in riga row */
void generaValori(int row){
    int c;
    if (row == N) {
        // if(vincoliSoddisfatti(row))
            stampaSoluzione();
    }
    else
        for(c=0;c<N;c++) {
            col[row] = c;
            diNOSE[row] = c - row;
            diNESO[row] = c - (N - row);
            if (vincoliSoddisfatti(row+1)) {
                nAss++;
                generaValori(row+1);
            }


        }
}


int main(void)
{
    generaValori(0);
    printf("N.ro assegnamenti %d\n",nAss);
    return 0;
}

