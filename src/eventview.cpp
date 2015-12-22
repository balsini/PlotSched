#include "eventview.h"

#include <QGraphicsLineItem>

EventView::EventView(QGraphicsItem * parent) :
  QGraphicsItemGroup(parent)
{
  setArrowUp(50, 50);
}

void EventView::setArrowUp(qreal at, qreal height)
{
  qreal x1, y1, x2, y2;

  x1 = x2 = at;
  y1 = 0;
  y2 = y1 + height;

  QGraphicsLineItem * body = new QGraphicsLineItem(x1,
                                                   y1,
                                                   x2,
                                                   y2,
                                                   this);

  this->addToGroup(body);
}
