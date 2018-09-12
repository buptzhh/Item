#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <qgraphicsview.h>
#include <QGraphicsPixmapItem>
#include "Block.h"
#include "Box.h"
#include "Player.h"
#include "Spot.h"
#include <QBrush>
#include <QImage>


int main(int argc, char *argv[]) {

	QApplication a(argc, argv);
	QGraphicsScene *scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 675, 675);
	scene->setBackgroundBrush(QBrush(QImage(":/photos/Floor")));
	
	Block * block1 = new Block();
	block1->setPos(150,150);
	scene->addItem(block1);
	Block * block2 = new Block();
	block2->setPos(75, 150);
	scene->addItem(block2);
	Block * block3 = new Block();
	block3->setPos(150, 225);
	scene->addItem(block3);
	
	Spot *spot1 = new Spot();
	spot1->setPos(375,375);
	scene->addItem(spot1);
	Spot *spot2 = new Spot();
	spot2->setPos(75, 225);
	scene->addItem(spot2);

	Box *box1 = new Box();
	box1->setPos(300, 300);
	scene->addItem(box1);
	Box *box2 = new Box();
	box2->setPos(375, 375);
	scene->addItem(box2);
	
	Player *player = new Player();
	player->setPos(450,450);
	scene->addItem(player);
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	QGraphicsView *view = new QGraphicsView(scene);
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view->setFixedSize(675, 675);
	view->show();

	return a.exec();
}
