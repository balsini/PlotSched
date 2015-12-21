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

Event::Event(QString event)
{
  correct = false;
}

Event::Event(const Event &o) : QObject()
{
  time_start = o.time_start;
  duration = o.duration;
  name = o.name;
  event = o.event;

  correct = o.correct;
}

bool Event::isCorrect()
{
  return correct;
}
