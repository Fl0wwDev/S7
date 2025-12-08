#include <stdio.h>

#define MAX_LONGUEUR 1000

int main() {
    char chaine1[MAX_LONGUEUR];
    char chaine2[MAX_LONGUEUR];
    
    printf("Entrez la première chaîne :\n");
    fgets(chaine1, MAX_LONGUEUR, stdin);
    
    printf("Entrez la deuxième chaîne :\n");
    fgets(chaine2, MAX_LONGUEUR, stdin);
    
    int i = 0, j = 0;
    int trouve = 0;
    
    while (chaine1[i] != '\0') {
        if (chaine1[i] == chaine2[j]) {
            j++;
            if (chaine2[j] == '\n' || chaine2[j] == '\0') {
                trouve = 1;
                break;
            }
        } else {
            i -= j;
            j = 0;
        }
        i++;
    }
    
    if (trouve) {
        printf("\nLa deuxième chaîne fait partie de la première.\n");
    } else {
        printf("\nLa deuxième chaîne ne fait pas partie de la première.\n");
    }
    
    return 0;
}