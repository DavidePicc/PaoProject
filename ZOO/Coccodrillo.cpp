#include <iostream>
#include <random>
#include "Coccodrillo.h"
#include "generate.h"


Coccodrillo::Coccodrillo(const std::string& nome, int eta, const char sesso, float peso, const Alimentazione* type, std::string cibo, float lunghezza, int numero_denti)
            : Animal(setNome(), setDescrizione(), eta, sesso, peso, type), lunghezza(lunghezza), numero_denti(numero_denti) {
                descrizione = setDescrizione();
            }

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

static std::string setDescrizione(){
    return "Il coccodrillo è un rettile appartenente all'ordine dei Crocodylia. È un animale di grandi dimensioni, con un corpo allungato e muscoloso, zampe corte e una lunga coda. Si caratterizza per la presenza di una testa larga e piatta, dotata di mascelle forti e denti affilati. I coccodrilli hanno una pelle dura e squamosa, di solito di colore verde-oliva o marrone, che può variare a seconda delle specie.";
}