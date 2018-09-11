#pragma once
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Player :public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
public:
	Player(QGraphicsItem * parent = 0);
	~Player();
	void keyPressEvent(QKeyEvent * event);
};