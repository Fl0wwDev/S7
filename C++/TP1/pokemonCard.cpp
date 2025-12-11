#include "pokemonCard.h"

PokemonCard::PokemonCard()
{
}

PokemonCard::PokemonCard(string _pokemonType, string _familyName, int _evolutionLevel, int _maxHP, int _HP, vector<tuple<int, int, string, int>> _attacks, int _energyCost, int _energy, int _attackDescription, int _damage)
{
    pokemonType = _pokemonType;
    familyName = _familyName;
    evolutionLevel = _evolutionLevel;
    maxHP = _maxHP;
    HP = _HP;
    attacks = _attacks;
    energyCost = _energyCost;
    energy = _energy;
    attackDescription = _attackDescription;
    damage = _damage;
}

void PokemonCard::setPokemonType(string _pokemonType){
    pokemonType = _pokemonType;
}; 
void PokemonCard::setFamilyName(string _familyName){
    familyName = _familyName;
};
void PokemonCard::setEvolutionLevel(int _evolutionLevel){
    evolutionLevel = _evolutionLevel;
};
void PokemonCard::setMaxHP(int _maxHP){
    maxHP = _maxHP;
};
void PokemonCard::setHP(int _HP){
    HP = _HP;
};
void PokemonCard::setAttacks(vector<tuple<int, int, string, int>> _attacks){
    attacks = _attacks;
};
void PokemonCard::setEnergyCost(int _energyCost){
    energyCost = _energyCost;
};
void PokemonCard::setEnergy(int _energy){
    energy = _energy;
};
void PokemonCard::setAttackDescription(string _attackDescription){ 
    attackDescription = _attackDescription;
};
void PokemonCard::setDamage(int _damage){
    damage = _damage;
};  
string PokemonCard::getPokemonType() const{
    return pokemonType;
};
string PokemonCard::getFamilyName() const{
    return familyName;
};
int PokemonCard::getEvolutionLevel() const{
    return evolutionLevel;
};
int PokemonCard::getMaxHP() const{
    return maxHP;
};
int PokemonCard::getHP() const{
    return HP;
};
vector<tuple<int, int, string, int>> PokemonCard::getAttacks() const{
    return attacks;
};
int PokemonCard::getEnergyCost() const{
    return energyCost;
};
int PokemonCard::getEnergy() const{
    return energy;
};
string PokemonCard::getAttackDescription() const{
    return attackDescription;
};
int PokemonCard::getDamage() const{
    return damage;
};
