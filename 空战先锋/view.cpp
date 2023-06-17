#include "view.h"
#include "service.h"
#include "data.h"
#include "dao.h"
#include<graphics.h>


void menuView() {
	cleardevice();
	//显示游戏标题-空战先锋
	outtextxy(350, 25, L"空战先锋");

	//开始游戏按钮
	TextButton buttonLevelChoose(350, 100, L"开始游戏");
	buttonLevelChoose.draw();

	//排行榜按钮
	TextButton buttonTheCharts(350, 150, L"排行榜");
	buttonTheCharts.draw();

	//设置按钮
	TextButton buttonSet(350, 200, L"设置");
	buttonSet.draw();

	//游戏教程按钮
	TextButton buttonCourse(350, 250, L"游戏教程");
	buttonCourse.draw();

	//退出游戏按钮
	TextButton buttonExit(350, 300, L"退出游戏");
	buttonExit.draw();

	ExMessage m;
	while (true) {
		m = getmessage(EX_MOUSE);
		if (m.message == WM_LBUTTONDOWN) {
			if (buttonLevelChoose.isIn(m.x, m.y)) {
				levelChooseView();
				return;
			}
			else if (buttonTheCharts.isIn(m.x, m.y)) {
				theChartsView();
			}
			else if (buttonSet.isIn(m.x, m.y)) {
				setView();
			}
			else if (buttonCourse.isIn(m.x, m.y)) {
				courseView();
			}
			else if (buttonExit.isIn(m.x, m.y)) {
				exit(1);
			}
		}
	}
}

void levelChooseView() {
	cleardevice();
	//关卡1
	TextButton buttonLevel1(350, 100, L"关卡1");
	buttonLevel1.draw();

	//关卡2
	TextButton buttonLevel2(350, 150, L"关卡2");
	buttonLevel2.draw();

	//关卡3
	TextButton buttonLevel3(350, 200, L"关卡3");
	buttonLevel3.draw();

	//返回主菜单
	TextButton buttonMenu(310, 350, L"返回主菜单");
	buttonMenu.draw();

	ExMessage m;
	while (true) {
		m = getmessage(EX_MOUSE);
		if (m.message == WM_LBUTTONDOWN) {
			if (buttonLevel1.isIn(m.x, m.y)) {
				level = 1;
				gameView();
				return;
			}
			else if (buttonLevel2.isIn(m.x, m.y)) {
				level = 2;
				gameView();
				return;
			}
			else if (buttonLevel3.isIn(m.x, m.y)) {
				level = 3;
				gameView();
				return;
			}
			else if (buttonMenu.isIn(m.x, m.y)) {
				menuView();
				return;
			}
		}
	}
}

void theChartsView() {
	cleardevice();
	outtextxy(10, 10, L"第一关排行榜");
	outtextxy(260, 10, L"第二关排行榜");
	outtextxy(510, 10, L"第三关排行榜");
	TCHAR s[5];
	Get();
	//绘制排行榜内容
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 10;j++) {
			if (markList.at(i*10+j).playerPoint == 0) {
				continue;
			}
			_stprintf_s(s, _T("%d"), j);
			outtextxy(10 + 250 * i, 50 + 40 * j, s);
			_stprintf_s(s, _T("%d"), markList.at(i * 10 + j).playerPoint);
			outtextxy(70 + 250 * i, 50 + 40 * j, s);//间隔60
		}
	}

	//绘制返回主菜单按钮
	TextButton buttonMenu(350, 410, L"返回主菜单");
	buttonMenu.draw();

	ExMessage m;
	while (true) {
		m = getmessage(EX_MOUSE);
		if (m.message == WM_LBUTTONDOWN) {
			if (buttonMenu.isIn(m.x, m.y)) {
				menuView();
				return;
			}
		}
	}
}

