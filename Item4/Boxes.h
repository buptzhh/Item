#pragma once
#include <QtWidgets/QApplication>
#include<QGraphicsRectItem>
#include <QObject>
#include <QBrush>
#include "LevelPass.h"
#define Size 75

class Boxes :public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	Boxes(QGraphicsItem * parent = 0);
	void isArrival();
	~Boxes();
	const bool getFlag();
private:
	bool flag = 0;          //flag用来判断box是否到达spot
	static int count;      //计数器记录到达spot的boxes数量
signals:
	void levelPass();
};
