/*
 * Assegnare un valore numerico a ogni lettera in modo che sia soddisfatta la condizione:
 * COCA + COLA = OASIS
 * valori delle variabili tutti diversi
 * intervallo dei valori 0..9
 * O diverso da 0
*/
#include <stdio.h>
int main(){
    int o,a,c,l,i,s;
    for(o=1; o<10; o++)
    {
        for(a=0; a<10; a++)
        {
            for(c=0; c<10; c++)
            {
                for(l=0; l<10; l++)
                {
                    for(i=0; i<10; i++)
                    {
                        for(s=0; s<10; s++)
                        {
                            if((2*a)%10==s && (c+l+((2*a)/10))==i && (2*o+(c+l+(2*a/10))/10)%10==s && (2*c)%10==a && ((2*c)/10)==o)
                                printf("o=%d \na=%d \nc=%d \nl=%d \ni=%d \ns=%d\n\n",o,a,c,l,i,s);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
