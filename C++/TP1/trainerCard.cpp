#include "headers/trainerCard.h"

TrainerCard::TrainerCard()
{
    cardName = "Trainer";
    trainerEffect = "";
}

TrainerCard::TrainerCard(const string& _cardName, const string& _effect)
{
    cardName = _cardName;
    trainerEffect = _effect;
}

void TrainerCard::setTrainerEffect(const string& _effect)
{
    trainerEffect = _effect;
}

string TrainerCard::getTrainerEffect() const
{
    return trainerEffect;
}

void TrainerCard::displayInfo()
{
    cout << "Trainer Card - Name: " << cardName
         << ", Effect: " << trainerEffect << endl;
}

