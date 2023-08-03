    #include "gameWidget.h"

    GameWidget::GameWidget(QWidget *parent) : QWidget(parent), soldi(1000) {//Setto i soldi ad una quota fissa, 1000 per iniziare
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
        createButton<Leone>(345, 55, "leone", leoni);
        createButton<Coccodrillo>(690, 138, "coccodrillo", coccodrilli);
        createButton<Pavone>(260, 200, "pavone", pavoni);
        createButton<Tartaruga>(565, 325, "tartaruga", tartarughe);
        createButton<Struzzo>(215, 430, "struzzo", struzzi);
        createButton<Giraffa>(750, 480, "giraffa", giraffe);

        //Creo l'orologio
        DigitalClock *clock = new DigitalClock(this);
        clock->show();

        //Mostro i soldi
        QLabel *money = new QLabel(this);
        money->setText("€ " + QString::number(soldi)); // Aggiungi "€" prima del numero
        money->move(630, 85);
        money->setStyleSheet("font-size: 30px; background-color: gold; border: 2px solid gold; border: 1px solid black;  border-radius: 10px;");
        money->show();

        
    }



    template <typename T>
    QPushButton* GameWidget::createButton(int x, int y, std::string animale, DLrecinto<T>& recinto) {
        QString var = "assets/" + QString::fromStdString(animale) + ".png";
        QPixmap pixmap(var);
        QIcon ButtonIcon(pixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::FastTransformation));

        QPushButton *button = new QPushButton(this);
        button->setIcon(ButtonIcon);
        button->setIconSize(QSize(80,80));
        button->setToolTip(QString::fromStdString(animale));//Se mi fermo sopra con il mouse vedo il nome dell'animale
        button->setCursor(Qt::PointingHandCursor);
        button->setStyleSheet("QPushButton {font-size: 50px; font-weight: bold; color: gray; background-color: transparent; border:none;}");
        button->move(x, y);

        // Connetti il segnale clicked() del bottone al tuo slot seeAnimals()
        connect(button, &QPushButton::clicked, [this, &recinto]() { this->template seeAnimals<T>(recinto); });

        return button;
    }

//DA RISTRUTTURARE SOSTITUENDO TEMPLATE CON EREDITARIETA' ?

/*void GameWidget::addAnimal(){

}



void GameWidget::giveFood(){

}*/