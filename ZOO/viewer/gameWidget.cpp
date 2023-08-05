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

        //PROVA////////////////////////////////////////////////////////
        leoni.insert(Leone());
        coccodrilli.insert(Coccodrillo());
        pavoni.insert(Pavone());
        tartarughe.insert(Tartaruga());
        struzzi.insert(Struzzo());
        giraffe.insert(Giraffa());

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

        //Creo il bottone
        QPushButton *button = new QPushButton(this);
        button->setIcon(ButtonIcon);
        button->setIconSize(QSize(80,80));
        button->setToolTip(QString::fromStdString(animale));//Se mi fermo sopra con il mouse vedo il nome dell'animale
        button->setCursor(Qt::PointingHandCursor);
        button->setStyleSheet("QPushButton {font-size: 50px; font-weight: bold; color: gray; background-color: transparent; border:none;}");
        button->move(x, y);

        // Crea una QProgressBar
        QProgressBar *healthBar = new QProgressBar;
        healthBar->setRange(0, 100); 
        healthBar->setValue(recinto.getVita()); // Imposta il valore iniziale a 50 (o qualsiasi altro valore iniziale della salute)
        healthBar->setStyleSheet("QProgressBar { border: 1px solid black; border-radius: 0px; text-align: center; }"
                                "QProgressBar::chunk { background-color: red; width: 10px; }"); // Imposta lo stile, incluso il colore rosso

        // Crea un QVBoxLayout
        QVBoxLayout *layout = new QVBoxLayout;

        // Aggiungi il bottone e la barra di progresso al layout
        layout->addWidget(button);
        layout->addWidget(healthBar);

        // Crea un QWidget come contenitore
        QWidget *container = new QWidget(this);
        container->setLayout(layout); // Imposta il layout del widget contenitore
        container->move(x, y); // Sposta il contenitore


        // Connetti il segnale clicked() di button al tuo slot seeAnimals()
        connect(button, &QPushButton::clicked, [this, &recinto, healthBar]() {this->template seeAnimals<T>(recinto, healthBar);});

        return button;
    }

    // definizione di seeAnimals come un metodo template all'interno della classe
    template <typename T>
    void GameWidget::seeAnimals(const DLrecinto<T>& recinto,  QProgressBar* healthBar) {
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle("Recinto");

        //Aggiungo bottone Aggiungi animale
        QPushButton *addButton = new QPushButton("Aggiungi Animale", dialog);
        addButton->setStyleSheet("color: black; background-color: #D3D3D3;");
        addButton->setFixedHeight(50);
        addButton->setCursor(Qt::PointingHandCursor);

        //Aggiungo bottone Sfama
        QPushButton *foodButton = new QPushButton("Sfama", dialog);
        foodButton->setStyleSheet("color: black; background-color: #D3D3D3;");
        foodButton->setFixedHeight(50);
        foodButton->setCursor(Qt::PointingHandCursor);

        QHBoxLayout *buttonLayout = new QHBoxLayout(); // Crea un nuovo layout orizzontale
        buttonLayout->addWidget(addButton); // Aggiunge il primo bottone al layout orizzontale
        buttonLayout->addWidget(foodButton); // Aggiunge il secondo bottone al layout orizzontale
        

        // Crea un widget per contenere i pulsanti
        QWidget *buttonWidget = new QWidget(dialog);

        // Crea un layout per i pulsanti
        QVBoxLayout *buttonLayout2 = new QVBoxLayout(buttonWidget);

        if(recinto.getSize() == 0){
            QLabel *emptyLabel = new QLabel("Gabbia vuota", dialog);
            QFont font;
            font.setPointSize(20);
            font.setBold(true);
            emptyLabel->setFont(font);
            emptyLabel->setAlignment(Qt::AlignCenter);
            buttonLayout2->addWidget(emptyLabel);
        }else{
            for(unsigned int i=0; i<recinto.getSize(); i++){
                QPushButton *button = new QPushButton(QString::fromStdString(recinto[i].getName()), buttonWidget);
                buttonLayout2->addWidget(button);
                connect(button, &QPushButton::clicked, [this, &recinto, i](){ this->animalDetails(recinto[i]); });
            }
        }

        // Crea un QScrollArea
        QScrollArea *scrollArea = new QScrollArea(dialog);
        scrollArea->setWidget(buttonWidget); // Imposta buttonWidget come widget figlio di scrollArea
        scrollArea->setWidgetResizable(true); // Permette al widget figlio di ridimensionarsi con scrollArea

        QVBoxLayout *layout = new QVBoxLayout(dialog);
        layout->addWidget(scrollArea);
        layout->addLayout(buttonLayout); // Aggiunge il layout orizzontale al layout verticale
        

        connect(addButton, &QPushButton::clicked, this, &GameWidget::addAnimal);
        //connect(foodButton, &QPushButton::clicked, [this, &recinto, healthBar]() { this->giveFood(recinto, healthBar); });        

        dialog->exec();
    }


//DA RISTRUTTURARE SOSTITUENDO TEMPLATE CON EREDITARIETA' ?

void GameWidget::animalDetails(Animal& a){
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Dettagli di " + QString::fromStdString(a.getName()));

    QLabel *nameLabel = new QLabel(QString::fromStdString(a.getName()), dialog);
    //QLabel *descriptionLabel = new QLabel(QString::fromStdString(a.setDescrizione()), dialog);
    // Aggiungi qui altri QLabel per mostrare altre proprietà dell'animale...

    //Bottone per emettere il verso ?
    QPushButton *bottoneVerso = new QPushButton("Emettere verso", dialog);
    //Connessione al verso

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(nameLabel);
    layout->addWidget(bottoneVerso);

    dialog->setLayout(layout);
    dialog->exec();
}


void GameWidget::addAnimal(){
    //
}



void GameWidget::giveFood(QProgressBar* healthBar){
    /*
    if(soldi > (100 - recinto.getVita()) * recinto.getSize()){//Se ho abbastanza soldi
        soldi -= (100 - recinto.getVita()) * recinto.getSize();
        recinto.setVita(100);
    }else{//Se non ho abbastanza soldi
        recinto.setVita(((100 - recinto.getVita()) * recinto.getSize()) * (soldi / 100));
        soldi = 0;
    }
    healthBar->setValue(recinto.getVita());
    */
}