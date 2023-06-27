#ifndef Coccodrillo_H
#define Coccodrillo_H
#include <iostream>
#include "Animal.h"

class Coccodrillo : public Animal {
private:
float lunghezza;
int numero_denti;

public:
    Coccodrillo(const std::string& nome, 
            int eta, 
            const char sesso, 
            float peso, 
            const std::string& cibo_preferito, 
            std::string& descrizione, 
            float lunghezza, 
            int numero_denti): Animal(nome, eta, sesso, peso, cibo_preferito, descrizione), lunghezza(setLunghezza()), numero_denti(setDenti()) {}

    std::string getName() const;
    void emettereVerso() const override;

    //Da aggiungere all'UML
    

    // METODI
};

template <typename T>
T generaNumeroCasuale(T min, T max);

float setLunghezza();
int setDenti();
int setEta();


#endif