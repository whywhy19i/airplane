#include<iostream>
#include<graphics.h>


#include"data.h"
#include"view.h"
#include"service.h"
#include"dao.h"


using namespace std;


/*
	������:����
	����:��������
	����: void
	����ֵ: void
*/
int main() {
	HWND wnd = initgraph(852, 480);		// ������ͼ����
	SetWindowText(wnd, L"��ս�ȷ�");		//���ô��ڵı���
	setbkcolor(WHITE);								//���û�ͼ�屳��Ϊ��ɫ
	cleardevice();
	setbkmode(TRANSPARENT);				// ����͸���������������Ĭ�����ֱ����ñ���ɫ��䣩
	
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 24;						// ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	settextcolor(BLACK);

	menuView();
	system("pause");
	return 0;
}