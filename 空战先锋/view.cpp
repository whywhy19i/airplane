#include "view.h"
#include "service.h"
#include "data.h"
#include "dao.h"
#include<graphics.h>


void menuView() {
	cleardevice();
	//��ʾ��Ϸ����-��ս�ȷ�
	outtextxy(350, 25, L"��ս�ȷ�");

	//��ʼ��Ϸ��ť
	TextButton buttonLevelChoose(350, 100, L"��ʼ��Ϸ");
	buttonLevelChoose.draw();

	//���а�ť
	TextButton buttonTheCharts(350, 150, L"���а�");
	buttonTheCharts.draw();

	//���ð�ť
	TextButton buttonSet(350, 200, L"����");
	buttonSet.draw();

	//��Ϸ�̳̰�ť
	TextButton buttonCourse(350, 250, L"��Ϸ�̳�");
	buttonCourse.draw();

	//�˳���Ϸ��ť
	TextButton buttonExit(350, 300, L"�˳���Ϸ");
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
	//�ؿ�1
	TextButton buttonLevel1(350, 100, L"�ؿ�1");
	buttonLevel1.draw();

	//�ؿ�2
	TextButton buttonLevel2(350, 150, L"�ؿ�2");
	buttonLevel2.draw();

	//�ؿ�3
	TextButton buttonLevel3(350, 200, L"�ؿ�3");
	buttonLevel3.draw();

	//�������˵�
	TextButton buttonMenu(310, 350, L"�������˵�");
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
	outtextxy(10, 10, L"��һ�����а�");
	outtextxy(260, 10, L"�ڶ������а�");
	outtextxy(510, 10, L"���������а�");
	TCHAR s[5];
	Get();
	//�������а�����
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 10;j++) {
			if (markList.at(i*10+j).playerPoint == 0) {
				continue;
			}
			_stprintf_s(s, _T("%d"), j);
			outtextxy(10 + 250 * i, 50 + 40 * j, s);
			_stprintf_s(s, _T("%d"), markList.at(i * 10 + j).playerPoint);
			outtextxy(70 + 250 * i, 50 + 40 * j, s);//���60
		}
	}

	//���Ʒ������˵���ť
	TextButton buttonMenu(350, 410, L"�������˵�");
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

