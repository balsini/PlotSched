#include "eventsparser.h"
#include "eventview.h"

#include <QDebug>

EventsParser::EventsParser()
{
  EventsParserWorker * worker = new EventsParserWorker;

  worker->moveToThread(&workerThread);
  connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
  connect(this, &EventsParser::operate, worker, &EventsParserWorker::doWork);
  connect(worker, &EventsParserWorker::resultReady, this, &EventsParser::handleResults);
  connect(worker, SIGNAL(eventGeneratedByWorker(QGraphicsItem *)), this, SLOT(eventGeneratedByWorker(QGraphicsItem *)));

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

void EventsParser::eventGeneratedByWorker(QGraphicsItem * e)
{
  emit eventGenerated(e);
}

void EventsParserWorker::doWork(QString path)
{
  QString result;
  QFile f(path);

  if (f.open(QIODevice::ReadOnly | QIODevice::Text)) {
    while (!f.atEnd()) {
      Event e(f.readLine());
      if (e.isCorrect()) {
        EventView * ev = new EventView();
        emit eventGeneratedByWorker(ev);
      }
    }
  }

  emit resultReady(result);
}
