#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    char chaine[]="abracadabra";
    int i;
    while (chaine[i]!='\0'){
        printf("%c", chaine[i]);
        i++;
    }
    return 0;
}
