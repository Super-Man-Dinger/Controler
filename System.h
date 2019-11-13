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
	void codingSystem(Identify identify, string &name);								//����ϵͳ
	void computerOperation(Identify identify, string name);							//��λ����


	
	void readStudentMessage();														//����ѧ����Ϣ
	void readManagerMessage();														//�������Ա��Ϣ
	void display_coding();															//��ʾ�������
	void display_identify();														//���ʶ��
	

	string enter_manager();															//ѧ����¼
	string enter_student();															//����Ա��¼
	Identify input_identify();														//�������
	string inputPassWords();														//��������
	void enroll_student();															//ѧ��ע��
	bool judge_Studentname(string name);											//�ж�ѧ�������Ƿ����
	bool judgeSet();																//�ж��Ƿ�����ע��
	bool enroll_judgeStudentPassWords(string name);									//�ж�ĳѧ���Ƿ��Ѿ�ע��
	bool enter_judgeStudentPassWords(string name, string passWords);				//�ж�ѧ�������Ƿ���ȷ
	void setPassWords_student(string name, string passWords);						//ѧ����������
	void writeStudentMessage(string name, string passWords);						//д��ѧ����Ϣ���ļ�

	Student _student;
	Manager _manager;
	std::list<Student>_studentList;
	string _name;
	string _passWords;
	bool _judgeSet = false;
	bool _judgeLogin = false;
	Identify _identify;
};
