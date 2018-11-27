/**
  pear.h
  Purpose: Makes a pear object
*/

#ifndef PEAR_H
#define PEAR_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class Pear : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit Pear(QObject *parent = nullptr);
    ~Pear();

signals:

public slots:

protected:
    /**
     * limits a space where pear can be
     *
     * @brief boundingRect
     * @return coordinates of a space where pear object can be
     */
    QRectF boundingRect() const;

    /**
     * paints a pear object
     *
     * @brief paint
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    /** color of pear */
    int color;
};

#endif // PEAR_H
