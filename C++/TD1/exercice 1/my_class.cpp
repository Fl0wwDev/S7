#include "my_class.h"
#include <iostream>

MyClass::MyClass(std::string _mot){
    mot = _mot;
};

void MyClass::printFonction(std::string mot){
    std::cout << mot << std::endl;
}