#include "mainwindow.h"
#include <QApplication>

#include <QDebug>

int main(int argc, char *argv[])
{
  if (argc == 2) {
    QApplication a(argc, argv);

    MainWindow w(argv[1]);
    w.show();

    return a.exec();
  } else {
    qDebug() << "Please, set the path of the plots";
  }
}
