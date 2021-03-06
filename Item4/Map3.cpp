﻿#include "Map3.h"
#define unit 75
extern int boxesNumber;

Map3::Map3()
{

}

Map3::Map3(QGraphicsScene *scene)
{
	//initialize the scene
	scene_ = scene;
	scene->setSceneRect(0, 0, 975, 675);
	scene->setBackgroundBrush(QBrush(QImage("Resources/Floor.jpg")));

	//create the map

	//block*54,player*1,,box*3
	for (int i = 0; i < 56; i++)
	{
		block[i] = new Block();
	}
	player = new Player();
	for (int i = 0; i < 4; i++)
	{
		box[i] = new Boxes();
		spot[i] = new Spot();
	}

	boxesNumber = 4;

	//row0
	for (int i = 0; i < 9; i++)
	{
		block[i]->setPos(unit*i, 0);
	}

	//row1
	for (int i = 9; i < 18; i++)
	{
		block[i]->setPos(unit*(i - 9), unit);
	}

	//row2
	int row2 = unit * 2;
	block[18]->setPos(0, row2);
	for (int i = 19; i < 22; i++)
	{
		block[i]->setPos(unit*(i - 13), row2);
	}

	//row3
	int row3 = unit * 3;
	block[22]->setPos(0, row3);
	for (int i = 23; i < 27; i++)
	{
		block[i]->setPos(unit*(i - 18), row3);
	}
	for (int i = 0; i < 3; i++)
	{
		box[i]->setPos(unit*(i + 2), row3);
	}

	//row4
	int row4 = unit * 4;
	block[27]->setPos(0, row4);
	block[28]->setPos(unit * 3, row4);
	for (int i = 29; i < 32; i++)
	{
		block[i]->setPos(unit*(i - 23), row4);
	}
	spot[0]->setPos(unit * 4, row4);
	spot[1]->setPos(unit * 5, row4);

	//row5
	int row5 = unit * 5;
	block[32]->setPos(0, row5);
	block[33]->setPos(unit, row5);
	block[34]->setPos(unit * 8, row5);
	spot[2]->setPos(unit * 4, row5);
	spot[3]->setPos(unit * 5, row5);
	box[3]->setPos(unit * 6, row5);

	//row6
	int row6 = unit * 6;
	block[35]->setPos(0, row6);
	block[36]->setPos(unit, row6);
	block[37]->setPos(unit * 8, row6);
	player->setPos(unit * 3, row6);

	//row7
	int row7 = unit * 7;
	for (int i = 38; i < 47; i++)
	{
		block[i]->setPos(unit*(i - 38), row7);
	}

	//row8
	int row8 = unit * 8;
	for (int i = 47; i < 56; i++)
	{
		block[i]->setPos(unit*(i - 47), row8);
	}

	//add items to the scene
	scene->addItem(player);
	for (int i = 0; i < 57; i++)
	{
		scene->addItem(block[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		scene->addItem(box[i]);
		scene->addItem(spot[i]);

	}
	//ÈËÎï¿ÉÒÆ¶¯ÉèÖÃ
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	QPushButton* reStart = new QPushButton("reStart");							 //加上重新开始按钮
	reStart->setGeometry(QRect(675, 0, 200, 75));
	QFont* font = new QFont;
	font->setFamily("Impact");
	font->setPointSize(20);
	QObject::connect(reStart, SIGNAL(clicked()), this, SLOT(reStart()));        //点下按钮则重新开始
	reStart->setFont(*font);

	scene->addWidget(reStart);

}

void Map3::reStart() {								//重置boxes和player位置
	//row3
	int row3 = unit * 3;
	for (int i = 0; i < 3; i++)
	{
		box[i]->setPos(unit*(i + 2), row3);
	}

	//row5
	int row5 = unit * 5;
	box[3]->setPos(unit * 6, row5);

	//row6
	int row6 = unit * 6;
	player->setPos(unit * 3, row6);

	for (int i = 0; i < boxesNumber; i++) {
		QBrush brush_Box(QImage("Resources/boxF.png"));
		box[i]->setBrush(brush_Box);
	}

	//ÈËÎï¿ÉÒÆ¶¯ÉèÖÃ
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
}

Map3::~Map3()
{
}