    #include "gameWidget.h"

    GameWidget::GameWidget(QWidget *parent) : QWidget(parent), soldi(100) {//Setto i soldi ad una quota fissa, 1000 per iniziare
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
        createButton(320, 48, "leone", leoni);
        createButton(680, 130, "coccodrillo", coccodrilli);
        createButton(255, 190, "pavone", pavoni);
        createButton(560, 315, "tartaruga", tartarughe);
        createButton(210, 420, "struzzo", struzzi);
        createButton(745, 470, "giraffa", giraffe);

        //Creo l'orologio
        DigitalClock *clock = new DigitalClock(this);
        clock->show();

        //Mostro i soldi
        QLabel *money = new QLabel(this);
        money->setText("€ " + QString::number(soldi)); // Aggiungi "€" prima del numero
        money->move(630, 85);
        money->setStyleSheet("font-size: 30px; background-color: gold; border: 2px solid gold; border: 1px solid black;  border-radius: 10px;");
        money->show();

        //Per aggiornare i soldi ogni secondo tramite timer
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, [this, money]() {
            soldi += leoni.makeMoney() /10 ;
            soldi += coccodrilli.makeMoney() /10 ;
            soldi += pavoni.makeMoney() /10 ;
            soldi += tartarughe.makeMoney() /10 ;
            soldi += struzzi.makeMoney() /10 ;
            soldi += giraffe.makeMoney() /10 ;

            money->setText("€ " + QString::number(soldi));
            money->adjustSize();
        });
        timer->start(1000); // Aggiorna ogni 5 secondi (5000 millisecondi)

        
    }



    QPushButton* GameWidget::createButton(int x, int y, std::string animale, DLrecinto& recinto) {
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
        healthBar->setValue(recinto.getVita()); // Imposta il valore della salute
        healthBar->setStyleSheet("QProgressBar { border: 1px solid black; border-radius: 0px; text-align: center; height: 15px; }"
                                "QProgressBar::chunk { background-color: #FF4D4D; width: 10px; }"); // Imposta lo stile, incluso il colore rosso

        //Label numero animali
        QLabel* numAnimali = new QLabel("Numero animali: " + QString::number(recinto.getSize()));
        numAnimali->setStyleSheet("QLabel{font-size: 15px; font-weight: bold; text-align: center;}");

        //Per aggiornare la vita ogni 2 secondi tramite timer
        QTimer *timer = new QTimer(this);

        // Connessione del timer alla slot di aggiornamento
        connect(timer, &QTimer::timeout, [this, &recinto, healthBar, numAnimali]() {
            recinto.riduciVita();
            healthBar->setValue(recinto.getVita()); // Aggiorna la barra della salute

            if(recinto.getVita() == 0 && recinto.getSize() > 0)
                recinto.remove();

            numAnimali->setText("Numero animali: " + QString::number(recinto.getSize()));
        });

        // Avvia il timer per aggiornarsi ogni 2 secondi
        timer->start(2000);


        // Crea un QVBoxLayout
        QVBoxLayout *layout = new QVBoxLayout;

        // Aggiungi il bottone e la barra di progresso al layout
        layout->addWidget(numAnimali);
        layout->addWidget(button);
        layout->addWidget(healthBar);

        // Crea un QWidget come contenitore
        QWidget *container = new QWidget(this);
        container->setLayout(layout); // Imposta il layout del widget contenitore
        container->move(x, y); // Sposta il contenitore


        // Connetti il segnale clicked() di button al tuo slot seeAnimals()
        connect(button, &QPushButton::clicked, [this, &recinto, healthBar]() {this-> seeAnimals(recinto, healthBar);});

        return button;
    }

    // definizione di seeAnimals
    void GameWidget::seeAnimals(DLrecinto& recinto,  QProgressBar* healthBar) {
        QDialog *dialog = new QDialog(this);
        dialog->setWindowTitle("Recinto con " + QString::number(recinto.getSize()) + (recinto.getSize() == 1 ? " animale" : " animali"));

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
            emptyLabel->setStyleSheet("QLabel { font: bold 20px;}");
            emptyLabel->setAlignment(Qt::AlignCenter);
            buttonLayout2->addWidget(emptyLabel);
        }else{
            for(unsigned int i=0; i<recinto.getSize(); i++){
                QPushButton *button = new QPushButton(QString::fromStdString((*recinto[i]).getName()), buttonWidget);
                buttonLayout2->addWidget(button);
                connect(button, &QPushButton::clicked, [this, &recinto, i](){ this->animalDetails(*recinto[i]); });
            }
        }

        // Crea un QScrollArea
        QScrollArea *scrollArea = new QScrollArea(dialog);
        scrollArea->setWidget(buttonWidget); // Imposta buttonWidget come widget figlio di scrollArea
        scrollArea->setWidgetResizable(true); // Permette al widget figlio di ridimensionarsi con scrollArea

        QVBoxLayout *layout = new QVBoxLayout(dialog);
        layout->addWidget(scrollArea);
        layout->addLayout(buttonLayout); // Aggiunge il layout orizzontale al layout verticale
        
        // Controllo sull'attributo "soldi"
        if (soldi <= 0) {
            addButton->setEnabled(false); // Disabilita il pulsante addButton
            addButton->setToolTip("Non hai abbastanza soldi per questa opzione"); // Imposta un messaggio di aiuto
        }

        connect(addButton, &QPushButton::clicked, [this, dialog, &recinto, healthBar](){ 
            this->addAnimal(recinto); 
            this->seeAnimals(recinto, healthBar); 
            dialog->accept(); // chiude la finestra di dialogo attuale
        });

        connect(foodButton, &QPushButton::clicked, [this, dialog, &recinto, healthBar]() { 
            this->giveFood(recinto, healthBar); 
            dialog->accept(); // chiude la finestra di dialogo attuale
            this->seeAnimals(recinto, healthBar); 
        });       
        
        dialog->exec();
    }



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


