#ifndef ANIMAL_DETAILS
#define ANIMAL_DETAILS

#include "animalVisitor.h"

class animalDetails : public animalVisitor {
    public:
        virtual void visitCoccodrillo(Coccodrillo& c) override;
        virtual void visitGiraffa(Giraffa& g) override;
        virtual void visitLeone(Leone& l) override;
        virtual void visitPavone(Pavone& p) override;
        virtual void visitStruzzo(Struzzo& s) override;
        virtual void visitTartaruga(Tartaruga& t) override;
};

#endif