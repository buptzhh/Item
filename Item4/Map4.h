#pragma once
#include"Block.h"
#include"Boxes.h"
#include"Player.h"
#include"Spot.h"
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
#include<qgraphicsitem.h>
class Map4 :public QObject
{
	Q_OBJECT
public:
	Map4(QGraphicsScene* scene);
	Map4();
	~Map4();
private:
	QGraphicsScene * scene_;
	Block * block[52];
	Boxes*box[6];
	Player *player;
	Spot* spot[6];
	public slots:
	void reStart();

};
