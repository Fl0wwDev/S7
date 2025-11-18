#include <stdio.h>
#include <ctype.h>

int main() {
    int compteur[26] = {0}; 
    int c;
    
    printf("test:\n");
    
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            c = toupper(c);
            compteur[c - 'A']++;
        }
    }
    
    printf("\nNombre d'occurrences de chaque lettre :\n");
    for (int i = 0; i < 26; i++) {
        if (compteur[i] > 0) {
            printf("%c : %d\n", 'A' + i, compteur[i]);
        }
    }
    
    return 0;
}