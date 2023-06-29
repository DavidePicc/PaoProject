#ifndef Coccodrillo_H
#define Coccodrillo_H
#include <iostream>
#include "Animal.h"

class Coccodrillo : public Animal {
public://private//////////////////////////////////////////////////////////////////////////////////////////////////////////////////DA ELIMINARE
    float lunghezza;
    int numero_denti;

public:
    Coccodrillo(int eta, const char sesso, float peso, std::string cibo, float lunghezza, int numero_denti);

    std::string getName() const override;
    std::string emettereVerso() const override;

    //Da aggiungere all'UML
    static const std::string setNome();
    static std::string setDescrizione();
};


#endif