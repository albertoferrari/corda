#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
  int inf;
  struct elemento *succ;
} Nodo;

typedef struct Coda {
    Nodo *ingresso;
    Nodo *uscita;
} Coda;

Coda inizializza() {
    Coda c;
    c.ingresso = NULL;
    c.uscita = NULL;
    return c;
}

int vuota(Coda c) {
    if (c.ingresso == NULL)
        return 1;
    return 0;
}

Coda inserisci(Coda c, int valore){
    Nodo *temp;
    temp = malloc(sizeof(Nodo));
    temp->inf = valore;
    temp->succ = NULL;
    if (vuota(c)) {
        c.uscita = temp;
        c.ingresso = temp;
        return c;
    }
    c.ingresso->succ = temp;
    c.ingresso = temp;
    return c;
}

void stampa(Coda c){
    Nodo *temp;
    temp = c.uscita;
    while(temp != NULL){
        printf(" %d ",temp->inf);
        temp = temp->succ;
    }
    printf("\n");
}

Coda elimina(Coda c){
    if (vuota(c))
        return c;
    if (c.ingresso == c.uscita) {
        free(c.ingresso);
        c.ingresso = NULL;
        c.uscita = NULL;
        return c;
    }
    Nodo *temp;
    temp = c.uscita;
    c.uscita = c.uscita->succ;
    free(temp);
    return c;
}

int main(void)
{
    Coda miaCoda;
    Nodo *elemento;
    miaCoda = inizializza();
    miaCoda = inserisci(miaCoda,10);
    miaCoda = inserisci(miaCoda,5);
    miaCoda = inserisci(miaCoda,20);
    stampa(miaCoda);
    miaCoda = elimina(miaCoda);
    stampa(miaCoda);
    miaCoda = elimina(miaCoda);
    stampa(miaCoda);
}

