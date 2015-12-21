#ifndef EVENTSPARSER_H
#define EVENTSPARSER_H

#include "event.h"

#include <QObject>
#include <QFile>
#include <QThread>

#include <QDebug>

class EventsParserWorker : public QObject
{
  Q_OBJECT

public slots:
  void doWork(QString path);

signals:
  void resultReady(const QString &result);
  void eventGenerated(Event e);
};

class EventsParser : public QObject
{
  Q_OBJECT
  QThread workerThread;

public:
  explicit EventsParser();
  ~EventsParser();
  void parseFile(QString);

public slots:
  void handleResults(const QString &);

signals:
  void operate(QString);
};

#endif // EVENTSPARSER_H
