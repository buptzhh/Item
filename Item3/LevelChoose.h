#pragma once
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
#include<qgraphicsitem.h>
#include<qpushbutton.h>
#include"Map.h"

class LevelChoose:public Map
{
	Q_OBJECT
public:
	LevelChoose(QGraphicsScene * scene);
	~LevelChoose();
	

public slots:

void levelChoose();
void deleteButton();

private:
	QGraphicsScene * scene_;
	QPushButton* button1;
	QPushButton* button2;
	QPushButton* button3;
	QPushButton* button4;
};

