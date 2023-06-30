#ifndef STRUZZO_H
#define STRUZZO_H

#include "Animal.h"

class Struzzo : public Animal {
private:
float velocitamax; //in km/h

public:
    Struzzo(const std::string& nome, int eta, const char sesso, float peso, const std::string& cibo_preferito, std::string& descrizione, float velocitamax);

    std::string emettereVerso() const override;
    const std::string setNome();
    std::string setDescrizione();

    // METODI
};
#endif
