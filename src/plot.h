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

public:
  explicit Plot(QWidget *parent = 0);
  void clear();

signals:

public slots:
  void addNewItem(QGraphicsItem * i);

};

#endif // PLOT_H
