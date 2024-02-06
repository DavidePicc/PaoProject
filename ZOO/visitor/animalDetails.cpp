#include "animalDetails.h"

#include "../src/Coccodrillo.h"
#include "../src/Giraffa.h"
#include "../src/Leone.h"
#include "../src/Pavone.h"
#include "../src/Struzzo.h"
#include "../src/Tartaruga.h"
#include "../src/Container.h"

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QScreen>
#include <QGuiApplication>
#include <QPushButton>
#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QScrollArea>
#include <QMessageBox>
#include <QKeyEvent>
#include <QInputDialog>
#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>


void animalDetails::visitCoccodrillo(Coccodrillo& c){
    QDialog *dialog = new QDialog();
    dialog->setWindowTitle(QString::fromStdString(c.getName()));

    // Imposta lo stile CSS per la finestra di dialogo
    dialog->setStyleSheet("QDialog { background-color: #666600;}"
                        "QPushButton { background-color: #999900; }");

    // Aggiungi il pulsante per emettere il verso
    QPushButton *bottoneDenti = new QPushButton("Dettagli denti", dialog);
    
    connect(bottoneDenti, &QPushButton::clicked, [&] (){
        QDialog *dialogDenti = new QDialog();

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
    QLabel *info = new QLabel(QString::fromStdString(c.getInfo()));
    
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(desc);
    verticalLayout->addWidget(info);
    verticalLayout->addSpacing(15);
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

void animalDetails::visitGiraffa(Giraffa& g){
    QDialog *dialog = new QDialog();
    dialog->setWindowTitle(QString::fromStdString(g.getName()));

    //stile CSS
    dialog->setStyleSheet("QDialog { background-color: #ffd700;}"
                        "QPushButton { background-color: #fff8dc; }");

    //pulsante sialza
    QPushButton *bottoneUp = new QPushButton("Si alza", dialog);
    
    connect(bottoneUp, &QPushButton::clicked, [&] (){
        QDialog *dialogUp = new QDialog();

        dialogUp->setStyleSheet("QDialog { background-color: #ffd700;}");

        QLabel *fotoUp = new QLabel();
        QPixmap image("assets/giraffa/giraffaUp.jpg");

        fotoUp->setPixmap(image);
        fotoUp->setScaledContents(true);
        fotoUp->setFixedSize(220, 367);//dimensioni QLabel

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
    QLabel *info = new QLabel(QString::fromStdString(g.getInfo()));
    
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(info);
    verticalLayout->addSpacing(15);
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
    habitat->setFixedSize(310, 105);

    QLabel *descrizioneHabitat = new QLabel("Savane e aree boschive: l'habitat delle giraffe");

    QVBoxLayout *verticalLayout1 = new QVBoxLayout;
    verticalLayout1->addWidget(habitat);
    verticalLayout1->addWidget(descrizioneHabitat);

    layout->addLayout(verticalLayout1, 1, 1, 1, 1);

    dialog->setLayout(layout);

    dialog->exec();
}

void animalDetails::visitLeone(Leone& l){
    //Creazione della finestra di dialogo
    QDialog *dialog = new QDialog();
    dialog->setWindowTitle(QString::fromStdString(l.getName()));

    // Imposta lo stile CSS per la finestra di dialogo
    dialog->setStyleSheet("QDialog { background-color: #ffb366;}"
                        "QPushButton { background-color: #ffd0a8; }");

    // Aggiungi il pulsante per emettere il verso
    QPushButton *bottoneRuggito = new QPushButton("Ruggito !", dialog);
    
    connect(bottoneRuggito, &QPushButton::clicked, [&] (){
        QDialog *dialogRuggito = new QDialog();

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
    QLabel *info = new QLabel(QString::fromStdString(l.getInfo()));
    
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(info);
    verticalLayout->addSpacing(15);
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

void animalDetails::visitPavone(Pavone& p){
    //Creazione della finestra di dialogo
    QDialog *dialog = new QDialog();
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
        QDialog *dialogRuota = new QDialog();

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
    QLabel *info = new QLabel(QString::fromStdString(p.getInfo()));

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

void animalDetails::visitStruzzo(Struzzo& s){
    QDialog *dialog = new QDialog();
    dialog->setWindowTitle(QString::fromStdString(s.getName()));

    //stile CSS
    dialog->setStyleSheet("QDialog { background-color: #a9a9a9;}"
                        "QPushButton { background-color: #d2b48c; }");

    //pulsante SiNasconde
    QPushButton *bottoneHide = new QPushButton("Si nasconde", dialog);
    
    connect(bottoneHide, &QPushButton::clicked, [&] (){
        QDialog *dialogHide = new QDialog();

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
        QDialog *dialogRun = new QDialog();

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
    layout->addWidget(fotoStruzzo, 0, 1, 1, 1); //Posizionato in colonna 0, riga 0 ed occupa 1 riga ed 1 colonna

    //(0, 1)
    QLabel *info = new QLabel(QString::fromStdString(s.getInfo()));
    
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(info);
    verticalLayout->addSpacing(15);
    verticalLayout->addWidget(bottoneHide);
    verticalLayout->addSpacing(15);
    verticalLayout->addWidget(bottoneRun);

    layout->addLayout(verticalLayout, 0, 0, 1, 1);

    //(1, 0)
    QLabel *descrizione = new QLabel("<b>Descrizione:</b>\n" +  QString::fromStdString(s.getDescrizione()));
    
    descrizione->setWordWrap(true);
    descrizione->setMaximumWidth(200);
    descrizione->setFixedHeight(200);

    layout->addWidget(descrizione, 1, 1, 1, 1);

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

    layout->addLayout(verticalLayout1, 1, 0, 1, 1);

    dialog->setLayout(layout);

    dialog->exec();
}

void animalDetails::visitTartaruga(Tartaruga& t){
        QDialog *dialog = new QDialog();
        dialog->setWindowTitle(QString::fromStdString(t.getName()));

        //stile CSS
        dialog->setStyleSheet("QDialog { background-color: #808000;}"
                            "QPushButton { background-color: #d2b48c; }");

        //pulsante guscio
        QPushButton *bottoneHide = new QPushButton("Entra nel guscio", dialog);
        
        connect(bottoneHide, &QPushButton::clicked, [&] (){
            QDialog *dialogHide = new QDialog();

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
        layout->addWidget(fotoTarta, 0, 1, 1, 1); //Posizionato in colonna 0, riga 0 ed occupa 1 riga ed 1 colonna

        //(0, 1)
        QLabel *info = new QLabel(QString::fromStdString(t.getInfo()));
        
        QVBoxLayout *verticalLayout = new QVBoxLayout;
        verticalLayout->addWidget(info);
        verticalLayout->addSpacing(15);
        verticalLayout->addWidget(bottoneHide);

        layout->addLayout(verticalLayout, 0, 0, 1, 1);

        //(1, 0)
        QLabel *descrizione = new QLabel("<b>Descrizione:</b>\n" +  QString::fromStdString(t.getDescrizione()));
        
        descrizione->setWordWrap(true);
        descrizione->setMaximumWidth(200);
        descrizione->setFixedHeight(200);

        layout->addWidget(descrizione, 1, 1, 1, 1);

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

        layout->addLayout(verticalLayout1, 1, 0, 1, 1);

        dialog->setLayout(layout);

        dialog->exec();
    }
