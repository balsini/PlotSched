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

bool Event::isCorrect()
{
  return correct;
}
