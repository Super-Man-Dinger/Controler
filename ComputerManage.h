#pragma once
#include"ComputerMessage.h"
#include<Windows.h>
#include<string>
#include<time.h>
#include<fstream>
#include<stdlib.h>
#include<sstream>
#include<list>
//#include"System.h"
#define CLEAR system("CLS")

using namespace std;
class Manager {
public:
	Manager();
	void setName(string name) {
		_name = name;
	}
	void setPassWords(string passWords) {
		_passWords = passWords;
	}
	void setJudgeLogin(bool judgeLogin) {
		_judgeLogin = judgeLogin;
	}
	bool getJudgeLogin() {
		return _judgeLogin;
	}
	string getName() {
		return _name;
	}
	string getPassWords() {
		return _passWords;
	}
	void managerOperation(string name);												//管理员操作
private:
//	void managerOperation();
	
	string _name;
	string _passWords;
	Computer _computer;
	bool _judgeSet = false;
	bool _judgeLogin = false;

	void printOut();
};
class Student {
public:
	Student();
	void setName(string name) {
		_name = name;
	}
	void setComputer(Computer computer) {
		_computer = computer;
	}
	void setPassWords(string passWords) {
		_passWords = passWords;
	}
	void setJudgeSet(bool judgeSet) {
		_judgeSet = judgeSet;
	}
	void setJudgeLogin(bool judgeLogin) {
		_judgeLogin = judgeLogin;
	}
	bool getJudgeSet() {
		return _judgeSet;
	}
	bool getJudgeLogin() {
		return _judgeLogin;
	}
	string getName() {
		return _name;
	}
	string getPassWords() {
		return _passWords;
	}
	void studentOperation(string name);												//学生操作

private:
//	void studentOperation();
	void initStudent();																//学生信息初始化
	void computerReserve();															//机位预定
	void computerCancel();															//机位退订
	void systemChoose();															//系统选择
	void randomAllocation(int chooseNumber);										//随机分配
	void display_operationChoose(string name);										//显示操作选择（学生界面）
	void display_computerReserve();													//显示机位预订
	void display_computerCancel();													//显示机位退订
	void display_systemChoose();													//显示系统选择

	string intToString(int n);														//整型转字符串


	string _name;
	string _passWords;
	Computer _computer;
	bool _judgeSet = false;
	bool _judgeLogin = false;


	void printOut();
	
};
void setComputerMessage();
Week weekChoose(string weekString);												//星期选择
Time timeChoose(string timeString);
void printOut();