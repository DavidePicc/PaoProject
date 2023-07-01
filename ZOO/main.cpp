#include "src/Coccodrillo.h"
#include "src/Leone.h"
#include "src/Pavone.h"
//#include <iostream>

int main(int argc, char *argv[]){
    //Prova coccodrillo
    {
        int eta = 10;
        char sesso = 'F';
        float peso = 500.0;
        std::string ciboPreferito = "Carne";
        float lunghezza = 5.5;
        int numeroDenti = 80;

        Coccodrillo c1(eta, sesso, peso, ciboPreferito, lunghezza, numeroDenti);
        std::cout << c1.nome << " " << c1.emettereVerso() << " " << c1.numero_denti << " " << c1.getName() << std::endl;
    }

    //Prova leone
    {
        Leone leone(5, 'M', 150.5, "Carne", 10, true);
        std::cout << leone.getName() << std::endl;
    }

    //Prova pavone
    {
        Pavone p(2, 'M', 20, "Mangime", 1.7);
        std::cout << p.getName() << " " << p.emettereVerso() <<std::endl;
    }
}
