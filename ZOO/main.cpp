#include "src/Coccodrillo.h"
#include "src/Leone.h"
#include "src/Pavone.h"///////////////Necessari ?

#include "viewer/mainMenu.h"



int main(int argc, char *argv[]){

    QApplication app(argc, argv);
    MainMenu menu;
    menu.show();

    return app.exec();
}