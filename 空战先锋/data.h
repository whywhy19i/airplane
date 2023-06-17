#pragma once

#include <time.h>
#include <conio.h>
#include <vector>
#include<graphics.h>
#include<string>
using namespace std;

//data.h�����ˣ�����
//void Boss::attack() �����ˣ�ޱ

//�洢��Ӧ�Ĺؿ���
__declspec(selectany)  int level;

//��Ӧ�ؿ��ел���Ѫ�����ٶȺ͹������Լ�����Ŀ
__declspec(selectany)  int level_hp;
__declspec(selectany)  int  level_ag;
__declspec(selectany)  int level_distance;
__declspec(selectany)  int num;

//�洢��ǰ���а��еķ���
//mark[i][j]-��i�أ���j���ķ���
//__declspec(selectany)  int mark[3][10];

//�洢���ֵķ���
__declspec(selectany)  int score;

//��ҵ�����
__declspec(selectany) string name;

//��ʾ���ֵĲ���״̬
//0������ 1���ŵ�һ������ 2���ŵڶ�������
__declspec(selectany)  int music_sign;

//��ײ��İ뾶
__declspec(selectany)  int collisionRadius = 40;

//��ͼƬ����͸���ĺ���
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
	int x;//���Ͻǵ�x����
	int y;//���Ͻǵ�x����

	virtual bool isIn(int point_x, int point_y) = 0;	// �жϵ��Ƿ��ڰ�ť��Χ��
	virtual void draw() = 0;										// ���ư�ť
};

//��Button���ܵĻ����϶����������ڰ�ť����ʾ���ֵĹ���
class TextButton :public Button {
public:
	TextButton(int x, int y, LPCTSTR str, COLORREF background_color = RGB(255, 205, 150)) :Button(x, y), str(str), background_color(background_color) {};
	static const int left = 5;
	static const int top = 5;
	static const int roundRadius = 5;
	LPCTSTR str;
	COLORREF background_color;//������ɫ
	bool isIn(int point_x, int point_y) override;
	void draw() override;
};

//��Button���ܵĻ����϶���ʵ�ֽ���ť����ΪͼƬ�Ĺ���
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
	int hp;//����ֵ
	int x;//���ĵ�λ��
	int y;//���ĵ�λ��
	int size;//��ײ�뾶
	int distance;
	int ag;//������
	int attack_sign;//�����ӵ�����Ƶ��
	virtual void attack() = 0;//�����ӵ�����ע�⽫�����������ӵ���ͬʱ���ӵ������ӵ�����
	virtual void draw() = 0;//����ͼƬ����ʾ
	//������λ�û���һ��������СԲ
	//�Ȳ����ɻ��ܻ���Ч��
};



//��Plane�Ļ����ϸĽ�Move-����ƶ�֮�󳬳��߽磬��ɻ�ԭ�ز���
//��ҷɻ�
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

//��Plane�Ļ����ϸĽ�Move-һֱǰ������������ƶ�,����������ұ߽磬�����ƶ�
//����isOut����
//ע��л���sizeҪ��һЩ
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


//��EnermyPlane�Ļ�����ʵ�ַ��䵯Ļ
//ע��Bossֻ�ܺ����ƶ�
//Boss����ײ���һ��
class Boss :public EnermyPlane {
public:
	Boss(int x, int y, int hp = 200, int ag = 5, int d = 5, int size = 3 * collisionRadius) :EnermyPlane(x, y, hp, ag, d, size) {
		appear_sign = 0;
		length = 50;
		width = 50;
		loadimage(&imgBoss, L"pic/enemy3_n1.png", length, width);
	};
	//��־Boss�Ƿ����
	//0-δ���֣�1-����
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
	int x;//���ĵ�λ��
	int y;//���ĵ�λ��
	int ag;//�˺�
	int distance;//�����ƶ���λ��
	int size;//��ײ�뾶
	int length;
	int width;
	IMAGE imgBullet;
	void draw();//����ͼƬ����ʾ
};


//�洢�����ִ�����ел�
__declspec(selectany)  vector<EnermyPlane> enermies;

//�洢��ҷ�����������ӵ�
__declspec(selectany)  vector<Bullet> myBullets;

//�洢�л�������������ӵ�
__declspec(selectany)  vector<Bullet> enermyBullets;

//����Boss����
__declspec(selectany)  Boss boss(0, 0);

//������ҷɻ�����
__declspec(selectany)  MyPlane plane(0, 0);