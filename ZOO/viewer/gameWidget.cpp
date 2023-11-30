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
    QString var = "assets/" + QString::fromStdString(animale) + "/" + QString::fromStdString(animale) + ".png";
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
        this->seeAnimals(recinto, healthBar)
    ;});
    
    //Per aggiornare la vita ogni 2 secondi tramite timer
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this, &recinto, healthBar, numAnimali]() {    // Connessione del timer alla slot di aggiornamento
        recinto.riduciVita();
        healthBar->setValue(recinto.getVita()); // Aggiorna la barra della salute

        numAnimali->setText("Numero animali: " + QString::number(recinto.getSize()));

        if(recinto.getVita() == 0 && recinto.getSize() > 0){
            recinto.remove();
            this->seeAnimals(recinto, healthBar);
        }
    });
    timer->start(2000);    // Avvia il timer per aggiornarsi ogni 2 secondi
}



//DA MIGLIORARE: non si aggiorna se muore animale
// definizione di seeAnimals
void GameWidget::seeAnimals(DLrecinto& recinto,  QProgressBar* healthBar) {
    qDeleteAll(emptyLabel->children());//puliza della label per nuovo seeAnimals()

    QWidget *dialog = new QWidget(emptyLabel);
    
    //BARRA RICERCA
    QLineEdit *searchLineEdit = new QLineEdit(emptyLabel); //non cambia se metto dentro dialog o searchline
    searchLineEdit->setPlaceholderText("Ricerca per nome");

    // Connessione del segnale returnPressed()
    connect(searchLineEdit, &QLineEdit::returnPressed, [this, &recinto, searchLineEdit]() {
        QString testoRicerca = searchLineEdit->text(); 
        eseguiRicerca(recinto, testoRicerca);
    });

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
    scrollArea->setFixedHeight(500);
    scrollArea->setWidgetResizable(true); // Permette al widget figlio di ridimensionarsi con scrollArea

    //Creo label titolo
    QLabel *titolo = new QLabel("Recinto con " + QString::number(recinto.getSize()) + (recinto.getSize() == 1 ? " animale" : " animali"));
    titolo->setStyleSheet("QLabel{font-size: 20px; font-weight: bold; text-align: center;}");

    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(titolo);
    layout->addWidget(scrollArea);
    layout->addLayout(buttonLayout); // Aggiunge il layout orizzontale al layout verticale
    layout->addWidget(searchLineEdit);
    
    // Controllo sull'attributo "soldi"
    if (gameModel.getSoldi() <= 0) {
        addButton->setEnabled(false); // Disabilita il pulsante addButton
        addButton->setToolTip("Non hai abbastanza soldi per questa opzione"); // Imposta un messaggio di aiuto
    }
    
    //Evento aggiungi animale
    connect(addButton, &QPushButton::clicked, [this, dialog, &recinto, healthBar](){ 
        this->gameModel.addAnimal(recinto); 
        dialog->close(); // chiude la finestra di dialogo attuale
        this->seeAnimals(recinto, healthBar); 
    });

    //Evento sfama
    connect(foodButton, &QPushButton::clicked, [this, dialog, &recinto, healthBar]() { 
        this->foodSlot(recinto, healthBar); 
        dialog->close(); // chiude la finestra di dialogo attuale        
        this->seeAnimals(recinto, healthBar); 
    });     

    dialog->show();

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

//Funzione per fare in modo che schiacciando esc esca un menù
void GameWidget::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Escape) {
        //gameModel.clockPausa(true);
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Menu di pausa", "Vuoi salvare la partita o tornare al menu principale?",
                                    QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

        if (reply == QMessageBox::Save) {
            QString nomePartita = QInputDialog::getText(this, "Salvataggio Partita", "Inserisci il nome della partita:");

            QFile file("savedFile/" + nomePartita + ".xml");

            //Sovrascrittura ?
            if(file.exists()) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "File esistente", "Il file: " + nomePartita + " esiste già, vuoi sovrascriverlo ?", QMessageBox::Yes|QMessageBox::No);
                if (reply == QMessageBox::No) 
                    return;
            }

            if(DataManager::writeData(nomePartita.toStdString(), gameModel, clock.getTime()) == true){
                QMessageBox::information(this, "Salvataggio completato", "Partita salvata correttamente!");
            }else{
                QMessageBox::information(this, "Salvataggio non completato", "La partita non è stata salvata correttamente, riprovare");
            }
        } else if (reply == QMessageBox::Discard) {
            MainMenu *menu = new MainMenu();
            menu->show();
            
            this->close();
            
            // Connessione del segnale aboutToQuit dell'applicazione per eliminare l'oggetto MainMenu prima della chiusura dell'applicazione
            QObject::connect(qApp, &QCoreApplication::aboutToQuit, [=]() {
                delete menu;
            });      
        }else {
            QWidget::keyPressEvent(event);
        }
        //gameModel.clockPausa(false); //STOP DELL'OROLOGIO
    }
}






