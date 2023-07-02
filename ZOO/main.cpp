#include "src/Coccodrillo.h"
#include "src/Leone.h"
#include "src/Pavone.h"
#include "viewer/MainWindow.h"



int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    QWidget window;
    window.setGeometry(100, 100, 800, 600); // Imposta le dimensioni e la posizione della finestra
    window.setStyleSheet("QWidget { background-image: url(ZOO/assets/ZooCover.png); }");

    QVBoxLayout *mainLayout = new QVBoxLayout(&window);
    QLabel *titleLabel = new QLabel("ZOO SIMULATOR", &window);
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    mainLayout->addLayout(buttonsLayout);

    QPushButton *nuovaPartita = new QPushButton("Nuova partita", &window);
    QPushButton *caricaPartita = new QPushButton("Carica partita", &window);


    buttonsLayout->addWidget(nuovaPartita);
    buttonsLayout->addWidget(caricaPartita);

    window.setLayout(mainLayout);
    window.show();

    return app.exec();
}