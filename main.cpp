#include<iostream>
#include"Display.h"
#include"System.h"
#include"ComputerMessage.h"
#include"ComputerManage.h"
#include<stdlib.h>
#include<cstdio>
#include<Windows.h>
using namespace std;
//list<Student>studentList;
void coverSystem();										//ϵͳ��ʼ����
void clear();											//����
void init();											//��ʼ��ԭʼ���������
int main() {
//	cout << "1" << endl;
	display();											//��ʾ����
	init();												//��ʼ��
//	printOut();
	coverSystem();
}
void init() {
	setComputerMessage();
//	readStudentMessage();
}
void coverSystem() {
	char ch;
	int judgeBreak = 0;
	system("pause");
	clear();
	System();											//����ϵͳ
}
void clear() {
	system("CLS");
}