//VISITOR
void GameWidget::animalDetails(Animal& a){
    if(dynamic_cast<Coccodrillo*>(&a)) {
        details(dynamic_cast<Coccodrillo&>(a));
    } else if(dynamic_cast<Giraffa*>(&a)) {
        details(dynamic_cast<Giraffa&>(a));
    } else if(dynamic_cast<Leone*>(&a)) {
        details(dynamic_cast<Leone&>(a));
    } else if(dynamic_cast<Pavone*>(&a)) {
        details(dynamic_cast<Pavone&>(a));
    } else if(dynamic_cast<Struzzo*>(&a)) {
        details(dynamic_cast<Struzzo&>(a));
    } else if(dynamic_cast<Tartaruga*>(&a)) {
        details(dynamic_cast<Tartaruga&>(a));
    } else {
        qDebug() << "Il tipo di animale scelto NON esiste\n";
    }
}



//LEONE
void GameWidget::details(Leone& l) {
    //Creazione della finestra di dialogo
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(QString::fromStdString(l.getName()));

    // Imposta lo stile CSS per la finestra di dialogo
    dialog->setStyleSheet("QDialog { background-color: #ffb366;}"
                          "QPushButton { background-color: #ffd0a8; }");

    // Aggiungi il pulsante per emettere il verso
    QPushButton *bottoneRuggito = new QPushButton("Ruggito !", dialog);
    
    connect(bottoneRuggito, &QPushButton::clicked, [&] (){
        QDialog *dialogRuggito = new QDialog(this);

        dialogRuggito->setStyleSheet("QDialog { background-color: #ffb366;}");

        QLabel *fotoRuggito = new QLabel();// Crea un QLabel
        QPixmap image("assets/leone/leoneRuggito.jpg");

        fotoRuggito->setPixmap(image);// Imposta l'immagine nel QLabel
        fotoRuggito->setScaledContents(true);
        fotoRuggito->setFixedSize(200, 150);// Imposta manualmente le dimensioni della QLabel

        QLabel *ruggito = new QLabel(QString::fromStdString(l.getDescrizioneRuggito()));
        ruggito->setWordWrap(true);
        ruggito->setMaximumWidth(500);
        ruggito->setFixedHeight(200);

        QHBoxLayout *layoutRuggito = new QHBoxLayout;
        layoutRuggito->addWidget(ruggito);
        layoutRuggito->addWidget(fotoRuggito);

        layoutRuggito->setSpacing(70);  // Spaziamento orizzontale tra i widget
        layoutRuggito->setAlignment(Qt::AlignCenter);  // Allineamento centrale

        dialogRuggito->setLayout(layoutRuggito);

        dialogRuggito->exec();
    });

    //Creazione immagine leone maschio o femmina
    QLabel *fotoLeo = new QLabel();// Crea un QLabel
    QPixmap image;
    
    if(l.getSex() == 'M')
        image.load("assets/leone/leoneMaschio.jpg");
    else
        image.load("assets/leone/leoneFemmina.jpg");

    fotoLeo->setPixmap(image);// Imposta l'immagine nel QLabel
    fotoLeo->setScaledContents(true);
    fotoLeo->setFixedSize(200, 150);// Imposta manualmente le dimensioni della QLabel

    // Layout fatto con grid
    QGridLayout *layout = new QGridLayout;
    layout->setHorizontalSpacing(70);  // Spaziamento orizzontale tra i widget
    layout->setVerticalSpacing(50);    // Spaziamento verticale tra i widget
    layout->setAlignment(Qt::AlignCenter);  // Allineamento centrale

    //Aggiunta vari layout
    //(0, 0)
    layout->addWidget(fotoLeo, 0, 0, 1, 1); //Posizionato in colonna 0, riga 0 ed occupa 1 riga ed 1 colonna

    //(0, 1)
    QLabel *info = new QLabel("Nome: \t\t" + QString::fromStdString(l.getName()) + 
                            "\nSesso:\t\t" +  QString(l.getSex()) +
                            "\nPeso: \t\t" +  QString::number(l.getPeso()) + " kg"
                            "\nCosto: \t\t" +  QString::number(l.getCosto()) + 
                            "\nRuggito:\t\t" +  QString::number(l.getRuggito()) + " dB"
                            "\nCibo preferito:\t" +  QString::fromStdString(l.getTipo()->getCiboPreferito())
                               );
    
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(info);
    verticalLayout->addWidget(bottoneRuggito);

    layout->addLayout(verticalLayout, 0, 1, 1, 1);

    //(1, 0)
    QLabel *descrizione = new QLabel("<b>Descrizione:</b>\n" +  QString::fromStdString(l.getDescrizione()));
    
    descrizione->setWordWrap(true);
    descrizione->setMaximumWidth(200);
    descrizione->setFixedHeight(200);

    layout->addWidget(descrizione, 1, 0, 1, 1);

    //(1, 1)
    QLabel *habitat = new QLabel();
    QPixmap habitatImg("assets/leone/leoneHabitat.jpg");

    habitat->setPixmap(habitatImg);
    habitat->setScaledContents(true);
    habitat->setFixedSize(200, 150);

    QLabel *descrizioneHabitat = new QLabel("Savana: l'habitat del leone");

    QVBoxLayout *verticalLayout1 = new QVBoxLayout;
    verticalLayout1->addWidget(habitat);
    verticalLayout1->addWidget(descrizioneHabitat);

    layout->addLayout(verticalLayout1, 1, 1, 1, 1);

    // Imposta il layout della finestra di dialogo
    dialog->setLayout(layout);

    // Mostra la finestra di dialogo
    dialog->exec();
}



