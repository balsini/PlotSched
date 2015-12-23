#ifndef PLOT_H
#define PLOT_H

#include <QWidget>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <QGraphicsItem>

class Plot : public QWidget
{
  Q_OBJECT

  QGraphicsScene * scene;
  QGraphicsView * view;

protected:
  virtual void wheelEvent(QWheelEvent* event);

public:
  explicit Plot(QWidget *parent = 0);
  void clear();

signals:

public slots:
  void addNewItem(QGraphicsItem * i);

};

#endif // PLOT_H
