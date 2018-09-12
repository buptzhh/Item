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
	setBrush(brush_Box);                               //ÿ���ж�ǰ����ͼ����δ�����flag���0
	flag = 0;

	QList<QGraphicsItem *> colliding_items = collidingItems(Qt::ContainsItemBoundingRect);            //���Ƿ��غ��ж��Ƿ񵽴�

	for (int i = 0, n = colliding_items.size(); i < n; ++i) {
		if (typeid(*(colliding_items[i])) == typeid(Spot)) {
			QBrush brush_Box2(QImage(":/photos/Box2"));
			setBrush(brush_Box2);                        //���ǵ�����ͼƬ���ɵ���ģʽ����flag���1
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