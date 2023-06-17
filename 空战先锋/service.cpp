#include "service.h"
#include<iostream>
using namespace std;

void init() {
	if (level == 1) {
		level_hp = 5;
		level_ag = 1;
		level_distance = 3;
	}
	else if (level == 2) {
		level_hp = 7;
		level_ag = 2;
		level_distance = 5;
	}
	else if (level == 3) {
		level_hp = 9;
		level_ag = 2;
		level_distance = 7;
	}
	// ��մ洢�л����ӵ���vector
	enermies.clear();
	myBullets.clear();
	enermyBullets.clear();
	score = 0;
	plane.x = 350;
	plane.y = 400;
	num = 100;
}

void enermyRenew()
{
	int w=getwidth(), h=getheight();
	auto it = enermies.begin();
	for (; it != enermies.end();)
	{
		if (it->y>getheight())
		{
			it=enermies.erase(it);
		}
		else
		{
			it++;
		}
	}
	if (num > 1)
	{
		EnermyPlane p1(rand()%w,0);
		enermies.push_back(p1);
		num--;
	}
}

void moveMyBullet()                    //�ҷ��ӵ��ƶ�
{
	for (auto it = myBullets.begin(); it != myBullets.end();)
	{
		if ((*it).y <0)               //�ӵ��ɳ��������߳�����
			it=myBullets.erase(it);
		else
		{
			(*it).y -= (*it).distance;
			it++;
		}

	}
}

void moveenermyBullets()            //�з��ӵ��ƶ�
{
	for (auto it = enermyBullets.begin(); it != enermyBullets.end();)
	{
		if ((*it).y > getheight())          //�ӵ��ɳ��������߳�����
			it=enermyBullets.erase(it);
		else
		{
			(*it).y += (*it).distance;
			it++;
		}

	}
}

void moveEnermyPlaneDown()                //�л��ɻ���ֱ�����ƶ�
{
	for (auto it = enermies.begin(); it != enermies.end(); )
	{
		if ((*it).y > getheight())        //�ɻ��ɳ��������߳�����
			it=enermies.erase(it);
		else
		{
			(*it).y += (*it).distance;
			if (it->attack_sign == 25) {
				it->attack();
				it->attack_sign = 0;
			}
			it->attack_sign++;
			it++;
		}

	}
}

void moveEnermyPlaneLR()          //�л��ɻ������ƶ�
{
	for (auto it = enermies.begin(); it != enermies.end(); it++)
	{
		int distance = 5;					//ÿ�������ƶ��ľ������ʵ��Ч������
		if (it->flag == 1)//����
		{              
			if ((*it).x + it->width < getwidth())        //��ֹ�ɻ����ҳ���
				(*it).x += distance;
			else
			{
				it->flag = 2;
				(*it).x -= distance;
			}
		}
		else if (it->flag == 2) {//����
			if ((*it).x - it->width > 0)        //��ֹ�ɻ����ҳ���
				(*it).x -= distance;
			else
			{
				it->flag = 1;
				(*it).x += distance;
			}
		}
	}

}

void Myplane_move()         //�ҷ��ɻ�ͨ���������ҷ�����ƶ�
{
	if (plane.attack_sign == 3) {
		plane.attack();
		plane.attack_sign = 0;
	}
	plane.attack_sign++;
	//��ȡ���̵İ���������               
	if (GetAsyncKeyState(VK_UP) && plane.y - plane.width / 2 > 0)
	{
		plane.y -= plane.distance;
	}
	if (GetAsyncKeyState(VK_DOWN) && plane.y + plane.width/ 2 < getheight())
	{
		plane.y += plane.distance;
	}
	if (GetAsyncKeyState(VK_LEFT) && plane.x > 0)
	{
		plane.x -= plane.distance;
	}
	if (GetAsyncKeyState(VK_RIGHT) && plane.x < getwidth())
	{
		plane.x += plane.distance;
	}
}

void move() {
	moveMyBullet();
	moveenermyBullets();
	moveEnermyPlaneDown();
	moveEnermyPlaneLR();
	Myplane_move();
}

void collisionDetection()
{
	//���з��ӵ����ҷ��ɻ���ײ
	for (auto it = enermyBullets.begin();it < enermyBullets.end();) {
		if (sqrt(pow((it->x - plane.x), 2) + pow(it->y - plane.y, 2)) <= (it->size + plane.size) / 2) {
			plane.hp -= it->ag;
			score -= 10;
			if (plane.hp <= 0) failView();
			it=enermyBullets.erase(it);
		}
		else it++;
	}

	//����ҷ��ɻ��͵з��ɻ���ײ
	for (auto it = enermies.begin();it < enermies.end();) {
		if (sqrt(pow((it->x - plane.x), 2) + pow(it->y - plane.y, 2)) <= (it->size + plane.size) / 2) {
			plane.hp -= it->ag;
			score += 10;
			if (plane.hp <= 0) failView();
			it = enermies.erase(it);
		}
		else it++;
	}
	//���з��ɻ����ҷ��ӵ���ײ
	if (myBullets.size() == 0)	return;
	for (auto it = myBullets.begin();it < myBullets.end();) {
		if (enermies.size() == 0)		return;
		for (auto it2 = enermies.begin();it2 < enermies.end();) {
			if (sqrt(pow(((it->x) - (it2->x)), 2) + pow((it->y) - (it2->y), 2)) <= ((it->size) + (it2->size)) / 2) {
				(it2->hp) -= it->ag;
				it = myBullets.erase(it);
				it2 = enermies.erase(it2);
				/*if (it2->hp <= 0) {
					it2 = enermies.erase(it2);
					score += 10;
				}
				else it2++;*/
			}
			else {
				it2++;
				it++;
			}
		}
	}
	
	
	if (boss.appear_sign == 1) {
		// ���boss�ӵ����ҷ��ɻ���ײ
		for (auto it = enermyBullets.begin();it < enermyBullets.end();) {
			if (sqrt(pow((it->x - plane.x), 2) + pow(it->y - plane.y, 2)) <= (it->size + plane.size) / 2) {
				plane.hp -= it->ag;
				score -= 10;
				if (plane.hp <= 0) failView();
				it = enermyBullets.erase(it, it + 1);
			}
			else it++;
		}
		//���boss���ҷ��ɻ���ײ
		if (sqrt(pow((boss.x - plane.x), 2) + pow(boss.y - plane.y, 2)) <= (boss.size + plane.size) / 2) {
			failView();
		}
	}
}

void bossAccure() {
	if (num == 0 && enermies.empty())
	{
		if (!boss.appear_sign) {
			if (level == 1) {
				boss.appear_sign = 1;
				boss.hp = 50;
				boss.size = 150;
				boss.ag = 1;
				boss.x = 426;
				boss.y = 100;
			}
			else if (level == 2) {
				boss.appear_sign = 1;
				boss.hp = 100;
				boss.size = 150;
				boss.ag = 2;
				boss.x = 426;
				boss.y = 100;
			}
			else if (level == 3) {
				boss.appear_sign = 1;
				boss.hp = 200;
				boss.size = 150;
				boss.ag = 3;
				boss.x = 426;
				boss.y = 100;
			}
			boss.draw();
		}
	}

}