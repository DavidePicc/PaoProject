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
    const Alimentazione* tipo;
    const unsigned int costo;
    

public:    
    //Costruttore vuoto
    Animal();

    //Costruttore con parametri
    Animal(const std::string name, std::string description, int age, const char sex, float weight, const Alimentazione* type, unsigned int value);

    //Animal(const std::string name, std::string description, int age, const char sex, float weight, std::string cibo_preferito);

    //virtual ~Animal();

    bool operator==(const Animal& other) const;

    std::string getName() const; 

    virtual std::string  emettereVerso() const = 0;

    unsigned int getCosto();
};

#endif