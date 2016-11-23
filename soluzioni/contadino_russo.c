#include <stdio.h>

/* Calcolo potenza con il metodo del contadino russo */
int potenza(int base, int esp){
    if(esp==0)
        return 1;
    if(esp%2==0)
        return(potenza(base*base,esp/2));
    else
        return(base*potenza(base,esp-1));
}

/* Calcolo del prodotto con il metodo del contadino russo */
int prodotto(int f1, int f2){
    int p = 0;	// conterra' il prodotto
    while (f1>0) {
        if(f1%2==0){
            f1 = f1 / 2;
            f2 = f2 * 2;
        }
        else {
            p = p + f2;
            f1 = f1 - 1;
        }
    }
    return p;
}


int main(void)
{
    int b,e,f1,f2;
    for(b=0;b<10;b++){
        for(e=0;e<10;e++)
            printf("%d elevato %d = %d \n",b,e,potenza(b, e));
        printf("----------------------\n");
    }
    printf("********************************\n");
    for(f1=0;f1<10;f1++){
        for(f2=0;f2<10;f2++)
            printf("%d * %d = %d \n",f1,f2,prodotto(f1, f2));
        printf("----------------------\n");
    }
    return 0;
}

