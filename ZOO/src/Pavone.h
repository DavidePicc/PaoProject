#ifndef PAVONE_H
#define PAVONE_H
#include "Animal.h"

class Pavone : public Animal {
protected:
    float raggioRuota;//raggio solo se sesso M in centimetri

public:
    Pavone();


    std::string emettereVerso() const override;
    static const std::string setNome();
    static std::string setDescrizione();

    // METODI
};
#endif