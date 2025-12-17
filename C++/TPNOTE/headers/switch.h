#ifndef SWITCH_H
#define SWITCH_H
#include "networkDevice.h"
#include <iostream>
#include <string>
using namespace std;

class Switch : public NetworkDevice {
private:
    int portCount; //nombre de ports

public:
    Switch();
    Switch(int _portCount);
    
    // le getter
    int getPortCount() const;


    // le setter
    void setPortCount(int ports);
    void printInfo() const override;
};

#endif