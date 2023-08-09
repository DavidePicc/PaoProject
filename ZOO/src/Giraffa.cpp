#include <iostream>
#include "Giraffa.h"
#include "generate.h"

Giraffa::Giraffa()
    : Animal(setNome(), setDescrizione(), comodo::generaNumeroCasuale(10, 25), comodo::setSesso(), comodo::generaNumeroCasuale(700, 1500), new Erbivoro("Foglie"), 7), LunghezzaCollo(comodo::generaNumeroCasuale(2.0, 2.5)), Altezza(comodo::generaNumeroCasuale(4.0, 6.0)) {}

std::string Giraffa::emettereVerso() const{
    return "Belato!\n";
}

const std::string Giraffa::setNome(){
    static unsigned int num = 0;
    num ++;
    return "Giraffa " + std::to_string(num);
}

std::string Giraffa::setDescrizione(){
    return "La giraffa è un genere di mammifero artiodattilo. Originaria dell'Africa, è il più alto animale terrestre, nonché il più grande ruminante esistente.";
}