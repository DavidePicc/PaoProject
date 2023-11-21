#include "gameWidget.h"
#include <iostream>

//Nuova partita
GameWidget::GameWidget() : gameModel(), clock(this) {   
    visualizer();
}

//Carica partita
GameWidget::GameWidget(std::string filename): gameModel(), clock(this){
    QString ora;
    if(DataManager::readData(filename, gameModel, ora) == true){
        visualizer();
    }
    else
        qDebug() << "Errore nel caricamento della partita";
}

void GameWidget::visualizer(){
    QPixmap pixmap("assets/map.jpg"); // Carica l'immagine di sfondo
    backgroundLabel->setPixmap(pixmap);
    mainLayout->addWidget(backgroundLabel);

    // Imposta il layout nella finestra principale
    mainLayout->addWidget(emptyLabel);

    // Imposta la dimensione della finestra principale(mainWidget)
    emptyLabel->setFixedSize(250, pixmap.height()); 
    this->setFixedSize(pixmap.width()+250, pixmap.height());

    // Ottieni le dimensioni dello schermo
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int x = (screenGeometry.width() - this->width()) / 2;
    int y = (screenGeometry.height() - this->height()) / 2;
    // Posiziona la finestra al centro dello schermo
    this->move(x, y);
	
    //Creo i bottoni nelle coordinate fisse
    createButton(310, 30, "leone", gameModel.getLeoni());
    createButton(660, 105, "coccodrillo", gameModel.getCoccodrilli());
    createButton(245, 185, "pavone", gameModel.getPavoni());
    createButton(528, 290, "tartaruga", gameModel.getTartarughe());
    createButton(200, 410, "struzzo", gameModel.getStruzzi());
    createButton(735, 445, "giraffa", gameModel.getGiraffe());

    //Creo l'orologio
    clock.show();
    clock.raise();

    //Mostro i soldi
    QLabel *money = new QLabel(this);
    money->setText("€ " + QString::number(gameModel.getSoldi())); // Aggiungi "€" prima del numero
    money->move(50, 40);
    money->setStyleSheet("font-size: 30px; background-color: gold; border: 2px solid gold; border: 1px solid black;  border-radius: 10px;");
    money->show();

    //Per aggiornare i soldi ogni secondo tramite timer
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this, money]() {
        gameModel.updateSoldi();

        money->setText("€ " + QString::number(gameModel.getSoldi()));
        money->adjustSize();
    });
    timer->start(1000); // Aggiorna ogni 1 secondi (1000 millisecondi)

    this->show();
    mainWidget->show();
}


void GameWidget::createButton(int x, int y, std::string animale, DLrecinto& recinto) {
    QString var = "assets/" + QString::fromStdString(animale) + ".png";
    QPixmap pixmap(var);
    QIcon ButtonIcon(pixmap.scaled(80, 80, Qt::KeepAspectRatio, Qt::FastTransformation));

    //Creo il bottone
    QPushButton *button = new QPushButton(backgroundLabel);
    button->setIcon(ButtonIcon);
    button->setIconSize(QSize(80,100));
    button->setToolTip(QString::fromStdString(animale));//Se mi fermo sopra con il mouse vedo il nome dell'animale
    button->setCursor(Qt::PointingHandCursor);
    button->setStyleSheet("QPushButton {font-size: 50px; font-weight: bold; color: gray; background-color: transparent; border:none;}");
    button->move(x, y);
    button->show();

    // Crea una QProgressBar
    QProgressBar *healthBar = new QProgressBar;
    healthBar->setRange(0, 100); 
    healthBar->setValue(recinto.getVita()); // Imposta il valore della salute
    healthBar->setStyleSheet("QProgressBar { border: 1px solid black; border-radius: 0px; text-align: center; height: 15px; }"
                            "QProgressBar::chunk { background-color: #FF4D4D; width: 15px; }"); // Imposta lo stile, incluso il colore rosso

    //Creo label numero animali
    QLabel* numAnimali = new QLabel("Numero animali: " + QString::number(recinto.getSize()));
    numAnimali->setStyleSheet("QLabel{font-size: 15px; font-weight: bold; text-align: center;}");

    //Per aggiornare la vita ogni 2 secondi tramite timer
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this, &recinto, healthBar, numAnimali]() {    // Connessione del timer alla slot di aggiornamento
        recinto.riduciVita();
        healthBar->setValue(recinto.getVita()); // Aggiorna la barra della salute

        if(recinto.getVita() == 0 && recinto.getSize() > 0)
            recinto.remove();

        numAnimali->setText("Numero animali: " + QString::number(recinto.getSize()));
    });
    timer->start(2000);    // Avvia il timer per aggiornarsi ogni 2 secondi


    // Crea un QVBoxLayout
    QVBoxLayout *layout = new QVBoxLayout;

    // Aggiungi il bottone e la barra di progresso al layout
    layout->addWidget(numAnimali);
    layout->addWidget(button);
    layout->addWidget(healthBar);

    // Crea un QWidget come contenitore
    QWidget *container = new QWidget(backgroundLabel);
    container->setLayout(layout); // Imposta il layout del widget contenitore
    container->move(x, y); // Sposta il contenitore
    container->show();//mostra il layout con barra e numero animali

    // Connetti il segnale clicked() di button al tuo slot seeAnimals()
    connect(button, &QPushButton::clicked, [this, &recinto, healthBar]() {
        this->seeAnimals(recinto, healthBar, recinto.getSize());});
    }

