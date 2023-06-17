#pragma once

#include"data.h"
#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream> //stringstream 函数
using namespace std;

/*---------------------------------------------说明-----------------------------------------
* 若中文格式出现乱码 则是rank文件的编码格式问题 请打开rank.txt 另存为 选择ANSI格式存储
*
* dao.h包括以下函数
*
* int IsRank()
* 负责人：可颂
*	功能：将积分与排行榜最低分对比，若可进入排行榜则记录并返回1 否则不记录返回0
*	参数：无
*	返回值：int 分数可进入排行榜则记录入排行榜并返回1 不能上榜返回0  若返回-1则说明出现意外情况
*
* void Get()
* 负责人:可颂
*	功能:获取排行榜数据，存入mark 调用此函数 将根据排行榜文件更新mark
*	参数: void
*	返回值: void
*
----------------------------------------------------------------------------------
*/

int isRank() ;

/*
	负责人:可颂

	功能: 调用get函数 得到vector markList 其中存放排行榜所有数据
	markList的起始为 markList.at(0) 末尾为markList.at(29)
	markList.at(0)到markList.at(9) 表示关卡1的前十名
	markList.at(10)到markList.at(19) 表示关卡2的前十名
	markList.at(20)到markList.at(29) 表示关卡3的前十名
	您可通过markList.at(0).playerPoint  markList.at(0).playerName 的形式访问vector中每个对象的两个值

	参数: void
	返回值: void
*/
void Get();