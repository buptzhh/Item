#pragma once
#include<qgraphicsscene.h>
#include<qgraphicsview.h>
#include<qgraphicsitem.h>
#include<qpushbutton.h>
#include"Map.h"
#define levelNumber 4
class LevelChoose:public Map
{
	Q_OBJECT
public:
	LevelChoose(QGraphicsScene * scene, const int &level);
	~LevelChoose();
	

public slots:

void levelChoose(const int &level);             //level为可选关卡


private:
	QGraphicsScene * scene_;
	QPushButton* button[levelNumber];          //选关按钮

};

