#ifndef GIRAFFA_H
#define GIRAFFA_H
#include "Animal.h"

class Giraffa : public Animal {
protected:
    float LunghezzaCollo;
    float Altezza;

public:
    Giraffa();

    Giraffa(const std::string& name, std::string description, int age, const char sex, float weight, const Alimentazione* type, unsigned int value, float lungcollo, float altezza);

    std::string emettereVerso() const override;

    static const std::string setNome();
    static std::string setDescrizione();

    void setLunghezzaCollo(float lungcollo);
    float getLunghezzaCollo() const;

    void setAltezza(float altezza);
    float getAltezza() const;
    // METODI
    std::string SiAlza();
};
#endif
