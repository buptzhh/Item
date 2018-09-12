#pragma once
#include <QtWidgets/QApplication>
#include<QGraphicsRectItem>
#include <QObject>
#include <QBrush>
#define Size 75

class Block :public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	Block(QGraphicsItem * parent = 0);
	~Block();
};

