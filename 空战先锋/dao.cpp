#include "dao.h"

int isRank() {
	int wrong = 0;
	int x = level;
	int n = score;
	fstream rankfile;
	//根据关卡数打开对应rank文件
firstif:                                                     //here is goto
	if (x == 1)rankfile.open("rank1.txt", ios::out | ios::in);
	if (x == 2)rankfile.open("rank2.txt", ios::out | ios::in);
	if (x == 3)rankfile.open("rank3.txt", ios::out | ios::in);
	//若打开文件成功 则开始判断是否能上榜
	//No.1   114514 屋大维 
	//加时间
	string s;
	int i = 1;

	if (rankfile.is_open()) {
		rankfile.seekp(0);
		while (!rankfile.eof()) {
			getline(rankfile, s);
			if (i == 19) {
				//将string s 转为 int
				stringstream tem(s);
				int min = 0;
				tem >> min;
				//若分数可以上榜 则加入排行榜 然后关闭文件 返回1 否则 关闭文件 返回0
				int number = 0;
				if (n > min) {
					rankfile.seekp(0);
					int temNumber;
					//找到新分数位置 在该位置插入两行数据 分别为名字和分数 然后删除最下方两行数据
					while (!rankfile.eof()) {//条件其实一定满足 因为新分数大于最后的分数 
						//扫描每一行分数 temNumber 记录此行分数 与新分数对比 直到新分数大于某一行分数 number记下这是第几行 
						temNumber = 0;
						getline(rankfile, s);
						number++;
						stringstream tem(s);
						tem >> temNumber;
						getline(rankfile, s);
						number++;
						if (n > temNumber) {
							number -= 1;
							break;
						}
					}
					//思路如下：新建一个空字符串，将文本文件一行行读取，不需要修改的就按原来的顺序保存到字符串中，
					//等读到需要修改的行的时候，将新的行保存到字符串中。然后继续保存后面的内容，将最后一组数据放弃。

					string str = "";
					int newNumber = 0;
					rankfile.seekg(0);
					while (getline(rankfile, s))
					{
						newNumber++;
						if (newNumber == number) {
							str = str + to_string(n) + '\n';
							str = str + name + '\n';
						}
						str = str + s + '\n';
						if (newNumber == 18)break;
					}
					//然后将文本清空，将新字符串保存进去。这样子就完成了某一行的修改。
					rankfile.close();
					if (x == 1)rankfile.open("rank1.txt", ios::out);
					if (x == 2)rankfile.open("rank2.txt", ios::out);
					if (x == 3)rankfile.open("rank3.txt", ios::out);
					rankfile << str;
					return 1;
				}
				else {
					rankfile.close();
					return 0;
				}

			};
			i++;
		}
	}
	else
	{//若打开失败则创建rank
		wrong++;
		if (wrong > 5)return -1;
		if (x == 1)rankfile.open("rank1.txt", ios::out);
		if (x == 2)rankfile.open("rank2.txt", ios::out);
		if (x == 3)rankfile.open("rank3.txt", ios::out);
		if (rankfile.is_open()) {
			for (int i = 0; i < 10; i++) {
				rankfile << "空" << endl << 0 << endl;
			}
			rankfile.close();
		}
		goto firstif;//跳至43行
	}
	rankfile.close();
	return -1;
}

void Get() {
	//读入rank1
	fstream file;
	markList.resize(30);
openrank1:
	file.open("rank1.txt", ios::in);
	if (file.is_open()) {
		file.seekg(0);
		string s;
		for (int i = 0; i < 20; i++) {
			if (!(i % 2)) {
				getline(file, s);
				stringstream ss(s);
				int tempoint = 0;
				ss >> tempoint;
				markList.at(i / 2).playerPoint = tempoint;
			}
			if (i % 2) {
				getline(file, s);
				markList.at(i / 2).playerName = s;
			}
		}
		file.close();
	}
	else {
		file.open("rank1.txt", ios::out);
		if (file.is_open()) {
			for (int i = 0; i < 10; i++) {
				file << "空" << endl << 0 << endl;
			}
			file.close();
			goto openrank1;
		}
	}
	//读入rank2
openrank2:
	file.open("rank2.txt", ios::in);
	if (file.is_open()) {
		file.seekg(0);
		string s;
		for (int i = 0; i < 20; i++) {
			if (!(i % 2)) {
				getline(file, s);
				stringstream ss(s);
				int tempoint = 0;
				ss >> tempoint;
				markList.at((i / 2) + 10).playerPoint = tempoint;
			}
			if (i % 2) {
				getline(file, s);
				markList.at((i / 2) + 10).playerName = s;
			}
		}
		file.close();
	}
	else {
		file.open("rank2.txt", ios::out);
		if (file.is_open()) {
			for (int i = 0; i < 10; i++) {
				file << 0 << endl << "空" << endl;
			}
			file.close();
			goto openrank2;
		}
	}
	//读入rank3
openrank3:
	file.open("rank3.txt", ios::in);
	if (file.is_open()) {
		file.seekg(0);
		string s;
		for (int i = 0; i < 20; i++) {
			if (!(i % 2)) {
				getline(file, s);
				stringstream ss(s);
				int tempoint = 0;
				ss >> tempoint;
				markList.at((i / 2) + 20).playerPoint = tempoint;
			}
			if (i % 2) {
				getline(file, s);
				markList.at((i / 2) + 20).playerName = s;
			}
		}
		file.close();
	}
	else {
		file.open("rank3.txt", ios::out);
		if (file.is_open()) {
			for (int i = 0; i < 10; i++) {
				file << 0 << endl << "空" << endl;
			}
			file.close();
			goto openrank3;
		}
	}
}