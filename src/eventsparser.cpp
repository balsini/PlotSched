#include "eventsparser.h"

#include <QDebug>

EventsParser::EventsParser()
{
  EventsParserWorker *worker = new EventsParserWorker;

  worker->moveToThread(&workerThread);
  connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
  connect(this, &EventsParser::operate, worker, &EventsParserWorker::doWork);
  connect(worker, &EventsParserWorker::resultReady, this, &EventsParser::handleResults);

  workerThread.start();
}

void EventsParser::parseFile(QString path)
{
  emit operate(path);
}

EventsParser::~EventsParser()
{
  workerThread.quit();
  workerThread.wait();
}

void EventsParser::handleResults(const QString &)
{}


plot_entity parseLine(QByteArray line)
{
  // TODO

  plot_entity e;
  QTextStream ss(line);

  ss >> e.time_start;
  ss >> e.name;
  ss >> e.event;

  qDebug() << "Read from device : " << e.time_start;
  qDebug() << "Read from device : " << e.name;
  qDebug() << "Read from device : " << e.event;

  qDebug() << "";

  return e;
}

bool correctLine(QByteArray line)
{
  // TODO

  if (line.size() < 2)
    return false;
  return true;
}

void EventsParserWorker::doWork(QString path)
{
  QString result;
  QFile f(path);

  if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
    while (!f.atEnd()) {
      QByteArray line = f.readLine();
      if (correctLine(line))
        parseLine(line);
    }
  }

  emit resultReady(result);
}
