#include"System.h"


System::System() {
	Identify identify;
	string name;
	display_identify();										//���ʶ��
	identify = input_identify();							//�������
	CLEAR;													//����
	
	display_coding();										//��ʾ��������
	codingSystem(identify, name);							//����ϵͳ
//	cout << name << endl;
	computerOperation(identify, name);						//��λ����
//	Student();
//	printOut();
//	Student();
}
//���ʶ��
void System::display_identify() {
	display_star();
	display_space();
	cout << "��ѡ�������ݣ�" << endl;
	display_space();
	cout << "��1������Ա" << endl;
	display_space();
	cout << "��2��ѧ��" << endl;
	display_star();
}
//�������
Identify System::input_identify() {
	int number;
	Identify identify=MANAGER;
	while (cin >> number) {
		CLEAR;
		display_identify();
		if (number != 1 && number != 2) {
			MessageBox(NULL, TEXT("�����������������"), TEXT("����"), MB_OK);
		}
		else {
			
			if (number == 1) {
				identify = MANAGER;
			}
			else {
				identify = STUDENT;
			}
			
			break;
		}
	}
	setIdentify(identify);
	return identify;
}
//��ʾ�������
void System::display_coding() {
	display_star();
	
	if (_identify == MANAGER) {
		display_space();
		cout << "����Ա��ã����¼��" << endl;
	}
	else {
		display_space();
		cout << "��1����¼" << endl;
		display_space();
		cout << "��2��ע��" << endl;
	}

	//display_space();
	//cout<<"��3���޸�����"
	display_star();
}
//����ϵͳ
void System::codingSystem(Identify identify, string &name) {
	int codingNumber;
	int judgeBreak = 0;
	if (_identify == MANAGER) {
		readStudentMessage();
		readManagerMessage();
		CLEAR;
		display_coding();
		enter_manager();
		return;
	}

	list<Student>::iterator it;

	while (cin >> codingNumber) {													//С������Ҫ���
		CLEAR;
		display_coding();
		readStudentMessage();
		readManagerMessage();
		//for (it = _studentList.begin(); it != _studentList.end(); it++) {
		//	if (!(*it).getPassWords().empty()) {
		//		cout << (*it).getName() << endl;
		//	}
		//}
		//MessageBox(NULL, TEXT("��"), TEXT("����"), MB_OK);
		switch (codingNumber)
		{
		case 1:if (_identify == MANAGER) {												//���Ϊ����Ա
			name = enter_manager();
			judgeBreak = 1;
		}
			   else {																	//���Ϊѧ��
			if (judgeSet() == true) {
				name = enter_student();
				judgeBreak = 1;
			}
			else {
				MessageBox(NULL, TEXT("Ŀǰû���û�������ע���û���"), TEXT("����"), MB_OK);
			}
		}

			break;
		case 2:
			enroll_student();
			break;
		default:
			MessageBox(NULL, TEXT("����������������룡"), TEXT("����"), MB_OK);
		}

		if (judgeBreak == 1) {
			break;
		}
		CLEAR;
		display_coding();
	}
}
//��λ����
void System::computerOperation(Identify identify, string name) {
	if (!_judgeLogin) {	//���û�е�¼�����˳�
		return;
	}
	
	if (identify == MANAGER) {
		_manager.managerOperation(name);
	}
	else {
		_student.studentOperation(name);
	}
}
//�ж��Ƿ�����ע��
bool System::judgeSet() {
	list<Student>::iterator it;
	for (it = _studentList.begin(); it != _studentList.end(); it++) {
		if (!(*it).getPassWords().empty()) {
			return true;
		}
	}
	return false;
}
//����Ա��¼
string System::enter_manager() {
	string accountNumber;
	string passWords;
	char ch;
	while (1) {
		CLEAR;
		display_coding();
		cout << "�û�����";
		cin >> accountNumber;												//�Ƿ�Ҫ�ж��û�������
		cout << "���룺";
		passWords = inputPassWords();
		if (_manager.getName() != accountNumber) {
			MessageBox(NULL, TEXT("�û������ڣ������������û�����"), TEXT("����"), MB_OK);
		}
		else {
			if (_manager.getPassWords() != passWords) {
				MessageBox(NULL, TEXT("����������������룡"), TEXT("����"), MB_OK);
			}
			else {
				_judgeLogin = true;
				MessageBox(NULL, TEXT("��¼�ɹ�"), NULL, MB_OK);
				CLEAR;
				break;
			}
		}
	}
	setName(accountNumber);
	setPassWords(passWords);
	return accountNumber;
}
//ѧ����¼
string System::enter_student() {
	string accountNumber;
	string passWords;
	char ch;
	while (1) {
		CLEAR;
		display_coding();
		cout << "������";
		cin >> accountNumber;												//�Ƿ�Ҫ�ж��û�������
		cout << "���룺";
		passWords = inputPassWords();
		if (!judge_Studentname(accountNumber)) {
			MessageBox(NULL, TEXT("�û������ڣ������������û�����"), TEXT("����"), MB_OK);
		}
		else {
			if (enter_judgeStudentPassWords(accountNumber,passWords)) {
				_judgeLogin = true;
				MessageBox(NULL, TEXT("��¼�ɹ�"), NULL, MB_OK);
				CLEAR;
				break;
			}
		}
	}
	_student.setName(accountNumber);
	_student.setPassWords(passWords);
	return accountNumber;
}
//�ж�ѧ�������Ƿ���ȷ
bool System::enter_judgeStudentPassWords(string name,string passWords) {
	list<Student>::iterator it;
	for (it = _studentList.begin(); it != _studentList.end(); it++) {
		if (name == (*it).getName()) {
			if ((*it).getPassWords().empty()) {
				MessageBox(NULL, TEXT("���û���δע�ᣡ����ע�ᣡ"), TEXT("����"), MB_OK);
				return false;
			}
			else {
				if ((*it).getPassWords() == passWords) {
					return true;
				}
				else {
					MessageBox(NULL, TEXT("����������������룡"), NULL, MB_OK);
				}
			}
		}
	}
	return false;
}
//��������
string System::inputPassWords() {
	int i = 0;
	char ch;
	string passWords;
	while (1) {
		ch = _getch();
		if (ch == 8) {
			i--;
			continue;
		}
		if (ch == '\r') {
			break;
		}
		if (i > 20) {
			break;
		}
		cout << "*";													//�˴������޷�ɾ����Ҫ��
		passWords.push_back(ch);
		i++;
	}
	cout << endl;
	return passWords;
}
//ѧ��ע��
void System::enroll_student() {

	string studentName;
	string passWords;
	while (1) {
		CLEAR;
		display_coding();
		cout << "������";
		cin >> studentName;												//�Ƿ�Ҫ�ж��û�������

		cout << "���룺";
		passWords = inputPassWords();
		if (!judge_Studentname(studentName)) {
			MessageBox(NULL, TEXT("���������ڣ����������룡"), NULL, MB_OK);
		}
		else {
			if (enroll_judgeStudentPassWords(studentName)) {
				MessageBox(NULL, TEXT("�û���ע�ᣡ���������룡"), NULL, MB_OK);
			}
			else {
				break;
			}
		}
	}
	setPassWords_student(studentName, passWords);
	_student.setJudgeSet(true);
	MessageBox(NULL, TEXT("ע��ɹ�"), NULL, MB_OK);
}
//ѧ����������
void System::setPassWords_student(string name, string passWords) {
	writeStudentMessage(name, passWords);
	list<Student>::iterator it;
	for (it = _studentList.begin(); it != _studentList.end(); it++) {
		if (name == (*it).getName()) {
			(*it).setPassWords(passWords);
			break;
		}
	}
}
//д��ѧ����Ϣ���ļ�
void System::writeStudentMessage(string name, string passWords) {
	ifstream in("StudentMessage.txt");
	int size;
	if (!in) {
		MessageBox(NULL, TEXT("�ļ���ʧ�ܣ�"), TEXT("����"), MB_OK);
		return;
	}
	string save((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	size = save.find(name) + name.size();
	save.insert(size, "\t"+passWords);
	ofstream out("StudentMessage.txt");
	if (!out) {
		MessageBox(NULL, TEXT("�ļ���ʧ�ܣ�"), TEXT("����"), MB_OK);
		return;
	}
	out << save ;
}
//�ж�ѧ�������Ƿ����
bool System::judge_Studentname(string name) {
	list<Student>::iterator it;
	for (it = _studentList.begin(); it != _studentList.end(); it++) {
		if (name == (*it).getName()) {
			return true;
		}
	}
	return false;
}
//�ж�ĳѧ���Ƿ��Ѿ�ע��
bool System::enroll_judgeStudentPassWords(string name) {
	list<Student>::iterator it;
	for (it = _studentList.begin(); it != _studentList.end(); it++) {
		if (name == (*it).getName()) {
			if (!(*it).getPassWords().empty()) {
				return true;
			}
		}
	}
	return false;
}
//����ѧ����Ϣ
void System::readStudentMessage() {
	_studentList.clear();
	ifstream inFile("StudentMessage.txt");
	string line;
	int size;
	OS OSName;
	if (inFile.fail()) {
		MessageBox(NULL, TEXT("�ļ���ʧ�ܣ�"), TEXT("����"), MB_OK);
		return;
	}
	inFile.seekg(sizeof("����	����"), ios::cur);
	getline(inFile, line);
	while (!inFile.eof()) {
		Student student_;
		string s, p;
		getline(inFile, line);
		size = line.find("\t");
		if (size != string::npos) {												//�ж��û��Ƿ��Ѿ������룬�жϳ�������Ϊ��
			for (int i = 0; i < line.length()&&line[i]!='\t'; i++) {
				s.push_back(line[i]);
			}
			student_.setName(s);
			p = line.erase(0, s.length() + 1);
			student_.setPassWords(p);
		}
		else {
			student_.setName(line);
		}
		
		_studentList.push_back(student_);
	}
	inFile.close();
}
//�������Ա��Ϣ
void System::readManagerMessage() {
	ifstream inFile("ManagerMessage.txt");
	string line;
	string s;
	string p;
	int size;
	OS OSName;
	if (inFile.fail()) {
		MessageBox(NULL, TEXT("�ļ���ʧ�ܣ�"), TEXT("����"), MB_OK);
		return;
	}
	getline(inFile, line);
	getline(inFile, line);
	for (int i = 0; i < line.length() && line[i] != '\t'; i++) {
		s.push_back(line[i]);
	}
	_manager.setName(s);
	p = line.erase(0, s.length() + 1);
	_manager.setPassWords(p);
	inFile.close();
}