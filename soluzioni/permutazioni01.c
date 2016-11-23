#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[4] = {'A','B','C','D'};
    int i1,i2,i3,i4;
    for (i1=0;i1<4;i1++)
        for (i2=0;i2<4;i2++)
            for (i3=0;i3<4;i3++)
                for (i4=0;i4<4;i4++)
                    if(i1!=i2 && i1!=i3 && i1!=i4 &&i2!=i3 && i2!=i4 &&i3!=i4)
                        printf("%C%C%C%C\n",a[i1],a[i2],a[i3],a[i4]);
    return 0;
}
