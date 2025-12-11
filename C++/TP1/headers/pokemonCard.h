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
        PokemonCard(string _pokemonType, string _familyName, int _evolutionLevel, int _maxHP, int _HP, vector<tuple<int, int, string, int>> _attacks, int _energyCost, int _energy, int _attackDescription, int _damage);
        void setPokemonType(string);
        void setFamilyName(string);
        void setEvolutionLevel(int);
        void setMaxHP(int);
        void setHP(int);
        void setAttacks(vector<tuple<int, int, string, int>>);
        void setEnergyCost(int);
        void setEnergy(int);
        void setAttackDescription(string);
        void setDamage(int);
        string getPokemonType() const;
        string getFamilyName() const;
        int getEvolutionLevel() const;
        int getMaxHP() const;
        int getHP() const;
        vector<tuple<int, int, string, int>> getAttacks() const;
        int getEnergyCost() const;
        int getEnergy() const;
        string getAttackDescription() const;
        int getDamage() const;
};

#endif