//COCCODRILLO
void GameWidget::details(Coccodrillo& c){
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(QString::fromStdString(c.getName()));

    // Imposta lo stile CSS per la finestra di dialogo
    dialog->setStyleSheet("QDialog { background-color: #666600;}"
                          "QPushButton { background-color: #999900; }");

    // Aggiungi il pulsante per emettere il verso
    QPushButton *bottoneDenti = new QPushButton("Dettagli denti", dialog);
    
    connect(bottoneDenti, &QPushButton::clicked, [&] (){
        QDialog *dialogDenti = new QDialog(this);

        dialogDenti->setStyleSheet("QDialog { background-color: #666600;}");

        QLabel *fotoDenti = new QLabel();// Crea un QLabel
        QPixmap image("assets/coccodrillo/coccodrilloDenti.jpg");

        fotoDenti->setPixmap(image);// Imposta l'immagine nel QLabel
        fotoDenti->setScaledContents(true);
        fotoDenti->setFixedSize(200, 150);// Imposta manualmente le dimensioni della QLabel

        QLabel *denti = new QLabel(QString::fromStdString(c.ApreBocca()));
        denti->setWordWrap(true);
        denti->setMaximumWidth(500);
        denti->setFixedHeight(200);

        QHBoxLayout *layoutDenti = new QHBoxLayout;
        layoutDenti->addWidget(fotoDenti);
        layoutDenti->addWidget(denti);

        layoutDenti->setSpacing(70);  // Spaziamento orizzontale tra i widget
        layoutDenti->setAlignment(Qt::AlignCenter);  // Allineamento centrale

        dialogDenti->setLayout(layoutDenti);

        dialogDenti->exec();
    });

    //Creazione immagine leone maschio o femmina
    QLabel *fotoCocco = new QLabel();// Crea un QLabel
    QPixmap image;
    
    if(c.getSex() == 'M')
        image.load("assets/coccodrillo/coccodrilloMaschio.jpg");
    else
        image.load("assets/coccodrillo/coccodrilloFemmina.jpg");

    fotoCocco->setPixmap(image);// Imposta l'immagine nel QLabel
    fotoCocco->setScaledContents(true);
    fotoCocco->setFixedSize(200, 150);// Imposta manualmente le dimensioni della QLabel

    // Layout fatto con grid
    QGridLayout *layout = new QGridLayout;
    layout->setHorizontalSpacing(70);  // Spaziamento orizzontale tra i widget
    layout->setVerticalSpacing(50);    // Spaziamento verticale tra i widget
    layout->setAlignment(Qt::AlignCenter);  // Allineamento centrale

    //Aggiunta vari layout
    //(0, 0)
    layout->addWidget(fotoCocco, 0, 0, 1, 1); //Posizionato in colonna 0, riga 0 ed occupa 1 riga ed 1 colonna

    //(0, 1)
    QLabel *descrizione = new QLabel("<b>Descrizione:</b>\n" +  QString::fromStdString(c.getDescrizione()));
    
    descrizione->setWordWrap(true);
    descrizione->setMaximumWidth(600);
    descrizione->setFixedHeight(200);

    layout->addWidget(descrizione, 0, 1, 1, 1);

    //(1, 0)
    QLabel *desc = new QLabel("<b>Attributi coccodrillo</b>");
    QLabel *info = new QLabel("Nome: \t\t" + QString::fromStdString(c.getName()) + 
                            "\nSesso:\t\t" +  QString(c.getSex()) +
                            "\nPeso: \t\t" +  QString::number(c.getPeso()) + " kg"
                            "\nCosto: \t\t" +  QString::number(c.getCosto()) + 
                            "\nCibo preferito:\t" +  QString::fromStdString(c.getTipo()->getCiboPreferito()) + 
                            "\nLunghezza:\t" + QString::number(c.getLunghezza(), 'f', 2) + " mt\n"
                               );
    
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(desc);
    verticalLayout->addWidget(info);
    verticalLayout->addWidget(bottoneDenti);

    layout->addLayout(verticalLayout, 1, 0, 1, 1);

    //(1, 1)
    QLabel *habitat = new QLabel();
    QPixmap habitatImg("assets/coccodrillo/coccodrilloHabitat.jpg");

    habitat->setPixmap(habitatImg);
    habitat->setScaledContents(true);
    habitat->setFixedSize(200, 150);

    QLabel *descrizioneHabitat = new QLabel("Palude: l'habitat del coccodrillo");

    QVBoxLayout *verticalLayout1 = new QVBoxLayout;
    verticalLayout1->addWidget(habitat);
    verticalLayout1->addSpacing(10);
    verticalLayout1->addWidget(descrizioneHabitat);

    layout->addLayout(verticalLayout1, 1, 1, 1, 1);

    // Imposta il layout della finestra di dialogo
    dialog->setLayout(layout);

    dialog->exec();
}



