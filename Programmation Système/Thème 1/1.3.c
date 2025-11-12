#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    char chaine[]="TEST TEST TEST TEST TEST LIBEREZ MOIIII";
    int i;
    while (chaine[i]!='\0'){
        printf("%c", chaine[i]);
        i++;
    }
    return 0;
}
