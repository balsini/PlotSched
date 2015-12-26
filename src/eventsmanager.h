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

  QMap <QString, QList<Event>> m;

public:
    EventsManager();

signals:

public slots:
    void newEventArrived(Event e)
    {
      QList<Event>::iterator i = m[e.getCaller()].begin();
      while (i != m[e.getCaller()].end() && (*i).getStart() < e.getStart())
        ++i;
      m[e.getCaller()].insert(i, e);
    }
};

#endif // EVENTSMANAGER_H
