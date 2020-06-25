#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();
    QApplication::setQuitOnLastWindowClosed(true);
    w->show();
    return a.exec();
}
