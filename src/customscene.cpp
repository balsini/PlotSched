#include "customscene.h"

#include <QGraphicsSceneMouseEvent>

#include <QDebug>

CustomScene::CustomScene(QObject *parent) :
  QGraphicsScene(parent)
{
  pressed = false;
  range = 0;
}


void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
  //qDebug() << "Mouse pressed at " << mouseEvent->lastScenePos();

  pressed = true;
  pressed_at = mouseEvent->lastScenePos();

  range = new RangeSelector;
  range->setStartPoint(pressed_at);
  this->addItem(range);
  range->setVisible();
}


void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
  //qDebug() << "Mouse released at " << mouseEvent->lastScenePos();

  this->removeItem(range);
  delete range;
  range = 0;
  pressed = false;

  emit rangeSelected(pressed_at.x(), mouseEvent->lastScenePos().x());
}


void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
  if (!pressed)
    return;

  range->setEndPoint(mouseEvent->lastScenePos());
  //qDebug() << "Moving mouse to " << mouseEvent->lastScenePos();
}
