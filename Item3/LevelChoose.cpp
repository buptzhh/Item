#include "LevelChoose.h"
#include "qsound.h"


LevelChoose::LevelChoose(QGraphicsScene* scene){
	//initialize the scene
	scene_ = scene;
	scene->setSceneRect(0, 0, 975, 675);
	levelChoose();
}

void LevelChoose::levelChoose()
{
	//��ʾѡ�ؽ���
	setBackgroundBrush(QBrush(QImage(":/photos/Floor")));

	

	//��ʾ����ѡ��ؿ���ť
	button1 = new QPushButton("level1", this);
	button2 = new QPushButton("level2", this);
	button3 = new QPushButton("level3", this);
	button4 = new QPushButton("level4", this);

	button1->setGeometry(QRect(75,75,75,75));
	button2->setGeometry(QRect(150,75,75,75));
	button3->setGeometry(QRect(225,75,75,75));
	button4->setGeometry(QRect(300,75,75,75));

	//button1->setStyleSheet("QPushButton{border-image:url(Resources/Block.png);background:transparent;border-radius:5px;}");  ���ڼ�ͼƬ
	//button1->setStyleSheet("QPushButton{border-image:url(Resources/Block.png);background:transparent;border-radius:5px;}");
	//button1->setStyleSheet("QPushButton{border-image:url(Resources/Block.png);background:transparent;border-radius:5px;}");
	//button1->setStyleSheet("QPushButton{border-image:url(Resources/Block.png);background:transparent;border-radius:5px;}");

	QObject::connect(button1, SIGNAL(clicked()), this, SLOT(createmap1()));
	QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createmap2()));
	QObject::connect(button3, SIGNAL(clicked()), this, SLOT(createmap3()));
	QObject::connect(button4, SIGNAL(clicked()), this, SLOT(createmap4()));	

	//QGraphicsProxyWidget* proxy1 = scene_->addWidget(button1);
	//QGraphicsProxyWidget* proxy2 = scene_->addWidget(button2);
	//QGraphicsProxyWidget* proxy3 = scene_->addWidget(button3);
	//QGraphicsProxyWidget* proxy4 = scene_->addWidget(button4);


	QObject::connect(button1, SIGNAL(clicked()), this, SLOT(deleteButton()));
	QObject::connect(button2, SIGNAL(clicked()), this, SLOT(deleteButton()));
	QObject::connect(button3, SIGNAL(clicked()), this, SLOT(deleteButton()));
	QObject::connect(button4, SIGNAL(clicked()), this, SLOT(deleteButton()));

}

void LevelChoose::deleteButton() {
	delete button1;
	delete button2;
	delete button3;
	delete button4;
}


LevelChoose::~LevelChoose()
{
	delete scene_;
	
}
