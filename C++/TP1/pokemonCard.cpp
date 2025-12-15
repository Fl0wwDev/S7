#include "headers/pokemonCard.h"

PokemonCard::PokemonCard()
{
    cardName = "";
    pokemonType = "";
    familyName = "";
    evolutionLevel = 0;
    maxHP = 0;
    HP = 0;
    energyAttached = 0;
}

PokemonCard::PokemonCard(const string& _cardName,
                         const string& _pokemonType,
                         const string& _familyName,
                         int _evolutionLevel,
                         int _maxHP,
                         int attack1Cost,
                         const string& attack1Desc,
                         int attack1Damage,
                         int attack2Cost,
                         const string& attack2Desc,
                         int attack2Damage)
{
    cardName = _cardName;
    pokemonType = _pokemonType;
    familyName = _familyName;
    evolutionLevel = _evolutionLevel;
    maxHP = _maxHP;
    HP = _maxHP;
    energyAttached = 0;

    Attack firstAttack;
    firstAttack.cost = attack1Cost;
    firstAttack.description = attack1Desc;
    firstAttack.damage = attack1Damage;
    attacks.push_back(firstAttack);

    Attack secondAttack;
    secondAttack.cost = attack2Cost;
    secondAttack.description = attack2Desc;
    secondAttack.damage = attack2Damage;
    attacks.push_back(secondAttack);
}

void PokemonCard::addEnergy(int amount)
{
    energyAttached += amount;
}

int PokemonCard::getEnergyAttached() const
{
    return energyAttached;
}

const vector<Attack>& PokemonCard::getAttacks() const
{
    return attacks;
}

string PokemonCard::getPokemonType() const
{
    return pokemonType;
}

string PokemonCard::getFamilyName() const
{
    return familyName;
}

int PokemonCard::getEvolutionLevel() const
{
    return evolutionLevel;
}

int PokemonCard::getMaxHP() const
{
    return maxHP;
}

int PokemonCard::getHP() const
{
    return HP;
}

void PokemonCard::reduceHP(int amount)
{
    HP -= amount;
    if (HP < 0) HP = 0;
}

void PokemonCard::healToMax()
{
    HP = maxHP;
}

void PokemonCard::displayInfo()
{
    cout << "Pokemon Card - Name: " << cardName
         << ", Type: " << pokemonType
         << ", Evolution Level: " << evolutionLevel
         << " of the family \"" << familyName << "\""
         << ", HP: " << HP << endl;

    cout << "\nAttacks:" << endl;
    for (size_t i = 0; i < attacks.size(); ++i) {
        cout << "Attack #" << i << ":" << endl;
        cout << "Attack cost: " << attacks[i].cost << endl;
        cout << "Attack current energy storage: " << energyAttached << endl;
        cout << "Attack description: " << attacks[i].description << endl;
        cout << "Attack damage: " << attacks[i].damage << endl;
        if (i + 1 < attacks.size()) {
            cout << "\n";
        }
    }

    if (attacks.size() == 2) {
        cout << "\nOnly 2 attacks exist." << endl;
    }
}
