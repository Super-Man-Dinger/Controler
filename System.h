#pragma once
#include"Display.h"
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<cstdio>
#include<list>
#include<Windows.h>
#include<fstream>
#include"ComputerManage.h"




typedef enum identify {
	MANAGER=0,
	STUDENT,
}Identify;
class System {
public:
	System();
	void setJudgeSet(bool judgeSet) {
		_judgeSet = judgeSet;
	}
	void setJudgeLogin(bool judgeLogin) {
		_judgeLogin = judgeLogin;
	}
	void setIdentify(Identify identify) {
		_identify = identify;
	}
	void setName(string name) {
		_name = name;
	}
	void setPassWords(string passWords) {
		_passWords = passWords;
	}
	Identify getIdentify() {
		return _identify;
	}
	string getName() {
		return _name;
	}
	string getPassWords() {
		return _passWords;
	}
private:
	void codingSystem(Identify identify, string &name);								//密码系统
	void computerOperation(Identify identify, string name);							//机位操作


	
	void readStudentMessage();														//读入学生信息
	void readManagerMessage();														//读入管理员信息
	void display_coding();															//显示密码操作
	void display_identify();														//身份识别
	

	string enter_manager();															//学生登录
	string enter_student();															//管理员登录
	Identify input_identify();														//输入身份
	string inputPassWords();														//输入密码
	void enroll_student();															//学生注册
	bool judge_Studentname(string name);											//判断学生姓名是否存在
	bool judgeSet();																//判断是否无人注册
	bool enroll_judgeStudentPassWords(string name);									//判断某学生是否已经注册
	bool enter_judgeStudentPassWords(string name, string passWords);				//判断学生密码是否正确
	void setPassWords_student(string name, string passWords);						//学生设置密码
	void writeStudentMessage(string name, string passWords);						//写入学生信息至文件

	Student _student;
	Manager _manager;
	std::list<Student>_studentList;
	string _name;
	string _passWords;
	bool _judgeSet = false;
	bool _judgeLogin = false;
	Identify _identify;
};
