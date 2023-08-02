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

QPushButton* GameWidget::createButton(int x, int y) {
    QPushButton *button = new QPushButton("+", this);
    button->setCursor(Qt::PointingHandCursor);
    button->setStyleSheet("QPushButton {font-size: 50px; font-weight: bold; color: gray; background-color: transparent; border:none;}");
    button->move(x, y);

    // Connetti il segnale clicked() del bottone al tuo slot chooseAnimal()
    connect(button, &QPushButton::clicked, this, &GameWidget::chooseAnimal);

    return button;
}

// Adatta il metodo chooseAnimal:

void GameWidget::chooseAnimal() {
    QDialog *dialog = new QDialog(this);
    QListWidget *listWidget = new QListWidget(dialog);

    QStringList descriptions = {
        "Leone",
        "Coccodrillo",
        "Pavone",
        "Tartaruga",
        "Struzzo",
        "Giraffa"
    };

    QStringList imagePaths = {
        "assets/leone.png",
        "assets/coccodrillo.png",
        "assets/pavone.png",
        "assets/tartaruga.png",
        "assets/struzzo.png",
        "assets/giraffa.png"
    };

    for (int i = 0; i < 6; ++i) {
        QListWidgetItem *item = new QListWidgetItem(QIcon(imagePaths[i]), descriptions[i]);
        listWidget->addItem(item);
    }

    connect(listWidget, &QListWidget::itemClicked, this, &GameWidget::handleItemClicked);

    QHBoxLayout *layout = new QHBoxLayout(dialog);
    layout->addWidget(listWidget);
    dialog->setLayout(layout);

    dialog->exec(); 
}

void GameWidget::handleItemClicked(QListWidgetItem *item) {
    QString animalName = item->text();

    if (animalName == "Leone") {
        //animal = new Leone();
    } else if (animalName == "Coccodrillo") {
        //animal = new Coccodrillo();
    } else if (animalName == "Pavone") {
        //animal = new Pavone();
    } else if (animalName == "Tartaruga") {
        //animal = new Tartaruga();
    } else if (animalName == "Struzzo") {
        //animal = new Struzzo();
    } else if (animalName == "Giraffa") {
        //animal = new Giraffa();
    }
}
