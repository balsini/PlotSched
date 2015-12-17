#include "mainwindow.h"
#include <QApplication>

#include <QDebug>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow * w;
  if (argc == 2) {
    w = new MainWindow(argv[1]);
  } else {
    w = new MainWindow();
  }
  w->show();

  return a.exec();
}
