#ifndef ROUTER_H
#define ROUTER_H
#include "networkDevice.h"
#include <iostream>
#include <string>

using namespace std;
class Router : public NetworkDevice {
private:
    int routingTableSize;
public:
    Router();
    Router(int _routingTableSize);
    // le getter
    int getRoutingTableSize() const;

    // le setter
    void setRoutingTableSize(int size);
    
    // override printInfo
    void printInfo() const override;
};

#endif