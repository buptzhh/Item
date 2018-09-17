#include "LevelChoose.h"
#include "qsound.h"

LevelChoose::LevelChoose() {

}

LevelChoose::LevelChoose(QGraphicsScene* scene, const int &level){ //调出界面方法：QGraphicsScene* scene = new QGraphicsScene();
	//initialize the scene											 //			  LevelChoose* c = new LevelChoose(scene,getlevel());
	scene_ = scene;													 //			  view->setScene(scene);
	scene->setSceneRect(0, 0, 975, 675);
	levelChoose(level);
}

void LevelChoose::levelChoose(const int &level)
{
	//显示选关界面
	setBackgroundBrush(QBrush(QImage("Resources/floor.jpg")));

	

	//显示可以选择关卡按钮
	button[1] = new QPushButton("level1");
	button[2] = new QPushButton("level2");
	button[3] = new QPushButton("level3");
	button[4] = new QPushButton("level4");

	button[1]->setGeometry(QRect(75, 75, 200, 75));
	button[2]->setGeometry(QRect(275, 75, 200, 75));
	button[3]->setGeometry(QRect(475, 75, 200, 75));
	button[4]->setGeometry(QRect(675, 75, 200, 75));

	scene_->addWidget(button[1]);
	scene_->addWidget(button[2]);
	scene_->addWidget(button[3]);
	scene_->addWidget(button[4]);

	//设置按钮字体
	QFont* font = new QFont;
	font->setFamily("Impact");
	font->setPointSize(20);

	for (int i = 1; i <= levelNumber; i++) {
		if (i <= level) {
			button[i]->setStyleSheet("QPushButton{border-image:url(Resources/ButtonNormal.png);background:transparent;}"
				"QPushButton:hover{border-image:url(Resources/ButtonHover.png);background:transparent;}"
				"QPushButton:pressed{border-image:url(Resources/ButtonPressed.png);background:transparent;");    //可选关卡的图
		}
		else {
			button[i]->setStyleSheet("QPushButton{border-image:url(Resources/ButtonPressed.png);background:transparent;border-radius:5px;}");  //不可选关卡的图
		}
		button[i]->setFont(*font);
	}
	
	switch (level) {
	case 4:QObject::connect(button[4], SIGNAL(clicked()), this, SLOT(createmap4())); 
	case 3:QObject::connect(button[3], SIGNAL(clicked()), this, SLOT(createmap3()));
	case 2:QObject::connect(button[2], SIGNAL(clicked()), this, SLOT(createmap2()));
	case 1:QObject::connect(button[1], SIGNAL(clicked()), this, SLOT(createmap1()));
	default:close();
	}

}




LevelChoose::~LevelChoose()
{
	delete scene_;
}
