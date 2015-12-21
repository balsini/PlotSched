#include "event.h"

#include <QTextStream>

#include <QDebug>

void Event::parseLine(QByteArray line)
{
  // TODO

  QTextStream ss(line);

  ss >> time_start;
  ss >> name;
  ss >> event;

  qDebug() << "Read from device : " << time_start;
  qDebug() << "Read from device : " << name;
  qDebug() << "Read from device : " << event;

  qDebug() << "";
}

bool correctLine(QByteArray line)
{
  // TODO

  if (line.size() < 2)
    return false;
  return true;
}

Event::Event(QByteArray event)
{
  correct = false;

  if (correctLine(event)) {
    parseLine(event);
    correct = true;
  }
}

Event::Event(const Event &o) : QObject()
{
  time_start = o.time_start;
  time_end = o.time_end;
  name = o.name;
  event = o.event;

  correct = o.correct;
}

bool Event::isCorrect()
{
  return correct;
}


bool Event::isRange()
{
  return range;
}
