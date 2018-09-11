#pragma once
#include <QtWidgets/QApplication>
#include <QGraphicsPixmapItem>
#include <QObject>

class Destination :public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	Destination(QGraphicsItem * parent = 0);
	~Destination();
};

