#ifndef TRAINERCARD_H
#define TRAINERCARD_H
#include <iostream>
#include <string>
#include "card.h"
using namespace std;

class TrainerCard : public Card {
    private:
        string cardName = "Trainer";
        string trainerEffect;
    public:
        TrainerCard();
        TrainerCard(string _trainerType, string _cardName);
        void setTrainerType(string);
        string getTrainerType() const;
};
#endif