//设置界面
void setView() {
	cleardevice();
	//设置标志位sign_now,sign_before用来检测标志位是否改变
	//0-音乐关闭,1播放第一首音乐，2播放第二首音乐
	int sign_before = 1, sign_now = 1;

	IMAGE imgSwitchOpen, imgSwitchClose, imgChoose, imgNoChoose, imgBackground;
	loadimage(&imgSwitchOpen, L"pic/setOpen.png", 40, 30);
	loadimage(&imgSwitchClose, L"pic/setClose.png", 40, 30);
	loadimage(&imgChoose, L"pic/setChoose.png", 20, 20);
	loadimage(&imgNoChoose, L"pic/setNoChoose.png", 20, 20);
	//图形按钮
	PictureButton buttonSwitchOpen(480, 70, &imgSwitchOpen);
	PictureButton buttonSwitchClose(480, 70, &imgSwitchClose);
	PictureButton buttonChoose1(375, 125, &imgChoose);
	PictureButton buttonNoChoose1(375, 125, &imgNoChoose);
	PictureButton buttonChoose2(525, 125, &imgChoose);
	PictureButton buttonNoChoose2(525, 125, &imgNoChoose);
	//文字按钮
	TextButton buttonMenu(350, 400, L"返回菜单");

	cleardevice();
	putimage(0, 0, &imgBackground);
	outtextxy(350, 20, L"设置界面");
	outtextxy(350, 70, L"音乐开关");
	outtextxy(300, 120, L"音乐1");
	outtextxy(450, 120, L"音乐2");
	buttonSwitchOpen.draw();
	buttonChoose1.draw();
	buttonNoChoose2.draw();
	buttonMenu.draw();
	ExMessage m;
	while (true) {
		m = getmessage(EX_MOUSE);
		if (sign_now == 0) {
			if (sign_before != sign_now) {
				BeginBatchDraw();
				cleardevice();
				putimage(0, 0, &imgBackground);
				outtextxy(350, 20, L"设置界面");
				outtextxy(350, 70, L"音乐开关");
				buttonSwitchClose.draw();
				buttonMenu.draw();
				EndBatchDraw();
				sign_before = sign_now;
			}
			if (m.message == WM_LBUTTONDOWN) {
				if (buttonSwitchClose.isIn(m.x, m.y)) {
					sign_now = 1;
				}
				else if (buttonMenu.isIn(m.x, m.y)) {
					menuView();
					return;
				}
			}
		}
		else if (sign_now == 1) {
			if (sign_before != sign_now) {
				BeginBatchDraw();
				cleardevice();
				putimage(0, 0, &imgBackground);
				outtextxy(350, 20, L"设置界面");
				outtextxy(350, 70, L"音乐开关");
				outtextxy(300, 120, L"音乐1");
				outtextxy(450, 120, L"音乐2");
				buttonSwitchOpen.draw();
				buttonChoose1.draw();
				buttonNoChoose2.draw();
				buttonMenu.draw();
				EndBatchDraw();
				sign_before = sign_now;
			}
			if (m.message == WM_LBUTTONDOWN) {
				if (buttonSwitchClose.isIn(m.x, m.y)) {
					sign_now = 0;
				}
				else if (buttonMenu.isIn(m.x, m.y)) {
					menuView();
					return;
				}
				else if (buttonNoChoose2.isIn(m.x, m.y)) {
					sign_now = 2;
				}
			}
		}
		else if (sign_now == 2) {
			if (sign_before != sign_now) {
				BeginBatchDraw();
				cleardevice();
				putimage(0, 0, &imgBackground);
				outtextxy(350, 20, L"设置界面");
				outtextxy(350, 70, L"音乐开关");
				outtextxy(300, 120, L"音乐1");
				outtextxy(450, 120, L"音乐2");
				buttonSwitchOpen.draw();
				buttonChoose2.draw();
				buttonNoChoose1.draw();
				buttonMenu.draw();
				EndBatchDraw();
				sign_before = sign_now;
			}
			if (m.message == WM_LBUTTONDOWN) {
				if (buttonSwitchClose.isIn(m.x, m.y)) {
					sign_now = 0;
				}
				else if (buttonMenu.isIn(m.x, m.y)) {
					menuView();
					return;
				}
				else if (buttonNoChoose1.isIn(m.x, m.y)) {
					sign_now = 1;
				}
			}
		}


	}

}

