#ifndef PAVONE_H
#define PAVONE_H

#include "Animal.h"

class Pavone : public Animal {
protected:
    float raggioRuota;//raggio solo se sesso M in centimetri

public:
    Pavone(unsigned int sizeRecinto);
    Pavone(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, float raggio);

    static const std::string setNome(unsigned int sizeRecinto);
    static std::string setDescrizione();

    // Metodi setter e getter per raggioRuota
    void setRaggioRuota(float raggio);
    float getRaggioRuota() const;

    std::string SfoggiaRuota() const;

    std::string getInfo() const override;

    virtual void accept(animalVisitor& v) override;
};
#endif
