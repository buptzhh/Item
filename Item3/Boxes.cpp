#include "Boxes.h"
#include "Block.h"
#include "Spot.h"
#include <QKeyEvent>
#include <QList>
#include "qsound.h"

int boxesNumber = 0;
int Boxes::count = 0;                                          //����������ʼ��Ϊ0

Boxes::Boxes(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent) {
	setRect(0, 0, Size, Size);
	QBrush brush_Box(QImage(":/photos/Box"));
	setBrush(brush_Box);
}

void Boxes::isArrival() {
	QList<QGraphicsItem *> colliding_items = collidingItems(Qt::ContainsItemBoundingRect);            //���Ƿ��غ��ж��Ƿ񵽴�

	if (0 == colliding_items.size() && 1 == flag){            //���Ѿ�����������뿪���յ㣬flag��0����������һ
		QBrush brush_Box(QImage(":/photos/Box"));
		setBrush(brush_Box);
		flag = 0;
		count--;
	}
	
	for (int i = 0, n = colliding_items.size(); i < n; ++i) {
		if (typeid(*(colliding_items[i])) == typeid(Spot)) {
			colliding_items[i]->stackBefore(this);
			QBrush brush_Box2(QImage(":/photos/Box2"));
			setBrush(brush_Box2);                        //���ǵ�����ͼƬ���ɵ���ģʽ����flag���1,��������һ
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