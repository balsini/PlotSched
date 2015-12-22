#ifndef EVENTSPARSER_H
#define EVENTSPARSER_H

#include "event.h"

#include <QObject>
#include <QFile>
#include <QThread>
#include <QGraphicsItem>

#include <QDebug>

class EventsParserWorker : public QObject
{
  Q_OBJECT

public slots:
  void doWork(QString path);

signals:
  void resultReady(const QString &result);
  void eventGeneratedByWorker(QGraphicsItem *);
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
  void eventGeneratedByWorker(QGraphicsItem *);

signals:
  void operate(QString);
  void eventGenerated(QGraphicsItem *);
};

#endif // EVENTSPARSER_H
