#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "pokemonCard.h"
#include "energyCard.h"
#include "trainerCard.h"

using namespace std;

class Player {
    private:
        string playerName;
        vector<Card*> benchCards;
        vector<PokemonCard*> ActionCards;
};

#endif