#pragma once
#include <QtWidgets/QApplication>
#include <QGraphicsPixmapItem>
#include <QObject>

class Box :public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	Box(QGraphicsItem * parent = 0);
	void isArrival();
	~Box();
};
