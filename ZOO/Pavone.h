#ifndef PAVONE_H
#define PAVONE_H
#include "Animal.h"

class Pavone : public Animal {
private:
float raggioRuota;//raggio solo se sesso M

public:
    Pavone(const std::string& nome, int eta, const char sesso, float peso, const std::string& cibo_preferito, std::string& descrizione, float raggioRuota);

    std::string getName() const override { 
        //return "Pavone"; 
        }

    void emettereVerso() const override {
        //std::cout << "eeee-ow!" << std::endl;
    }

    // METODI
};
#endif