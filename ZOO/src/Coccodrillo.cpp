#include <iostream>
#include "Coccodrillo.h"
#include "generate.h"

Coccodrillo::Coccodrillo()
    : Animal(setNome(), setDescrizione(), comodo::generaNumeroCasuale(10, 100), comodo::setSesso(), comodo::generaNumeroCasuale(100, 800), new Carnivoro("Carne"), 5), lunghezza(comodo::generaNumeroCasuale(2.0, 5.0)), numero_denti(comodo::generaNumeroCasuale(60, 70)) {}

std::string Coccodrillo::emettereVerso() const{
    return "Grrrr!";
}

const std::string Coccodrillo::setNome(){
    static unsigned int num = 0;
    num ++;
    return "Coccodrillo " + std::to_string(num);
}

std::string Coccodrillo::setDescrizione(){
    return "Il coccodrillo è un rettile appartenente all'ordine dei Crocodylia. È un animale di grandi dimensioni, con un corpo allungato e muscoloso, zampe corte e una lunga coda. Si caratterizza per la presenza di una testa larga e piatta, dotata di mascelle forti e denti affilati. I coccodrilli hanno una pelle dura e squamosa, di solito di colore verde-oliva o marrone, che può variare a seconda delle specie.";
}