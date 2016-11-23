#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/timeb.h>

int main(void)
{
    struct timeb start,end;
    ftime(&start);
    long i,j;
    for(i=0;i<1000000;i++)
        for(j=0;j<1000;j++)
            ;
    ftime(&end);

    printf("start.time     = %ld (seconds)", start.time);
    printf(" - start.millitm  = %d (mlliseconds)\n", start.millitm);

    printf("end.time       = %ld (seconds)", end.time);
    printf(" - end.millitm    = %d (mlliseconds)\n", end.millitm);

    return EXIT_SUCCESS;
}
