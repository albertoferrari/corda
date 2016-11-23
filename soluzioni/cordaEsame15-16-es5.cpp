#include<iostream>

using namespace std;

// Costanti per agevolare la lettura del codice
const int NERA = 0, BIANCA = 1;

// Massimo valore di N
const int N_MASSIMO = 100;

// Il parametro N
int N;

// Il vettore che memorizza i colori delle perline
int perline[N_MASSIMO];

// Numero di perline nere (o bianche) lette
int numeroBianche = 0, numeroNere = 0;

// Esegue una mossa partendo da inizio e finendo in fine (o viceversa), estremi inclusi
void eseguiMossa(int inizio, int fine) {
	if(fine < inizio) {
		int t = inizio;

		inizio = fine;

		fine = t;
	}

	cout << (inizio + 1) << " " << (fine + 1) << endl;

	while(fine >= inizio) {
		int t = perline[fine];

		perline[fine] = perline[inizio];

		perline[inizio] = t;

		fine--;

		inizio++;
	}
}

// Cerca una mossa partendo dall'indice inizio
// L'indice inizio corrisponde sempre a un punto di discontinuità nel colore delle perline
void cercaMossa(int inizio) {
	int perlinaIniziale = perline[inizio];

	int i, j;

	// Cerca la posizione della prima perlina di colore diverso da perlinaIniziale
	for(i = 1; i < N; i++) {
		if(perline[(inizio + i) % N] != perlinaIniziale)
			break;
	}

	// Cerca la posizione della prima perlina di colore uguale a perlinaIniziale
	for(j = i + 1; j < N; j++) {
		if(perline[(inizio + j) % N] == perlinaIniziale)
			break;
	}

	// Esegue la mossa trovata
	eseguiMossa(inizio, (inizio + j - 1) % N);
}

// Indica se la sequenza di perline è ordinata
bool perlineOrdinate(int inizio) {
	int perlinaIniziale = perline[inizio];

	int i;

	for(i = 1; i < N; i++) {
		if(perline[(inizio + i) % N] != perlinaIniziale)
			break;
	}

	// Le perline sono ordinate?
	if(perlinaIniziale == NERA && i == numeroNere)
		return true;

	if(perlinaIniziale == BIANCA && i == numeroBianche)
		return true;

	return false;
}

// Cerca il primo indice nel vettore in cui cambia il colore delle perline
int cercaInizio() {
	int i;

	for(i = 1; i < N; i++)
		if(perline[i] != perline[0])
			break;

	return i;
}

// Legge i valori in input
void leggiValori() {
	cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> perline[i];

		if(perline[i] == NERA)
			numeroNere++;
		else
			numeroBianche++;
	}
}

// Funzione principale
int main() {
	leggiValori();

	if(numeroNere == 0 || numeroBianche == 0)
		return EXIT_SUCCESS;

	int i = cercaInizio();

	while(!perlineOrdinate(i)) {
		cercaMossa(i);

		i = cercaInizio();
	}

	return EXIT_SUCCESS;
}
