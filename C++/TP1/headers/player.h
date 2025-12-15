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
        vector<PokemonCard*> actionCards;

        void deleteCards();
    public:
        explicit Player(const string& name = "");
        ~Player();

        string getName() const;
        void addCardToBench(Card* card);
        void displayBench();
        void displayAction();
        void activatePokemonCard(int benchIndex);
        void attachEnergyCard(int benchIndex, int actionIndex);
        void attack(int actionIndex, int attackIndex, Player& opponent, int opponentActionIndex);
        void useTrainer(int benchIndex);
};

#endif