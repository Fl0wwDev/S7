#include <stdio.h>

int main() {
    FILE *file = fopen("toto", "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    int ch;
    while ((ch = getc(file)) != EOF) {
        printf("test");
        putchar(ch);
    }

    FILE *file2 = fopen("titi", "w");
    if (file2 == NULL) {
        perror("");
        return 1;
    }

    fclose(file);
    fclose(file2);
    return 0;
}