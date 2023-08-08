#ifndef STRUZZO_H
#define STRUZZO_H

#include "Animal.h"

class Struzzo : public Animal {
protected:
    float velocitamax; //in km/h

public:
    Struzzo();

    std::string emettereVerso() const override;
    static const std::string setNome();
    static std::string setDescrizione();

    // METODI
};
#endif
