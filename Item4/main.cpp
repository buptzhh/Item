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
#include "Start.h"
#include "Userfile.h"
#include "Users.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);


//	Map* map = new Map();
//	map->show();

	QGraphicsScene* s = new QGraphicsScene();
	LevelChoose* c = new LevelChoose(s,4);
	c->setScene(s);
	
	c->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	c->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	c->setFixedSize(975, 675);
	c->show();

	return a.exec();
}
