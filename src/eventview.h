#ifndef EVENTVIEW_H
#define EVENTVIEW_H

#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include "event.h"

class EventView : public QGraphicsItemGroup
{
  qreal height;

  void setEvent(Event e);

public:
  explicit EventView(Event e, QGraphicsItem * parent = 0);

  void drawArrowUp(qreal time, qreal row);
  void drawCircle(qreal x, qreal y, qreal radius);
};

#endif // EVENTVIEW_H
