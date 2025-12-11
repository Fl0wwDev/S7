#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include <iostream>
#include <string>
#include "card.h"
#include <vector>
using namespace std;

class PokemonCard : public Card {
    private:
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int HP;
        vector<tuple<int, int, string, int>> attacks;
        int energyCost;
        int energy;
        string attackDescription;
        int damage;
    public:
        PokemonCard();
};

#endif