#include <stdio.h>

// Ritorna true se Q è primo, false altrimenti
unsigned primo(unsigned Q) {
    if (Q < 2)
        return 0;
    for (unsigned divisore = 2; divisore < Q; ++divisore)
        if (Q % divisore == 0)
            return 0;
    return 1;
}


// Ritorna true se Q è primo, false altrimenti
unsigned primo_migliorato(unsigned Q) {
    if (Q < 2)
        return 0;
    for (unsigned divisore = 2; divisore * divisore <= Q; ++divisore)
        if (Q % divisore == 0)
            return 0;
    return 1;
}

// Ritorna il più piccolo divisore primo di N
unsigned trova_D(unsigned N) {
    for (unsigned D = 2; D <= N; ++D)
        if (N % D == 0)
    return D;
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    unsigned N;
    fscanf(fin, "%u", &N);
    unsigned D = trova_D(N);
    if (primo_migliorato(N/D))
        fprintf(fout, "%u %u",D,N/D);
    else
        fprintf(fout, "%d",-1);
    fclose(fin);
    fclose(fout);
    return 0;
}
