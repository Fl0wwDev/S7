#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
    protected:
        string cardName;

    public:
        Card() = default;
        explicit Card(const string& name) : cardName(name) {}
        virtual ~Card() = default;

        string getCardName() const { return cardName; }
        virtual void displayInfo() = 0;
};

#endif