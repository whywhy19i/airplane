#pragma once

#include <time.h>
#include <conio.h>
#include <vector>
#include<graphics.h>
#include<string>
using namespace std;

//data.h负责人：阿良
//void Boss::attack() 负责人：薇

//存储对应的关卡数
__declspec(selectany)  int level;

//对应关卡中敌机的血量，速度和攻击力以及总数目
__declspec(selectany)  int level_hp;
__declspec(selectany)  int  level_ag;
__declspec(selectany)  int level_distance;
__declspec(selectany)  int num;

//存储当前排行榜中的分数
//mark[i][j]-第i关，第j名的分数
//__declspec(selectany)  int mark[3][10];

//存储本局的分数
__declspec(selectany)  int score;

//玩家的姓名
__declspec(selectany) string name;

//表示音乐的播放状态
//0不播放 1播放第一首音乐 2播放第二首音乐
__declspec(selectany)  int music_sign;

//碰撞箱的半径
__declspec(selectany)  int collisionRadius = 40;

//将图片背景透明的函数
void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg);

class information {
public:
	int playerPoint;
	string playerName;
};
__declspec(selectany)  vector<information> markList;

class Button {
public:
	Button(int x, int y) :x(x), y(y) {};
	int x;//左上角的x坐标
	int y;//右上角的x坐标

	virtual bool isIn(int point_x, int point_y) = 0;	// 判断点是否在按钮范围内
	virtual void draw() = 0;										// 绘制按钮
};

//在Button功能的基础上额外增加上在按钮上显示文字的功能
class TextButton :public Button {
public:
	TextButton(int x, int y, LPCTSTR str, COLORREF background_color = RGB(255, 205, 150)) :Button(x, y), str(str), background_color(background_color) {};
	static const int left = 5;
	static const int top = 5;
	static const int roundRadius = 5;
	LPCTSTR str;
	COLORREF background_color;//背景颜色
	bool isIn(int point_x, int point_y) override;
	void draw() override;
};

//在Button功能的基础上额外实现将按钮加载为图片的功能
class PictureButton :public Button {
public:
	PictureButton(int x, int y, IMAGE* image) :Button(x, y), img(image) {};
	IMAGE* img;
	bool isIn(int point_x, int point_y) override;
	void draw() override;
};

class Plane {
public:
	Plane(int x, int y, int hp, int ag, int d, int size = collisionRadius) :x(x), y(y), hp(hp), ag(ag), distance(d), size(size) {
		attack_sign = 0;
	};
	int hp;//生命值
	int x;//中心点位置
	int y;//中心点位置
	int size;//碰撞半径
	int distance;
	int ag;//攻击力
	int attack_sign;//控制子弹发射频率
	virtual void attack() = 0;//发射子弹——注意将攻击力赋给子弹，同时将子弹插入子弹数组
	virtual void draw() = 0;//加载图片并显示
	//在中心位置绘制一个高亮的小圆
	//先不做飞机受击的效果
};



//在Plane的基础上改进Move-如果移动之后超出边界，则飞机原地不动
//玩家飞机
class MyPlane :public Plane {
public:
	MyPlane(int x, int y, int hp = 100, int ag = 3, int d = 10, int size = collisionRadius) :Plane(x, y, hp, ag, d) {
		length = 70;
		width = 70;
		loadimage(&imgMyPlane, L"pic/hero1.png", length, width);
	};
	int length;
	int width;
	IMAGE imgMyPlane;
	void attack() override;
	void draw() override;
};

//在Plane的基础上改进Move-一直前进，随机左右移动,如果碰到左右边界，则反向移动
//增加isOut函数
//注意敌机的size要大一些
class EnermyPlane :public Plane {
public:
	EnermyPlane(int x, int y, int hp = level_hp, int ag = level_ag, int d = level_distance, int size = collisionRadius) :Plane(x, y, hp, ag, d) {
		length = 50;
		width = 50;
		flag = rand() % 3;
		loadimage(&imgEnemyPlane, L"pic/enemy1.png", length, width);
	};
	int length;
	int width;
	int flag;
	IMAGE imgEnemyPlane;
	void attack() override;
	void draw() override;
};


//在EnermyPlane的基础上实现发射弹幕
//注意Boss只能横向移动
//Boss的碰撞箱大一点
class Boss :public EnermyPlane {
public:
	Boss(int x, int y, int hp = 200, int ag = 5, int d = 5, int size = 3 * collisionRadius) :EnermyPlane(x, y, hp, ag, d, size) {
		appear_sign = 0;
		length = 50;
		width = 50;
		loadimage(&imgBoss, L"pic/enemy3_n1.png", length, width);
	};
	//标志Boss是否出现
	//0-未出现，1-出现
	void attack();
	void draw();
	int length;
	int width;
	IMAGE imgBoss;
	int appear_sign;
};


class Bullet {
public:
	Bullet(int x, int y, int ag = level_ag, int d = 8, int size = 15) :x(x), y(y), ag(ag), distance(d), size(size) {
		length = 6;
		width = 16;
		loadimage(&imgBullet, L"pic/bullet1.png", length, width);
	};
	int x;//中心点位置
	int y;//中心点位置
	int ag;//伤害
	int distance;//单次移动的位移
	int size;//碰撞半径
	int length;
	int width;
	IMAGE imgBullet;
	void draw();//加载图片并显示
};


//存储场上现存的所有敌机
__declspec(selectany)  vector<EnermyPlane> enermies;

//存储玩家发射出的所有子弹
__declspec(selectany)  vector<Bullet> myBullets;

//存储敌机发射出的所有子弹
__declspec(selectany)  vector<Bullet> enermyBullets;

//创建Boss对象
__declspec(selectany)  Boss boss(0, 0);

//创建玩家飞机对象
__declspec(selectany)  MyPlane plane(0, 0);