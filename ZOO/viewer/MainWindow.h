#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QSpacerItem>



namespace View {

    class MainWindow: public QWidget {
        Q_OBJECT

        //private:

        public:
            MainWindow();
    };

}

#endif