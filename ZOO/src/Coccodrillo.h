#ifndef Coccodrillo_H
#define Coccodrillo_H
#include "Animal.h"


class Coccodrillo : public Animal {
protected:
    float lunghezza;
    int numero_denti;

public:
    Coccodrillo(unsigned int sizeRecinto);
    Coccodrillo(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, float lunghezza, int numerodenti);
    
    // Metodi setter e getter per lunghezza e numero denti
    void setLunghezza(float lunghezza);
    float getLunghezza() const;

    void setNumeroDenti(int numerodenti);
    int getNumeroDenti() const;

    static const std::string setNome(unsigned int sizeRecinto);
    static std::string setDescrizione();

    std::string ApreBocca();

    std::string getInfo() const override;
};


#endif
