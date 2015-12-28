#include "eventsmanager.h"

EventsManager::EventsManager()
{
  last_event = 0;
}


void EventsManager::clear()
{
  events_container.clear();
}


void EventsManager::newEventArrived(Event e)
{
  QList<Event>::iterator i = events_container[e.getCaller()].begin();
  while (i != events_container[e.getCaller()].end() && (*i).getStart() < e.getStart())
    ++i;
  events_container[e.getCaller()].insert(i, e);
  if (e.getStart() > last_event)
    last_event = e.getStart();
}

unsigned long EventsManager::countCallers()
{
  return events_container.count();
}


QList<Event> * EventsManager::getCallerEventsList(unsigned long caller)
{
  unsigned long c = 0;
  QMap <QString, QList<Event>>::iterator i = events_container.begin();
  while (c <= caller && i != events_container.end()) {
    ++i;
    ++c;
  }
  return &(*i);
}


QMap <QString, QList<Event>> * EventsManager::getCallers()
{
  return &events_container;
}


void EventsManager::magnify(qreal start, qreal end)
{
  static qreal last_magnification = 1;
  qreal size = end - start;

  if (size == 0)
    return;

  qreal last_event_magnified = last_event * last_magnification;
  qreal fraction;
  qreal normalized = size / last_event_magnified;

  if (size > 0)
    fraction = 1 / normalized;
  else
    fraction = -normalized;

  last_magnification = fraction;

  for (QMap<QString, QList<Event>>::iterator l = events_container.begin();
       l != events_container.end();
       ++l) {
    for (QList<Event>::iterator i = (*l).begin(); i != (*l).end(); ++i)
      (*i).setMagnification(fraction);
  }
}
