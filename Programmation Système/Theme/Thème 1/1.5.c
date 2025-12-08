#include <stdio.h>

#define MAX_LIGNES 10
#define MAX_LONGUEUR 1000

int main() {
    char lignes[MAX_LIGNES][MAX_LONGUEUR];
    int nb_lignes = 0;
    int c, pos = 0;
    
    while ((c = getchar()) != EOF && nb_lignes < MAX_LIGNES) {
        if (c == '\n') {
            lignes[nb_lignes][pos] = '\0';
            nb_lignes++;
            pos = 0;
        } else if (pos < MAX_LONGUEUR - 1) {
            lignes[nb_lignes][pos++] = c;
        }
    }
    
    printf("\nLes 10 dernières lignes :\n");
    for (int i = 0; i < nb_lignes; i++) {
        puts(lignes[i]);
    }
    
    return 0;
}