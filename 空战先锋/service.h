#pragma once
#include "data.h"
#include"view.h"
#include <vector>

/*
	负责人:朴野
	功能:初始化我方飞机
			根据level，设定level_hp,level_ag,level_distance
			把三个vector置空
	参数: void
	返回值: void
*/
void init();

/*
	负责人:高磊
	功能:分别调用成员函数move
	参数: void
	返回值: void
*/
void move(); 
void moveMyBullet();
void moveenermyBullets();
void moveEnermyPlaneDown();
void moveEnermyPlaneLR();
void Myplane_move();

/*
	难点
	负责人:阿旭
	功能:
		检测我方飞机是否与敌方子弹碰撞，遍历敌方子弹数组，若碰撞，我方飞机掉血，对应子弹销毁（从数组中去掉erase）
		检测敌方飞机是否与我方子弹碰撞，二层遍历两个数组，若碰撞，敌方飞机掉血，对应子弹销毁（从数组中去掉）
		检测我方飞机是否与敌方飞机碰撞，遍历敌方飞机数组，若碰撞，双方飞机掉血
	参数: void
	返回值: void
*/
void collisionDetection();



/*
	负责人:薇
	功能:刷新敌机
			若飞出界面（借助敌机类型的isOut函数——data.h中），从敌机数组中删掉
			如果剩余敌机数量num>0,生成2架新的敌机，插入敌机数组
			剩余敌机数量num减少2
	参数: void
	返回值: void
*/
void enermyRenew();


/*
	负责人:朴野
	功能:刷新子弹
			若飞出界面（借助子弹类型的isOut函数——data.h中），从（我方、敌方）子弹数组中删掉
	参数: void
	返回值: void
*/
//本模块直接在move中完成
//void bulletRenew();


/*
	负责人:北极没有光
	功能:当敌机数组已空，且剩余敌机数组num==0,且appear_sign==0，出现Boss
			初始化Boss在界面最上方的中间（初始化x,y）
	参数: void
	返回值: void
*/
void bossAccure();



/*
	负责人:曾志林
	功能:根据music_sign的值来播放音乐
			0-不播放
			1-播放第一首音乐
			2-播放第二首音乐
			音乐资源见群文件中组长的分享
	参数: void
	返回值: void
*/
void musicPlay();

