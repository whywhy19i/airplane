#pragma once

#include"data.h"
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream> //stringstream ����
using namespace std;

/*---------------------------------------------˵��-----------------------------------------
* �����ĸ�ʽ�������� ����rank�ļ��ı����ʽ���� ���rank.txt ���Ϊ ѡ��ANSI��ʽ�洢
*
* dao.h�������º���
*
* int IsRank()
* �����ˣ�����
*	���ܣ������������а���ͷֶԱȣ����ɽ������а����¼������1 ���򲻼�¼����0
*	��������
*	����ֵ��int �����ɽ������а����¼�����а񲢷���1 �����ϰ񷵻�0  ������-1��˵�������������
*
* void Get()
* ������:����
*	����:��ȡ���а����ݣ�����mark ���ô˺��� ���������а��ļ�����mark
*	����: void
*	����ֵ: void
*
----------------------------------------------------------------------------------
*/

int isRank() ;

/*
	������:����

	����: ����get���� �õ�vector markList ���д�����а���������
	markList����ʼΪ markList.at(0) ĩβΪmarkList.at(29)
	markList.at(0)��markList.at(9) ��ʾ�ؿ�1��ǰʮ��
	markList.at(10)��markList.at(19) ��ʾ�ؿ�2��ǰʮ��
	markList.at(20)��markList.at(29) ��ʾ�ؿ�3��ǰʮ��
	����ͨ��markList.at(0).playerPoint  markList.at(0).playerName ����ʽ����vector��ÿ�����������ֵ

	����: void
	����ֵ: void
*/
void Get();