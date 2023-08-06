#include <typeinfo>
#include "Animal.h"
#include "generate.h"

Animal::Animal(const std::string name, std::string description, int age, const char sex, float weight, const Alimentazione* type, unsigned int value)
    : nome(name), descrizione(description), eta(age), sesso(sex), peso(weight), tipo(type), costo(value) {}

bool Animal::operator==(const Animal& other) const{
    return (typeid(*this) == typeid(other)) ? 1 : 0;
}

std::string Animal::getName() const{
    return nome;
}

unsigned int Animal::getCosto(){
    return costo;
}