#ifndef Coccodrillo_H
#define Coccodrillo_H
#include "Animal.h"


class Coccodrillo : public Animal {
protected:
    float lunghezza;
    int numero_denti;

public:
    Coccodrillo();
    std::string emettereVerso() const override;

    //Da aggiungere all'UML
    static const std::string setNome();
    static std::string setDescrizione();
};


#endif