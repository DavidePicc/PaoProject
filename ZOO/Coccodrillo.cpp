#include <iostream>
#include <random>
#include "Coccodrillo.h"
#include "generate.h"


Coccodrillo::Coccodrillo(const std::string& nome, int eta, const char sesso, float peso, const std::string& cibo_preferito, std::string descrizione, float lunghezza, int numero_denti)
            : Animal(setNome(), comodo::generaNumeroCasuale(10, 80), comodo::setSesso(), comodo::generaNumeroCasuale(200.0, 900.0), setCiboPreferito(), setDescrizione()), lunghezza(comodo::generaNumeroCasuale(4, 7)), numero_denti(comodo::generaNumeroCasuale(60, 70)) {}
 
std::string Coccodrillo::getName() const { 
    return nome; 
}

std::string Coccodrillo::emettereVerso() const{
    return "Grrrr!\n";
}

const std::string setNome(){
    static unsigned int num;
    return "Coccodrillo " + std::to_string(num);
}

std::string setCiboPreferito(){
    return "Carne";
}

std::string setDescrizione(){
    //std::string a = "Nome: " + nome + "\nEta: " + std::to_string(eta) + "\nSesso: " + sesso + "\nPeso: " + std::to_string(peso) + "\nCibo preferito: " + /*cibo_preferito*/ + "\nLunghezza: " + std::to_string(lunghezza) + "\nNumero denti: " + std::to_string(numero_denti);
    //return a;
}