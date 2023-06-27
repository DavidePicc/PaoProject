#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "animaltype.h"

class Animal {
private:
    std::string nome;//nome o codice dell'animale
    std::string descrizione;
    int eta;
    char sesso;
    float peso;//in kg
    Alimentazione tipo;
    
public:
    Animal(const std::string& nome, int eta, const char sesso, float peso, const std::string& cibo_preferito, std::string& descrizione);

    virtual ~Animal();

    std::string getName() const { return "Animale"; }

    virtual void emettereVerso() const {}

    bool operator==(const Animal& other) const {
        // confronto tra Animal
        
        //return true;
    }
};

#endif