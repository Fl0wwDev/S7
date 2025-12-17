#ifndef SERVER_H
#define SERVER_H

#include "networkDevice.h"
#include <iostream>
#include <string>
using namespace std;

class Server : public NetworkDevice {
private:
    int cpuCores; //nombre de coeurs cpu
public:
    Server();
    Server(int _cpuCores);
    
    // le getter
    int getCpuCores() const;

    // le setter
    void setCpuCores(int cores);
    void printInfo() const override;
};

#endif