#ifndef ENERGIYCARD_H
#define ENERGIYCARD_H

#include <iostream>
#include <string>
#include "card.h"

class EnergyCard : public Card {
    private:
        string energyType;
    public:
        EnergyCard();
        explicit EnergyCard(const string& _energyType);
        EnergyCard(const string& _energyType, const string& _cardName);

        void setEnergyType(const string&);
        string getEnergyType() const;
        void displayInfo() override;
};


#endif