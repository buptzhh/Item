#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <qgraphicsview.h>
#include <QGraphicsPixmapItem>
#include "Block.h"
#include "Boxes.h"
#include "Player.h"
#include "Spot.h"
#include <QBrush>
#include <QImage>
#include "Map.h"
#include "Map1.h"
#include "Map2.h"
#include "Map3.h"
#include "Map4.h"
#include <qpushbutton.h>
#include "Choose_Level.h"


int main(int argc, char *argv[]) {
	QApplication a(argc, argv);


//	Map* map = new Map();
//	map->show();

	QGraphicsScene* ch = new QGraphicsScene();
	Choose_Level* c = new Choose_Level(ch);
	c->show();

	return a.exec();
}
