/*
 * Soluzione Sudoku
 * CSP
*/
#include <stdio.h>

/* griglia sudoku risolto */
int grid[81] =       {1,6,4,5,2,9,7,8,3,
                      8,3,9,7,1,4,2,6,5,
                      2,5,7,6,3,8,9,4,1,
                      6,2,1,9,4,5,8,3,7,
                      4,9,3,8,7,2,5,1,6,
                      7,8,5,1,6,3,4,2,9,
                      9,4,6,2,5,1,3,7,8,
                      3,1,8,4,9,7,6,5,2,
                      5,7,2,3,8,6,1,9,4};

/* 1 valore predefinito */
int fix[81] =        {1,1,0,0,0,0,0,0,0,
                      0,0,1,0,0,1,0,1,1,
                      0,1,1,1,0,1,1,1,0,
                      0,0,0,1,0,0,0,1,0,
                      0,0,0,1,1,1,0,0,0,
                      0,1,0,0,0,0,0,0,0,
                      0,1,1,1,0,1,1,1,0,
                      1,1,0,1,0,0,1,0,0,
                      0,0,0,0,0,0,0,1,1};


int foundSol = 0;       // soluzione non trovata

/* return 1 se è ammissibile inserire il valore val nella cella nCel*/
int possibile(int val, int nCel){
    int cel;
    int r,c,reg;                // riga, colonna e regione della cella
    int rc,cc,regc;             // riga, colonna e regione della cella analizzata
    r = nCel / 9;
    c = nCel % 9;
    reg = 3 * (r/3) + (c/3);
    for (cel=0;cel<81;cel++) {
        if (nCel != cel && grid[cel] == val) {      // se altra cella ha lo stesso valore
            rc = cel / 9;                           // verifica riga, colonna, regione
            cc = cel % 9;
            regc = 3 * (rc/3) + (cc/3);
            if (rc == r || cc == c || regc == reg){ // conflitto di vincoli
                return 0;
            }
        }
    }
    return 1;
}

/* return 1 se i vincoli sono soddisfatti per tutte le celle valorizzate */
int ammissibile(){
    int cel;
    for (cel=0;cel<81;cel++) {
        if (grid[cel]!=0)       // cella valorizzata
            if (!possibile(grid[cel],cel))
                return 0;
    }
    return 1;
}

void stampaSudoku(){
    printf("----------------------------\n");
    int r,c;
    for (r=0;r<9;r++) {
        for (c=0;c<9;c++)
            printf(" %d ",grid[9*r + c]);
        printf("\n");
    }
    printf("----------------------------\n");
}

/* Genera i valori iniziali eliminando i valori delle celle non fissate*/
void generaValoriIniziali(){
    int cel;
    for (cel=0;cel<81;cel++) {
        if (fix[cel]==0)            // Eliminazione valori non prefissati
            grid[cel]=0;
    }
}

/* 1 se esiste una soluzione partendo dalla cella cel */
int esisteSoluzione(int cel) {
    if (foundSol)
        return 1;               // gia' trovata altra soluzione
    if (cel==81) {              // soluzione trovata!
        stampaSudoku();
        foundSol = 1;
        return 1;
    }
    if (fix[cel]==1)            // cella con valore prefissato
        return esisteSoluzione(cel+1);
    int val;
    int sol = 0;                // soluzione al momento non trovata
    for (val=1;val<=9;val++) {
        if (possibile(val,cel)) {   // valore accettabile
            grid[cel] = val;        // inserito nella cella
            if (esisteSoluzione(cel+1))
                sol = 1;
        }
    }
    if (!sol) {
       grid[cel] = 0;
       return 0;                // ramo senza soluzioni
    }
    return 1;
}

int main(void)
{
    printf("Soluzione predefinita\n");
    stampaSudoku();
    generaValoriIniziali();             // Elimina valori dalle celle non prefissate
    printf("Situazione di partenza\n");
    stampaSudoku();
    printf("Soluzione trovata\n");
    if (!esisteSoluzione(0))
        printf("Sudoku non risolto\n");
    return 0;
}
