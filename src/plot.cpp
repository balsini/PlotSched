#include "plot.h"

#include <QGridLayout>

Plot::Plot(QWidget *parent) :
  QWidget(parent)
{
  scene = new QGraphicsScene(this);
  view = new QGraphicsView(scene);

  this->setLayout(new QGridLayout(this));
  this->layout()->addWidget(view);
}


void Plot::addNewItem(QGraphicsItem * i)
{
  scene->addItem(i);
}


void Plot::clear()
{
  scene->clear();
}
