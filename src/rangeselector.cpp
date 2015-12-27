#include "rangeselector.h"

#include <QPen>

RangeSelector::RangeSelector()
{
  horizontal = new QGraphicsLineItem(this);
  vertical_left = new QGraphicsLineItem(this);
  vertical_right = new QGraphicsLineItem(this);

  QPen p;

  p.setWidth(2);

  horizontal->setPen(p);
  vertical_left->setPen(p);
  vertical_right->setPen(p);

  this->addToGroup(horizontal);
  this->addToGroup(vertical_left);
  this->addToGroup(vertical_right);
  setVisible(false);
}


void RangeSelector::update()
{
  horizontal->setLine(start.x(), start.y(), end.x(), start.y());
  vertical_left->setLine(start.x(), start.y() - 5, start.x(), start.y() + 5);
  vertical_right->setLine(end.x(), start.y() - 5, end.x(), start.y() + 5);
}


void RangeSelector::setStartPoint(QPointF p)
{
  start = p;
  update();
}


void RangeSelector::setEndPoint(QPointF p)
{
  end = p;
  update();
}


void RangeSelector::setVisible(bool v)
{
  horizontal->setVisible(v);
  vertical_left->setVisible(v);
  vertical_right->setVisible(v);

  update();
}
