#pragma once
#include <QtWidgets/QApplication>
#include <QObject>
#include<QGraphicsRectItem>
#include <QBrush>
#define Size 75

class Spot :public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	Spot(QGraphicsItem * parent = 0);
	~Spot();
};

