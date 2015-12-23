#ifndef EVENTVIEW_H
#define EVENTVIEW_H

#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include "event.h"

class EventView : public QGraphicsItemGroup
{
  qreal height;
  qreal vertical_offset;
  Event * e_;

  void setEvent(Event e);

public:
  explicit EventView(Event e, QGraphicsItem * parent = 0);
  ~EventView();

  void drawArrowUp();
  void drawRect(qreal duration);
  void drawCircle(qreal x, qreal y, qreal radius);
};

void clearEventMap();

#endif // EVENTVIEW_H
