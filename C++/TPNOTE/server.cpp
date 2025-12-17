#include "headers/server.h"

Server::Server()
{
}

Server::Server(int _cpuCores)
{
    cpuCores = _cpuCores;
}

int Server::getCpuCores() const
{
    return cpuCores;
}

void Server::setCpuCores(int cores)
{
    cpuCores = cores;
}


void Server::printInfo() const
{
    cout << "LE SERVEUR" << endl;
    cout << "Hostname: " << getHostname() << endl;
    cout << "IP Address: " << getIpAddress() << endl;
    cout << "Location: " << getLocation() << endl;
    cout << "Vendor: " << getVendor() << endl;
    cout << "OS Version: " << getOsVersion() << endl;
    cout << "Year: " << getYear() << endl;
    cout << "Power Consumption: " << getPowerConsumption() << " W" << endl;
    cout << "Is Critical: " << (getIsCritical() ? "Yes" : "No") << endl;
    cout << "CPU Cores: " << cpuCores << endl;
}
