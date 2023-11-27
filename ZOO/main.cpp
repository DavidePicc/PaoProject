#include "viewer/mainMenu.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    MainMenu *menu = new MainMenu;
    menu->show();

    int result = app.exec();

    delete menu;// Liberazione della memoria allocata dinamicamente

    return result;
}
