#include "Choose_Level.h"
#include "qsound.h"


Choose_Level::Choose_Level(QGraphicsScene* scene){
	//initialize the scene
	scene_ = scene;
	scene->setSceneRect(0, 0, 975, 675);
	levelchoose();
}

void Choose_Level::levelchoose()
{
	

	//显示可以选择关卡按钮
	button1 = new QPushButton("levell", this);
	button1->setGeometry(QRect(75,75,75,75));
	QObject::connect(button1, SIGNAL(clicked()), this, SLOT(createmap1()));
	//QGraphicsProxyWidget* proxy1 = scene->addWidget(button1);

	button2 = new QPushButton("level2", this);
	button2->setGeometry(QRect(150,75,75,75));
	QObject::connect(button2, SIGNAL(clicked()), this, SLOT(createmap2()));
	//QGraphicsProxyWidget* proxy2 = scene->addWidget(button2);

	button3 = new QPushButton("level3", this);
	button3->setGeometry(QRect(225,75,75,75));
	QObject::connect(button3, SIGNAL(clicked()), this, SLOT(createmap3()));
	//QGraphicsProxyWidget* proxy3 = scene->addWidget(button3);

	button4 = new QPushButton("level4", this);
	button4->setGeometry(QRect(300,75,75,75));
	QObject::connect(button4, SIGNAL(clicked()), this, SLOT(createmap4()));
	//QGraphicsProxyWidget* proxy4 = scene->addWidget(button4);


}



Choose_Level::~Choose_Level()
{
	delete scene_;
	delete button1;
	delete button2;
	delete button3;
	delete button4;
}