//GIRAFFA
void GameWidget::details(Giraffa& g){
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(QString::fromStdString(g.getName()));

    //stile CSS
    dialog->setStyleSheet("QDialog { background-color: #ffd700;}"
                          "QPushButton { background-color: #fff8dc; }");

    //pulsante sialza
    QPushButton *bottoneUp = new QPushButton("Si alza", dialog);
    
    connect(bottoneUp, &QPushButton::clicked, [&] (){
        QDialog *dialogUp = new QDialog(this);

        dialogUp->setStyleSheet("QDialog { background-color: #ffd700;}");

        QLabel *fotoUp = new QLabel();
        QPixmap image("assets/giraffa/giraffaUp.jpg");

        fotoUp->setPixmap(image);
        fotoUp->setScaledContents(true);
        fotoUp->setFixedSize(200, 150);//dimensioni QLabel

        QLabel *testa = new QLabel(QString::fromStdString(g.SiAlza()));
        testa->setWordWrap(true);
        testa->setMaximumWidth(500);
        testa->setFixedHeight(200);

        QHBoxLayout *layoutUp = new QHBoxLayout;
        layoutUp->addWidget(testa);
        layoutUp->addWidget(fotoUp);

        layoutUp->setSpacing(70);  // Spaziamento tra widget
        layoutUp->setAlignment(Qt::AlignCenter);  // Allineamento

        dialogUp->setLayout(layoutUp);

        dialogUp->exec();
    });

    QLabel *fotoGiraffa = new QLabel();
    QPixmap image;
    image.load("assets/giraffa/giraffaDown.jpg");

    fotoGiraffa->setPixmap(image);
    fotoGiraffa->setScaledContents(true);
    fotoGiraffa->setFixedSize(200, 150);// dimensioni QLabel

    // Layout fatto con grid
    QGridLayout *layout = new QGridLayout;
    layout->setHorizontalSpacing(70);  // Spaziamento orizzontale tra i widget
    layout->setVerticalSpacing(50);    // Spaziamento verticale tra i widget
    layout->setAlignment(Qt::AlignCenter);  // Allineamento centrale

    //layout
    //(0, 0)
    layout->addWidget(fotoGiraffa, 0, 0, 1, 1); //Posizionato in colonna 0, riga 0 ed occupa 1 riga ed 1 colonna

    //(0, 1)
    QLabel *info = new QLabel("Nome: \t\t" + QString::fromStdString(g.getName()) + 
                            "\nSesso:\t\t" +  QString(g.getSex()) +
                            "\nPeso: \t\t" +  QString::number(g.getPeso()) + " kg"
                            "\nCosto: \t\t" +  QString::number(g.getCosto()) + 
			    "\nAltezza: \t\t" +  QString::number(g.getAltezza()) + " m"
                            "\nLunghezza collo:\t\t" +  QString::number(g.getLunghezzaCollo()) + " m"
                            "\nCibo preferito:\t" +  QString::fromStdString(g.getTipo()->getCiboPreferito())
                               );
    
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(info);
    verticalLayout->addWidget(bottoneUp);

    layout->addLayout(verticalLayout, 0, 1, 1, 1);

    //(1, 0)
    QLabel *descrizione = new QLabel("<b>Descrizione:</b>\n" +  QString::fromStdString(g.getDescrizione()));
    
    descrizione->setWordWrap(true);
    descrizione->setMaximumWidth(200);
    descrizione->setFixedHeight(200);

    layout->addWidget(descrizione, 1, 0, 1, 1);

    //(1, 1)
    QLabel *habitat = new QLabel();
    QPixmap habitatImg("assets/giraffa/giraffaHabitat.jpg");

    habitat->setPixmap(habitatImg);
    habitat->setScaledContents(true);
    habitat->setFixedSize(200, 150);

    QLabel *descrizioneHabitat = new QLabel("Savane e aree boschive: l'habitat delle giraffe");

    QVBoxLayout *verticalLayout1 = new QVBoxLayout;
    verticalLayout1->addWidget(habitat);
    verticalLayout1->addWidget(descrizioneHabitat);

    layout->addLayout(verticalLayout1, 1, 1, 1, 1);

    dialog->setLayout(layout);

    dialog->exec();
}



