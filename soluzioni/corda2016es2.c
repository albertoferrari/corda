#include <stdio.h>

int max(int a,int b){
    if (a>b)
        return a;
    return b;
}

int main(void)
{
    int i;
    int v[15];
    // int v[] = {7,3,8,8,1,0,2,7,4,4,4,5,2,6,5};
    for (i=0;i<15;i++)
        scanf("%d",&v[i]);
    v[9] += max(v[13],v[14]);
    v[8] += max(v[12],v[13]);
    v[7] += max(v[11],v[12]);
    v[6] += max(v[10],v[11]);
    v[5] += max(v[8],v[9]);
    v[4] += max(v[7],v[8]);
    v[3] += max(v[6],v[7]);
    v[2] += max(v[4],v[5]);
    v[1] += max(v[3],v[4]);
    v[0] += max(v[1],v[2]);
    printf("%d\n",v[0]);
    /*
    for (i=0;i<15;i++)
        printf("v[%d]=%d\n",i,v[i]);
    */
    return 0;
}

