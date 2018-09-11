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
	setPixmap(QPixmap(":/photos/Box2"));                                  //ÿ���ж�ǰ����ͼ����δ����

	QList<QGraphicsItem *> colliding_items = collidingItems();            //�ж��Ƿ񵽴�

	for (int i = 0, n = colliding_items.size(); i < n; ++i) {
		if (typeid(*(colliding_items[i])) == typeid(Destination))
			setPixmap(QPixmap(":/photo/Box"));
	}
}

Box::~Box()
{
}