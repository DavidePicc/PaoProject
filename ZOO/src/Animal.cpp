#include <typeinfo>
#include <iostream>
#include "Animal.h"
#include "generate.h"

Animal::Animal(const std::string name, std::string description, int age, const char sex, float weight, const Alimentazione* type, unsigned int value)
    : nome(name), descrizione(description), eta(age), sesso(sex), peso(weight), tipo(type), costo(value) {}

bool Animal::operator==(const Animal& other) const{
    return ((*this) == (other)) ? 1 : 0;
}

std::string Animal::getName() const{
    return nome;
}

unsigned int Animal::getCosto() const {
    return costo;
}

// start NEW
void Animal::setDescrizione(const std::string& description) {
    descrizione = description;
}

std::string Animal::getDescrizione() const {
    return descrizione;
}

void Animal::setEta(int age) {
    eta = age;
}

int Animal::getEta() const {
    return eta;
}

void Animal::setPeso(float weight) {
    peso = weight;
}

float Animal::getPeso() const {
    return peso;
}

char Animal::getSex() const{
    return sesso;
}

const Alimentazione* Animal::getTipo() const {
    return tipo;
}

// Metodo per stampare le informazioni dell'animale
std::string Animal::getInfo() const {
    return  "Nome:\t\t" + nome +
            "\nEtà:\t\t" + std::to_string(eta) +
            "\nSesso:\t\t" + sesso +
            "\nPeso:\t\t" + std::to_string(peso) + " kg" +
            "\nCibo preferito:\t" + tipo->getCiboPreferito() +
            "\nCosto:\t\t" + std::to_string(costo);
}
