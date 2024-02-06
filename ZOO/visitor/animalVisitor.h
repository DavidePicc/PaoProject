#ifndef ANIMAL_VISITOR
#define ANIMAL_VISITOR

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

class Coccodrillo;
class Giraffa;
class Leone;
class Pavone;
class Struzzo;
class Tartaruga;

class animalVisitor : public QWidget{
    Q_OBJECT

    public:
        virtual ~animalVisitor() = default;
        virtual void visitCoccodrillo(Coccodrillo& c) = 0;
        virtual void visitGiraffa(Giraffa& g) = 0;
        virtual void visitLeone(Leone& l) = 0;
        virtual void visitPavone(Pavone& p) = 0;
        virtual void visitStruzzo(Struzzo& s) = 0;
        virtual void visitTartaruga(Tartaruga& t) = 0;
};

#endif