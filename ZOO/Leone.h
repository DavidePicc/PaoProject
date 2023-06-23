#ifndef LEONE_H
#define LEONE_H
#include "Animal.h"

class Leone : public Animal {
private:
int rugito; //-Ruggito: Misura in boh
bool criniera;//-Criniera: Si/No solo per maschi



public:
    Leone(const std::string& nome, int eta, const char sesso, float peso, const std::string& cibo_preferito, std::string& descrizione, int rugito, bool criniera);
    std::string getName() const override { 
        //return "Leone"; 
        }
    void emettereVerso() const override {
        //std::cout << "Ruggito!" << std::endl;
    }

    // METODI
};
#endif