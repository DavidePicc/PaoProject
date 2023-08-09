#ifndef LEONE_H
#define LEONE_H
#include "Animal.h"

class Leone : public Animal {
protected:
    int ruggito; //-Ruggito: Misura in DB (max 110)
    bool criniera;//-Criniera: Si/No solo per maschi


public:
    Leone();
     Leone(const std::string& name, std::string description, int age, const char sex, float weight, const Alimentazione* type, unsigned int value,
          int rug, bool cri);

    std::string emettereVerso() const override;

    void setRuggito(int rug);
    int getRuggito() const;

    void setCriniera(bool cri);
    bool hasCriniera() const;

    
};
#endif
