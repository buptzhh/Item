#include "Destination.h"


Destination::Destination(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap(":/photos/Destination"));
}


Destination::~Destination()
{
}
