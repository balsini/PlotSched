#include "tracefilelister.h"
#include "ui_tracefilelister.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QTreeWidgetItem>

#include <QDebug>

TraceFileLister::TraceFileLister(QWidget *parent) :
  QDockWidget("Traces", parent)
{
  tree = new QTreeWidget(this);
  tree->setColumnCount(1);

  tree->clear();
  tree->setHeaderLabel("Filename");

  this->setWidget(tree);

  connect(tree, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(traceSelected(QTreeWidgetItem*,int)));
}

TraceFileLister::~TraceFileLister() {}

void TraceFileLister::addFolderToTree(QTreeWidgetItem * parent, QString dir)
{
  QDir * root = new QDir(dir);

  QStringList l = root->entryList();
  QTreeWidgetItem * j;
  for (auto o : l) {
    if (o != "." && o != "..") {
      j = new QTreeWidgetItem(parent);
      j->setText(0, o);

      QString newDir = root->absoluteFilePath(o);
      QFileInfo * fi = new QFileInfo(newDir);
      if (fi->isDir()) {
        addFolderToTree(j, newDir);
      }
      delete fi;
    }
  }

  delete root;
}

void TraceFileLister::update(QString path)
{
  QFileInfo * fi = new QFileInfo(path);

  if (fi->isDir()) {
    tree->clear();
    tree->setHeaderLabel(fi->absoluteFilePath());

    QTreeWidgetItem * j = new QTreeWidgetItem(tree);
    j->setText(0, fi->absoluteFilePath());
    addFolderToTree(j, path);
  }

  delete fi;
}

void TraceFileLister::traceSelected(QTreeWidgetItem * i, int col)
{
  QString fullPath;

  do {
    fullPath.insert(0, "/" + i->text(col));
    i = i->parent();
  } while (i != 0);

  fullPath.remove(0, 1);

  emit traceChosen(fullPath);
}
