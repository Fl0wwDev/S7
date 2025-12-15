#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include <iostream>
#include <string>
#include "card.h"

using namespace std;

class TrainerCard : public Card {
    private:
        string trainerEffect;
    public:
        TrainerCard();
        TrainerCard(const string& _cardName, const string& _effect);
        void setTrainerEffect(const string&);
        string getTrainerEffect() const;
        void displayInfo() override;
};
#endif