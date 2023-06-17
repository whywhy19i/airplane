//view.h负责人：流星
#pragma once
/*
	小难点
	负责人: 
	功能: 主菜单界面
	参数: void
	返回值: void
*/
void menuView();

/*
	负责人:
	功能:关卡选择界面
	参数: void
	返回值: void
*/
void levelChooseView();

/*
	负责人:
	功能:排行榜展示界面
	参数: void
	返回值: void
*/
void theChartsView();

/*
	小难点：在于几个按钮之间的交互要怎么实现，同时要和音乐播放交互
	负责人:
	功能:设置界面
	参数: void
	返回值: void
*/
void setView();

/*
	负责人:
	功能:教程界面
			教程贴图就好，见原型图
	参数: void
	返回值: void
*/
void courseView();


/*
	小难点
	负责人:
	功能:暂停界面
				注意重新开始和返回游戏的区别（前者要初始化再进入游戏界面）
	参数: void
	返回值: void
*/
void stopView();



/*
	小难点
	负责人:
	功能:根据三个vector数组和我方飞机,Boss位置信息，打印当前地图
	参数: void
	返回值: void
*/
void printGameView();
/*
	大难点
	负责人:
	功能:游戏界面整合,游戏主循环
				init();
				while(true){
					enermyRenew();
					bulletRenew();
					if(按下按键)	修改direction
					move();
					printGameView();
					if(松开按键)	direction修改成0
					collisionDetection();
					判断我机是否死亡
						死亡——failView
					判断Boss是否死亡
						死亡——victoryView()
					bossAccure();
				}
	参数: void
	返回值: void
*/
void gameView();


/*
	负责人:
	功能:胜利界面，原型图忘记设计了,大概就是暂停界面+分数+“恭喜胜利”之类的
			然后还要更新mark数组（排行榜）的数据
	参数: void
	返回值: void
*/
void victoryView();

/*
	负责人:
	功能:失败界面，暂停界面+“失败”
	参数: void
	返回值: void
*/
void failView();

