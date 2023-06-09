#ifndef PAVONE_H
#define PAVONE_H
#include "Animal.h"

class Pavone : public Animal {
private:
float raggioRuota;//raggio solo se sesso M

public:
    Pavone(int eta, const char sesso, float peso, std::string cibo, float ruota);


    std::string emettereVerso() const override;
    static const std::string setNome();
    static std::string setDescrizione();

    // METODI
};
#endif