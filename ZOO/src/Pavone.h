#ifndef PAVONE_H
#define PAVONE_H
#include "Animal.h"

class Pavone : public Animal {
protected:
    float raggioRuota;//raggio solo se sesso M in centimetri

public:
    Pavone();

    Pavone(const std::string& name, std::string description, int age, const char sex, float weight, const Alimentazione* type, unsigned int value, float raggio);

    std::string emettereVerso() const override;

    static const std::string setNome();
    static std::string setDescrizione();

    // Metodi setter e getter per raggioRuota
    void setRaggioRuota(float raggio);
    float getRaggioRuota() const;

    std::string SfoggiaRuota() const;

};
#endif
