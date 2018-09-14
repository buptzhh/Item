#include "Boxes.h"
#include "Block.h"
#include "Spot.h"
#include <QKeyEvent>
#include <QList>
#include "qsound.h"

int boxesNumber = 0;
int Boxes::count = 0;                                          //将计数器初始化为0

Boxes::Boxes(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent) {
	setRect(0, 0, Size, Size);
	QBrush brush_Box(QImage(":/photos/Box"));
	setBrush(brush_Box);
}

void Boxes::isArrival() {
	QList<QGraphicsItem *> colliding_items = collidingItems(Qt::ContainsItemBoundingRect);            //以是否重合判定是否到达

	if (0 == colliding_items.size() && 1 == flag){            //若已经到达过但是离开了终点，flag变0，计数器减一
		QBrush brush_Box(QImage(":/photos/Box"));
		setBrush(brush_Box);
		flag = 0;
		count--;
	}
	
	for (int i = 0, n = colliding_items.size(); i < n; ++i) {
		if (typeid(*(colliding_items[i])) == typeid(Spot)) {
			colliding_items[i]->stackBefore(this);
			QBrush brush_Box2(QImage(":/photos/Box2"));
			setBrush(brush_Box2);                        //若是到达则将图片换成到达模式，且flag变成1,计数器加一
			if (flag == 0) {
				count++;
				flag = 1;
			}
			QSound::play(":/sound/Arrival");
		}
	}

	if (count == boxesNumber)
	{
		QSound::play(":/sound/Win");
		return;
	}
}

const bool Boxes::getFlag() {
	return flag;
}

Boxes::~Boxes()
{
}