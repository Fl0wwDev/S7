#include "headers/networkInfrastructure.h"
#include <algorithm>
#include <iostream>

const size_t NetworkInfrastructure::MAX_DEVICES = 100;

//le constructeur par défaut
NetworkInfrastructure::NetworkInfrastructure() : name("") {
}

//le constructeur paramétré
NetworkInfrastructure::NetworkInfrastructure(const string& name) : name(name) {
}

//le getter
string NetworkInfrastructure::getName() const {
    return name;
}

vector<NetworkDevice*>& NetworkInfrastructure::getDevices() {
    return devices;
}

const vector<NetworkDevice*>& NetworkInfrastructure::getDevices() const {
    return devices;
}

//le setter
void NetworkInfrastructure::setName(const string& _name) {
    name = _name;
}

// Affiche tous les équipements
void NetworkInfrastructure::listDevices() const {
    cout << "infrastructure: " << name << endl;
    cout << "le nombre d'équipements: " << devices.size() << endl;
}

// ajoute équipement ordre alphabétique et refuse les doublons
bool NetworkInfrastructure::addDevice(NetworkDevice* device) {
    if (device == nullptr) {
        return false;
    }
    
    //ça verifie les doublons
    if (searchDeviceByHostname(device->getHostname()) != nullptr) {
        cout << "y'a deja un equipement avec ce hostname '" << device->getHostname() 
             << "' existe déjà." << endl;
        return false;
    }
    
    //ça verifie si on a atteint le nombre maximum d'équipements
    if (devices.size() >= MAX_DEVICES) {
        cout << "le nombre maximum d'équipements (" << MAX_DEVICES << ") est atteint." << endl;
        return false;
    }
    
    //ça insère l'équipement en ordre alphabétique
    auto it = devices.begin();
    while (it != devices.end() && (*it)->getHostname() < device->getHostname()) {
        ++it;
    }
    devices.insert(it, device);
    return true;
}

//ça cherche un équipement par hostname
NetworkDevice* NetworkInfrastructure::searchDeviceByHostname(const string& hostname) const {
    for (const auto& device : devices) {
        if (device->getHostname() == hostname) {
            return device;
        }
    }
    return nullptr;
}

//ça supprime un équipement par hostname
bool NetworkInfrastructure::removeDeviceByHostname(const string& hostname) {
    for (auto it = devices.begin(); it != devices.end(); ++it) {
        if ((*it)->getHostname() == hostname) {
            delete *it;
            devices.erase(it);
            cout << "Équipement '" << hostname << "' supprimé avec succès." << endl;
            return true;
        }
    }
    cout << "Erreur: Équipement '" << hostname << "' non trouvé." << endl;
    return false;
}

//ça calcule la consommation moyenne d'énergie
double NetworkInfrastructure::averagePowerConsumption() const {
    if (devices.empty()) {
        return 0.0;
    }
    
    double total = 0.0;
    for (const auto& device : devices) {
        total += device->getPowerConsumption();
    }
    
    return total / devices.size();
}
