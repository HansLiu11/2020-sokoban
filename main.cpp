#include "mainwindow.h"
#include <QApplication>
#include <vector>
#include <sstream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
