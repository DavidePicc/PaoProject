#ifndef ANIMALTYPE_H
#define ANIMALTYPE_H

#include <string>

// Classe Alimentazione
class Alimentazione {
protected:
    std::string cibo_preferito;

public:
    Alimentazione(const std::string& cibo_preferito);

    Alimentazione(const Alimentazione& other); // CDC

    Alimentazione& operator=(const Alimentazione& other);
    
    std::string getCiboPreferito() const;

    virtual ~Alimentazione();

    // METODI
};

// Sottoclasse Erbivoro
class Erbivoro : public Alimentazione {
public:
    Erbivoro();

    // METODI
};

// Sottoclasse Carnivoro
class Carnivoro : public Alimentazione {
public:
    Carnivoro();

    // METODI
};

// Sottoclasse Onnivoro (sottoclasse di Carnivoro)
class Onnivoro : public Carnivoro, public Erbivoro {
public:
    Onnivoro();

    // METODI
};

#endif