#include "eventsmanager.h"

EventsManager::EventsManager()
{}


void EventsManager::newEventArrived(Event e)
{
  QList<Event>::iterator i = m[e.getCaller()].begin();
  while (i != m[e.getCaller()].end() && (*i).getStart() < e.getStart())
    ++i;
  m[e.getCaller()].insert(i, e);
}
