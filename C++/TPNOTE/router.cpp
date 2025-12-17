#include "headers/router.h"

Router::Router()
{
}

Router::Router(int _routingTableSize)
{
    routingTableSize = _routingTableSize;
}

int Router::getRoutingTableSize() const
{
    return routingTableSize;
}

void Router::setRoutingTableSize(int size)
{
    routingTableSize = size;
}

void Router::printInfo() const
{
    cout << "LE ROUTEUR" << endl;
    cout << "Hostname: " << getHostname() << endl;
    cout << "IP Address: " << getIpAddress() << endl;
    cout << "Location: " << getLocation() << endl;
    cout << "Vendor: " << getVendor() << endl;
    cout << "OS Version: " << getOsVersion() << endl;
    cout << "Year: " << getYear() << endl;
    cout << "Power Consumption: " << getPowerConsumption() << " W" << endl;
    cout << "Is Critical: " << (getIsCritical() ? "Yes" : "No") << endl;
    cout << "Routing Table Size: " << routingTableSize << endl;
}
