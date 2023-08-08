#ifndef GIRAFFA_H
#define GIRAFFA_H
#include "Animal.h"

class Giraffa : public Animal {
protected:
    float LunghezzaCollo;
    float Altezza;

public:
    Giraffa();

    std::string emettereVerso() const override;
    static const std::string setNome();
    static std::string setDescrizione();

    // METODI
};
#endif
