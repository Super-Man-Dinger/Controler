#include"ComputerManage.h"
#include"ComputerMessage.h"
Student _student;
std::list<Computer>computerList;
std::list<Student>studentList;
Student::Student() {

}
Manager::Manager() {

}
//整型转字符串
string Student::intToString(int n) {
	char ch;
	string s;
	for (int i = 0; n > 0; i++) {
		ch = n % 10 + 48;
		n /= 10;
		s = s.insert(0, 1, ch);
	}
	return s;
}
//学生信息初始化
void Student::initStudent() {
	_student.setName(_name);
	_student.setPassWords(_passWords);
	_student.setJudgeLogin(_judgeLogin);
	_student.setJudgeSet(_judgeSet);
}
//显示机位预订
void Student::display_computerReserve() {
	display_star();
	display_space();
	cout << "【机位预订】" << endl << endl << endl;
	display_space();
	cout << "【1】随机分配" << endl;
	display_space();
	cout << "【2】自主选择" << endl;
	display_star();
}
//显示机位退订
void Student::display_computerCancel() {

}
//显示系统选择
void Student::display_systemChoose() {
	display_star();
	display_space();
	cout << "请选择你需要的系统：" << endl << endl << endl;
	display_space();
	cout << "【1】Windows7" << endl;
	display_space();
	cout << "【2】Linux" << endl;
	display_space();
	cout << "【3】Windows7&&Linux" << endl;
	display_star();
}
//显示操作选择（学生界面）
void Student::display_operationChoose(string name) {
	display_star();
	display_space();
	cout << name << "同学，你好！" << endl;
	display_space();
	cout << "请选择你要进行的操作" << endl << endl << endl;
	display_space();
	cout << "【1】机位预定" << endl;
	display_space();
	cout << "【2】机位退订" << endl;
	display_star();
}
//学生操作
void Student::studentOperation(string name) {
	initStudent();
	string chooseNumber;
	display_operationChoose(name);
	while (cin >> chooseNumber) {
		if (chooseNumber == "1") {												//机位预定
			computerReserve();
			break;
		}
		else if (chooseNumber == "2") {											//机位退订
			computerCancel();
			break;
		}
		else {
			MessageBox(NULL, TEXT("输入错误！请重新输入！"), TEXT("错误！"), MB_OK);
		}
	}
}
//机位预订
void Student::computerReserve() {
	CLEAR;
	display_computerReserve();
	string chooseNumber;
	while (cin >> chooseNumber) {

		if (chooseNumber == "1") {															//随机分配
			systemChoose();
			break;
		}
		else if (chooseNumber == "2") {														//自己选择

			break;
		}
		else {
			MessageBox(NULL, TEXT("输入错误！请重新输入！"), TEXT("错误！"), MB_OK);
		}
		CLEAR;
		display_computerReserve();
	}
}
//机位退订
void Student::computerCancel() {

}
//系统选择
void Student::systemChoose() {
	CLEAR;
	display_systemChoose();
	const char* _chooseNumber;
	int computerNumber;
	srand(time(NULL));
//	cout << computerNumber;
	string chooseNumber;
	while (cin >> chooseNumber) {
		if (chooseNumber == "1"||chooseNumber=="2"||chooseNumber=="3") {						//选择Windows7
			_chooseNumber = chooseNumber.c_str();
			randomAllocation(atoi(_chooseNumber)-1);
			break;
		}
		//else if (chooseNumber == "2") {														//选择Linux
		//	break;
		//}
		//else if (chooseNumber == "3") {														//选择Windows7&&Linux
		//	break;
		//}
		else {
			MessageBox(NULL, TEXT("输入错误！请重新输入！"), TEXT("错误！"), MB_OK);
		}
		CLEAR;
		display_systemChoose();
	}
}
//随机分配
void Student::randomAllocation(int chooseNumber) {
	list<Computer>::iterator it;
	int number;
	
	int size = 0;
	stringstream stream;
	string test;
	test = intToString(15);
	cout << "test=" << test << endl;
	srand(time(NULL));
	if (chooseNumber == 0) {
		number = rand() % 20 + 1;
//		cout << "number=" << numberString << endl;
		for (it = computerList.begin(); it != computerList.end(); it++) {

		}
	}
	for (it = computerList.begin(); it != computerList.end(); it++) {
		if (chooseNumber == 0) {
			number = rand() % 20 + 1;

		}
	}

	cout << "size=" << size << endl;
}
//星期选择
Week weekChoose(string weekString) {
	Week week = Sunday;
	if (weekString == "Sunday") {
		week = Sunday;
	}
	else if (weekString == "Monday") {
		week = Monday;
	}
	else if (weekString == "Tuesday") {
		week = Tuesday;
	}
	else if (weekString == "Wednesday") {
		week = Wednesday;
	}
	else if (weekString == "Thursday") {
		week = Thursday;
	}
	else if (weekString == "Friday") {
		week = Friday;
	}
	else if (weekString == "Saturday") {
		week = Saturday;
	}
	else {
		MessageBox(NULL, TEXT("星期读取错误！"), TEXT("错误！"), MB_OK);
	}
	return week;
}
//时间选择
Time timeChoose(string timeString) {
	int size;
	Time time;
	const char* str;
	string hourString;
	string minuteString;
	int hour;
	int minute;
	time.hour = "00";
	time.minute = "00";
	time.timeString = time.hour + ":" + time.minute;
	size = timeString.find(":");
	if (size != string::npos&&timeString.length()==5) {
		for (int i = 0; i < timeString.length(); i++) {
			if (i < 2) {
				hourString.push_back(timeString[i]);
			}
			if (i > 2 && i < 5) {
				minuteString.push_back(timeString[i]);
			}
		}
		str = hourString.c_str();
		hour = atoi(str);
		str = minuteString.c_str();
		minute = atoi(str);
		if (hour >= 0 && hour < 24&&minute>=0&&minute<60) {
			time.hour = hour;
			time.minute = minute;
			time.timeString = timeString;
			return time;
		}
	}
	MessageBox(NULL, TEXT("时间格式错误！"), TEXT("错误！"), MB_OK);
	return time;
}
//管理员操作
void Manager::managerOperation(string name) {

}
//读入电脑信息
void setComputerMessage() {
	ifstream inFile;
	int size;
	int number;
	string s;
	string line;
	OS OSName;
	Date date;
	inFile.open("ComputerMessage.txt");
	if (inFile.fail()) {
		MessageBox(NULL, TEXT("文件打开失败！"), TEXT("错误！"), MB_OK);
		return;
	}
	inFile.seekg(sizeof("编号	系统		日期		星期	时间	学生"), ios::cur);
	getline(inFile, line);
	while (!inFile.eof()) {
		Computer computer_;
		string s, p;
		getline(inFile, line);
		size = line.find("\t");
		for (int i = 0; i < line.length() && line[i] != '\t'; i++) {
			s.push_back(line[i]);
		}
		computer_.setComputerNumber(s);
		p = line.erase(0, s.length() + 1);
		string().swap(s);
		if (size != string::npos) {
			for (int i = 0; i < p.length() && p[i] != '\t'; i++) {
				s.push_back(p[i]);
			}
			if (s == "Windows7") {
				computer_.setOSName(Windows7);
			}
			else if (s == "Linux") {
				computer_.setOSName(Linux);
			}
			else if (s == "Windows7_Linux") {
				computer_.setOSName(Windows7_Linux);
			}
			p = line.erase(0, s.length() + 1);
			for (int i = 0; i < p.length(); i++) {
				if (i < 4) {
					date.year.push_back(p[i]);
				}
				else if (i < 6) {
					date.month.push_back(p[i]);
				}
				else {
					date.day.push_back(p[i]);
				}
			}
			p = p.erase(0, s.length() + 1);
			size = p.find("\t");
			string().swap(s);
			if (size != string::npos) {
				for (int i = 0; i < p.length() && p[i] != '\t'; i++) {
					s.push_back(p[i]);
				}
				computer_.setWeek(weekChoose(s));
				p = p.erase(0, s.length() + 1);
				size = p.find("\t");
				string().swap(s);
				if (size != string::npos) {
					for (int i = 0; i < p.length() && p[i] != '\t'; i++) {
						s.push_back(p[i]);
					}
					Time time;
					time = timeChoose(s);
					computer_.setTime(time);
					p = p.erase(0, s.length() + 1);
					size = p.find("\t");
					string().swap(s);
					computer_.setStudentName(p);
				}
			}
		}
		computerList.push_back(computer_);
	}
	inFile.close();
}
//打印
void printOut() {
	list<Computer>::iterator i;
	
	for (i=computerList.begin(); i != computerList.end(); i++) {
		cout << (*i).getComputerNumber() << "--" << (*i).getComputerOSName() << endl;
	}
	cout << "===" << computerList.size() << endl;
}
