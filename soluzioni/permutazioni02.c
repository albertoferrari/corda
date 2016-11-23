#include <stdio.h>
#include <stdlib.h>

int allDifferent(int v[],int n){
    int i,j;
    for (i=0;i<n-1;i++)
        for (j=i+1;j<n;j++)
            if (v[i]==v[j])
                return 0;
    return 1;
}

int main(void)
{
    char a[4] = {'A','B','C','D'};
    int p[4];
    for (p[0]=0;p[0]<4;p[0]++)
        for (p[1]=0;p[1]<4;p[1]++)
            for (p[2]=0;p[2]<4;p[2]++)
                for (p[3]=0;p[3]<4;p[3]++)
                    if(allDifferent(p,4))
                        printf("%C%C%C%C\n",a[p[0]],a[p[1]],a[p[2]],a[p[3]]);
    return 0;
}

