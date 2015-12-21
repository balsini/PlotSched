#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include <QString>
#include <QByteArray>

class Event : public QObject
{
  Q_OBJECT

  enum event {
    DEADLINE,
    ACTIVATION
  };

  unsigned long time_start;
  unsigned long duration;
  QString name;
  QString event;

  bool correct;

  void parseLine(QByteArray b);

public:
  Event(QString event);
  bool isCorrect();
};


#endif // EVENT_H
