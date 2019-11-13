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
	void managerOperation(string name);												//����Ա����
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
	void studentOperation(string name);												//ѧ������

private:
//	void studentOperation();
	void initStudent();																//ѧ����Ϣ��ʼ��
	void computerReserve();															//��λԤ��
	void computerCancel();															//��λ�˶�
	void systemChoose();															//ϵͳѡ��
	void randomAllocation(int chooseNumber);										//�������
	void display_operationChoose(string name);										//��ʾ����ѡ��ѧ�����棩
	void display_computerReserve();													//��ʾ��λԤ��
	void display_computerCancel();													//��ʾ��λ�˶�
	void display_systemChoose();													//��ʾϵͳѡ��

	string intToString(int n);														//����ת�ַ���


	string _name;
	string _passWords;
	Computer _computer;
	bool _judgeSet = false;
	bool _judgeLogin = false;


	void printOut();
	
};
void setComputerMessage();
Week weekChoose(string weekString);												//����ѡ��
Time timeChoose(string timeString);
void printOut();