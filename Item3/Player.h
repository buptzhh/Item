#pragma once

#include<QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#define Size 75
#define Step 75

class Player :public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	Player(QGraphicsItem * parent = 0);
	void keyPressEvent(QKeyEvent * event);
	~Player();
};