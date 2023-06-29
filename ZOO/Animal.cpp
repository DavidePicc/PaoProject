#include <typeinfo>
#include "Animal.h"

Animal::Animal(const std::string name, std::string description, int age, const char sex, float weight, const Alimentazione* type)
        : nome(name), descrizione(description), eta(age), sesso(sex), peso(weight), tipo(type) {}

bool Animal::operator==(const Animal& other) const{
    if(typeid(*this) == typeid(other))
        return 1;
    else
        return 0;
}

//virtual ~Animal();