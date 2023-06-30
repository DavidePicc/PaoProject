#include <iostream>
#include <random>
#include "Coccodrillo.h"
#include "generate.h"


Coccodrillo::Coccodrillo(int eta, const char sesso, float peso, std::string cibo, float lunghezza, int numero_denti)
    : Animal(setNome(), setDescrizione(), eta, sesso, peso, new Carnivoro(cibo)), lunghezza(lunghezza), numero_denti(numero_denti) {}
    
std::string Coccodrillo::getName() const { 
    return nome; 
}

std::string Coccodrillo::emettereVerso() const{
    return "Grrrr!";
}

const std::string Coccodrillo::setNome(){
    static unsigned int num = 1;
    return "Coccodrillo " + std::to_string(num);
}

std::string Coccodrillo::setDescrizione(){
    return "Il coccodrillo è un rettile appartenente all'ordine dei Crocodylia. È un animale di grandi dimensioni, con un corpo allungato e muscoloso, zampe corte e una lunga coda. Si caratterizza per la presenza di una testa larga e piatta, dotata di mascelle forti e denti affilati. I coccodrilli hanno una pelle dura e squamosa, di solito di colore verde-oliva o marrone, che può variare a seconda delle specie.";
}