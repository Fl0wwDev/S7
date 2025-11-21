#include <stdio.h>

int main() {
    FILE *file = fopen("toto", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int ch;
    while ((ch = getc(file)) != EOF) {
        printf("test");
        putchar(ch);
    }

    fclose(file);
    return 0;
}