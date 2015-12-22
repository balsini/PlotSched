#ifndef EVENTVIEW_H
#define EVENTVIEW_H

#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include "event.h"

class EventView : public QGraphicsItemGroup
{
  qreal height;

public:
  explicit EventView(QGraphicsItem * parent = 0);
  void drawArrowUp(qreal time, qreal row);
  void drawCircle(qreal x, qreal y, qreal radius);
};

#endif // EVENTVIEW_H
