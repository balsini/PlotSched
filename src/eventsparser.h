#ifndef EVENTSPARSER_H
#define EVENTSPARSER_H

#include <QObject>
#include <QFile>
#include <QThread>

#include <QDebug>

enum event {
  DEADLINE,
  ACTIVATION
};

typedef struct plot_entity_ {
  unsigned long time_start;
  unsigned long duration;
  QString name;
  QString event;
} plot_entity;

class EventsParserWorker : public QObject
{
  Q_OBJECT

public slots:
  void doWork(QString path);

signals:
  void resultReady(const QString &result);
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
