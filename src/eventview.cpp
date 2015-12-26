#include "eventview.h"

#include <QMap>

#include <QGraphicsLineItem>

QMap<QString, int> map;

EventView::EventView(Event e, QGraphicsItem * parent) :
  QGraphicsItemGroup(parent)
{
  height = 30;
  vertical_offset = 50;

  setEvent(e);
}

EventView::~EventView()
{
  delete e_;
}

void EventView::setEvent(Event e)
{
  //drawCircle(50, 50, 4);
  //drawCircle(0, 0, 4);


  qDeleteAll(this->childItems());

  e_ = new Event(e);

  if (map.find(e.getCaller()) == map.end())
    map.insert(e.getCaller(), map.count());

  switch (e.getKind()) {
    case RUNNING :
      drawRect(e.getDuration());
      break;
    case ACTIVATION:
      drawArrowUp();
      break;
    case DEAD:
      drawCircle();
      break;
    default: return;
  }

  this->moveBy(e.getStart(), vertical_offset * map[e.getCaller()]);
}

void EventView::drawCircle()
{
  QGraphicsEllipseItem * body = new QGraphicsEllipseItem(-4,
                                                         -4,
                                                         4 * 2,
                                                         4 * 2,
                                                         this);
  this->addToGroup(body);
}


void EventView::drawArrowUp()
{
  /******************************
   *
   *                / (x2, y2)
   *              ///
   *            / / /
   *   (left) /  /  / (right)
   *            /
   *           /
   *          /
   *         / (x1, y1)
   *
   ******************************/

  // First of all, create an arrow with (x1, y1) = (0, 0)

  QGraphicsLineItem * body = new QGraphicsLineItem(0,
                                                   0,
                                                   0,
                                                   height,
                                                   this);
  QGraphicsLineItem * left = new QGraphicsLineItem(0,
                                                   0,
                                                   height / 5.0,
                                                   height / 4.0,
                                                   this);
  QGraphicsLineItem * right = new QGraphicsLineItem(0,
                                                    0,
                                                    -height / 5.0,
                                                    height / 4.0,
                                                    this);
  this->addToGroup(body);
  this->addToGroup(left);
  this->addToGroup(right);

  this->moveBy(0, -height);
}


void EventView::drawRect(qreal duration)
{
  /******************************
   *
   *          ____________
   *         |            |
   *         |            | height
   *         |____________|
   *  (x1, y1)  duration
   *
   ******************************/

  qreal rectHeight = height / 1.9;

  QGraphicsRectItem * r = new QGraphicsRectItem(0,
                                                0,
                                                duration,
                                                rectHeight,
                                                this);
  this->addToGroup(r);

  this->moveBy(0, -rectHeight);
}

void clearEventMap()
{
  map.clear();
}
