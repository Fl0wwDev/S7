#include <stdio.h>
#include <string.h>

struct mois {
    char nom[10];  
    int jours; 
};

int main() {
    const struct mois mois_annee[12] = {
        {"janvier", 31},
        {"fevrier", 28},
        {"mars", 31},
        {"avril", 30},
        {"mai", 31},
        {"juin", 30},
        {"juillet", 31},
        {"aout", 31},
        {"septembre", 30},
        {"octobre", 31},
        {"novembre", 30},
        {"decembre", 31}
    };
    
    char saisie[20];
    int trouve = 0;
    
    printf("met mois");
    scanf("%s", saisie);
    
    for (int i = 0; i < 12; i++) {
        if (strcmp(saisie, mois_annee[i].nom) == 0) {
            printf("mois : %d\n", i + 1);
            printf("jours : %d\n", mois_annee[i].jours);
            trouve = 1;
            break;
        }
    }
    
    if (!trouve) {
        printf("marche po\n");
    }
    
    return 0;
}