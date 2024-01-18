#ifndef ANIMALTYPE_H
#define ANIMALTYPE_H

#include <string>

// Classe Alimentazione
class Alimentazione {//Astratta
protected:
    std::string cibo_preferito;

public:
    //Costruttori
    Alimentazione();
    Alimentazione(const std::string& cibo_preferito);

    //Costruttore di copia
    Alimentazione(const Alimentazione& other);

    Alimentazione& operator=(const Alimentazione& other);
    
    void setCiboPreferito(std::string a);

    std::string getCiboPreferito() const;
};

// Sottoclasse Erbivoro
class Erbivoro : virtual public Alimentazione {
public:
    Erbivoro();
    Erbivoro(const std::string& cibo_preferito);
};

// Sottoclasse Carnivoro
class Carnivoro : virtual public Alimentazione {
public:
    Carnivoro();
    Carnivoro(const std::string& cibo_preferito);
};

// Sottoclasse Onnivoro (sottoclasse di Carnivoro)
class Onnivoro : public Carnivoro, public Erbivoro {
public:
    Onnivoro();
    Onnivoro(const std::string& cibo_preferito);
};

#endif