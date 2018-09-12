#include "Block.h"



Block::Block(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent) {
	setRect(0, 0, Size, Size);
	QBrush brush_Block(QImage(":/photos/Block"));
	setBrush(brush_Block);
}


Block::~Block()
{
}
