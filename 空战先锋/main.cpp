#include<iostream>
#include<graphics.h>


#include"data.h"
#include"view.h"
#include"service.h"
#include"dao.h"


using namespace std;


/*
	负责人:流星
	功能:创建界面
	参数: void
	返回值: void
*/
int main() {
	HWND wnd = initgraph(852, 480);		// 创建绘图窗口
	SetWindowText(wnd, L"空战先锋");		//设置窗口的标题
	setbkcolor(WHITE);								//设置绘图板背景为白色
	cleardevice();
	setbkmode(TRANSPARENT);				// 设置透明文字输出背景（默认文字背景用背景色填充）
	
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 24;						// 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("楷体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	settextcolor(BLACK);

	menuView();
	system("pause");
	return 0;
}