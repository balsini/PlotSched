#include "eventview.h"

#include <QGraphicsLineItem>

EventView::EventView(QGraphicsItem * parent) :
  QGraphicsItemGroup(parent)
{
  height = 20;

  drawCircle(50, 50, 4);
  drawCircle(0, 0, 4);
  drawArrowUp(50, 50);
}

void EventView::drawCircle(qreal x, qreal y, qreal radius)
{

  QGraphicsEllipseItem * body = new QGraphicsEllipseItem(x - radius,
                                                         y - radius,
                                                         radius * 2,
                                                         radius * 2,
                                                         this);
  this->addToGroup(body);
}

void EventView::drawArrowUp(qreal time, qreal row)
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

  QGraphicsItemGroup * g = new QGraphicsItemGroup(this);

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
  g->addToGroup(body);
  g->addToGroup(left);
  g->addToGroup(right);

  g->moveBy(0, -height);

  // Now, move it to the correct place

  g->moveBy(time, row);
}
