#ifndef PAVONE_H
#define PAVONE_H
#include "Animal.h"

class Pavone : public Animal {
protected:
    float raggioRuota;//raggio solo se sesso M in centimetri

public:
    Pavone();

    Pavone(const std::string& name, std::string description, int age, const char sex, float weight, const Alimentazione* type, unsigned int value,
           float wheelRadius);

    std::string emettereVerso() const override;

    // Metodi setter e getter per raggioRuota
    void setRaggioRuota(float wheelRadius);
    float getRaggioRuota() const;

    std::string SfoggiaRuota() const;

};
#endif
