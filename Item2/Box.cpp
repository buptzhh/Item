#include "Box.h"
#include "Block.h"
#include "Spot.h"
#include <QKeyEvent>
#include <QList>
#include"qsound.h"


Box::Box(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent) {
	setRect(0, 0, Size, Size);
	QBrush brush_Box(QImage(":/photos/Box"));
	setBrush(brush_Box);
}

void Box::isArrival() {
	QBrush brush_Box(QImage(":/photos/Box"));
	setBrush(brush_Box);                               //每次判断前将贴图换回未到达，且flag变成0
	flag = 0;

	QList<QGraphicsItem *> colliding_items = collidingItems(Qt::ContainsItemBoundingRect);            //以是否重合判定是否到达

	for (int i = 0, n = colliding_items.size(); i < n; ++i) {
		if (typeid(*(colliding_items[i])) == typeid(Spot)) {
			QBrush brush_Box2(QImage(":/photos/Box2"));
			setBrush(brush_Box2);                        //若是到达则将图片换成到达模式，且flag变成1
			flag = 1;
			QSound::play(":/sound/Arrival");
		}
	}
}

const bool Box::getFlag() {
	return flag;
}

Box::~Box()
{
}