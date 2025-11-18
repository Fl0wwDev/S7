#include <stdio.h>
#include <string.h>

#define MAX_LONGUEUR 1000

int main() {
    char chaine1[MAX_LONGUEUR];
    char chaine2[MAX_LONGUEUR];
    
    printf("Entrez une chaîne de caractères :\n");
    
    if (fgets(chaine1, MAX_LONGUEUR, stdin) != NULL) {
        strcpy(chaine2, chaine1);
        
        printf("\nChaîne copiée : ");
        puts(chaine2);
        printf("Longueur : %zu\n", strlen(chaine2) - 1);
    }
    
    return 0;
}