#include "mainMenu.h"
#include "gameWidget.h"

MainMenu::MainMenu(QWidget *parent) : QWidget(parent) {
    QPixmap pixmap("assets/ZooCover.png"); // Carica l'immagine

    // Imposta la dimensione della finestra sulla dimensione dell'immagine
    this->setFixedSize(pixmap.width(), pixmap.height()-50);

    // Imposta l'immagine di sfondo
    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap);
    this->setPalette(palette);

    // Ottieni le dimensioni dello schermo
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;

    // Posiziona la finestra al centro dello schermo
    this->move(x, y);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QLabel *titleLabel = new QLabel("ZOO SIMULATOR", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("QLabel { font-size: 70px; font-weight: bold; color: white; }");
    mainLayout->addWidget(titleLabel);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    mainLayout->addLayout(buttonsLayout);

    QPushButton *nuovaPartita = new QPushButton("Nuova partita", this);
    QPushButton *caricaPartita = new QPushButton("Carica partita", this);
    nuovaPartita->setStyleSheet("QPushButton { font-size: 20px; font-weight: bold; background-color: black; color: white; height : 50px}");
    caricaPartita->setStyleSheet("QPushButton { font-size: 20px; font-weight: bold; background-color: black; color: white; height : 50px}");

    buttonsLayout->addWidget(nuovaPartita);
    buttonsLayout->addWidget(caricaPartita);

    this->setLayout(mainLayout);

    nuovaPartita->setCursor(Qt::PointingHandCursor);
    caricaPartita->setCursor(Qt::PointingHandCursor);

    // Collegamento dei segnali dei bottoni ai rispettivi slot
    connect(nuovaPartita, &QPushButton::clicked, this, &MainMenu::handleNewGameButton);
    connect(caricaPartita, &QPushButton::clicked, this, &MainMenu::handleLoadGameButton);
}




void MainMenu::handleNewGameButton() {
    GameWidget *gameWidget = new GameWidget();
    gameWidget->show();

    this->close(); // Chiudiamo il MainMenu
}

void MainMenu::handleLoadGameButton() {
    // Qui puoi gestire il caricamento di una partita esistente
    // Come esempio, creo semplicemente un nuovo GameWidget
    //GameWidget *gameWidget = new GameWidget();
    //gameWidget->show();

    //this->close(); // Chiudiamo il MainMenu
}
