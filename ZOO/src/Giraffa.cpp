#include <iostream>
#include "Giraffa.h"
#include "generate.h"

Giraffa::Giraffa()
    : Animal(setNome(), setDescrizione(), comodo::generaNumeroCasuale(10, 25), comodo::setSesso(), comodo::generaNumeroCasuale(700, 1500), new Erbivoro("Foglie"), 7), LunghezzaCollo(comodo::generaNumeroCasuale(2.0, 2.5)), Altezza(comodo::generaNumeroCasuale(4.0, 6.0)) {}


Giraffa::Giraffa(const std::string& name, std::string description, int age, const char sex, float weight, const Alimentazione* type, unsigned int value, float lungcollo, float altezza)
    : Animal(name, description, age, sex, weight, type, value), LunghezzaCollo(lungcollo), Altezza(altezza) {}

std::string Giraffa::emettereVerso() const {
    return "Belato!";
}

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

const std::string Giraffa::setNome(){
    static unsigned int num = 0;
    num ++;
    return "Giraffa " + std::to_string(num);
}

std::string Giraffa::setDescrizione(){
    return "La giraffa è un genere di mammifero artiodattilo. Originaria dell'Africa, è il più alto animale terrestre, nonché il più grande ruminante esistente.";
}

std::string Giraffa::SiAlza(){
    return "La giraffa si è alzata e ha un altezza di:" + std::to_string(Altezza) + "e un collo di:" + std::to_string(LunghezzaCollo);
}
