#ifndef GIRAFFA_H
#define GIRAFFA_H
#include "Animal.h"

class Giraffa : public Animal {
protected:
    float LunghezzaCollo;
    float Altezza;

public:
    Giraffa(unsigned int sizeRecinto);
    Giraffa(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, float lungcollo, float altezza);

    static const std::string setNome(unsigned int sizeRecinto);
    static std::string setDescrizione();

    void setLunghezzaCollo(float lungcollo);
    float getLunghezzaCollo() const;

    void setAltezza(float altezza);
    float getAltezza() const;

    std::string SiAlza();

    std::string getInfo() const override;

};
#endif
