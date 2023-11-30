#include "mainMenu.h"

MainMenu::MainMenu(QWidget *parent) : QWidget(parent) {
    QPixmap pixmap("assets/ZooCover.png"); // Carica l'immagine

    // Imposta la dimensione della finestra sulla dimensione dell'immagine
    this->setFixedSize(pixmap.width(), pixmap.height());

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
    nuovaPartita->setStyleSheet("QPushButton { font-size: 20px; font-weight: bold; background-color: black; color: white; height : 50px}"
                                "QPushButton:pressed { background-color: #505050; }");
    caricaPartita->setStyleSheet("QPushButton { font-size: 20px; font-weight: bold; background-color: black; color: white; height : 50px}"
                                "QPushButton:pressed { background-color: #505050; }");

    buttonsLayout->addWidget(nuovaPartita);
    buttonsLayout->addWidget(caricaPartita);

    this->setLayout(mainLayout);

    nuovaPartita->setCursor(Qt::PointingHandCursor);
    caricaPartita->setCursor(Qt::PointingHandCursor);

    // Collegamento dei segnali dei bottoni ai rispettivi slot
    connect(nuovaPartita, &QPushButton::clicked, this, &MainMenu::handleNewGameButton);
    connect(caricaPartita, &QPushButton::clicked, this, &MainMenu::handleLoadGameButton);
}



//Bottone "Nuova partita"
void MainMenu::handleNewGameButton() {
    GameWidget *gameWidget = new GameWidget();
    gameWidget->show();

    this->close(); // Chiudiamo il MainMenu
}

//Bottone "Carica partita"
void MainMenu::handleLoadGameButton() {
    QDir directory("savedFile");

    if(directory.entryInfoList(QDir::Files).count() == 0){
        QDialog dialog;
        dialog.setWindowTitle("Avviso");

        QVBoxLayout *layout = new QVBoxLayout(&dialog);

        QLabel *label = new QLabel("Non sono presenti file di salvataggio");
        label->setAlignment(Qt::AlignCenter);
        
        // Imposta lo stile CSS per il QLabel
        label->setStyleSheet("font-size: 18px; font-weight: bold;");
        
        layout->addWidget(label);

        dialog.setLayout(layout);
        dialog.exec();
    }else{
        QDialog dialog;
        dialog.setWindowTitle("File Salvati");

        QVBoxLayout *layout = new QVBoxLayout(&dialog);

        // Aggiungi una label
        QLabel *chooseLabel = new QLabel("Scegli tra le seguenti partite", &dialog);
        chooseLabel->setAlignment(Qt::AlignCenter);
        chooseLabel->setStyleSheet("font-size: 18px; font-weight: bold;");
        layout->addWidget(chooseLabel);

        //Inizializzo valore per chiudere mainWindow
        bool buttonClicked = false;

        //Guardo quanti file sono presenti nella cartella dei file salvati
        QDir directory("savedFile");
        QStringList savedFile = directory.entryList(QStringList() << "*.xml", QDir::Files);

        foreach (QString filename, savedFile) {
            QFileInfo fileInfo(filename);
    
            QString baseName = fileInfo.baseName(); // Ottieni solo il nome del file senza estensione

            QHBoxLayout *fileLayout = new QHBoxLayout;

            QPushButton *fileButton = new QPushButton(baseName); // Mostra solo il nome del file senza estensione

            
            // Connetti il segnale clicked del bottone a una slot o a una lambda function per gestire il click sul file
            QObject::connect(fileButton, &QPushButton::clicked, [&, filename]() {
                GameWidget *gameWidget = new GameWidget(filename.toStdString());//Perchè filename è QString
                gameWidget->show();
                buttonClicked = true;
                dialog.accept();
            });

            fileLayout->addWidget(fileButton);

            // Aggiungi un pulsante di eliminazione
            QPushButton *deleteButton = new QPushButton("Elimina");
            QObject::connect(deleteButton, &QPushButton::clicked, [&, filename]() {
                QFile::remove("savedFile/" + filename); // Rimuove il file
                dialog.close();
                handleLoadGameButton();
             });

            fileLayout->addWidget(deleteButton);

            layout->addLayout(fileLayout);
        }

        dialog.setLayout(layout);
        dialog.resize(300, 200);
        dialog.exec();
        
        if (buttonClicked)
            // Chiude MainWindow dopo un breve ritardo
            QTimer::singleShot(0, this, &QWidget::close);
    }
}