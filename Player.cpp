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

void arrival(Box* box_) {                   //�ĺ������ڵ���Box�����isArrival����
	box_->isArrival();
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
					//scene()->removeItem(this);//ͼƬ������Ƿ�������ײ��

					QList<QGraphicsItem *>colliding_item2 = colliding_item1[i]->collidingItems();//�ڼ������������������ӵ���ײ
					for (int j = 0, m = colliding_item2.size(); j < m; j++)
					{
						if (typeid(*(colliding_item2[j])) == typeid(Block))//����������ϰ������нӴ�
						{/*������ϰ���
						 �赲���ӵ��ƶ������ǲ��ܼ���ǰ����,�������� �ϰ���-����-�ˣ�ʩ��������������*/
							if (colliding_item1[i]->pos().x() == colliding_item2[j]->pos().x() + Size
								&& colliding_item1[i]->pos().y() == colliding_item2[j]->pos().y()
								&& colliding_item1[i]->pos().x() + Size == (pos().x())
								&& colliding_item1[i]->pos().y() == (pos().y()))
								setPos(x() + Step, y());
						}
						else
						{
							if (colliding_item1[i]->pos().x() + Size == (pos().x())
								&& colliding_item1[i]->pos().y() == (pos().y()))//�˴������Ҳ���
							{
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x() - Step, colliding_item1[i]->pos().y());
								arrival(dynamic_cast<Box*>(colliding_item1[i]));
							}
						}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().x() + Size == (pos().x())//�˴��ϰ����Ҳ���
						&& colliding_item1[i]->pos().y() == (pos().y()))
						setPos(x() + Step, y());
				}
			}
			QBrush brush_L(QImage(":/photos/L"));//��ÿ���¼���ͬʱ��������ͼƬ��ͬ����setBrush����
			setBrush(brush_L);
			setPos(x() - Step, y());
			QSound::play(":/sound/Move");                     //�����������Ʒ�
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
								setPos(x() - Step, y());
						}
						else
							if (colliding_item1[i]->pos().x() == (pos().x() + Size)//�˴����������
								&& colliding_item1[i]->pos().y() == (pos().y()))
							{
								colliding_item1[i]->setPos(colliding_item1[i]->pos().x() + Step, colliding_item1[i]->pos().y());
								arrival(dynamic_cast<Box*>(colliding_item1[i]));
							}
					}
				}
				else if (typeid(*(colliding_item1[i])) == typeid(Block))
				{
					if (colliding_item1[i]->pos().x() == (pos().x() + Size)//�˴��ϰ��������
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
							if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
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
					if (colliding_item1[i]->pos().y() + Size == (pos().y())//�˴��ϰ���������
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
							if (colliding_item1[i]->pos().x() == (pos().x())//�˴�����������
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
					if (colliding_item1[i]->pos().y() == (pos().y() + Size)//�˴��ϰ���������
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