#ifndef MY_CLASS_H
#define MY_CLASS_H
#include <string>

class MyClass {
    private:
        std::string mot;
    public:
        MyClass() {};
        MyClass(std::string _mot);
        void printFonction(std::string _mot);

};

#endif