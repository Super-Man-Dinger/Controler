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
void coverSystem();										//系统初始界面
void clear();											//清屏
void init();											//初始化原始计算机数据
int main() {
//	cout << "1" << endl;
	display();											//显示界面
	init();												//初始化
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
	System();											//进入系统
}
void clear() {
	system("CLS");
}