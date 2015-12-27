#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QGraphicsScene>

class CustomScene : public QGraphicsScene
{
  Q_OBJECT

  qreal pressed_at;

public:
  explicit CustomScene(QObject *parent = 0);

signals:
  void rangeSelected(qreal, qreal);

public slots:
  virtual void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
  virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);

};

#endif // CUSTOMSCENE_H
