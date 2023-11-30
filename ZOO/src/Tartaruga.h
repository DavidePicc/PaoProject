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
    Tartaruga(unsigned int sizeRecinto);
    Tartaruga(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, float X, float Y);

    void setMisura(float X, float Y);
    Dim_Guscio getMisura() const;
    float getMisuraX() const;
    float getMisuraY() const;

    std::string siNasconde() const;
    
    static const std::string setNome(unsigned int sizeRecinto);
    static std::string setDescrizione();

    // METODI
};
#endif
