#ifndef ENEMYSPACESHIP_H
#define ENEMYSPACESHIP_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "linksignal.h"

class EnemySpaceship : public QGraphicsPixmapItem {
public:
    enum { Type = UserType + 1};
    EnemySpaceship(qreal xspread);
    void advance(int phase);
    LinkSignal &getController();
    int type() const;
private:
    int yspeed = 3;
    LinkSignal Controller;
    void endGameMessageEnemySpaceship(int var);
    void destroyEnemySpaceshipBullet(int var);
    void destroyEnemySpaceshipRange();
};

#endif // ENEMYSPACESHIP_H