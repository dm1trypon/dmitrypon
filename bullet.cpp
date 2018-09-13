#include "spaceship.h"
#include "widget.h"
#include "bullet.h"
#include "linksignal.h"
#include "asteroid.h"
#include "enemyspaceship.h"

#include <QDebug>

Bullet::Bullet(QPointF initPos, QGraphicsItem *parent) : QGraphicsLineItem (parent)
{
    setPen(QPen(QBrush(Qt::red), 3));
    setLine(0, 0, 0, -bulletLenght);
    setPos(initPos);
}

void Bullet::advance(int phase)
{
    if (phase >= 1)
    {
        moveBullet();
    }
    if (phase <= 0) {
        collisionObjects();
    }
}

void Bullet::moveBullet()
{
    moveBy(0, -yspeed);
    if (collision()) {
        delete this;
    }
}

void Bullet::collisionObjects()
{
    foreach(QGraphicsItem* item, collidingItems()) {
        Asteroid* objAsteroid = qgraphicsitem_cast<Asteroid*>(item);
        EnemySpaceship* objEnemySpaceship = qgraphicsitem_cast<EnemySpaceship*>(item);
        destroyDefinition(item, objAsteroid, objEnemySpaceship);
    }
}

void Bullet::destroyDefinition(QGraphicsItem* item, Asteroid* objAsteroid, EnemySpaceship* objEnemySpaceship)
{
    if (objAsteroid) {
        item->setData(0, true);
        setData(0, true);
    }
    if (objEnemySpaceship) {
        checkDestroyEnemySpaceship(item);
    }
}

void Bullet::checkDestroyEnemySpaceship (QGraphicsItem* item)
{
    item->setData(0, true);
    setData(0, true);
}

bool Bullet::collision()
{
    return data(0).toBool() || this->y() < SCREEN_TOP;
}
