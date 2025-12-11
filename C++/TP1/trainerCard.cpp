#include "trainerCard.h"

TrainerCard::TrainerCard()
{
}

TrainerCard::TrainerCard(string _trainerType, string _cardName)
{
    trainerEffect = _trainerType;
    cardName = _cardName;
}

void TrainerCard::setTrainerType(string _trainerType)
{
    trainerEffect = _trainerType;
}

string TrainerCard::getTrainerType() const
{
    return trainerEffect;
}

