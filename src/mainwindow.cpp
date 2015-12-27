#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customtoolbar.h"
#include "eventview.h"

#include <QToolBar>
#include <QToolButton>
#include <QIcon>
#include <QFileDialog>

#include <QDebug>

MainWindow::MainWindow(QString folder, QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  plot = new Plot(this);
  this->setCentralWidget(plot);

  populate_toolbar();
  populate_dock();

  if (folder != 0) {
    filename = folder;
    updateTitle();

    emit newFolderChosen(filename);
  }

  ep = new EventsParser;
  //connect(ep, SIGNAL(eventGenerated(QGraphicsItem*)), plot, SLOT(addNewItem(QGraphicsItem*)));
  connect(ep, SIGNAL(eventGenerated(Event)), &em, SLOT(newEventArrived(Event)));
  connect(ep, SIGNAL(fileParsed()), this, SLOT(updatePlot()));
}

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  plot = new Plot(this);
  this->setCentralWidget(plot);

  populate_toolbar();
  populate_dock();

  ep = new EventsParser;
  //connect(ep, SIGNAL(eventGenerated(QGraphicsItem*)), plot, SLOT(addNewItem(QGraphicsItem*)));
  connect(ep, SIGNAL(eventGenerated(Event)), &em, SLOT(newEventArrived(Event)));
  connect(ep, SIGNAL(fileParsed()), this, SLOT(updatePlot()));
}

void MainWindow::populate_dock()
{
  tfl = new TraceFileLister(this);
  this->addDockWidget(Qt::LeftDockWidgetArea, tfl, Qt::Vertical);

  connect(this, SIGNAL(newFolderChosen(QString)), tfl, SLOT(update(QString)));
  connect(tfl, SIGNAL(traceChosen(QString)), this, SLOT(newTraceChosen(QString)));
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
  delete ep;
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

  emit newFolderChosen(filename);
}


void MainWindow::on_actionRefresh_Folder_triggered()
{}


void MainWindow::newTraceChosen(QString path)
{
  //qDebug() << "Chosen new trace : " << path;

  QFileInfo f(path);
  if (f.isFile()) {
    em.clear();
    ep->parseFile(path);
  }
}


void MainWindow::on_actionTraces_Files_triggered()
{
  tfl->setVisible(!tfl->isVisible());
}

void MainWindow::updatePlot()
{
  plot->clear();

  QMap <QString, QList<Event>> * m = em.getCallers();
  for (QList<Event> l : *m) {
    qDebug() << "Trovato caller";
    for (Event e : l) {
      qDebug() << " - Trovato evento";
      EventView * ev = new EventView(e);
      plot->addNewItem(ev);
    }
  }
  //for (auto caller : em)
  //    qDebug() << "Trovato Evento :" << e.getCaller() << " " << e.getStart();

  qDebug() << "MainWindow::updatePlot()";
}
