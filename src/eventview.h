#ifndef EVENTVIEW_H
#define EVENTVIEW_H

#include <QGraphicsItemGroup>

class EventView : public QGraphicsItemGroup
{
public:
  explicit EventView(QGraphicsItem * parent = 0);

  void setArrowUp(qreal at, qreal height);
};

#endif // EVENTVIEW_H
