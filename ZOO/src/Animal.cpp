#include <typeinfo>
#include <iostream>
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

const Alimentazione* Animal::getTipo() const {
    return tipo;
}

// Metodo per stampare le informazioni dell'animale
void Animal::stampa() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Descrizione: " << descrizione << std::endl;
    std::cout << "Età: " << eta << std::endl;
    std::cout << "Sesso: " << sesso << std::endl;
    std::cout << "Peso: " << peso << " kg" << std::endl;
    std::cout << "Cibo preferito: " << tipo->getCiboPreferito() << std::endl;
    std::cout << "Costo: " << costo << std::endl;
}

std::ostream& Animal::operator<<(std::ostream& os) {
    (*this).stampa();
    return os;
}
