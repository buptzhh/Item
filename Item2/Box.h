#pragma once
#include <QtWidgets/QApplication>
#include<QGraphicsRectItem>
#include <QObject>
#include <QBrush>
#define Size 75

class Box :public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	Box(QGraphicsItem * parent = 0);
	void isArrival();
	~Box();
	const bool getFlag();
private:
	bool flag = 0;          //flag用来判断box是否到达spot
};
