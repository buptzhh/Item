#pragma once
#include <QtWidgets/QApplication>
#include<QGraphicsRectItem>
#include <QObject>
#include <QBrush>
#define Size 75

class Boxes :public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	Boxes(QGraphicsItem * parent = 0);
	void isArrival();
	~Boxes();
	const bool getFlag();
private:
	bool flag = 0;          //flag�����ж�box�Ƿ񵽴�spot
	static int count;      //��������¼����spot��boxes����
};
