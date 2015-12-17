#ifndef TRACEFILELISTER_H
#define TRACEFILELISTER_H

#include <QDockWidget>

class TraceFileLister : public QDockWidget
{
  Q_OBJECT

public:
  explicit TraceFileLister(QWidget *parent = 0);
  ~TraceFileLister();

};

#endif // TRACEFILELISTER_H
