#pragma once
#include <QtWidgets/QApplication>
#include <QGraphicsPixmapItem>
#include <QObject>

class Block :public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	Block(QGraphicsItem * parent = 0);
	~Block();
};

