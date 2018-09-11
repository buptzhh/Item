#include "Box.h"
#include "Block.h"
#include "Destination.h"
#include <QKeyEvent>
#include <QList>
#define run_speed 75

Box::Box(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap(":/photos/Box2"));
}

void Box::isArrival() {
	setPixmap(QPixmap(":/photos/Box2"));                                  //每次判断前将贴图换回未到达

	QList<QGraphicsItem *> colliding_items = collidingItems();            //判断是否到达

	for (int i = 0, n = colliding_items.size(); i < n; ++i) {
		if (typeid(*(colliding_items[i])) == typeid(Destination))
			setPixmap(QPixmap(":/photo/Box"));
	}
}

Box::~Box()
{
}