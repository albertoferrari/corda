#include<iostream>

using namespace std;

// Legge un (sotto)albero
// profonditaCorrente è il valore attuale della profondità dell'albero letto
int leggiAlbero(int profonditaCorrente) {
	int figli;

	cin >> figli;

	int profondita = profonditaCorrente;

	for(int i = 0; i < figli; i++) {
		int p = leggiAlbero(profonditaCorrente + 1);

		if(p > profondita)
			profondita = p;
	}

	return profondita;
}

// Funzione principale
int main() {
	int profondita = leggiAlbero(0);

	cout << profondita << endl;

	return EXIT_SUCCESS;
}
