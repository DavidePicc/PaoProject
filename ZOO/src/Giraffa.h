#ifndef GIRAFFA_H
#define GIRAFFA_H
#include "Animal.h"

class Giraffa : public Animal {
protected:
    float LunghezzaCollo;
    float Altezza;

public:
    Giraffa();
    Giraffa(int eta, const char sesso, float peso, std::string cibo, float LunghezzaCollo, int Altezza);

    std::string emettereVerso() const override;
    static const std::string setNome();
    static std::string setDescrizione();

    // METODI
};
#endif
