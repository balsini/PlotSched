#include "plot.h"

#include <QGridLayout>
#include <QWheelEvent>

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

void Plot::wheelEvent(QWheelEvent *event)
{
  view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
  // Scale the view / do the zoom
  double scaleFactor = 1.1;
  if(event->delta() > 0) {
    // Zoom in
    view->scale(scaleFactor, 1);

  } else {
    // Zooming out
    view->scale(1.0 / scaleFactor, 1);
  }

  //ui->graphicsView->setTransform(QTransform(h11, h12, h21, h22, 0, 0));
}
