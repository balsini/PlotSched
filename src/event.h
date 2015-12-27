#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include <QString>
#include <QByteArray>

enum event_kind {
  ACTIVATION,
  DEAD,
  RUNNING,
  BLOCKED,
  DEADLINE
};

class Event : public QObject
{
  Q_OBJECT

  unsigned long time_start;
  unsigned long duration;
  unsigned long cpu;
  unsigned long row;
  QString caller;
  QString event;
  event_kind kind;

  bool correct;
  bool pending;
  bool range;

  void parseLine(QByteArray b);

public:
  Event();
  Event(const Event &o);
  Event& operator=(const Event &o);
  void parse(QByteArray line);
  bool isCorrect();
  bool isPending();
  bool isRange();
  unsigned long getRow() {return row; }
  void setRow(unsigned long r) { row = r; }
  unsigned long getStart();
  unsigned long getDuration();
  QString getCaller();
  event_kind getKind();
};


#endif // EVENT_H
