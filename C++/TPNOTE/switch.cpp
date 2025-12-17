#include "headers/switch.h"

Switch::Switch()
{
}

Switch::Switch(int _portsCount)
{
    portCount = _portsCount;
}

int Switch::getPortCount() const
{
    return portCount;
}

void Switch::setPortCount(int ports)
{
    portCount = ports;
}

void Switch::printInfo() const
{
    cout << "LE SWITCH" << endl;
    cout << "Hostname: " << getHostname() << endl;
    cout << "IP Address: " << getIpAddress() << endl;
    cout << "Location: " << getLocation() << endl;
    cout << "Vendor: " << getVendor() << endl;
    cout << "OS Version: " << getOsVersion() << endl;
    cout << "Year: " << getYear() << endl;
    cout << "Power Consumption: " << getPowerConsumption() << " W" << endl;
    cout << "Is Critical: " << (getIsCritical() ? "Yes" : "No") << endl;
    cout << "Port Count: " << portCount << endl;
}