//PAVONE
void GameWidget::details(Pavone& p){
    //Creazione della finestra di dialogo
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(QString::fromStdString(p.getName()));

    // Imposta lo stile CSS per la finestra di dialogo
    dialog->setStyleSheet("QDialog { background-color: #99b3ff;}"
                          "QPushButton {"
                                        "    border-radius: 5px;"
                                        "    padding: 10px;"
                                        "    background-color: #8f94a3;"  // Colore di sfondo
                                        "    color: white;"               // Colore del testo
                                        "}" );

    // Aggiungi il pulsante per fare la ruota
    QPushButton *bottoneRuota = new QPushButton("Ruota", dialog);
    
    connect(bottoneRuota, &QPushButton::clicked, [&] (){
        QDialog *dialogRuota = new QDialog(this);

        dialogRuota->setStyleSheet("QDialog { background-color: #99b3ff;}");

        QLabel *fotoRuota = new QLabel();// Crea un QLabel
        QPixmap image;
        
        if(p.getSex() == 'M' || p.getSex() == 'm')
            image.load("assets/pavone/pavoneRuota.jpeg");
        else
            image.load("assets/pavone/pavoneRuotaFemmina.jpg");
        

        fotoRuota->setPixmap(image);// Imposta l'immagine nel QLabel
        fotoRuota->setScaledContents(true);
        fotoRuota->setFixedSize(200, 150);// Imposta manualmente le dimensioni della QLabel

        QLabel *ruota = new QLabel(QString::fromStdString(p.SfoggiaRuota()));
        ruota->setWordWrap(true);
        ruota->setMaximumWidth(500);
        ruota->setFixedHeight(200);

        QHBoxLayout *layoutRuota = new QHBoxLayout;
        layoutRuota->addWidget(ruota);
        layoutRuota->addWidget(fotoRuota);

        layoutRuota->setSpacing(70);  // Spaziamento orizzontale tra i widget
        layoutRuota->setAlignment(Qt::AlignCenter);  // Allineamento centrale

        dialogRuota->setLayout(layoutRuota);

        dialogRuota->exec();
    });

    //Creazione immagine leone maschio o femmina
    QLabel *fotoPavone = new QLabel();// Crea un QLabel
    QPixmap image;
    
    if(p.getSex() == 'M')
        image.load("assets/pavone/pavoneMaschio.jpg");
    else
        image.load("assets/pavone/pavoneFemmina.jpg");

    fotoPavone->setPixmap(image);// Imposta l'immagine nel QLabel
    fotoPavone->setScaledContents(true);
    fotoPavone->setFixedSize(200, 150);// Imposta manualmente le dimensioni della QLabel

    // Layout fatto con grid
    QGridLayout *layout = new QGridLayout;
    layout->setHorizontalSpacing(70);  // Spaziamento orizzontale tra i widget
    layout->setVerticalSpacing(50);    // Spaziamento verticale tra i widget
    layout->setAlignment(Qt::AlignCenter);  // Allineamento centrale

    //Aggiunta vari layout
    //(0, 0)
    layout->addWidget(fotoPavone, 0, 0, 1, 1); //Posizionato in colonna 0, riga 0 ed occupa 1 riga ed 1 colonna

    //(0, 1)
    QLabel *info = new QLabel("Nome: \t\t" + QString::fromStdString(p.getName()) + 
                            "\nSesso:\t\t" +  QString(p.getSex()) +
                            "\nPeso: \t\t" +  QString::number(p.getPeso()) + " kg"
                            "\nCosto: \t\t" +  QString::number(p.getCosto()) + 
                            "\nRaggio ruota: \t" + QString::number(p.getRaggioRuota(), 'f', 2) +
                            "\nCibo preferito:\t" +  QString::fromStdString(p.getTipo()->getCiboPreferito())
                               );

    layout->addWidget(info, 0, 1, 1, 1);

    //(1, 0)
    QLabel *descrizione = new QLabel("<b>Descrizione:</b>\n" +  QString::fromStdString(p.getDescrizione()));
    
    descrizione->setWordWrap(true);
    descrizione->setMaximumWidth(200);
    descrizione->setFixedHeight(200);

    layout->addWidget(descrizione, 1, 0, 1, 1);

    //(1, 1)
    layout->addWidget(bottoneRuota, 1, 1, 1, 1);


    // Imposta il layout della finestra di dialogo
    dialog->setLayout(layout);

    // Mostra la finestra di dialogo
    dialog->exec();
}



