#include "Player.h"
#include <QKeyEvent>
#include <QList>
#include "Block.h"
#include "Box.h"
#include <QGraphicsScene>
#include <QBrush>
#include "qsound.h"


Player::Player(QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent) {
	setRect(0, 0, Size, Size);
	QBrush brush_D(QImage(":/photos/D"));
	setBrush(brush_D);
}

void arrival(Box* box_) {                   //改函数用于调用Box类里的isArrival函数
	box_->isArrival();
}

void Player::keyPressEvent(QKeyEvent* event)
{
	{
		if (event->key() == Qt::Key_Left)//当按下按键时
		{
			QList<QGraphicsItem* >colliding_item1 = collidingItems();//检测与玩家的碰撞
			for (int i = 0, n = colliding_item1.size(); i < n; i++)
			{

				if (typeid(*(colliding_item1[i])) == typeid(Box))//如果玩家与箱子发生了碰撞
				{
					//scene()->removeItem(this);//图片情况下是发生了碰撞的

					QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();//在检测在这种情况下与箱子的碰撞
					for (int j = 0, m = colliding_item2.size(); j < m; j++)
					{
						if (typeid(*(colliding_item2[j])) == typeid(Block))//如果箱子与障碍物又有接触
						{/*如果有障碍物
						 阻挡箱子的推动则人是不能继续前进的,下述就是 障碍物-箱子-人，施力方向向左的情况*/
							if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x() + Size
								&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
								&& colliding_item1[i]->pos().x() + Size == (pos().x())
								&& colliding_item1[i]->pos().y() == (pos().y()))
								setPos(x() + Step, y());
						}
						else
						{
							if (colliding_item1[i]->pos().x() + Size == (pos().x())
								&& colliding_item1[i]->pos().y() == (pos().y()))//人从箱子右侧推
							{
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x() - Step, colliding_item1[i]->pos().y());
								arrival(dynamic_cast<Box*>(colliding_item1[i]));
							}
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().x() + Size == (pos().x())//人从障碍物右侧推
						&& colliding_item1[i]->pos().y() == (pos().y()))
						setPos(x() + Step, y());
				}
			}
			QBrush brush_L(QImage(":/photos/L"));//在每按下键的同时更换朝向图片，同样用setBrush函数
			setBrush(brush_L);
			setPos(x() - Step, y());
			QSound::play(":/sound/Move");                     //电音王子宋云飞
		}//其它几个按键同理
		else if (event->key() == Qt::Key_Right)
		{
			QList<QGraphicsItem* >colliding_item1 = collidingItems();
			for (int i = 0, n = colliding_item1.size(); i < n; i++)
			{
				if (typeid(*(colliding_item1[i])) == typeid(Box))
				{
					QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
					for (int j = 0, m = colliding_item2.size(); j < m; j++)
					{
						if (typeid(*(colliding_item2[j])) == typeid(Block))
						{
							if (colliding_item1[i]->pos().x() + Size == colliding_item2[j]->pos().x()
								&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
								&& colliding_item1[i]->pos().x() == (pos().x() + Size)
								&& colliding_item1[i]->pos().y() == (pos().y()))
								setPos(x() - Step, y());
						}
						else
							if (colliding_item1[i]->pos().x() == (pos().x() + Size)//人从箱子左侧推
								&& colliding_item1[i]->pos().y() == (pos().y()))
							{
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x() + Step, colliding_item1[i]->pos().y());
								arrival(dynamic_cast<Box*>(colliding_item1[i]));
							}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().x() == (pos().x() + Size)//人从障碍物左侧推
						&& colliding_item1[i]->pos().y() == (pos().y()))
						setPos(x() - Step, y());
				}
			}
			QBrush brush_R(QImage(":/photos/R"));
			setBrush(brush_R);
			setPos(x() + Step, y());
			QSound::play(":/sound/Move");
		}
		else if (event->key() == Qt::Key_Up)
		{
			QList<QGraphicsItem* >colliding_item1 = collidingItems();
			for (int i = 0, n = colliding_item1.size(); i < n; i++)
			{
				if (typeid(*(colliding_item1[i])) == typeid(Box))
				{
					QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
					for (int j = 0, m = colliding_item2.size(); j < m; j++)
					{
						if (typeid(*(colliding_item2[j])) == typeid(Block))
						{
							if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()
								&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y() + Size
								&& colliding_item1[i]->pos().x() == (pos().x())
								&& colliding_item1[i]->pos().y() + Size == (pos().y()))
								setPos(x(), y() + Step);
						}
						else
						{
							if (colliding_item1[i]->pos().x() == (pos().x())//人从箱子下面推
								&& colliding_item1[i]->pos().y() + Size == (pos().y()))
							{
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() - Step);
								arrival(dynamic_cast<Box*>(colliding_item1[i]));
							}
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().y() + Size == (pos().y())//人从障碍物下面推
						&& colliding_item1[i]->pos().x() == (pos().x()))
						setPos(x(), y() + Step);
				}
			}
			QBrush brush_U(QImage(":/photos/U"));
			setBrush(brush_U);
			setPos(x(), y() - Step);
			QSound::play(":/sound/Move");
		}
		else if (event->key() == Qt::Key_Down)
		{
			QList<QGraphicsItem* >colliding_item1 = collidingItems();
			for (int i = 0, n = colliding_item1.size(); i < n; i++)
			{
				if (typeid(*(colliding_item1[i])) == typeid(Box))
				{
					QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();
					for (int j = 0, m = colliding_item2.size(); j < m; j++)
					{
						if (typeid(*(colliding_item2[j])) == typeid(Block))
						{
							if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x()
								&& colliding_item1[i]->pos().y() + Size == colliding_item2[j]->pos().y()
								&& colliding_item1[i]->pos().x() == (pos().x())
								&& colliding_item1[i]->pos().y() == (pos().y() + Size))
								setPos(x(), y() - Step);
						}
						else
						{
							if (colliding_item1[i]->pos().x() == (pos().x())//人从箱子上面推
								&& colliding_item1[i]->pos().y() == (pos().y() + Size))
							{
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() + Step);
								arrival(dynamic_cast<Box*>(colliding_item1[i]));
							}
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().y() == (pos().y() + Size)//人从障碍物上面推
						&& colliding_item1[i]->pos().x() == (pos().x()))
						setPos(x(), y() - Step);
				}
			}
			QBrush brush_D(QImage(":/photos/D"));
			setBrush(brush_D);
			setPos(x(), y() + Step);
			QSound::play(":/sound/Move");
		}
	}
}




Player::~Player() {

}