#ifndef ENERGIYCARD_H
#define ENERGYCARD_H

#include <iostream>
#include <string>
#include "card.h"

class EnergyCard : public Card {
    private:
        string cardName = "Energy";
        string energyType;
    public:
        EnergyCard();
        EnergyCard(string _energyType, string _cardName);
        void setEnergyType(string);
        string getEnergyType() const;
};


#endif