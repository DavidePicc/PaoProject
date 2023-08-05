#include <iostream>
#include "Struzzo.h"
#include "generate.h"

Struzzo::Struzzo()
    :Animal(setNome(), setDescrizione(), comodo::generaNumeroCasuale(5, 60), comodo::setSesso(), comodo::generaNumeroCasuale(70, 130), new Erbivoro("Erba")), velocitamax(comodo::generaNumeroCasuale(30, 70)) {}

Struzzo::Struzzo(int eta, const char sesso, float peso, std::string cibo, float velocita)
    : Animal(setNome(), setDescrizione(), eta, sesso, peso, new Carnivoro(cibo)), velocitamax(velocita) {}
    

std::string Struzzo::emettereVerso() const{
    return "Grugnito!\n";
}

const std::string Struzzo::setNome(){
    static unsigned int num = 0;
    num ++;
    return "Struzzo " + std::to_string(num);
}

std::string Struzzo::setDescrizione(){
    return "Lo struzzo comune semplicemente struzzo, è una grande specie di uccello incapace di volare originario delle vaste savane dell'Africa.";
}
