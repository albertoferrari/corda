#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
  int inf;
  struct elemento *succ;
} Nodo;

typedef Nodo *Lista;

Lista inizializza() {
    return NULL;
}

int vuota(Lista l) {
    if (l==NULL)
        return 1;
    return 0;
}

Lista inserisciTesta(Lista l, int valore){
    Nodo *temp;
    temp = malloc(sizeof(Nodo));
    temp->inf = valore;
    temp->succ = l;
    return temp;
}

Lista inserisciCoda(Lista l, int valore){
    if (vuota(l))
        return inserisciTesta(l,valore);
    Nodo *temp;
    temp = l;
    while(temp->succ != NULL)
        temp = temp->succ;
    Nodo *nuovoElemento;
    nuovoElemento = malloc(sizeof(Nodo));
    nuovoElemento->inf = valore;
    nuovoElemento->succ = NULL;
    temp->succ = nuovoElemento;
    return l;
}

void stampa(Lista l){
    Nodo *temp;
    temp = l;
    while(temp != NULL){
        printf(" %d ",temp->inf);
        temp = temp->succ;
    }
    printf("\n");
}

Lista ricerca(Lista l, int valore){
    Nodo *temp;
    temp = l;
    while(temp != NULL) {
        if (temp->inf == valore)
            return temp;
        temp = temp->succ;
    }
    return NULL;
}

Lista eliminaTesta(Lista l){
    if (vuota(l))
        return NULL;
    Nodo *temp;
    temp = l;
    l = l->succ;
    free(temp);
    return l;
}

Lista eliminaCoda(Lista l){
    if (vuota(l))
        return NULL;
    if (l->succ == NULL)
        return eliminaTesta(l);
    Nodo *penultimo;
    Nodo *ultimo;
    penultimo = l;
    ultimo = penultimo->succ;
    while(ultimo->succ != NULL) {
        penultimo = ultimo;
        ultimo = ultimo->succ;
    }
    free(ultimo);
    penultimo->succ = NULL;
    return l;
}

int main(void)
{
    Lista miaLista;
    Nodo *elemento;
    miaLista = inizializza();
    miaLista = inserisciCoda(miaLista,10);
    miaLista = inserisciTesta(miaLista,5);
    miaLista = inserisciTesta(miaLista,8);
    miaLista = inserisciCoda(miaLista,50);
    stampa(miaLista);
    elemento = ricerca(miaLista,5);
    if (elemento != NULL)
        printf("trovato il valore %d \n", elemento->inf);
    miaLista = eliminaTesta(miaLista);
    miaLista = eliminaTesta(miaLista);
    stampa(miaLista);
    miaLista = eliminaCoda(miaLista);
    stampa(miaLista);
    miaLista = eliminaCoda(miaLista);
}

