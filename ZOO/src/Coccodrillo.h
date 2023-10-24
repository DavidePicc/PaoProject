#ifndef Coccodrillo_H
#define Coccodrillo_H
#include "Animal.h"


class Coccodrillo : public Animal {
protected:
    float lunghezza;
    int numero_denti;

public:
    Coccodrillo();
    Coccodrillo(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, float lunghezza, int numerodenti);
    
    std::string emettereVerso() const override;

    // Metodi setter e getter per lunghezza e numero denti
    void setLunghezza(float lunghezza);
    float getLunghezza() const;

    void setNumeroDenti(int numerodenti);
    int getNumeroDenti() const;

    //Da aggiungere all'UML
    static const std::string setNome();
    static std::string setDescrizione();

    std::string ApreBocca();
};


#endif
