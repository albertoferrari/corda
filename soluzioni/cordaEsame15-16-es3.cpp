#include<iostream>

using namespace std;

// Massimo valore di N
const int N_MASSIMO = 100;

// I parametri del problema
int N, K;

// Vettore che memorizza i valori letti
int vettore[N_MASSIMO];

// Calcola il massimo delle somme di tutte le sottosequenze che partono da un indice maggiore o uguale a inizio
int massimo(int inizio) {
	// Valore della somma della sottosequenza che parte da inizio
	int m = 0;

	// Calcola la somma della sottosequenza che parte da inizio
	for(int i = 0; i < K; i++)
		m = m + vettore[inizio + i];

	// Esiste una sottosequenza che inizia da (inizio + 1)?
	if(inizio + K == N)
		return m;

	// Calcola il massimo delle somme di tutte le sottosequenze che partono da un indice maggiore o uguale a (inizio + 1)
	int ms = massimo(inizio + 1);

	// Ritorna il massimo tra m e ms
	if(m > ms)
		return m;

	return ms;
}

// Legge i parametri e i valori
void leggiValori() {
	cin >> N;

	cin >> K;

	for(int i = 0; i < N; i++)
		cin >> vettore[i];
}

// Funzione principale
int main() {
	leggiValori();

	int m = massimo(0);

	cout << m << endl;

	return EXIT_SUCCESS;
}
