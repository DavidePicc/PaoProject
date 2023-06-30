#ifndef LEONE_H
#define LEONE_H
#include "Animal.h"

class Leone : public Animal {
private:
int ruggito; //-Ruggito: Misura in DB (max 110)
bool criniera;//-Criniera: Si/No solo per maschi



public:
    Leone(int eta, const char sesso, float peso, std::string cibo, int rug, bool crin);
    std::string emettereVerso() const override;

    //Da aggiungere all'UML
    static const std::string setNome();
    static std::string setDescrizione();
};
#endif