//���ý���
void setView() {
	cleardevice();
	//���ñ�־λsign_now,sign_before��������־λ�Ƿ�ı�
	//0-���ֹر�,1���ŵ�һ�����֣�2���ŵڶ�������
	int sign_before = 1, sign_now = 1;

	IMAGE imgSwitchOpen, imgSwitchClose, imgChoose, imgNoChoose, imgBackground;
	loadimage(&imgSwitchOpen, L"pic/setOpen.png", 40, 30);
	loadimage(&imgSwitchClose, L"pic/setClose.png", 40, 30);
	loadimage(&imgChoose, L"pic/setChoose.png", 20, 20);
	loadimage(&imgNoChoose, L"pic/setNoChoose.png", 20, 20);
	//ͼ�ΰ�ť
	PictureButton buttonSwitchOpen(480, 70, &imgSwitchOpen);
	PictureButton buttonSwitchClose(480, 70, &imgSwitchClose);
	PictureButton buttonChoose1(375, 125, &imgChoose);
	PictureButton buttonNoChoose1(375, 125, &imgNoChoose);
	PictureButton buttonChoose2(525, 125, &imgChoose);
	PictureButton buttonNoChoose2(525, 125, &imgNoChoose);
	//���ְ�ť
	TextButton buttonMenu(350, 400, L"���ز˵�");

	cleardevice();
	putimage(0, 0, &imgBackground);
	outtextxy(350, 20, L"���ý���");
	outtextxy(350, 70, L"���ֿ���");
	outtextxy(300, 120, L"����1");
	outtextxy(450, 120, L"����2");
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
				outtextxy(350, 20, L"���ý���");
				outtextxy(350, 70, L"���ֿ���");
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
				outtextxy(350, 20, L"���ý���");
				outtextxy(350, 70, L"���ֿ���");
				outtextxy(300, 120, L"����1");
				outtextxy(450, 120, L"����2");
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
				outtextxy(350, 20, L"���ý���");
				outtextxy(350, 70, L"���ֿ���");
				outtextxy(300, 120, L"����1");
				outtextxy(450, 120, L"����2");
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

//�̳̽���
void courseView() {
	cleardevice();
	//���̵̳�ͼƬ������
	IMAGE img;
	loadimage(&img, L"pic/hero1.png", 652, 360);
	putimage(100, 50, &img);

	//�ص����˵���ť
	TextButton buttonMenu(350, 420, L"�������˵�");
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
	//������Ϸ��ť
	TextButton buttonBack(350, 100, L"������Ϸ");
	buttonBack.draw();

	//�������˵���ť
	TextButton buttonMenu(350, 150, L"�������˵�");
	buttonMenu.draw();

	//���¿�ʼ��ť
	TextButton buttonRestart(350, 200, L"���¿�ʼ");
	buttonRestart.draw();

	//���ð�ť
	TextButton buttonSet(350, 250, L"����");
	buttonSet.draw();

	//�˳���Ϸ��ť
	TextButton buttonExit(350, 300, L"�˳���Ϸ");
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

	//��Ϸ���ݴ�ӡ
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

	//������Ϣ��ӡ
	LOGFONT g;
	gettextstyle(&g);						// ��ȡ��ǰ��������
	g.lfHeight = 16;						// ��������߶�Ϊ 16
	settextstyle(&g);
	outtextxy(10, 10, L"����ֵ��");
	TCHAR s[5];
	_stprintf_s(s, _T("%d"), plane.hp);		// ��ӡѪ��
	outtextxy(70, 10, s);
	outtextxy(10, 30, L"������");
	_stprintf_s(s, _T("%d"), score);		// ��ӡ����
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
	//��ӡ��������ϲȡ��ʤ��
	LOGFONT g;
	gettextstyle(&g);
	g.lfHeight = 24;
	settextstyle(&g);

	outtextxy(300, 10, L"��ϲȡ��ʤ����");
	outtextxy(300, 40, L"���ķ����ǣ�");
	TCHAR s[5];
	_stprintf_s(s, _T("%d"), score);
	outtextxy(450, 40, s);

	g.lfHeight = 32;
	settextstyle(&g);

	//ѡ��ؿ���ť
	TextButton buttonChoose(350, 100, L"ѡ��ؿ�");
	buttonChoose.draw();

	//�������˵���ť
	TextButton buttonMenu(350, 150, L"�������˵�");
	buttonMenu.draw();

	//���¿�ʼ��ť
	TextButton buttonRestart(350, 200, L"���¿�ʼ");
	buttonRestart.draw();

	//���ð�ť
	TextButton buttonSet(350, 250, L"����");
	buttonSet.draw();

	//�˳���Ϸ��ť
	TextButton buttonExit(350, 300, L"�˳���Ϸ");
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
	//��ӡ���������ź�ʧ����
	LOGFONT g;
	gettextstyle(&g);
	g.lfHeight = 24;
	settextstyle(&g);

	outtextxy(300, 10, L"���ź�ʧ���ˣ�");
	outtextxy(300, 40, L"���ķ����ǣ�");
	TCHAR s[5];
	_stprintf_s(s, _T("%d"), score);
	outtextxy(450, 40, s);

	g.lfHeight = 32;
	settextstyle(&g);

	//ѡ��ؿ���ť
	TextButton buttonChoose(350, 100, L"ѡ��ؿ�");
	buttonChoose.draw();

	//�������˵���ť
	TextButton buttonMenu(350, 150, L"�������˵�");
	buttonMenu.draw();

	//���¿�ʼ��ť
	TextButton buttonRestart(350, 200, L"���¿�ʼ");
	buttonRestart.draw();

	//���ð�ť
	TextButton buttonSet(350, 250, L"����");
	buttonSet.draw();

	//�˳���Ϸ��ť
	TextButton buttonExit(350, 300, L"�˳���Ϸ");
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