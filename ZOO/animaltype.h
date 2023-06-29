#ifndef ANIMALTYPE_H
#define ANIMALTYPE_H

#include <string>

// Classe Alimentazione
class Alimentazione {//Astratta
protected:
    std::string cibo_preferito;

public:
    //Costruttore
    Alimentazione(const std::string& cibo_preferito);

    //Costruttore di copia
    Alimentazione(const Alimentazione& other);

    virtual ~Alimentazione();/////////////////////////////////////

    Alimentazione& operator=(const Alimentazione& other);
    
    void setCiboPreferito(std::string a);

    std::string getCiboPreferito() const;

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