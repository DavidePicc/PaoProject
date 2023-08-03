#include "src/Coccodrillo.h"
#include "src/Leone.h"
#include "src/Pavone.h"
#include "viewer/mainMenu.h"
#include "viewer/gameWidget.h"



int main(int argc, char *argv[]){
    
    QApplication app(argc, argv);
    MainMenu menu;
    menu.show();

    return app.exec();
}