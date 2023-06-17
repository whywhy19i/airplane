#include "data.h"
#include <graphics.h>	
#include <conio.h>
#pragma comment( lib, "MSIMG32.LIB")

void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}

bool TextButton::isIn(int point_x, int point_y) {
	if (point_x >= x && point_x <= x + textwidth(str) + 2 * left && point_y >= y && point_y <= y + textheight(str) + 2 * top)
		return true;
	else
		return false;
}

void TextButton::draw() {
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 30;						// ��������߶�Ϊ 30
	_tcscpy_s(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ

	setlinestyle(PS_SOLID, 1);//ֱ�ߣ����Ϊ1
	setfillcolor(background_color);         // �����ɫ����
	//���б߿�����Բ�Ǿ���(��x,����y,�Ҳ�x,�ײ�y,��Բ�Ŀ�ȣ���Բ�ĸ߶�)
	fillroundrect(x, y, x + textwidth(str) + 2 * left, y + textheight(str) + 2 * top, roundRadius, roundRadius);
	outtextxy(x + left, y + top, str);
}

bool PictureButton::isIn(int point_x, int point_y) {
	int height = img->getheight();
	int width = img->getwidth();
	if (point_x >= x && point_x <= x + width && point_y >= y && point_y <= y + height)
		return true;
	else
		return false;
}

void PictureButton::draw() {
	transparentimage3(NULL, x, y, img);
}

void MyPlane::attack() {
	Bullet b(x, y-width, ag);
	myBullets.push_back(b);
}

void MyPlane::draw() {
	transparentimage3(NULL, x - length / 2, y - width / 2, &imgMyPlane);
}


void EnermyPlane::attack() {
	Bullet b(x, y+width, ag);
	enermyBullets.push_back(b);
}

void EnermyPlane::draw() {
	transparentimage3(NULL, x - length / 2, y - width / 2, &imgEnemyPlane);
}

void Boss::attack() {
	/*Bullet zidan[20];
	for (auto& z : zidan)
	{
		z.ag = level_ag;
		z.y = boss.y + boss.size;

	}
	int dis = 2 * boss.size / 20;
	for (int i = 0; i < 10; i++)
	{
		zidan[i].x = boss.x + dis * i;
	}
	for (int i = 0; i < 10; i++)
	{
		zidan[19 - i].x = boss.x - dis * (i + 1);
	}
	for (auto g : zidan)
	{
		enermyBullets.push_back(g);
	}
	for (auto z : enermyBullets)
	{
		z.draw();
	}*/
}

void Boss::draw() {
	transparentimage3(NULL, x - length / 2, y - width / 2, &imgBoss);
}

void Bullet::draw() {
	transparentimage3(NULL, x - length / 2, y - width / 2, &imgBullet);
}