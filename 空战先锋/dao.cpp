#include "dao.h"

int isRank() {
	int wrong = 0;
	int x = level;
	int n = score;
	fstream rankfile;
	//���ݹؿ����򿪶�Ӧrank�ļ�
firstif:                                                     //here is goto
	if (x == 1)rankfile.open("rank1.txt", ios::out | ios::in);
	if (x == 2)rankfile.open("rank2.txt", ios::out | ios::in);
	if (x == 3)rankfile.open("rank3.txt", ios::out | ios::in);
	//�����ļ��ɹ� ��ʼ�ж��Ƿ����ϰ�
	//No.1   114514 �ݴ�ά 
	//��ʱ��
	string s;
	int i = 1;

	if (rankfile.is_open()) {
		rankfile.seekp(0);
		while (!rankfile.eof()) {
			getline(rankfile, s);
			if (i == 19) {
				//��string s תΪ int
				stringstream tem(s);
				int min = 0;
				tem >> min;
				//�����������ϰ� ��������а� Ȼ��ر��ļ� ����1 ���� �ر��ļ� ����0
				int number = 0;
				if (n > min) {
					rankfile.seekp(0);
					int temNumber;
					//�ҵ��·���λ�� �ڸ�λ�ò����������� �ֱ�Ϊ���ֺͷ��� Ȼ��ɾ�����·���������
					while (!rankfile.eof()) {//������ʵһ������ ��Ϊ�·����������ķ��� 
						//ɨ��ÿһ�з��� temNumber ��¼���з��� ���·����Ա� ֱ���·�������ĳһ�з��� number�������ǵڼ��� 
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
					//˼·���£��½�һ�����ַ��������ı��ļ�һ���ж�ȡ������Ҫ�޸ĵľͰ�ԭ����˳�򱣴浽�ַ����У�
					//�ȶ�����Ҫ�޸ĵ��е�ʱ�򣬽��µ��б��浽�ַ����С�Ȼ����������������ݣ������һ�����ݷ�����

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
					//Ȼ���ı���գ������ַ��������ȥ�������Ӿ������ĳһ�е��޸ġ�
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
	{//����ʧ���򴴽�rank
		wrong++;
		if (wrong > 5)return -1;
		if (x == 1)rankfile.open("rank1.txt", ios::out);
		if (x == 2)rankfile.open("rank2.txt", ios::out);
		if (x == 3)rankfile.open("rank3.txt", ios::out);
		if (rankfile.is_open()) {
			for (int i = 0; i < 10; i++) {
				rankfile << "��" << endl << 0 << endl;
			}
			rankfile.close();
		}
		goto firstif;//����43��
	}
	rankfile.close();
	return -1;
}

void Get() {
	//����rank1
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
				file << "��" << endl << 0 << endl;
			}
			file.close();
			goto openrank1;
		}
	}
	//����rank2
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
				file << 0 << endl << "��" << endl;
			}
			file.close();
			goto openrank2;
		}
	}
	//����rank3
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
				file << 0 << endl << "��" << endl;
			}
			file.close();
			goto openrank3;
		}
	}
}