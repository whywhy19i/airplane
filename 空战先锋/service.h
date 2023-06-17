#pragma once
#include "data.h"
#include"view.h"
#include <vector>

/*
	������:��Ұ
	����:��ʼ���ҷ��ɻ�
			����level���趨level_hp,level_ag,level_distance
			������vector�ÿ�
	����: void
	����ֵ: void
*/
void init();

/*
	������:����
	����:�ֱ���ó�Ա����move
	����: void
	����ֵ: void
*/
void move(); 
void moveMyBullet();
void moveenermyBullets();
void moveEnermyPlaneDown();
void moveEnermyPlaneLR();
void Myplane_move();

/*
	�ѵ�
	������:����
	����:
		����ҷ��ɻ��Ƿ���з��ӵ���ײ�������з��ӵ����飬����ײ���ҷ��ɻ���Ѫ����Ӧ�ӵ����٣���������ȥ��erase��
		���з��ɻ��Ƿ����ҷ��ӵ���ײ����������������飬����ײ���з��ɻ���Ѫ����Ӧ�ӵ����٣���������ȥ����
		����ҷ��ɻ��Ƿ���з��ɻ���ײ�������з��ɻ����飬����ײ��˫���ɻ���Ѫ
	����: void
	����ֵ: void
*/
void collisionDetection();



/*
	������:ޱ
	����:ˢ�µл�
			���ɳ����棨�����л����͵�isOut��������data.h�У����ӵл�������ɾ��
			���ʣ��л�����num>0,����2���µĵл�������л�����
			ʣ��л�����num����2
	����: void
	����ֵ: void
*/
void enermyRenew();


/*
	������:��Ұ
	����:ˢ���ӵ�
			���ɳ����棨�����ӵ����͵�isOut��������data.h�У����ӣ��ҷ����з����ӵ�������ɾ��
	����: void
	����ֵ: void
*/
//��ģ��ֱ����move�����
//void bulletRenew();


/*
	������:����û�й�
	����:���л������ѿգ���ʣ��л�����num==0,��appear_sign==0������Boss
			��ʼ��Boss�ڽ������Ϸ����м䣨��ʼ��x,y��
	����: void
	����ֵ: void
*/
void bossAccure();



/*
	������:��־��
	����:����music_sign��ֵ����������
			0-������
			1-���ŵ�һ������
			2-���ŵڶ�������
			������Դ��Ⱥ�ļ����鳤�ķ���
	����: void
	����ֵ: void
*/
void musicPlay();

