#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Экспериментальное исследования статических характеристик биполярного транзистора");
    w.show();
    return a.exec();
}
