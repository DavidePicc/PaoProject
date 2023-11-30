#include <iostream>
#include <iomanip>
#include "Giraffa.h"
#include "generate.h"

Giraffa::Giraffa(unsigned int sizeRecinto)
    : Animal(setNome(sizeRecinto), setDescrizione(), comodo::generaNumeroCasuale(10, 25), comodo::setSesso(), comodo::generaNumeroCasuale(700, 1500), new Erbivoro("Foglie"), 7), LunghezzaCollo(comodo::generaNumeroCasuale(2.0, 2.5)), Altezza(comodo::generaNumeroCasuale(4.0, 6.0)) {}


Giraffa::Giraffa(const std::string& name, int age, const char sex, float weight, const Alimentazione* type, float lungcollo, float altezza)
    : Animal(name, setDescrizione(), age, sex, weight, type, 7), LunghezzaCollo(lungcollo), Altezza(altezza) {}
    

void Giraffa::setLunghezzaCollo(float lungcollo) {
    LunghezzaCollo = lungcollo;
}

float Giraffa::getLunghezzaCollo() const {
    return LunghezzaCollo;
}

void Giraffa::setAltezza(float height) {
    Altezza = height;
}

float Giraffa::getAltezza() const {
    return Altezza;
}

const std::string Giraffa::setNome(unsigned int sizeRecinto){
    return "Giraffa " + std::to_string(sizeRecinto + 1);
}

std::string Giraffa::setDescrizione(){
    return "La giraffa è un genere di mammifero artiodattilo. Originaria dell'Africa, è il più alto animale terrestre, nonché il più grande ruminante esistente.";
}

std::string Giraffa::SiAlza(){
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2); 
    oss << "La giraffa si è alzata e ha un altezza di: " << Altezza << " m e un collo di: " << LunghezzaCollo << " m";
    return oss.str();
}
