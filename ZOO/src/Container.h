/*#ifndef VETTORE_H
#define VETTORE_H

#include <iostream>
#include "Animal.h"

class Vettore {
private:
    Animal* array;  // array che conterrà gli animali
    int size;

public:
    // Costruttore di default
    Vettore();
    // Costruttore con size specificata
    Vettore(int size);
    // Costruttore di copia
    Vettore(const Vettore& other);
    // Distruttore
    ~Vettore();

    // Assegnazione di un vettore di animali ad un altro
    Vettore& operator=(const Vettore& other);

    // Unire due vettori di animali in un unico vettore più grande
    void Unite(const Vettore& other);

    // Overloading dell'operatore di output
    friend std::ostream& operator<<(std::ostream& os, const Vettore& v);

    // Overloading dell'operatore di accesso []
    Animal& operator[](int index);
};

#endif  // VETTORE_H
*/