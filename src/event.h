#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include <QString>
#include <QByteArray>

class Event : public QObject
{
  Q_OBJECT

  enum event {
    ARROW_UP,
    ARROW_DOWN,
    ARROW_CUSTOM,
    ACTIVATION
  };

  unsigned long time_start;
  unsigned long time_end;
  QString name;
  QString event;

  bool correct;
  bool range;

  void parseLine(QByteArray b);

public:
  Event(QByteArray event);
  Event(const Event &o);
  bool isCorrect();
  bool isRange();
};


#endif // EVENT_H
