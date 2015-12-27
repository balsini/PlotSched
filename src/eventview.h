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
  QColor eventToColor(event_kind e);

public:
  explicit EventView(const Event &e, QGraphicsItem * parent = 0);
  ~EventView();

  void drawArrowUp();
  void drawRect(qreal duration, QColor color);
  void drawCircle();
};

#endif // EVENTVIEW_H
