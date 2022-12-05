#include "mainwindow.h"
//#include "conversion.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFile file(":/style.css");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());

    QPalette* palette = new QPalette();
    palette->setColor(w.backgroundRole(), Qt::gray);
    w.setPalette(*palette);

    w.show();
    return a.exec();
}
