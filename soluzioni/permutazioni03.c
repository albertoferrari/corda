#include <stdio.h>
#include <stdlib.h>

#define DIM 4

/* Elabora (stampa) l'array v di n elementi */
void elabora(char v[],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%c ",v[i]);
    printf("\n");
}

/* Scambia gli elementi x e y dell'array v */
void scambia(char v[],int x, int y){
    int temp;
    temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}

/* Elabora le permutazioni dell'array v di n elementi
 * scambiando l'elemento di indice pos coi precedenti
*/
void permuta(char v[],int pos,int n){
    int k;
    if(pos>0) {
        for (k=pos;k>=0;k--){
            scambia(v,k,pos);
            permuta(v,pos-1,n);
            scambia(v,k,pos);
        }
    } else
        elabora(v,n);
}


int main(void) {
    char a[DIM] = {'A','B','C','D'};
    permuta(a,DIM-1,DIM);
    return 0;
}
