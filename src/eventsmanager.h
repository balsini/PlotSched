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

  QMap<QString, QList<Event>> events_container;
  qreal last_event;

public:
    EventsManager();
    void clear();
    unsigned long countCallers();
    QList<Event> * getCallerEventsList(unsigned long caller);
    QMap <QString, QList<Event>> * getCallers();

signals:

public slots:
    void newEventArrived(Event e);
    void magnify(qreal start, qreal end);
};

#endif // EVENTSMANAGER_H
