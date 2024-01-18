#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iomanip> 
#include <typeinfo>
#include <iostream>
#include "generate.h"
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
    Animal(const std::string name, std::string description, int age, const char sex, float weight, const Alimentazione* type, unsigned int value);

    bool operator==(const Animal& other) const;

    std::string getName() const; 

    void setDescrizione(const std::string& description);

    std::string getDescrizione() const;

    void setEta(int age);

    int getEta() const;

    void setPeso(float weight);

    float getPeso() const;

    char getSex() const;

    const Alimentazione* getTipo() const;

    unsigned int getCosto() const;

    virtual std::string getInfo() const;
};

#endif
