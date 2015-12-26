#include "event.h"

#include <QTextStream>
#include <QMap>

#include <QDebug>

QMap<QString, QMap<event_kind, Event *>> pending_events;

void Event::parseLine(QByteArray line)
{
  // TODO
  QString status;

  correct = false;

  QTextStream ss(line);

  ss >> time_start;
  ss >> caller;
  ss >> cpu;
  ss >> event;
  ss >> status;

  if (event == "RUNNING") {
    kind = RUNNING;
  } else if (event == "DEAD") {
    kind = DEAD;
  } else if (event == "ACTIVATION" || event == "CREATION") {
    kind = ACTIVATION;
  } else if (event == "DEADLINE") {
    kind = DEADLINE;
  }

  if (status == "I") {
    correct = true;
    pending = false;
  } else if (status == "E") {
    pending = false;
    if (pending_events[caller].find(kind) != pending_events[caller].end()) {
      duration = time_start - pending_events[caller].find(kind).value()->getStart();
      this->time_start = pending_events[caller].find(kind).value()->getStart();
      correct = true;

      Event * ev = pending_events[caller].find(kind).value();
      pending_events[caller].remove(kind);
      delete ev;
    }
  } else if (status == "S") {
    pending = true;
    Event * ev = new Event(*this);
    pending_events[caller].insert(kind, ev);
  }

  qDebug() << "Read from device : " << time_start;
  qDebug() << "Read from device : " << caller;
  qDebug() << "Read from device : " << cpu;
  qDebug() << "Read from device : " << event;
  qDebug() << "Read from device : " << status;

  qDebug() << "";
}


bool correctLine(QByteArray line)
{
  // TODO

  if (line.size() < 2)
    return false;
  return true;
}


Event::Event()
{
  correct = false;
}


void Event::parse(QByteArray line)
{
  if (correctLine(line))
    parseLine(line);
}


Event::Event(const Event &o) : QObject()
{
  row = o.row;
  time_start = o.time_start;
  duration = o.duration;
  caller = o.caller;
  event = o.event;
  kind = o.kind;
  correct = o.correct;
  pending = o.pending;
}


Event& Event::operator=(const Event &o)
{
  row = o.row;
  time_start = o.time_start;
  duration = o.duration;
  caller = o.caller;
  event = o.event;
  kind = o.kind;
  correct = o.correct;
  pending = o.pending;

  return *this;
}


bool Event::isCorrect()
{
  return correct;
}


bool Event::isPending()
{
  return pending;
}


bool Event::isRange()
{
  return range;
}


unsigned long Event::getStart()
{
  return time_start;
}


unsigned long Event::getDuration()
{
  return duration;
}


QString Event::getCaller()
{
  return caller;
}


event_kind Event::getKind()
{
  return kind;
}
