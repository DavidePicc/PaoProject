#ifndef TARTARUGA_H
#define TARTARUGA_H

#include "Animal.h"

struct Dim_Guscio {//dimensioni guscio in cm
    float x;
    float y;
};

class Tartaruga : public Animal {
private:
    Dim_Guscio misura;

public:
    Tartaruga();
    Tartaruga(int eta, const char sesso, float peso, std::string cibo, float x,  float y);

    std::string emettereVerso() const override;
    static const std::string setNome();
    static std::string setDescrizione();

    // METODI
};
#endif
