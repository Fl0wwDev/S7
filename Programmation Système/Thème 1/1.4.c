#include <stdio.h>
#include <ctype.h>

int main() {
    int c;
    int dans_mot = 0;
    
    printf("text:\n");
    
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            if (!dans_mot) {
                if (dans_mot) {
                    putchar('\n');
                }
                dans_mot = 1;
            }
            putchar(c);
        } else {
            if (dans_mot) {
                putchar('\n');
                dans_mot = 0;
            }
        }
    }
    
    if (dans_mot) {
        putchar('\n');
    }
    
    return 0;
}