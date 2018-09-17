﻿
#include "Map1.h"
#include<qbrush.h>
#define unit 75
extern int boxesNumber;

Map1::Map1()
{

}

Map1::Map1(QGraphicsScene *scene)
{
	//initialize the scene
	scene_ = scene;
	scene->setSceneRect(0, 0, 975, 675);
	scene->setBackgroundBrush(QBrush(QImage("Resources/Floor.jpg")));

	//create the map

	//block*54,player*1,,box*3
	for (int i = 0; i <54; i++)
	{
		block[i] = new Block();
	}
	player = new Player();
	for (int i = 0; i < 3; i++)
	{
		box[i] = new Boxes();
		spot[i] = new Spot();
	}

	boxesNumber = 3;

	//row0
	for (int i = 0; i < 9; i++)
	{
		block[i]->setPos(unit*i, 0);
	}
	//row1
	int row1 = unit;
	block[9]->setPos(0, row1);
	block[10]->setPos(unit * 4, row1);
	block[11]->setPos(unit * 5, row1);
	block[12]->setPos(unit * 6, row1);
	block[13]->setPos(unit * 7, row1);
	block[14]->setPos(unit * 8, row1);
	player->setPos(unit, row1);

	//row2
	int row2 = unit * 2;
	block[15]->setPos(0, row2);
	block[16]->setPos(unit * 4, row2);
	block[17]->setPos(unit * 5, row2);
	block[18]->setPos(unit * 6, row2);
	block[19]->setPos(unit * 7, row2);
	block[20]->setPos(unit * 8, row2);
	box[0]->setPos(unit * 2, row2);
	box[1]->setPos(unit * 3, row2);

	//row3
	int row3 = unit * 3;
	block[21]->setPos(0, row3);
	block[22]->setPos(unit * 4, row3);
	block[23]->setPos(unit*5., row3);
	block[24]->setPos(unit * 6, row3);
	block[25]->setPos(unit * 8, row3);
	box[2]->setPos(unit * 2, row3);
	spot[0]->setPos(unit * 7, row3);

	//row4
	int row4 = unit * 4;
	block[26]->setPos(0, row4);
	block[27]->setPos(unit * 1, row4);
	block[28]->setPos(unit * 2, row4);
	block[29]->setPos(unit * 4, row4);
	block[30]->setPos(unit * 5, row4);
	block[31]->setPos(unit * 6, row4);
	block[32]->setPos(unit * 8, row4);
	spot[1]->setPos(unit * 7, row4);

	//row5
	int row5 = unit * 5;
	block[33]->setPos(0, row5);
	block[34]->setPos(unit * 1, row5);
	block[35]->setPos(unit * 2, row5);
	block[36]->setPos(unit * 8, row5);
	spot[2]->setPos(unit * 7, row5);

	//row6
	int row6 = unit * 6;
	block[37]->setPos(0, row6);
	block[38]->setPos(unit, row6);
	block[39]->setPos(unit * 5, row6);
	block[40]->setPos(unit * 8, row6);

	//row7
	int row7 = unit * 7;
	block[41]->setPos(0, row7);
	block[42]->setPos(unit, row7);
	block[43]->setPos(unit * 5, row7);
	block[44]->setPos(unit * 8, row7);

	//row8
	for (int i = 45; i < 54; i++)
	{
		block[i]->setPos(unit*(i - 45), unit * 8);
	}


	//add items to the scene
	scene->addItem(player);
	for (int i = 0; i < 54; i++)
	{
		scene->addItem(block[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		scene->addItem(box[i]);
		scene->addItem(spot[i]);

	}

	QPushButton* reStart = new QPushButton("reStart");							 //加上重新开始按钮
	reStart->setGeometry(QRect(675, 0, 200, 75));
	QFont* font = new QFont;
	font->setFamily("Impact");
	font->setPointSize(20);
	QObject::connect(reStart, SIGNAL(clicked()), this, SLOT(reStart()));        //点下按钮则重新开始
	reStart->setFont(*font);

	scene->addWidget(reStart);

	//ÈËÎï¿ÉÒÆ¶¯ÉèÖÃ
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();



}

void Map1::reStart() {									//重置boxes和player位置
	int row1 = unit;
	player->setPos(unit, row1);

	//row2
	int row2 = unit * 2;
	box[0]->setPos(unit * 2, row2);
	box[1]->setPos(unit * 3, row2);

	//row3
	int row3 = unit * 3;
	box[2]->setPos(unit * 2, row3);

	for (int i = 0; i < boxesNumber; i++) {
		QBrush brush_Box(QImage("Resources/boxF.png"));
		box[i]->setBrush(brush_Box);
	}
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();
}

Map1::~Map1()
{
}