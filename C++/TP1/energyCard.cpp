#include "energyCard.h"

EnergyCard::EnergyCard()
{
}
EnergyCard::EnergyCard(string _energyType, string _cardName)
{
    energyType = _energyType;
    cardName = _cardName;
}
void EnergyCard::setEnergyType(string _energyType)
{
    energyType = _energyType;
}
string EnergyCard::getEnergyType() const
{
    return energyType;
}