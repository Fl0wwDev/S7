#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
    protected:
        string cardName;

    public:
        Card() {}
        Card(const string& name) : cardName(name) {}
        virtual ~Card() {}

        string getCardName() const { return cardName; }
        virtual void displayInfo() = 0;
};

#endif