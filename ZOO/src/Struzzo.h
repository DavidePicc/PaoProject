#ifndef STRUZZO_H
#define STRUZZO_H

#include "Animal.h"

class Struzzo : public Animal {
protected:
    float velocitamax; //in km/h

public:
    Struzzo(unsigned int sizeRecinto);
    Struzzo(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, float velo);

    void setVelocitaMax(float velo);
    float getVelocitaMax() const;

    std::string corre() const;
    std::string nascondeTesta() const;
    
    static const std::string setNome(unsigned int sizeRecinto);
    static std::string setDescrizione();
    
    std::string getInfo() const override;

    virtual void accept(animalVisitor& v) override;
};
#endif
