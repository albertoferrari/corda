#include <stdio.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    char input[100000];
    int i = 0, ns = 0, eo = 0;
    fscanf(fin, "%s", input);
    while (input[i] != '*') {
        switch (input[i]) {
            case 'N': ns++; break;
            case 'S': ns--; break;
            case 'E': eo++; break;
            case 'O': eo--; break;
        }
        i++;
    }
    fprintf(fout, "%d", ns*ns + eo*eo);
    fprintf(fout,"\nOK\n");
    fclose(fin);
    fclose(fout);
    return 0;
}
