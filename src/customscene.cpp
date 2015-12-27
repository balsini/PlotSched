#include "customscene.h"

#include <QGraphicsSceneMouseEvent>

#include <QDebug>

CustomScene::CustomScene(QObject *parent) :
  QGraphicsScene(parent)
{
}


void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
  //qDebug() << "Mouse pressed at " << mouseEvent->lastScenePos();

  pressed_at = mouseEvent->lastScenePos().x();
}

void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
  //qDebug() << "Mouse released at " << mouseEvent->lastScenePos();

  emit rangeSelected(pressed_at, mouseEvent->lastScenePos().x());
}