//STRUZZO
void GameWidget::details(Struzzo& s){
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(QString::fromStdString(s.getName()));

    //stile CSS
    dialog->setStyleSheet("QDialog { background-color: #a9a9a9;}"
                          "QPushButton { background-color: #d2b48c; }");

    //pulsante SiNasconde
    QPushButton *bottoneHide = new QPushButton("Si nasconde", dialog);
    
    connect(bottoneHide, &QPushButton::clicked, [&] (){
        QDialog *dialogHide = new QDialog(this);

        dialogHide->setStyleSheet("QDialog { background-color: #a9a9a9;}");

        QLabel *fotoHide = new QLabel();
        QPixmap image("assets/struzzo/struzzoHide.jpg");

        fotoHide->setPixmap(image);
        fotoHide->setScaledContents(true);
        fotoHide->setFixedSize(200, 150);//dimensioni QLabel

        QLabel *testa = new QLabel(QString::fromStdString(s.nascondeTesta()));
        testa->setWordWrap(true);
        testa->setMaximumWidth(500);
        testa->setFixedHeight(200);

        QHBoxLayout *layoutHide = new QHBoxLayout;
        layoutHide->addWidget(testa);
        layoutHide->addWidget(fotoHide);

        layoutHide->setSpacing(70);  // Spaziamento tra widget
        layoutHide->setAlignment(Qt::AlignCenter);  // Allineamento

        dialogHide->setLayout(layoutHide);

        dialogHide->exec();
    });

    //pulsante Corre
    QPushButton *bottoneRun = new QPushButton("Corre", dialog);
    
    connect(bottoneRun, &QPushButton::clicked, [&] (){
        QDialog *dialogRun = new QDialog(this);

        dialogRun->setStyleSheet("QDialog { background-color: #a9a9a9;}");

        QLabel *fotoRun = new QLabel();
        QPixmap image("assets/struzzo/struzzoCorre.jpg");

        fotoRun->setPixmap(image);
        fotoRun->setScaledContents(true);
        fotoRun->setFixedSize(200, 150);//dimensioni QLabel

        QLabel *corre = new QLabel(QString::fromStdString(s.corre()));
        corre->setWordWrap(true);
        corre->setMaximumWidth(500);
        corre->setFixedHeight(200);

        QHBoxLayout *layoutHide = new QHBoxLayout;
        layoutHide->addWidget(corre);
        layoutHide->addWidget(fotoRun);

        layoutHide->setSpacing(70);  // Spaziamento tra widget
        layoutHide->setAlignment(Qt::AlignCenter);  // Allineamento

        dialogRun->setLayout(layoutHide);

        dialogRun->exec();
    });

    QLabel *fotoStruzzo = new QLabel();
    QPixmap image;
    
    if(s.getSex() == 'M')
        image.load("assets/struzzo/struzzoMale.jpg");
    else
        image.load("assets/struzzo/struzzoFem.jpg");

    fotoStruzzo->setPixmap(image);
    fotoStruzzo->setScaledContents(true);
    fotoStruzzo->setFixedSize(200, 150);// dimensioni QLabel

    // Layout fatto con grid
    QGridLayout *layout = new QGridLayout;
    layout->setHorizontalSpacing(70);  // Spaziamento orizzontale tra i widget
    layout->setVerticalSpacing(50);    // Spaziamento verticale tra i widget
    layout->setAlignment(Qt::AlignCenter);  // Allineamento centrale

    //layout
    //(0, 0)
    layout->addWidget(fotoStruzzo, 0, 0, 1, 1); //Posizionato in colonna 0, riga 0 ed occupa 1 riga ed 1 colonna

    //(0, 1)
    QLabel *info = new QLabel("Nome: \t\t" + QString::fromStdString(s.getName()) + 
                            "\nSesso:\t\t" +  QString(s.getSex()) +
                            "\nPeso: \t\t" +  QString::number(s.getPeso()) + " kg"
                            "\nCosto: \t\t" +  QString::number(s.getCosto()) + 
                            "\nVelocità:\t\t" +  QString::number(s.getVelocitaMax()) + " km/h"
                            "\nCibo preferito:\t" +  QString::fromStdString(s.getTipo()->getCiboPreferito())
                               );
    
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(info);
    verticalLayout->addWidget(bottoneHide);
    verticalLayout->addWidget(bottoneRun);

    layout->addLayout(verticalLayout, 0, 1, 1, 1);

    //(1, 0)
    QLabel *descrizione = new QLabel("<b>Descrizione:</b>\n" +  QString::fromStdString(s.getDescrizione()));
    
    descrizione->setWordWrap(true);
    descrizione->setMaximumWidth(200);
    descrizione->setFixedHeight(200);

    layout->addWidget(descrizione, 1, 0, 1, 1);

    //(1, 1)
    QLabel *habitat = new QLabel();
    QPixmap habitatImg("assets/struzzo/struzzoHabitat.jpg");

    habitat->setPixmap(habitatImg);
    habitat->setScaledContents(true);
    habitat->setFixedSize(200, 150);

    QLabel *descrizioneHabitat = new QLabel("Sahel: l'habitat dello struzzo");

    QVBoxLayout *verticalLayout1 = new QVBoxLayout;
    verticalLayout1->addWidget(habitat);
    verticalLayout1->addWidget(descrizioneHabitat);

    layout->addLayout(verticalLayout1, 1, 1, 1, 1);

    dialog->setLayout(layout);

    dialog->exec();
}



