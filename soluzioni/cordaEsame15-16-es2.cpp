#include<iostream>

using namespace std;

// Lunghezza (nota) del vettore che memorizza il triangolo
const int LUNGHEZZA_TRIANGOLO = 15;

// Vettore che memorizza il triangolo
int triangolo[LUNGHEZZA_TRIANGOLO];

// Calcola l'indice nel vettore dell'elemento in basso a sinistra
int indiceBassoSinistra(int livello, int indice) {
	return indice + (livello + 1);
}

// Calcola l'indice nel vettore dell'elemento in basso a destra
int indiceBassoDestra(int livello, int indice) {
	return indice + (livello + 1) + 1;
}

// Calcola il massimo della somma partendo da un livello e da un indice
int massimo(int livello, int indice) {
	// Indice massimo possibile
	if(livello == 4)
		return triangolo[indice];

	// Indice dell'elemento in basso a sinistra
	int s = indiceBassoSinistra(livello, indice);

	// Massimo della somma del percorso che passa per l'elemento in basso a sinistra
	int ms = triangolo[indice] + massimo(livello + 1, s);

	// Indice dell'elemento in basso a destra
	int d = indiceBassoDestra(livello, indice);

	// Massimo della somma del percorso che passa per l'elemento in basso a destra
	int md = triangolo[indice] + massimo(livello + 1, d);

	if(md > ms)
		return md;

	return ms;
}

// Legge il triangolo
void leggiTriangolo() {
	for(int i = 0; i < LUNGHEZZA_TRIANGOLO; i++)
		cin >> triangolo[i];
}

// Funzione principale
int main() {
	leggiTriangolo();

	int m = massimo(0, 0);

	cout << m << endl;

	return EXIT_SUCCESS;
}