//教程界面
void courseView() {
	cleardevice();
	//将教程的图片贴上来
	IMAGE img;
	loadimage(&img, L"pic/hero1.png", 652, 360);
	putimage(100, 50, &img);

	//回到主菜单按钮
	TextButton buttonMenu(350, 420, L"返回主菜单");
	buttonMenu.draw();

	ExMessage m;
	while (true) {
		m = getmessage(EX_MOUSE);
		if (m.message == WM_LBUTTONDOWN) {
			if (buttonMenu.isIn(m.x, m.y)) {
				menuView();
				return;
			}
		}
	}
}

void stopView() {
	cleardevice();
	//返回游戏按钮
	TextButton buttonBack(350, 100, L"返回游戏");
	buttonBack.draw();

	//返回主菜单按钮
	TextButton buttonMenu(350, 150, L"返回主菜单");
	buttonMenu.draw();

	//重新开始按钮
	TextButton buttonRestart(350, 200, L"重新开始");
	buttonRestart.draw();

	//设置按钮
	TextButton buttonSet(350, 250, L"设置");
	buttonSet.draw();

	//退出游戏按钮
	TextButton buttonExit(350, 300, L"退出游戏");
	buttonExit.draw();


	ExMessage m;
	while (true) {
		m = getmessage(EX_MOUSE);
		if (m.message == WM_LBUTTONDOWN) {
			if (buttonBack.isIn(m.x, m.y)) {
				return;
			}
			if (buttonMenu.isIn(m.x, m.y)) {
				menuView();
				return;
			}
			if (buttonRestart.isIn(m.x, m.y)) {
				gameView();
				return;
			}
			if (buttonSet.isIn(m.x, m.y)) {
				setView();
				return;
			}
			if (buttonExit.isIn(m.x, m.y)) {
				exit(1);
			}
		}
	}
}

void printGameView() {
	cleardevice();
	BeginBatchDraw();

	IMAGE imgStop;
	loadimage(&imgStop, L"pic/stop.png", 30, 30);
	PictureButton buttonStop(800, 0, &imgStop);
	buttonStop.draw();

	IMAGE imgBackground;
	loadimage(NULL, L"pic/background.png");

	//游戏内容打印
	for (auto i = enermies.begin();i < enermies.end();i++) {
		i->draw();
	}
	for (auto i = myBullets.begin();i < myBullets.end();i++) {
		i->draw();
	}
	for (auto i = enermyBullets.begin();i < enermyBullets.end();i++) {
		i->draw();
	}
	plane.draw();
	if (boss.appear_sign == 1) {
		boss.draw();
	}

	//文字信息打印
	LOGFONT g;
	gettextstyle(&g);						// 获取当前字体设置
	g.lfHeight = 16;						// 设置字体高度为 16
	settextstyle(&g);
	outtextxy(10, 10, L"生命值：");
	TCHAR s[5];
	_stprintf_s(s, _T("%d"), plane.hp);		// 打印血量
	outtextxy(70, 10, s);
	outtextxy(10, 30, L"分数：");
	_stprintf_s(s, _T("%d"), score);		// 打印分数
	outtextxy(70, 30, s);
	EndBatchDraw();
	g.lfHeight = 32;
	settextstyle(&g);
}

