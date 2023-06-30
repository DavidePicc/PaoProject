#include <iostream>
#include "Struzzo.h"



Struzzo::Struzzo(int eta, const char sesso, float peso, std::string cibo, float LunghezzaCollo, int Altezza)
    : Animal(setNome(), setDescrizione(), eta, sesso, peso, new Carnivoro(cibo)), LunghezzaCollo(LunghezzaCollo), Altezza(Altezza) {}
    
std::string Struzzo::getName() const { 
    return nome; 
}

std::string Struzzo::emettereVerso() const{
    return "Grugnito!\n";
}

const std::string setNome(){
    static unsigned int num;
    return "Struzzo " + std::to_string(num);
}

static std::string setDescrizione(){
    return "Lo struzzo comune semplicemente struzzo, è una grande specie di uccello incapace di volare originario delle vaste savane dell'Africa.";
}