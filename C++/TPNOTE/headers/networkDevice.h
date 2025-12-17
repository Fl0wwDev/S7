#ifndef NETWORKDEVICE_H
#define NETWORKDEVICE_H
#include <iostream>
#include <string>
using namespace std;

class NetworkDevice
{
private:
    string hostname;
    string ipAddress;
    string location;
    string vendor;
    string osVersion;
    int year;
    double powerConsumption;
    bool isCritical;

public:
    NetworkDevice();
    NetworkDevice(string _hostname, string _ipAddress, string _location, 
                  string _vendor, string _osVersion, int _year, 
                  double _powerConsumption, bool _isCritical);
    NetworkDevice(const NetworkDevice& other);

    // le getters
    string getHostname() const;
    string getIpAddress() const;
    string getLocation() const;
    string getVendor() const;
    string getOsVersion() const;
    int getYear() const;
    double getPowerConsumption() const;
    bool getIsCritical() const;

    // les setters
    void setHostname(string _hostname);
    void setIpAddress(string _ipAddress);
    void setLocation(string _location);
    void setVendor(string _vendor);
    void setOsVersion(string _osVersion);
    void setYear(int _year);
    void setPowerConsumption(double _powerConsumption);
    void setIsCritical(bool _iscritical);

    // la fonction ping
    bool ping() const;
    
    // la fonction virtuelle printINFO
    virtual void printInfo() const;
};

#endif