#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "schedulingvisualizer.hpp"
#include "tracefilelister.h"

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
  TraceFileLister * tfl;

  void updateTitle();
  void populate_toolbar();
  void populate_dock();

public:
  MainWindow(QString folder, QWidget *parent = 0);
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:
  void newTraceChosen(QString);

private slots:
  void on_actionQuit_triggered();
  void on_actionOpen_triggered();
  void on_actionOpen_Folder_triggered();
  void on_actionRefresh_Folder_triggered();

  void on_actionTraces_Files_triggered();

signals:
  void newFolderChosen(QString);
};

#endif // MAINWINDOW_H
