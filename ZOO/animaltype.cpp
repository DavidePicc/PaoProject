#include "animaltype.h"

Alimentazione::Alimentazione(const std::string& cibo_favorito): cibo_preferito(cibo_favorito) {}

Alimentazione::Alimentazione(const Alimentazione& other){
    cibo_preferito = other.cibo_preferito;
}

Alimentazione& Alimentazione::operator=(const Alimentazione& other){
    if(cibo_preferito != other.cibo_preferito)
        cibo_preferito = other.cibo_preferito;
    return *this;
}

void Alimentazione::setCiboPreferito(std::string a){
    cibo_preferito = a;
}
    
std::string Alimentazione::getCiboPreferito() const{
    return cibo_preferito;
}