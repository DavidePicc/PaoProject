#include <iostream>
#include "Tartaruga.h"



Tartaruga::Tartaruga(int eta, const char sesso, float peso, std::string cibo, float x,  float y)
    : Animal(setNome(), setDescrizione(), eta, sesso, peso, new Carnivoro(cibo)), isura.x(x), misura.y(y) {}
    
std::string Tartaruga::getName() const { 
    return nome; 
}

std::string Tartaruga::emettereVerso() const{
    return "Grugnito!\n";
}

const std::string setNome(){
    static unsigned int num;
    return "Tartaruga " + std::to_string(num);
}

static std::string setDescrizione(){
    return "Le testuggini delle Galapagos sono le tartarughe terrestri più grandi al mondo, con una lunghezza del carapace che si aggira attorno ai 150 centimetri ed un peso che può raggiungere i 300 kg. ";
}