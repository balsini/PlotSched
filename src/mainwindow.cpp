#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customtoolbar.h"
#include "tracefilelister.h"

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

  filename = folder;
  updateTitle();

  populate_toolbar();
  populate_dock();
}

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  populate_toolbar();
  populate_dock();
}

void MainWindow::populate_dock()
{
  TraceFileLister * tfl = new TraceFileLister(this);
  this->addDockWidget(Qt::LeftDockWidgetArea, tfl, Qt::Vertical);
}

void MainWindow::populate_toolbar()
{
  CustomToolBar * ct = new CustomToolBar(this);

  this->addToolBar(ct);

  connect(ct, SIGNAL(openButtonClicked()), this, SLOT(on_actionOpen_Folder_triggered()));
  connect(ct, SIGNAL(refreshButtonClicked()), this, SLOT(on_actionRefresh_Folder_triggered()));
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
