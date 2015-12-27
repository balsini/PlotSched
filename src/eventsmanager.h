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
    void newEventArrived(Event e);
};

#endif // EVENTSMANAGER_H
