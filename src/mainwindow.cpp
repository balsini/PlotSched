#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QToolBar>
#include <QToolButton>
#include <QIcon>
#include <QFileDialog>

MainWindow::MainWindow(QString folder, QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  sv = 0;

  if (folder != 0) {
    sv = new SchedulingVisualizer(folder, this);
    this->ui->mainLayout->addWidget(sv);
  }


  QToolButton * buttonOpen = new QToolButton(this);
  buttonOpen->setIcon(QIcon::fromTheme("document-open"));
  this->ui->mainToolBar->addWidget(buttonOpen);

  connect(buttonOpen, SIGNAL(clicked()), this, SLOT(on_actionOpen_Folder_triggered()));

  QToolButton * buttonRefresh = new QToolButton(this);
  buttonRefresh->setIcon(QIcon::fromTheme("view-refresh"));
  this->ui->mainToolBar->addWidget(buttonRefresh);

  connect(buttonRefresh, SIGNAL(clicked()), this, SLOT(on_actionRefresh_Folder_triggered()));

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

void MainWindow::updateTitle()
{
  QString t = "PlotSched";
  if (filename.length() > 0) {
    t.append(" - ");
    t.append(filename);
  }
  this->setWindowTitle(t);
}

void MainWindow::on_actionOpen_triggered()
{
  QString tmpfilename = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "./",
        "Plot Sched Trace (*.pst)"
        );

  filename = tmpfilename;
  updateTitle();
}

void MainWindow::on_actionQuit_triggered()
{
  close();
}

void MainWindow::on_actionOpen_Folder_triggered()
{
  QString tmpfilename = QFileDialog::getExistingDirectory(
        this,
        tr("Open Directory"),
        "./",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
        );

  filename = tmpfilename;
  updateTitle();

  if (sv)
    delete sv;

  sv = new SchedulingVisualizer(tmpfilename, this);
  this->ui->mainLayout->addWidget(sv);
}


void MainWindow::on_actionRefresh_Folder_triggered()
{
  if (sv)
    delete sv;

  sv = new SchedulingVisualizer(filename, this);
  this->ui->mainLayout->addWidget(sv);
}
