#ifndef EVENTVIEW_H
#define EVENTVIEW_H

#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include "event.h"

class EventView : public QGraphicsItemGroup
{

public:
  explicit EventView(QGraphicsItem * parent = 0);
  void setArrowUp(qreal at, qreal height);
};

#endif // EVENTVIEW_H
