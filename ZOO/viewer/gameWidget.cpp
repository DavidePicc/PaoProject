#include "gameWidget.h"

GameWidget::GameWidget(QWidget *parent) : QWidget(parent) {
    QPixmap pixmap("assets/map.jpg"); // Carica l'immagine

    // Crea una QLabel e imposta l'immagine
    QLabel *label = new QLabel(this);
    label->setPixmap(pixmap);

    // Imposta la dimensione della finestra sulla dimensione dell'immagine
    this->setFixedSize(pixmap.width(), pixmap.height());

    // Ottieni le dimensioni dello schermo
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;

    // Posiziona la finestra al centro dello schermo
    this->move(x, y);

    //Creo i bottoni nelle coordinate fisse
    QPushButton *recinto1 = createButton(350, 60);
    QPushButton *recinto2 = createButton(700, 150);
    QPushButton *recinto3 = createButton(270, 210);
    QPushButton *recinto4 = createButton(575, 335);
    QPushButton *recinto5 = createButton(220, 440);
    QPushButton *recinto6 = createButton(760, 490);

    //Creo l'orologio
    DigitalClock *clock = new DigitalClock(this);
    clock->show();

}

//Metodo per creare bottone con caratteristiche specificate
QPushButton* GameWidget::createButton(int x, int y) {
    QPushButton *button = new QPushButton("+", this);
    button->setCursor(Qt::PointingHandCursor);
    button->setStyleSheet("QPushButton {font-size: 50px; font-weight: bold; color: gray; background-color: transparent; border:none;}");
    button->move(x, y);
    return button;
}