#ifndef GIRAFFA_H
#define GIRAFFA_H
#include "Animal.h"

class Giraffa : public Animal {
private:
float LunghezzaCollo;
float Altezza;

public:
    Giraffa(const std::string& nome, int eta, const char sesso, float peso, const std::string& cibo_preferito, std::string& descrizione, float LunghezzaCollo, float Altezza);

    std::string emettereVerso() const override;
    const std::string setNome();
    std::string setDescrizione();

    // METODI
};
#endif
