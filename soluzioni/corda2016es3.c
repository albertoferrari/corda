#include <stdio.h>

int main(void)
{
    int i,j,n,k;
    int v[100];
    printf("Lunghezza sequenza: ");
    scanf("%d",&n);
    printf("Lunghezza sottosequenza: ");
    scanf("%d",&k);
    for (i=0;i<n;i++)
        scanf("%d",&v[i]);
    int seqMax = v[0];
    for (j=1;j<k;j++)
        seqMax += v[j];     // prima sequenza di k elementi è massima
    int seq;
    for(i=1;i<=n-k;i++) {
        seq = v[i];
        for (j=1;j<k;j++)
            seq += v[i+j];     // valore sequenza
        if (seq > seqMax)
            seqMax = seq;
    }
    printf("Valore massimo sottosequenza di %d elementi = %d\n",k,seqMax);
    return 0;
}

