#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

class Card{
    private:
        string cardName;
    public:
        Card();
        virtual void displayInfo() = 0;

};
#endif