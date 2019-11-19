#include"System.h"


System::System() {
	Identify identify;
	string name;
	display_identify();										//身份识别
	identify = input_identify();							//输入身份
	CLEAR;													//清屏
	
	display_coding();										//显示操作界面
	codingSystem(identify, name);							//密码系统
//	cout << name << endl;
	computerOperation(identify, name);						//机位操作
//	Student();
//	printOut();
//	Student();
}
//身份识别
void System::display_identify() {
	display_star();
	display_space();
	cout << "请选择你的身份：" << endl;
	display_space();
	cout << "【1】管理员" << endl;
	display_space();
	cout << "【2】学生" << endl;
	display_star();
}
//输入身份
Identify System::input_identify() {
	int number;
	Identify identify=MANAGER;
	while (cin >> number) {
		CLEAR;
		display_identify();
		if (number != 1 && number != 2) {
			MessageBox(NULL, TEXT("输入错误！请重新输入"), TEXT("错误！"), MB_OK);
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
//显示密码操作
void System::display_coding() {
	display_star();
	
	if (_identify == MANAGER) {
		display_space();
		cout << "管理员你好！请登录！" << endl;
	}
	else {
		display_space();
		cout << "【1】登录" << endl;
		display_space();
		cout << "【2】注册" << endl;
	}

	//display_space();
	//cout<<"【3】修改密码"
	display_star();
}
//密码系统
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

	while (cin >> codingNumber) {													//小数问题要解决
		CLEAR;
		display_coding();
		readStudentMessage();
		readManagerMessage();
		//for (it = _studentList.begin(); it != _studentList.end(); it++) {
		//	if (!(*it).getPassWords().empty()) {
		//		cout << (*it).getName() << endl;
		//	}
		//}
		//MessageBox(NULL, TEXT("！"), TEXT("错误！"), MB_OK);
		switch (codingNumber)
		{
		case 1:if (_identify == MANAGER) {												//身份为管理员
			name = enter_manager();
			judgeBreak = 1;
		}
			   else {																	//身份为学生
			if (judgeSet() == true) {
				name = enter_student();
				judgeBreak = 1;
			}
			else {
				MessageBox(NULL, TEXT("目前没有用户，请先注册用户！"), TEXT("错误！"), MB_OK);
			}
		}

			break;
		case 2:
			enroll_student();
			break;
		default:
			MessageBox(NULL, TEXT("输入错误！请重新输入！"), TEXT("错误！"), MB_OK);
		}

		if (judgeBreak == 1) {
			break;
		}
		CLEAR;
		display_coding();
	}
}
//机位操作
void System::computerOperation(Identify identify, string name) {
	if (!_judgeLogin) {	//如果没有登录，则退出
		return;
	}
	
	if (identify == MANAGER) {
		_manager.managerOperation(name);
	}
	else {
		_student.studentOperation(name);
	}
}
//判断是否无人注册
bool System::judgeSet() {
	list<Student>::iterator it;
	for (it = _studentList.begin(); it != _studentList.end(); it++) {
		if (!(*it).getPassWords().empty()) {
			return true;
		}
	}
	return false;
}
//管理员登录
string System::enter_manager() {
	string accountNumber;
	string passWords;
	char ch;
	while (1) {
		CLEAR;
		display_coding();
		cout << "用户名：";
		cin >> accountNumber;												//是否要判断用户名过长
		cout << "密码：";
		passWords = inputPassWords();
		if (_manager.getName() != accountNumber) {
			MessageBox(NULL, TEXT("用户不存在！请重新输入用户名！"), TEXT("错误！"), MB_OK);
		}
		else {
			if (_manager.getPassWords() != passWords) {
				MessageBox(NULL, TEXT("密码错误！请重新输入！"), TEXT("错误！"), MB_OK);
			}
			else {
				_judgeLogin = true;
				MessageBox(NULL, TEXT("登录成功"), NULL, MB_OK);
				CLEAR;
				break;
			}
		}
	}
	setName(accountNumber);
	setPassWords(passWords);
	return accountNumber;
}
//学生登录
string System::enter_student() {
	string accountNumber;
	string passWords;
	char ch;
	while (1) {
		CLEAR;
		display_coding();
		cout << "姓名：";
		cin >> accountNumber;												//是否要判断用户名过长
		cout << "密码：";
		passWords = inputPassWords();
		if (!judge_Studentname(accountNumber)) {
			MessageBox(NULL, TEXT("用户不存在！请重新输入用户名！"), TEXT("错误！"), MB_OK);
		}
		else {
			if (enter_judgeStudentPassWords(accountNumber,passWords)) {
				_judgeLogin = true;
				MessageBox(NULL, TEXT("登录成功"), NULL, MB_OK);
				CLEAR;
				break;
			}
		}
	}
	_student.setName(accountNumber);
	_student.setPassWords(passWords);
	return accountNumber;
}
//判断学生密码是否正确
bool System::enter_judgeStudentPassWords(string name,string passWords) {
	list<Student>::iterator it;
	for (it = _studentList.begin(); it != _studentList.end(); it++) {
		if (name == (*it).getName()) {
			if ((*it).getPassWords().empty()) {
				MessageBox(NULL, TEXT("该用户尚未注册！请先注册！"), TEXT("错误！"), MB_OK);
				return false;
			}
			else {
				if ((*it).getPassWords() == passWords) {
					return true;
				}
				else {
					MessageBox(NULL, TEXT("密码错误！请重新输入！"), NULL, MB_OK);
				}
			}
		}
	}
	return false;
}
//输入密码
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
		cout << "*";													//此处密码无法删除，要改
		passWords.push_back(ch);
		i++;
	}
	cout << endl;
	return passWords;
}
//学生注册
void System::enroll_student() {

	string studentName;
	string passWords;
	while (1) {
		CLEAR;
		display_coding();
		cout << "姓名：";
		cin >> studentName;												//是否要判断用户名过长

		cout << "密码：";
		passWords = inputPassWords();
		if (!judge_Studentname(studentName)) {
			MessageBox(NULL, TEXT("姓名不存在！请重新输入！"), NULL, MB_OK);
		}
		else {
			if (enroll_judgeStudentPassWords(studentName)) {
				MessageBox(NULL, TEXT("用户已注册！请重新输入！"), NULL, MB_OK);
			}
			else {
				break;
			}
		}
	}
	setPassWords_student(studentName, passWords);
	_student.setJudgeSet(true);
	MessageBox(NULL, TEXT("注册成功"), NULL, MB_OK);
}
//学生设置密码
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
//写入学生信息至文件
void System::writeStudentMessage(string name, string passWords) {
	ifstream in("StudentMessage.txt");
	int size;
	if (!in) {
		MessageBox(NULL, TEXT("文件打开失败！"), TEXT("错误！"), MB_OK);
		return;
	}
	string save((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	size = save.find(name) + name.size();
	save.insert(size, "\t"+passWords);
	ofstream out("StudentMessage.txt");
	if (!out) {
		MessageBox(NULL, TEXT("文件打开失败！"), TEXT("错误！"), MB_OK);
		return;
	}
	out << save ;
}
//判断学生姓名是否存在
bool System::judge_Studentname(string name) {
	list<Student>::iterator it;
	for (it = _studentList.begin(); it != _studentList.end(); it++) {
		if (name == (*it).getName()) {
			return true;
		}
	}
	return false;
}
//判断某学生是否已经注册
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
//读入学生信息
void System::readStudentMessage() {
	_studentList.clear();
	ifstream inFile("StudentMessage.txt");
	string line;
	int size;
	OS OSName;
	if (inFile.fail()) {
		MessageBox(NULL, TEXT("文件打开失败！"), TEXT("错误！"), MB_OK);
		return;
	}
	inFile.seekg(sizeof("姓名	密码"), ios::cur);
	getline(inFile, line);
	while (!inFile.eof()) {
		Student student_;
		string s, p;
		getline(inFile, line);
		size = line.find("\t");
		if (size != string::npos) {												//判断用户是否已经有密码，判断成立，则为有
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
//读入管理员信息
void System::readManagerMessage() {
	ifstream inFile("ManagerMessage.txt");
	string line;
	string s;
	string p;
	int size;
	OS OSName;
	if (inFile.fail()) {
		MessageBox(NULL, TEXT("文件打开失败！"), TEXT("错误！"), MB_OK);
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