#include "eventsparser.h"
#include "event.h"

#include <QDebug>

EventsParser::EventsParser()
{
  EventsParserWorker * worker = new EventsParserWorker;

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


void EventsParserWorker::doWork(QString path)
{
  QString result;
  QFile f(path);

  if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
    while (!f.atEnd()) {
      Event e(f.readLine());
      if (e.isCorrect())
        emit eventGenerated(e);
    }
  }

  emit resultReady(result);
}
