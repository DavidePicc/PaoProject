#ifndef Coccodrillo_H
#define Coccodrillo_H
#include <iostream>
#include "Animal.h"

class Coccodrillo : public Animal {
private:
    float lunghezza;
    int numero_denti;

public:
    Coccodrillo(const std::string& nome, int eta, const char sesso, float peso, const std::string& cibo_preferito, std::string descrizione, float lunghezza, int numero_denti);

    std::string getName() const;
    std::string emettereVerso() const override;

    //Da aggiungere all'UML
    static const std::string setNome();
    std::string setCiboPreferito();
    std::string setDescrizione(); //Da fare
};


#endif