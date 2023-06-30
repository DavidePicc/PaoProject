#include <iostream>
#include "Giraffa.h"



Giraffa::Giraffa(int eta, const char sesso, float peso, std::string cibo, float LunghezzaCollo, int Altezza)
    : Animal(setNome(), setDescrizione(), eta, sesso, peso, new Carnivoro(cibo)), LunghezzaCollo(LunghezzaCollo), Altezza(Altezza) {}
    
std::string Giraffa::getName() const { 
    return nome; 
}

std::string Giraffa::emettereVerso() const{
    return "Belato!\n";
}

const std::string setNome(){
    static unsigned int num;
    return "Giraffa " + std::to_string(num);
}

static std::string setDescrizione(){
    return "La giraffa è un genere di mammifero artiodattilo. Originaria dell'Africa, è il più alto animale terrestre, nonché il più grande ruminante esistente.";
}