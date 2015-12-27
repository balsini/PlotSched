#include "eventsmanager.h"

EventsManager::EventsManager()
{}


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
}
