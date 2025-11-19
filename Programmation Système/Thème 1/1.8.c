#include <stdio.h>


int main(int argc, char const *argv[])
{
    /* code */
    char str[20];

    int mois[12] = {"janvier", "février", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "décembre"};

    for(int i=0; i < 12; i++){
        prinf("%s", mois[i]);
    }
    scanf("%[^\n]%*c", str);
    printf("%s", str);
    return 0;
}
