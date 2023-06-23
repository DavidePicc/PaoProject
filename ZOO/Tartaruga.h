#ifndef TARTARUGA_H
#define TARTARUGA_H

#include "Animal.h"

struct Dim_Guscio {//dimensioni guscio in cm
    float x;
    float y;
};

class Tartaruga : public Animal {
private:
Dim_Guscio misura;

public:
    Tartaruga(const std::string& nome, int eta, const char sesso, float peso, const std::string& cibo_preferito, std::string& descrizione,
    float misura.x,  float misura.y);

    std::string getName() const override { 
        //return "Tartaruga"; 
        }

    void emettereVerso() const override {
        //std::cout << "NULL!" << std::endl;//NULL, non fa versi
    }

    // METODI
};
#endif