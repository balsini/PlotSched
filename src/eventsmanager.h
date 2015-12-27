#ifndef EVENTSMANAGER_H
#define EVENTSMANAGER_H

#include <QObject>
#include <QMap>
#include <QList>
#include <QString>

#include "event.h"

class EventsManager : public QObject
{
  Q_OBJECT

  QMap <QString, QList<Event>> events_container;

public:
    EventsManager();
    void clear();
    unsigned long countCallers() { return events_container.count(); }
    QList<Event> * getCallerEventsList(unsigned long caller)
    {
      unsigned long c = 0;
      QMap <QString, QList<Event>>::iterator i = events_container.begin();
      while (c <= caller && i != events_container.end()) {
        ++i;
        ++c;
      }
      return &(*i);
    }

    QMap <QString, QList<Event>> * getCallers()
    {
      return &events_container;
    }

signals:

public slots:
    void newEventArrived(Event e);
};

#endif // EVENTSMANAGER_H
