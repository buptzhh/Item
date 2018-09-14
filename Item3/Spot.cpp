#include "Spot.h"


Spot::Spot(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent) {
	setRect(0, 0, Size, Size);
	QBrush brush_Spot(QImage(":/photos/Spot"));
	setBrush(brush_Spot);
}


Spot::~Spot()
{
}
