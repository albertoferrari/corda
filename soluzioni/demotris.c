


/*
  Copyright (C) 2014 Alessandro Bugatti (alessandro.bugatti@istruzione.it)

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/*! \file
 *  \brief Semplice implementazione della metodologia MiniMax applicata la gioco del tris
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione  21/05/2014
 *  \date  Ultima modifica 21/05/2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct mossa{
    int riga;
    int colonna;
};

int tris[3][3];
struct mossa da_fare; //La mossa da fare dopo ogni scelta minimax

//Converte i numeri nella matrice nei segni grafici desiderati
//Se si vogliono cambiare i simboli basta modificare qui
char conversione(int n)
{
    if (n == 0) return ' ';
    if (n == 1) return 'x';
    if (n == -1) return 'o';
}

/*Stampa della griglia*/
void stampa_griglia()
{
    int i;
    char c1,c2,c3;
    printf("\t\t\t\t***** TRIS *****\n\n");
    for (i=0 ; i < 3 ; i++)
    {
        c1 = conversione( tris[i][0]);
        c2 = conversione( tris[i][1]);
        c3 = conversione( tris[i][2]);
        printf("\t  %c | %c | %c \n", c1,c2,c3);
        if (i!= 2) printf("\t -----------\n");
    }
}

//Cambia il turno da 1 a -1 e viceversa
int cambio_turno(int turno)
{
    return -turno;
}

//Controlla se la mossa è corretta
//Restituisce 1 se lo è, 0 altrimenti
int mossa_corretta(int x, int y)
{
    if ( (x < 1 || x > 3) || (y < 1 || y > 3) || tris[x-1][y-1] != 0)
        return 0;
    return 1;
}

//Controlla se il gioco è finito
int finito()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tris[i][j] == 0)
                return 0;
    return 1;
}

//controlla se qualcuno ha vinto
//Ritorna 1 se ha vinto il giocatore 1, -1 se ha vinto il giocatore -1,
//0 se nessuno ha vinto e la partita è finita, 2 se la partita è ancora in corso

int controlla_vittoria()
{
    int i;
    //Controllo le righe
    for (i=0 ; i < 3 ; i++)
        if (tris[i][0]!=0 && tris[i][0]==tris[i][1] && tris[i][1]==tris[i][2])
            return tris[i][0];
    //Controllo le colonne
    for (i=0 ; i < 3 ; i++)
        if (tris[0][i]!=0 && tris[0][i]==tris[1][i] && tris[1][i]==tris[2][i])
            return tris[0][i];
    //Controllo le diagonali
    if (tris[0][0]!=0 && tris[0][0]==tris[1][1] && tris[1][1]==tris[2][2])
        return tris[0][0];
    if (tris[0][2]!=0 && tris[0][2]==tris[1][1] && tris[1][1]==tris[2][0])
        return tris[0][2];
    if (finito())
        return 0;
    return 2;
}


//Funzione minimax, i giocatori sono indicati con 1 e -1
int minimax(int giocatore)
{
    int valore;
    //Se la situazione è valutabile ritorna il valore
    //1 vince il giocatore 1
    //-1 vince il giocatore -1
    //0 pareggio
    if ((valore = controlla_vittoria()) != 2)
        return valore;
    int mossa_migliore;
    int i,j;
    mossa c;
    //Inizializzo la mossa migliore con un valore che è sicuramente
    //perdente per entrambi, in modo che venga sostituito da valori
    //migliori
    mossa_migliore = (giocatore == 1) ? -2 : 2;
    //Provo tutte le mosse
    for ( i = 0; i < 3; i++)
        for ( j = 0; j < 3; j++)
        {
            //Se qualche casella è già occupata non viene provata
            if (mossa_corretta(i+1,j+1))
            {
                //Segno la mossa che sto provando
                tris[i][j] = giocatore;
                //Calcolo ricorsivamente il valore della posizione
                //chiamandola sull'altro giocatore
                valore = minimax(cambio_turno(giocatore));
                //Se sono il giocatore 1 cerco di massimizzare
                if (giocatore == 1 && valore > mossa_migliore)
                {
                    c.riga = i;
                    c.colonna = j;
                    mossa_migliore = valore;
                }
                //Se sono il giocatore -1 cerco di minimizzare
                if (giocatore == -1 && valore < mossa_migliore)
                {
                    c.riga = i;
                    c.colonna = j;
                    mossa_migliore = valore;
                }
                //Faccio backtracking
                tris[i][j] = 0;
            }
        }
   //Segno nella variabile globale la mossa da fare
   da_fare = c;
   //Ritorno il valore della posizione
   return mossa_migliore;
}

int main()
{
    char nomi[2][20], prima_mossa[20];
    int riga, colonna, turno=1, mosse = 0, errore, vittoria = 0;
    int computer;
    vittoria = controlla_vittoria();
    strcpy(nomi[0],"Computer");
    printf("Nome giocatore: ");
    scanf("%s", nomi[1]);
    printf("Vuoi fare la prima mossa (s/n): ");
    scanf("%s",prima_mossa);
    if (strcmp(prima_mossa,"s")==0)
        computer = -1;
    else
        computer = 1;
    /*Riempimento griglia*/
    for (riga=0 ; riga < 3 ; riga++)
        for (colonna=0 ; colonna<3 ; colonna++)
            tris[riga][colonna] = 0;
    while (vittoria == 2) {
        stampa_griglia();
        if (turno == computer)
        {
            minimax(turno);
            tris[da_fare.riga][da_fare.colonna] = turno;
        }
        else
        /*Acquisizione coordinate*/
        do {
            errore = 0;
            printf("Gioca %s\n", nomi[1]);
            printf("Numero di riga : ");
            scanf("%d", &riga);
            printf("Numero di colonna : ");
            scanf("%d", &colonna);
            if (mossa_corretta(riga,colonna)==0) {
                printf("POSIZIONE ERRATA!!\n");
                putchar('\a');
                errore = 1;
            }
            else  tris[riga-1][colonna-1] = turno;
        } while (errore == 1);
        /*Controlli*/
        vittoria = controlla_vittoria();
        turno = cambio_turno(turno);
        mosse++;
    }
    /*Visualizza risultati*/
    stampa_griglia();
    if (vittoria == 0)
        printf("Partita patta.\n");
    else
        printf("Ha vinto %s\n",nomi[abs(vittoria-1)/2]);
    return 0;
}
