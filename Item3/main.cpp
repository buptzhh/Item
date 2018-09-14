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
#include "LevelChoose.h"
#include "LevelPass.h"
#include "Parameter.h"


int main(int argc, char *argv[]) {
	QApplication a(argc, argv);


//	Map* map = new Map();
//	map->show();

	QGraphicsScene* ch = new QGraphicsScene();
	LevelChoose* c = new LevelChoose(ch);
	c->show();

	return a.exec();
}
