#include "Player.h"
#include <QKeyEvent>
#include <QList>
#include "Block.h"
#include "Box.h"
#include <QGraphicsScene>
#include <QBrush>

#define step 75
#define Size 75

Player::Player(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
	setPixmap(QPixmap(":/photos/D"));
}

void Player::keyPressEvent(QKeyEvent* event)
{
	{
		if (event->key() == Qt::Key_Left)//�����°���ʱ
		{
			QList<QGraphicsItem* >colliding_item1 = collidingItems();//�������ҵ���ײ
			for (int i = 0, n = colliding_item1.size(); i < n; i++)
			{
				if (typeid(*(colliding_item1[i])) == typeid(Box))//�����������ӷ�������ײ
				{
					QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();//�ڼ������������������ӵ���ײ
					for (int j = 0, m = colliding_item2.size(); j < m; j++)
					{
						if (typeid(*(colliding_item2[j])) == typeid(Block))//����������ϰ������нӴ�
						{/*������ϰ����赲���ӵ��ƶ������ǲ��ܼ���ǰ����,
						 �������� �ϰ���-����-�ˣ�ʩ��������������*/
							if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x() + Size
								&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
								&& colliding_item1[i]->pos().x() + Size == (pos().x())
								&& colliding_item1[i]->pos().y() == (pos().y()))
								setPos(x() + step, y());
						}
						else
						{
							if (colliding_item1[i]->pos().x() + Size == (pos().x())
								&& colliding_item1[i]->pos().y() == (pos().y()))//�˴������Ҳ���
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x() - step, colliding_item1[i]->pos().y());
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().x() + Size == (pos().x())//�˴��ϰ����Ҳ���
						&& colliding_item1[i]->pos().y() == (pos().y()))
						setPos(x() + step, y());
				}
			}
			setPos(x() - step, y());
			setPixmap(QPixmap(":/photos/L"));
		}//������������ͬ��
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
								setPos(x() - step, y());
						}
						else 
						{
							if (colliding_item1[i]->pos().x() == (pos().x() + Size)//�˴����������
								&& colliding_item1[i]->pos().y() == (pos().y()))
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x() + step, colliding_item1[i]->pos().y());
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().x() == (pos().x() + Size)//�˴��ϰ��������
						&& colliding_item1[i]->pos().y() == (pos().y()))
						setPos(x() - step, y());
				}
			}
			setPos(x() + step, y());
			setPixmap(QPixmap(":/photos/R"));
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
								setPos(x(), y() + step);
						}
						else
						{
							if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
								&& colliding_item1[i]->pos().y() + Size == (pos().y()))
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() - step);
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().y() + Size == (pos().y())//�˴��ϰ���������
						&& colliding_item1[i]->pos().x() == (pos().x()))
						setPos(x(), y() + step);
				}
			}
			setPos(x(), y() - step);
			setPixmap(QPixmap(":/photos/U"));
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
								setPos(x(), y() - step);
						}
						else
						{
							if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
								&& colliding_item1[i]->pos().y() == (pos().y() + Size))
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x(), colliding_item1[i]->pos().y() + step);
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().y() == (pos().y() + Size)//�˴��ϰ���������
						&& colliding_item1[i]->pos().x() == (pos().x()))
						setPos(x(), y() - step);
				}
			}
			setPos(x(), y() + step);
			setPixmap(QPixmap(":/photos/D"));
		}
	}
}

Player::~Player() {

}