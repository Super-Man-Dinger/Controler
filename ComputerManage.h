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
	void studentOperation(string name);												//ѧ������

private:
//	void studentOperation();
	void initStudent();																//ѧ����Ϣ��ʼ��
	void computerReserve();															//��λԤ��
	void computerCancel();															//��λ�˶�
	void systemChoose();															//ϵͳѡ��
	void inputMessage();															//����Ԥ����Ϣ
	
	Date inputDate();																//��������
	Week inputWeek();																//��������
	Time inputTime();																//����ʱ��
	bool randomAllocation(int chooseNumber);										//�������
	bool selfAllocation();															//��������
	bool judgeSeatFull();															//�жϻ�λ�Ƿ�ѡ��
	bool judgeReserve();															//�ж�ѧ���Ƿ��Ѿ�Ԥ��
	void display_seat(string numberString);											//��ʾ��λ
	void display_allSeat(int chooseNumber);											//��ʾ��λ�ֲ�
	void display_operationChoose(string name);										//��ʾ����ѡ��ѧ�����棩
	void display_computerReserve();													//��ʾ��λԤ��
	void display_computerCancel();													//��ʾ��λ�˶�
	void display_systemChoose();													//��ʾϵͳѡ��
	void writeComputerMessage(int operationMode);													//д�������Ϣ

	string intToString(int n);														//����ת�ַ���
	int stringToInt(string s);														//�ַ���ת����
	string weekToString(int weekNumber);												//����ö�ٻ��ַ���
	string OSNameToString(OS systemNumber);										//ϵͳö��ת�ַ���

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

Week weekChoose(string weekString);												//����ѡ��
Time timeChoose(string timeString);
void printOut();