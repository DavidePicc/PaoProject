#ifndef Coccodrillo_H
#define Coccodrillo_H
#include "Animal.h"

class Coccodrillo : public Animal {
private:
float lunghezza;
int numero_denti;

public:
    Coccodrillo(const std::string& nome, int eta, const char sesso, float peso, const std::string& cibo_preferito, std::string& descrizione, float lunghezza, int numero_denti;);

    std::string getName() const override { 
        //return "Coccodrillo"; 
        }
    void emettereVerso() const override {
       // std::cout << "Brrr!" << std::endl;
    }

    // METODI
};
#endif