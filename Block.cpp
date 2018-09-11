#include "Block.h"



Block::Block(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap(":/photos/Block"));
}


Block::~Block()
{
}
