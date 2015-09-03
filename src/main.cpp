#include "mainwindow.h"
#include <QApplication>

#include <QDebug>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  //qDebug() << argc;
  //qDebug() << argv[1];

  if (argc == 2) {
    MainWindow w(argv[1]);
    w.show();
    return a.exec();
  } else {
    MainWindow w;
    w.show();
    return a.exec();
  }
}
