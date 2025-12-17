#ifndef NETWORK_INFRASTRUCTURE_H
#define NETWORK_INFRASTRUCTURE_H

#include <string>
#include <vector>
#include <map>
#include "networkDevice.h"
using namespace std;

class NetworkInfrastructure {
private:
    string name;
    static const size_t MAX_DEVICES;
    vector<NetworkDevice*> devices;

public:
    //constructeurs
    NetworkInfrastructure();
    NetworkInfrastructure(const string& _name);

    //le getter
    string getName() const;
    vector<NetworkDevice*>& getDevices();
    const vector<NetworkDevice*>& getDevices() const;

    //le setter
    void setName(const string& name);

    //les fonctions
    void listDevices() const;
    bool addDevice(NetworkDevice* device);
    NetworkDevice* searchDeviceByHostname(const string& hostname) const;
    bool removeDeviceByHostname(const string& hostname);
    double averagePowerConsumption() const;
};

#endif