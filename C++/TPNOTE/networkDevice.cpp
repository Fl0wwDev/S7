#include "headers/networkDevice.h"

NetworkDevice::NetworkDevice()
{
}

NetworkDevice::NetworkDevice(string _hostname, string _ipAddress, string _location, string _vendor, string _osVersion, int _year, double _powerConsumption, bool _isCritical)
{
    hostname = _hostname;
    ipAddress = _ipAddress;
    location = _location;
    vendor = _vendor;
    osVersion = _osVersion;
    year = _year;
    powerConsumption = _powerConsumption;
    isCritical = _isCritical;
}


// les getters
string NetworkDevice::getHostname() const {
    return hostname;
}

string NetworkDevice::getIpAddress() const {
    return ipAddress;
}
string NetworkDevice::getLocation() const {
    return location;
}

string NetworkDevice::getVendor() const {
    return vendor;
}
string NetworkDevice::getOsVersion() const {
    return osVersion;
}
int NetworkDevice::getYear() const {
    return year;
}
double NetworkDevice::getPowerConsumption() const {
    return powerConsumption;
}
bool NetworkDevice::getIsCritical() const {
    return isCritical;
}

// les setters
void NetworkDevice::setHostname(string _hostname) {
    hostname = _hostname;
} 

void NetworkDevice::setIpAddress(string _ipAddress) {
    ipAddress = _ipAddress;
}

void NetworkDevice::setLocation(string _location) {
    location = _location;
}

void NetworkDevice::setVendor(string _vendor) {
    vendor = _vendor;
}

void NetworkDevice::setOsVersion(string _osVersion) {
    osVersion = _osVersion;
}

void NetworkDevice::setYear(int _year) {
    year = _year;
}

void NetworkDevice::setPowerConsumption(double _powerConsumption) {
    powerConsumption = _powerConsumption;
}

void NetworkDevice::setIsCritical(bool _isCritical) {
    isCritical = _isCritical;
}

bool NetworkDevice::ping() const {
    cout << "Pinging " << ipAddress << "..." << endl;
    return true;
}
void NetworkDevice::printInfo() const {
    cout << "Hostname: " << hostname << endl;
    cout << "IP address: " << ipAddress << endl;
    cout << "Location: " << location << endl;
    cout << "Vendor: " << vendor << endl;
    cout << "OS Version: " << osVersion << endl;
    cout << "Installed in  " << year << endl;
    cout << "This device is " << (isCritical ? "critical" : "not critical") << endl;
    cout << "Power Consumption: " << powerConsumption << "W" << endl;
}