#pragma once
#include"ComputerMessage.h"
#include<Windows.h>
#include<string>
#include<time.h>
#include<math.h>
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
	void setComputerNumber(string computerNumber) {
		_computerNumber = computerNumber;
	}
	void setJudgeSet(bool judgeSet) {
		_judgeSet = judgeSet;
	}
	void setJudgeLogin(bool judgeLogin) {
		_judgeLogin = judgeLogin;
	}
	void setJudgeReserve(bool judgeReserve){
		_judgeReserve = judgeReserve;
	}
	bool getJudgeSet() {
		return _judgeSet;
	}
	bool getJudgeLogin() {
		return _judgeLogin;
	}
	bool getJudgeReserve() {
		return _judgeReserve;
	}
	string getName() {
		return _name;
	}
	string getPassWords() {
		return _passWords;
	}
	string getComputerNumber() {
		return _computerNumber;
	}
	void studentOperation(string name);												//学生操作

private:
//	void studentOperation();
	void initStudent();																//学生信息初始化
	void computerReserve();															//机位预定
	void computerCancel();															//机位退订
	void systemChoose();															//系统选择
	void inputMessage();															//输入预定信息
	
	Date inputDate();																//输入日期
	Week inputWeek();																//输入星期
	Time inputTime();																//输入时间
	bool randomAllocation(int chooseNumber);										//随机分配
	bool selfAllocation();															//自主分配
	bool judgeSeatFull();															//判断机位是否选满
	bool judgeReserve();															//判断学生是否已经预订
	void display_seat(string numberString);											//显示机位
	void display_allSeat(int chooseNumber);											//显示机位分布
	void display_operationChoose(string name);										//显示操作选择（学生界面）
	void display_computerReserve();													//显示机位预订
	void display_computerCancel();													//显示机位退订
	void display_systemChoose();													//显示系统选择
	void writeComputerMessage(int operationMode);													//写入机房信息

	string intToString(int n);														//整型转字符串
	int stringToInt(string s);														//字符串转整型
	string weekToString(int weekNumber);												//星期枚举换字符串
	string OSNameToString(OS systemNumber);										//系统枚举转字符串

	string _name;
	string _computerNumber;
	string _passWords;
	Computer _computer;
	bool _judgeSet = false;
	bool _judgeLogin = false;
	bool _judgeReserve = false;

	void printOut();
	
};
void setComputerMessage();

Week weekChoose(string weekString);												//星期选择
Time timeChoose(string timeString);
void printOut();