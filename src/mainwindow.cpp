#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "schedulingvisualizer.hpp"

#include <QToolBar>
#include <QToolButton>
#include <QIcon>

MainWindow::MainWindow(QString folder, QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  SchedulingVisualizer * sv = new SchedulingVisualizer(folder, this);

  this->ui->mainLayout->addWidget(sv);

  QToolButton * buttonOpen = new QToolButton(this);
  buttonOpen->setIcon(QIcon::fromTheme("document-open"));
  this->ui->mainToolBar->addWidget(buttonOpen);

  QToolButton * buttonRefresh = new QToolButton(this);
  buttonRefresh->setIcon(QIcon::fromTheme("view-refresh"));
  this->ui->mainToolBar->addWidget(buttonRefresh);

  /*
  this->ui->mainToolBar->addSeparator();

  QToolButton * buttonZoomIn = new QToolButton(this);
  buttonZoomIn->setIcon(QIcon::fromTheme("zoom-in"));
  this->ui->mainToolBar->addWidget(buttonZoomIn);

  QToolButton * buttonZoomOut = new QToolButton(this);
  buttonZoomOut->setIcon(QIcon::fromTheme("zoom-out"));
  this->ui->mainToolBar->addWidget(buttonZoomOut);
  */
}

MainWindow::~MainWindow()
{
  delete ui;
}
