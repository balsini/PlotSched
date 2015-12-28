#include "plot.h"

#include <QGridLayout>
#include <QWheelEvent>

#include <QDebug>

Plot::Plot(QWidget *parent) :
  QWidget(parent)
{
  scene = new CustomScene(this);
  view = new QGraphicsView(scene);

  this->setLayout(new QGridLayout(this));
  this->layout()->addWidget(view);

  connect(scene, SIGNAL(rangeSelected(qreal,qreal)), this, SLOT(rangeSelected(qreal, qreal)));
}


void Plot::addNewItem(QGraphicsItem * i)
{
  scene->addItem(i);
}


void Plot::clear()
{
  scene->clear();
}


void Plot::rangeSelected(qreal init, qreal end)
{
  qDebug() << "Zooming range selected : " << init << " " << end;
  emit zoomChanged(init, end);

  scene->setSceneRect(scene->itemsBoundingRect());

  /*
  qreal old_x = scene->itemsBoundingRect().x();
  qreal old_y = scene->itemsBoundingRect().y();
  qreal old_w = scene->itemsBoundingRect().width();
  qreal old_h = scene->itemsBoundingRect().height();

  qreal size = end - init;
  if (size > 0)
    scene->setSceneRect(init, old_y, size, old_h);
  else
    scene->setSceneRect(init, old_y, size, old_h);
    */
}
