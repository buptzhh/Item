#pragma once
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
#include<qgraphicsitem.h>
#include<qpushbutton.h>
#include"Map.h"
#include"Map1.h"
#include"Map2.h"
#include"Map3.h"
#include"Map4.h"
class Choose_Level:public Map{
	Q_OBJECT
public:
	Choose_Level(QGraphicsScene * scene);
	~Choose_Level();
	

public slots:

void levelchoose();

private:
	QGraphicsScene * scene_;
	QPushButton* button1;
	QPushButton* button2;
	QPushButton* button3;
	QPushButton* button4;
};

