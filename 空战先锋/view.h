//view.h�����ˣ�����
#pragma once
/*
	С�ѵ�
	������: 
	����: ���˵�����
	����: void
	����ֵ: void
*/
void menuView();

/*
	������:
	����:�ؿ�ѡ�����
	����: void
	����ֵ: void
*/
void levelChooseView();

/*
	������:
	����:���а�չʾ����
	����: void
	����ֵ: void
*/
void theChartsView();

/*
	С�ѵ㣺���ڼ�����ť֮��Ľ���Ҫ��ôʵ�֣�ͬʱҪ�����ֲ��Ž���
	������:
	����:���ý���
	����: void
	����ֵ: void
*/
void setView();

/*
	������:
	����:�̳̽���
			�̳���ͼ�ͺã���ԭ��ͼ
	����: void
	����ֵ: void
*/
void courseView();


/*
	С�ѵ�
	������:
	����:��ͣ����
				ע�����¿�ʼ�ͷ�����Ϸ������ǰ��Ҫ��ʼ���ٽ�����Ϸ���棩
	����: void
	����ֵ: void
*/
void stopView();



/*
	С�ѵ�
	������:
	����:��������vector������ҷ��ɻ�,Bossλ����Ϣ����ӡ��ǰ��ͼ
	����: void
	����ֵ: void
*/
void printGameView();
/*
	���ѵ�
	������:
	����:��Ϸ��������,��Ϸ��ѭ��
				init();
				while(true){
					enermyRenew();
					bulletRenew();
					if(���°���)	�޸�direction
					move();
					printGameView();
					if(�ɿ�����)	direction�޸ĳ�0
					collisionDetection();
					�ж��һ��Ƿ�����
						��������failView
					�ж�Boss�Ƿ�����
						��������victoryView()
					bossAccure();
				}
	����: void
	����ֵ: void
*/
void gameView();


/*
	������:
	����:ʤ�����棬ԭ��ͼ���������,��ž�����ͣ����+����+����ϲʤ����֮���
			Ȼ��Ҫ����mark���飨���а񣩵�����
	����: void
	����ֵ: void
*/
void victoryView();

/*
	������:
	����:ʧ�ܽ��棬��ͣ����+��ʧ�ܡ�
	����: void
	����ֵ: void
*/
void failView();

