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

//Costruttori vuoti
Alimentazione::Alimentazione() {}
Carnivoro::Carnivoro() {}
Erbivoro::Erbivoro() {}

//Costruttori con parametri
Carnivoro::Carnivoro(const std::string& cibo_favorito): Alimentazione(cibo_favorito) {}
Erbivoro::Erbivoro(const std::string& cibo_favorito): Alimentazione(cibo_favorito) {}
Onnivoro::Onnivoro(const std::string& cibo_preferito): Alimentazione(cibo_preferito) {}
