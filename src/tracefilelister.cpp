#include "tracefilelister.h"
#include "ui_tracefilelister.h"

#include <QTreeWidget>
#include <QVBoxLayout>
#include <QLabel>

TraceFileLister::TraceFileLister(QWidget *parent) :
  QDockWidget("Traces", parent)
{
  QTreeWidget * t = new QTreeWidget(this);

  this->setWidget(t);
}

TraceFileLister::~TraceFileLister()
{
}
