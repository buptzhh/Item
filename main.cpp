#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <qgraphicsview.h>
#include <QGraphicsPixmapItem>
#include "Block.h"
#include "Box.h"
#include "Player.h"
#include "Destination.h"
#include <QBrush>
#include <QImage>


int main(int argc, char *argv[]) {

	QApplication a(argc, argv);
	QGraphicsScene *scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 675, 675);
	scene->setBackgroundBrush(QBrush(QImage(":/photos/Floor")));
	
	Block * block = new Block();
	block->setPos(0,0);
	scene->addItem(block);
	
	Destination *destination = new Destination();
	destination->setPos(150,150);
	scene->addItem(destination);

	Box *box = new Box();
	box->setPos(300, 300);
	scene->addItem(box);
	
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