void gameView() {
	init();
	IMAGE imgStop;
	loadimage(&imgStop, L"pic/stop.png", 30, 30);
	PictureButton buttonStop(800, 0, &imgStop);

	cleardevice();
	ExMessage m;
	int i = 0;
	while (true) {
		if (i == 50) {
			enermyRenew();
			i = 0;
		}
		else i++;
		while (peekmessage(&m, EX_MOUSE | EX_KEY)) {
			if (m.message == WM_LBUTTONDOWN) {
				if (buttonStop.isIn(m.x, m.y)) {
					stopView();
				}
			}
		 }
		move();
		printGameView();
		collisionDetection();
		//if (plane.hp <= 0)	failView();
		//if (boss.hp <= 0)		victoryView();
		bossAccure();
		Sleep(20);
	}

}

void victoryView() {
	cleardevice();
	//打印分数，恭喜取得胜利
	LOGFONT g;
	gettextstyle(&g);
	g.lfHeight = 24;
	settextstyle(&g);

	outtextxy(300, 10, L"恭喜取得胜利！");
	outtextxy(300, 40, L"您的分数是：");
	TCHAR s[5];
	_stprintf_s(s, _T("%d"), score);
	outtextxy(450, 40, s);

	g.lfHeight = 32;
	settextstyle(&g);

	//选择关卡按钮
	TextButton buttonChoose(350, 100, L"选择关卡");
	buttonChoose.draw();

	//返回主菜单按钮
	TextButton buttonMenu(350, 150, L"返回主菜单");
	buttonMenu.draw();

	//重新开始按钮
	TextButton buttonRestart(350, 200, L"重新开始");
	buttonRestart.draw();

	//设置按钮
	TextButton buttonSet(350, 250, L"设置");
	buttonSet.draw();

	//退出游戏按钮
	TextButton buttonExit(350, 300, L"退出游戏");
	buttonExit.draw();


	ExMessage m;
	while (true) {
		m = getmessage(EX_MOUSE);
		if (m.message == WM_LBUTTONDOWN) {
			if (buttonChoose.isIn(m.x, m.y)) {
				levelChooseView();
				return;
			}
			if (buttonMenu.isIn(m.x, m.y)) {
				menuView();
				return;
			}
			if (buttonRestart.isIn(m.x, m.y)) {
				gameView();
				return;
			}
			if (buttonSet.isIn(m.x, m.y)) {
				setView();
				return;
			}
			if (buttonExit.isIn(m.x, m.y)) {
				exit(1);
			}
		}
	}
}

void failView() {
	cleardevice();
	//打印分数，很遗憾失败了
	LOGFONT g;
	gettextstyle(&g);
	g.lfHeight = 24;
	settextstyle(&g);

	outtextxy(300, 10, L"很遗憾失败了！");
	outtextxy(300, 40, L"您的分数是：");
	TCHAR s[5];
	_stprintf_s(s, _T("%d"), score);
	outtextxy(450, 40, s);

	g.lfHeight = 32;
	settextstyle(&g);

	//选择关卡按钮
	TextButton buttonChoose(350, 100, L"选择关卡");
	buttonChoose.draw();

	//返回主菜单按钮
	TextButton buttonMenu(350, 150, L"返回主菜单");
	buttonMenu.draw();

	//重新开始按钮
	TextButton buttonRestart(350, 200, L"重新开始");
	buttonRestart.draw();

	//设置按钮
	TextButton buttonSet(350, 250, L"设置");
	buttonSet.draw();

	//退出游戏按钮
	TextButton buttonExit(350, 300, L"退出游戏");
	buttonExit.draw();


	ExMessage m;
	while (true) {
		m = getmessage(EX_MOUSE);
		if (m.message == WM_LBUTTONDOWN) {
			if (buttonChoose.isIn(m.x, m.y)) {
				levelChooseView();
				return;
			}
			if (buttonMenu.isIn(m.x, m.y)) {
				menuView();
				return;
			}
			if (buttonRestart.isIn(m.x, m.y)) {
				gameView();
				return;
			}
			if (buttonSet.isIn(m.x, m.y)) {
				setView();
				return;
			}
			if (buttonExit.isIn(m.x, m.y)) {
				exit(1);
			}
		}
	}
}