//TARTARUGA
void GameWidget::details(Tartaruga& t){
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(QString::fromStdString(t.getName()));

    //stile CSS
    dialog->setStyleSheet("QDialog { background-color: #808000;}"
                          "QPushButton { background-color: #d2b48c; }");

    //pulsante guscio
    QPushButton *bottoneHide = new QPushButton("Entra nel guscio", dialog);
    
    connect(bottoneHide, &QPushButton::clicked, [&] (){
        QDialog *dialogHide = new QDialog(this);

        dialogHide->setStyleSheet("QDialog { background-color: #808000;}");

        QLabel *fotoHide = new QLabel();
        QPixmap image("assets/tartaruga/tartaHide.jpg");

        fotoHide->setPixmap(image);
        fotoHide->setScaledContents(true);
        fotoHide->setFixedSize(200, 150);//dimensioni QLabel

        QLabel *testa = new QLabel(QString::fromStdString(t.siNasconde()));
        testa->setWordWrap(true);
        testa->setMaximumWidth(500);
        testa->setFixedHeight(200);

        QHBoxLayout *layoutHide = new QHBoxLayout;
        layoutHide->addWidget(testa);
        layoutHide->addWidget(fotoHide);

        layoutHide->setSpacing(70);  // Spaziamento tra widget
        layoutHide->setAlignment(Qt::AlignCenter);  // Allineamento

        dialogHide->setLayout(layoutHide);

        dialogHide->exec();
    });

    QLabel *fotoTarta = new QLabel();
    QPixmap image;
    image.load("assets/tartaruga/tartaOut.jpg");

    fotoTarta->setPixmap(image);
    fotoTarta->setScaledContents(true);
    fotoTarta->setFixedSize(200, 150);// dimensioni QLabel

    // Layout fatto con grid
    QGridLayout *layout = new QGridLayout;
    layout->setHorizontalSpacing(70);  // Spaziamento orizzontale tra i widget
    layout->setVerticalSpacing(50);    // Spaziamento verticale tra i widget
    layout->setAlignment(Qt::AlignCenter);  // Allineamento centrale

    //layout
    //(0, 0)
    layout->addWidget(fotoTarta, 0, 0, 1, 1); //Posizionato in colonna 0, riga 0 ed occupa 1 riga ed 1 colonna

    //(0, 1)
    QLabel *info = new QLabel("Nome: \t\t" + QString::fromStdString(t.getName()) + 
                            "\nSesso:\t\t" +  QString(t.getSex()) +
                            "\nPeso: \t\t" +  QString::number(t.getPeso()) + " kg"
                            "\nCosto: \t\t" +  QString::number(t.getCosto()) + 
                            "\nGuscio di:\t\t" +  QString::number(t.getMisuraX()) + " per " + QString::number(t.getMisuraY()) +
                            "\nCibo preferito:\t" +  QString::fromStdString(t.getTipo()->getCiboPreferito())
                               );
    
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(info);
    verticalLayout->addWidget(bottoneHide);

    layout->addLayout(verticalLayout, 0, 1, 1, 1);

    //(1, 0)
    QLabel *descrizione = new QLabel("<b>Descrizione:</b>\n" +  QString::fromStdString(t.getDescrizione()));
    
    descrizione->setWordWrap(true);
    descrizione->setMaximumWidth(200);
    descrizione->setFixedHeight(200);

    layout->addWidget(descrizione, 1, 0, 1, 1);

    //(1, 1)
    QLabel *habitat = new QLabel();
    QPixmap habitatImg("assets/tartaruga/tartarugaHabitat.jpg");

    habitat->setPixmap(habitatImg);
    habitat->setScaledContents(true);
    habitat->setFixedSize(200, 150);

    QLabel *descrizioneHabitat = new QLabel("Isole Galapagos: l'habitat delle tartarughe giganti");

    QVBoxLayout *verticalLayout1 = new QVBoxLayout;
    verticalLayout1->addWidget(habitat);
    verticalLayout1->addWidget(descrizioneHabitat);

    layout->addLayout(verticalLayout1, 1, 1, 1, 1);

    dialog->setLayout(layout);

    dialog->exec();
}
