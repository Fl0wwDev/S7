#include "headers/energyCard.h"

EnergyCard::EnergyCard()
{
    cardName = "Energy";
    energyType = "";
}

EnergyCard::EnergyCard(const string& _energyType)
{
    cardName = "Energy";
    energyType = _energyType;
}

EnergyCard::EnergyCard(const string& _energyType, const string& _cardName)
{
    cardName = _cardName;
    energyType = _energyType;
}

void EnergyCard::setEnergyType(const string& _energyType)
{
    energyType = _energyType;
}

string EnergyCard::getEnergyType() const
{
    return energyType;
}

void EnergyCard::displayInfo()
{
    cout << "Energy Card - Type: " << energyType << endl;
}