//DA MIGLIORARE: non si aggiorna se muore animale
// definizione di seeAnimals
void GameWidget::seeAnimals(DLrecinto& recinto,  QProgressBar* healthBar, size_t numAnimali) {
    qDeleteAll(emptyLabel->children());//puliza della label per nuovo seeAnimals()

    QWidget *dialog = new QWidget(emptyLabel);
    
    //QUI era la searchline

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

    // Crea un nuovo layout orizzontale
    QHBoxLayout *buttonLayout = new QHBoxLayout(); 
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

    //Creo label titolo
    QLabel *titolo = new QLabel("Recinto con " + QString::number(recinto.getSize()) + (recinto.getSize() == 1 ? " animale" : " animali"));
    titolo->setStyleSheet("QLabel{font-size: 20px; font-weight: bold; text-align: center;}");

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(titolo);
    layout->addWidget(scrollArea);
    layout->addLayout(buttonLayout); // Aggiunge il layout orizzontale al layout verticale
    
    // Controllo sull'attributo "soldi"
    if (gameModel.getSoldi() <= 0) {
        addButton->setEnabled(false); // Disabilita il pulsante addButton
        addButton->setToolTip("Non hai abbastanza soldi per questa opzione"); // Imposta un messaggio di aiuto
    }
    
    //Evento aggiungi animale
    connect(addButton, &QPushButton::clicked, [this, dialog, &recinto, healthBar](){ 
        this->gameModel.addAnimal(recinto); 
        dialog->close(); // chiude la finestra di dialogo attuale
        this->seeAnimals(recinto, healthBar, recinto.getSize()); 
    });

    //Evento sfama
    connect(foodButton, &QPushButton::clicked, [this, dialog, &recinto, healthBar]() { 
        this->foodSlot(recinto, healthBar); 
        dialog->close(); // chiude la finestra di dialogo attuale        
        this->seeAnimals(recinto, healthBar, recinto.getSize()); 
    });     

    dialog->show();

    //BARRA RICERCA
        QLineEdit *searchLineEdit = new QLineEdit(emptyLabel); //non cambia se metto dentro dialog o searchline
        searchLineEdit->setPlaceholderText("Cerca per nome dentro al recinto");
        // Connessione del segnale returnPressed()
        connect(searchLineEdit, &QLineEdit::returnPressed, [this, &recinto, searchLineEdit]() {
        QString testoRicerca = searchLineEdit->text(); 
        eseguiRicerca(recinto, testoRicerca);
        });

        searchLineEdit->move(0,0);//da sistemare la posizione
        searchLineEdit->show();
    //BARRA RICERCA

/*
    //Per aggiornare la lista nel caso di rimozione animali
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this, &recinto, dialog, healthBar, numAnimali]() {    // Connessione del timer alla slot di aggiornamento
        if(dialog->isVisible() && recinto.getSize() != numAnimali){
            dialog->close(); // chiude la finestra di dialogo attuale
            this->seeAnimals(recinto, healthBar, recinto.getSize()); 
        }
    });
    timer->start(1000);    // Avvia il timer per aggiornarsi ogni 1 secondo
*/
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


void GameWidget::foodSlot(DLrecinto& recinto, QProgressBar *healthBar) {
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
    if (gameModel.enoughMoney(recinto, 25)) {
        button1->setEnabled(false); // Disabilita il pulsante 1
        button1->setToolTip("Non hai abbastanza soldi per questa opzione"); // Imposta un messaggio di aiuto
    }

    if (gameModel.enoughMoney(recinto, 50)) {
        button2->setEnabled(false); // Disabilita il pulsante 3
        button2->setToolTip("Non hai abbastanza soldi per questa opzione"); // Imposta un messaggio di aiuto
    }

    if (gameModel.enoughMoney(recinto, 75)) {
        button3->setEnabled(false); // Disabilita il pulsante 3
        button3->setToolTip("Non hai abbastanza soldi per questa opzione"); // Imposta un messaggio di aiuto
    }

    if (gameModel.enoughMoney(recinto, 100)) {
        button4->setEnabled(false); // Disabilita il pulsante 4
        button4->setToolTip("Non hai abbastanza soldi per questa opzione"); // Imposta un messaggio di aiuto
    }

    // Connettiamo i segnali dei pulsanti ad uno slot appropriato (da implementare)
    connect(button1, &QPushButton::clicked, [&]() {
        gameModel.giveFood(recinto, 25);
        healthBar->setValue(25);
        dialog->close();
    });

    connect(button2, &QPushButton::clicked, [&]() {
        gameModel.giveFood(recinto, 50);
        healthBar->setValue(50);
        dialog->close();
    });

    connect(button3, &QPushButton::clicked, [&]() {
        gameModel.giveFood(recinto, 75);
        healthBar->setValue(75);
        dialog->close();
    });

    connect(button4, &QPushButton::clicked, [&]() {
        gameModel.giveFood(recinto, 100);
        healthBar->setValue(100);
        dialog->close();
    });

    dialog->exec();
}

//BARRA RICERCA
//funzione di ricerca
void GameWidget::eseguiRicerca(DLrecinto& recinto, QString testoRicerca) {
    
    std::shared_ptr<Animal> risultatoRicerca = recinto.findAnimal(testoRicerca.toStdString());

    if (risultatoRicerca) {
        animalDetails(*risultatoRicerca);
    } else {
        QMessageBox::information(this, "Animale non trovato nel recinto", "L'animale cercato non è stato trovato.");
    }
}   
//BARRA RICERCA

//Funzione per fare in modo che schiacciando esc esca un menù
void GameWidget::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Escape) {
        //gameModel.clockPausa(true);
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Menu di pausa", "Vuoi salvare la partita o tornare al menu principale?",
                                      QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

        if (reply == QMessageBox::Save) {
            QString nomePartita = QInputDialog::getText(nullptr, "Salvataggio Partita", "Inserisci il nome della partita:");

            QFile file("savedFile/" + nomePartita + ".xml");

            //Sovrascrittura ?
            if(file.exists()) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(nullptr, "File esistente", "Il file: " + nomePartita + " esiste già, vuoi sovrascriverlo ?", QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::No) 
                    return;
            }

            if(DataManager::writeData(nomePartita.toStdString(), gameModel, clock.getTime()) == true){
                QMessageBox::information(nullptr, "Salvataggio completato", "Partita salvata correttamente!");
            }else{
                QMessageBox::information(nullptr, "Salvataggio non completato", "La partita non è stata salvata correttamente, riprovare");
            }
        } else if (reply == QMessageBox::Discard) {
            this->close();
        }else {
            QWidget::keyPressEvent(event);
        }
        //gameModel.clockPausa(false); //STOP DELL'OROLOGIO
    }
}