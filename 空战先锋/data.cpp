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
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 30;						// 设置字体高度为 30
	_tcscpy_s(f.lfFaceName, _T("楷体"));		// 设置字体为“楷体”
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式

	setlinestyle(PS_SOLID, 1);//直线，宽度为1
	setfillcolor(background_color);         // 填充颜色设置
	//画有边框的填充圆角矩形(左部x,顶部y,右部x,底部y,椭圆的宽度，椭圆的高度)
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