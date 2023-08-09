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

    Tartaruga(const std::string& name, std::string description, int age, const char sex, float weight, const Alimentazione* type, unsigned int value,
              float X, float Y);

    void setMisura(float X, float Y);
    Dim_Guscio getMisura() const;

    std::string siNasconde() const;
    
    std::string emettereVerso() const override;
    static const std::string setNome();
    static std::string setDescrizione();

    // METODI
};
#endif
