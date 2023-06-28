#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "animaltype.h"

class Animal {
protected:
    const std::string nome;//nome o codice dell'animale
    std::string descrizione;
    int eta;
    const char sesso;
    float peso;//in kg
    const Alimentazione tipo;
    
public:
    Animal();
    Animal(const std::string& nome, int eta, const char sesso, float peso, const std::string& cibo_preferito, std::string descrizione);

    virtual ~Animal();

    virtual std::string getName() const =0;

    virtual std::string  emettereVerso() const = 0;

    bool operator==(const Animal& other) const;
};

#endif