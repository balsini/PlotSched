#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "schedulingvisualizer.hpp"

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

  Ui::MainWindow *ui;
  SchedulingVisualizer * sv;
  QString filename;

  void updateTitle();
  void populate_toolbar();
  void populate_dock();

public:
  MainWindow(QString folder, QWidget *parent = 0);
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_actionQuit_triggered();
  void on_actionOpen_triggered();
  void on_actionOpen_Folder_triggered();
  void on_actionRefresh_Folder_triggered();
};

#endif // MAINWINDOW_H
