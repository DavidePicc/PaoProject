#ifndef LEONE_H
#define LEONE_H
#include "Animal.h"

class Leone : public Animal {
protected:
    int ruggito; //-Ruggito: Misura in DB (max 110)


public:
    Leone(unsigned int sizeRecinto);
    Leone(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, int rug);

    static const std::string setNome(unsigned int sizeRecinto);
    static std::string setDescrizione();

    void setRuggito(int rug);
    int getRuggito() const;
    std::string getDescrizioneRuggito() const;
};
#endif
