#include <stdio.h>


int MESI[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int sol1(int g1, int m1, int g2, int m2) {
    if (m1 == m2)
        return (g2 - g1);
    int n = MESI[m1] - g1;
    m1++;
    while (m1 < m2) {
        n += MESI[m1];
        m1++;
    }
    n += g2;
    return n;
}

int gg(int g, int m) {
    for (m-- ; m >= 1 ; m--)
        g += MESI[m];
    return g;
}

int sol2(int g1, int m1, int g2, int m2) {
    return gg(g2, m2) - gg(g1, m1);
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int g1, m1, g2, m2;
    fscanf(fin, "%d %d %d %d", &g1, &m1, &g2, &m2);
    fprintf(fout, "%d", sol1(g1, m1, g2, m2));

    for (m1 = 1 ; m1 <= 12 ; m1++)
        for (m2 = m1 ; m2 <= 12 ; m2++)
            for (g1 = 1 ; g1 <= MESI[m1] ; g1++)
               for (g2 = (m1 < m2 ? 1 : g1) ; g2 <= MESI[m2] ; g2++)
                   if (sol1(g1, m1, g2, m2) != sol2(g1, m1, g2, m2)) {
                      printf("ERRORE %d, %d %d %d\n", g1,m1,g2,m2);
                      return 0;
                   }
    printf("OK\n");

    fclose(fin);
    fclose(fout);
    return 0;
}