void GameWidget::addAnimal(DLrecinto& recinto){
    std::shared_ptr<Animal> a;

    if(&recinto == &leoni)
        a = std::make_shared<Leone>();
    else if(&recinto == &coccodrilli)
        a = std::make_shared<Coccodrillo>();
    else if(&recinto == &pavoni)
        a = std::make_shared<Pavone>();
    else if(&recinto == &tartarughe)
        a = std::make_shared<Tartaruga>();
    else if(&recinto == &struzzi)
        a = std::make_shared<Struzzo>();
    else if(&recinto == &giraffe)
        a = std::make_shared<Giraffa>();
    else
        throw("Errore 1\n");

    recinto.insert(a);
    soldi -= (*a).getCosto();
}



void GameWidget::giveFood(DLrecinto& recinto, QProgressBar* healthBar) {
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("Sfama");

    QVBoxLayout *layout = new QVBoxLayout(dialog); // Imposta il layout del dialogo

    QLabel *sceltaLabel = new QLabel("Scegli tra le seguenti opzioni: ", dialog);
    QFont font = sceltaLabel->font(); // Ottieni il font corrente
    font.setBold(true); // Imposta il grassetto
    sceltaLabel->setFont(font); // Applica il nuovo font
    sceltaLabel->setAlignment(Qt::AlignCenter); // Allinea la label al centro
    layout->addWidget(sceltaLabel); // Aggiungi la label al layout

    // Crea due nuovi layout orizzontali per i pulsanti
    QHBoxLayout *buttonLayout1 = new QHBoxLayout;
    QHBoxLayout *buttonLayout2 = new QHBoxLayout;

    layout->addLayout(buttonLayout1); 
    layout->addLayout(buttonLayout2); 

    // Crea i quattro pulsanti
    QPushButton *button1 = new QPushButton("25%\n€ " + QString::number(recinto.moneyTo(25)), dialog);
    QPushButton *button2 = new QPushButton("50%\n€ " + QString::number(recinto.moneyTo(50)), dialog);
    QPushButton *button3 = new QPushButton("75%\n€ " + QString::number(recinto.moneyTo(75)), dialog);
    QPushButton *button4 = new QPushButton("100%\n€ " + QString::number(recinto.moneyTo(100)), dialog);

    // Aggiungi i pulsanti ai layout orizzontali
    buttonLayout1->addWidget(button1);
    buttonLayout1->addWidget(button2);
    buttonLayout2->addWidget(button3);
    buttonLayout2->addWidget(button4);

    // Controllo sull'attributo "soldi"
    if (soldi < recinto.moneyTo(25) || recinto.getVita() >= 25) {
        button1->setEnabled(false); // Disabilita il pulsante 1
        button1->setToolTip("Non hai abbastanza soldi per questa opzione"); // Imposta un messaggio di aiuto
    }

    if (this->soldi < recinto.moneyTo(50) || recinto.getVita() >= 50) {
        button2->setEnabled(false); // Disabilita il pulsante 2
        button2->setToolTip("Non hai abbastanza soldi per questa opzione"); // Imposta un messaggio di aiuto
    }

    if (this->soldi < recinto.moneyTo(75) || recinto.getVita() >= 75) {
        button3->setEnabled(false); // Disabilita il pulsante 3
        button3->setToolTip("Non hai abbastanza soldi per questa opzione"); // Imposta un messaggio di aiuto
    }

    if (this->soldi < recinto.moneyTo(100) || recinto.getVita() >= 100) {
        button4->setEnabled(false); // Disabilita il pulsante 1
        button4->setToolTip("Non hai abbastanza soldi per questa opzione"); // Imposta un messaggio di aiuto
    }

    // Connettiamo i segnali dei pulsanti ad uno slot appropriato (da implementare)
    connect(button1, &QPushButton::clicked, [&]() {
        soldi -= recinto.moneyTo(25);
        recinto.setVita(25);
        healthBar->setValue(25);
        dialog->close();
    });

    connect(button2, &QPushButton::clicked, [&]() {
        soldi -= recinto.moneyTo(50);
        recinto.setVita(50);
        healthBar->setValue(50);
        dialog->close();
    });

    connect(button3, &QPushButton::clicked, [&]() {
        soldi -= recinto.moneyTo(75);
        recinto.setVita(75);
        healthBar->setValue(75);
        dialog->close();
    });

    connect(button4, &QPushButton::clicked, [&]() {
        soldi -= recinto.moneyTo(100);
        recinto.setVita(100);
        healthBar->setValue(100);
        dialog->close();
    });

    dialog->exec();
}

//Funzione per fare in modo che schiacciando esc esca un menù
void GameWidget::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Escape) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Menu di pausa", "Vuoi salvare la partita o tornare al menu principale?",
                                      QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

        if (reply == QMessageBox::Save) {
            // Codice per salvare la partita
        } else if (reply == QMessageBox::Discard) {
            this->close();
        }else {
            QWidget::keyPressEvent(event);
        }
    }
}