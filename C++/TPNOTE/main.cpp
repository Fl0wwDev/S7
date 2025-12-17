#include <iostream>
#include "headers/networkInfrastructure.h"
#include "headers/router.h"
#include "headers/server.h"
#include "headers/switch.h"
#include "headers/knnDouble.h"
using namespace std;

int main() {

    //test infra réseaux
    NetworkInfrastructure infra("le date center de Mahé");

    //test équipements
    Router* router1 = new Router(256);
    router1->setHostname("le routeur Mahé");
    router1->setIpAddress("0.0.0.0");
    router1->setLocation("Salle e28");
    router1->setVendor("Apple");
    router1->setOsVersion("IOS 2");
    router1->setYear(2020);
    router1->setPowerConsumption(3);
    router1->setIsCritical(true);

    Server* server1 = new Server(16);
    server1->setHostname("le server de Mahé");
    server1->setIpAddress("1.1.1.1");
    server1->setLocation("Salle BYOD 1");
    server1->setVendor("Microsoft");
    server1->setOsVersion("Debian");
    server1->setYear(2021);
    server1->setPowerConsumption(4);
    server1->setIsCritical(true);

    Switch* switch1 = new Switch(48);
    switch1->setHostname("le switch de Mahé");
    switch1->setIpAddress("2.2.2.2");
    switch1->setLocation("Salle El Ayady");
    switch1->setVendor("Asus");
    switch1->setOsVersion("macOS");
    switch1->setYear(2010);
    switch1->setPowerConsumption(4);
    switch1->setIsCritical(false);


    //test de addDevice
    cout << "test de addDevice" << endl;
    infra.addDevice(router1);
    infra.addDevice(server1);
    infra.addDevice(switch1);
    cout << endl;

    //test de listDevices
    cout << "test de listDevices" << endl;
    infra.listDevices();
    cout << endl;

    //test de searchDeviceByHostname
    cout << "test de searchDeviceByHostname" << endl;
    if (NetworkDevice* found = infra.searchDeviceByHostname("le server de Mahé"))
    {
        cout << "lequipemet a été trouvé " << found->getHostname() << endl;
    } else {
        cout << "pas trouvé" << endl;
    }


    //test de averagePowerConsumption
    cout << "test de averagePowerConsumption" << endl;
    double avgPower = infra.averagePowerConsumption();
    cout << "Consommation moyenne: " << avgPower << " W" << endl;
    cout << endl;

    //test de refus de doublon
    cout << "test de refus de doublon" << endl;
    Server* duplicate = new Server(8);
    duplicate->setHostname("le server de Mahé");  //même hostname que server1
    
    bool added = infra.addDevice(duplicate);
    if (!added) {
        cout << "doublon bien réfusé on supprime pour libérer de la mémoire" << endl;
        delete duplicate;  //libérer la mémoire
    }
    cout << endl;

    //test printInfo avant suppression
    cout << "test de printInfo" << endl;
    router1->printInfo();
    server1->printInfo();
    switch1->printInfo();
    cout << endl;

    //test de removeDeviceByHostname
    cout << "test de removeDeviceByHostname" << endl;
    infra.removeDeviceByHostname("le switch de Mahé");
    cout << endl;

    //test KNNDouble
    cout << "test KNNDouble" << endl;
    KNNDouble knn(3);

    // equipement inconnu
    NetworkDevice* unknown = new NetworkDevice();
    unknown->setHostname("device inconnu");
    unknown->setPowerConsumption(4);// proche du switch1/server1
    unknown->setYear(2021);

    //construire les voisins et afficher les k plus proches
    vector<int> neighbors = knn.findNearestNeighbors(infra.getDevices(), unknown);
    cout << "k plus proches voisins (" << neighbors.size() << ") :" << endl;
    for (int idx : neighbors) {
        cout << " - " << infra.getDevices()[idx]->getHostname() << " (" 
             << infra.getDevices()[idx]->getPowerConsumption() << " W, "
             << infra.getDevices()[idx]->getYear() << ")" << endl;
    }

    delete unknown; //on nettoie
    return 0;
}
