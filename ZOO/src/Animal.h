#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "animaltype.h"

class Animal {
private:
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

    virtual ~Animal();

    bool operator==(const Animal& other) const;

    std::string getName() const; 

    virtual std::string  emettereVerso() const = 0;

    // start NEW
    void setDescrizione(const std::string& description);

    std::string getDescrizione() const;

    void setEta(int age);

    int getEta() const;

    void setPeso(float weight);

    float getPeso() const;

    const Alimentazione* getTipo() const;

    unsigned int getCosto() const;

    std::ostream& operator<<(std::ostream& os, const Animal& animal);

    virtual void stampa() const;
    //end NEW

};

#endif
