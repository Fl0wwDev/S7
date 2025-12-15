#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include <iostream>
#include <string>
#include "card.h"
#include <vector>

using namespace std;

struct Attack {
    int cost;
    string description;
    int damage;
};

class PokemonCard : public Card {
    private:
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int HP;
        vector<Attack> attacks;
        int energyAttached;
    public:
        PokemonCard();
        PokemonCard(const string& _cardName,
                    const string& _pokemonType,
                    const string& _familyName,
                    int _evolutionLevel,
                    int _maxHP,
                    int attack1Cost,
                    const string& attack1Desc,
                    int attack1Damage,
                    int attack2Cost,
                    const string& attack2Desc,
                    int attack2Damage);

        void addEnergy(int amount = 1);
        int getEnergyAttached() const;
        const vector<Attack>& getAttacks() const;
        string getPokemonType() const;
        string getFamilyName() const;
        int getEvolutionLevel() const;
        int getMaxHP() const;
        int getHP() const;
        void reduceHP(int amount);
        void healToMax();
        void displayInfo() override;
};

#endif