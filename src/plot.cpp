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
  //emit zoomChanged(mouse_pressed_at, mouse_released_at);
}
