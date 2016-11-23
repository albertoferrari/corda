#include <stdio.h>
#include <stdlib.h>

#define MAX 13



void riempivett(int v[])
{
    int i;
    for(i=1; i < MAX; i++)
    {
        if(i == 5)
            v[i] = 2;
        else
            v[i] = 1;
    }


}

void stampav(int v[])
{
    int i;
    for(i=1; i < MAX; i++)
        printf("Elemento numero %d --->  %d\n",i,v[i]);
}

void elabora(int v[])
{
    int somma1 = v[1] + v[2] + v[3] + v[4];
    int somma2 = v[5] + v[6] + v[7] + v[8];

    printf("1=  %d   2=  %d\n",somma1,somma2);

 //caso uguali
    if(somma1 == somma2)
    {
        somma1 = v[9] + v[10];
        somma2 = v[11] + v[1];

        if(somma1 == somma2)
        {
            if(v[12] == v[1])
                printf("no");
            else if(v[12] > v[1])
                printf("12+");
            else
                printf("12-");
        }

        else if(somma1 > somma2)
        {
            if(v[9] == v[10])
                printf("11-");
            else if(v[9] > v[10])
                printf("9+");
            else
                printf("10+");
        }

        else
        {
            if(v[9] == v[10])
                printf("11+");
            else if(v[9] > v[10])
                printf("10-");
            else
                printf("9-");
        }
    }

//caso maggiore

    else if(somma1 < somma2)
    {
        somma1 = v[1] + v[2] + v[5];
        somma2 = v[3] + v[4] + v[6];

        if(somma1 == somma2)
        {
            if(v[7] > v[8])
                printf("8-");
            else if(v[7] < v[8])
                printf("7-");
        }

        else if(somma1 > somma2)
        {
            if(v[1] == v[2])
                printf("6-");
            else if(v[1] > v[2])
                printf("1+");
            else
                printf("2+");
        }

        else
        {
            if(v[3] == v[4])
                printf("5-");
            else if(v[3] > v[4])
                printf("3+");
            else
                printf("4+");
        }
    }


//caso minore

    else if(somma1 > somma2)
    {
        somma1 = v[1] + v[2] + v[5];
        somma2 = v[3] + v[4] + v[6];

        if(somma1 == somma2)
        {
            if(v[7] > v[8])
                printf("8+");
            else if(v[7] < v[8])
                printf("7+");
        }

        else if(somma1 > somma2)
        {
            if(v[1] == v[2])
                printf("6+");
            else if(v[1] > v[2])
                printf("1-");
            else
                printf("2-");
        }

        else
        {
            if(v[3] == v[4])
                printf("5+");
            else if(v[3] > v[4])
                printf("3-");
            else
                printf("4-");
        }
    }



}
int main()
{
    int v[MAX];

    riempivett(v);
    stampav(v);

    printf("\n\n\n");
    elabora(v);



    return 0;
}

