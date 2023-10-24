#ifndef STRUZZO_H
#define STRUZZO_H

#include "Animal.h"

class Struzzo : public Animal {
protected:
    float velocitamax; //in km/h

public:
    Struzzo();
    Struzzo(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, float velo);

    std::string emettereVerso() const override;

    void setVelocitaMax(float velo);
    float getVelocitaMax() const;

    std::string corre() const;
    std::string nascondeTesta() const;
    
    static const std::string setNome();
    static std::string setDescrizione();
    
    // METODI
};
#endif
