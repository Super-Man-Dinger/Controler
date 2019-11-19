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
//字符串转整型
int Student::stringToInt(string s) {
	int number = 0;
	int n;
	bool judgeRight = true;
	for (int i = 0; i < s.length(); i++) {
		n = s[i];
		if (n<'0' || n>'9'){
			MessageBox(NULL, TEXT("字符串无法转化为整型！"), TEXT("错误！"), MB_OK);
			return -1;
		}
		else {
			n -= 48;
			number = number + n * pow(10, s.length() - i - 1);
		}
	}
	return number;
}
//星期枚举换字符串
string Student::weekToString(int weekNumber) {
	string weekString;
	if (weekNumber >= 0 && weekNumber <= 6) {
		switch (weekNumber) {
		case 0:weekString = "Sunday";
			break;
		case 1:weekString = "Monday";
			break;
		case 2:weekString = "Tuesday";
			break;
		case 3:weekString = "Wednesday";
			break;
		case 4:weekString = "Thursday";
			break;
		case 5:weekString = "Friday";
			break;
		case 6:weekString = "Saturday";
			break;
		}
		return weekString;
	}
}
//系统枚举转字符串
string Student::OSNameToString(OS systemNumber) {
	switch (systemNumber) {
	case 0:return "Windows7";
	case 1:return "Linux";
	case 2:return "Windows7_Linux";
	}
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
	list<Computer>::iterator it;
	string systemString;
	Computer computer_;
	CLEAR;
	display_star();
	display_space();
	cout << "您的机位信息为：" << endl;
	display_space();
	for (it = computerList.begin(); it != computerList.end(); it++) {
		if ((*it).getStudentName()==_student.getName()) {
			computer_ = (*it);
			break;
		}
	}
	if (computer_.getComputerOSName() == 0) {
		systemString = "Windows7";
	}
	else if (computer_.getComputerOSName() == 1) {
		systemString = "Linux";
	}
	else {
		systemString = "Windows7_Linux";
	}
	cout << "机位号：" << computer_.getComputerNumber() << endl;
	display_space();
	cout << "系统：" << systemString << endl;
	display_space();
	cout << "日期：" << computer_.getDate().year << computer_.getDate().month << computer_.getDate().day << endl;
	display_space();
	cout << "星期：" << weekToString(computer_.getWeek()) << endl;
	display_space();
	cout << "时间：" << computer_.getTime().timeString << endl;
	display_star();
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
//显示机位
void Student::display_seat(string numberString) {
	display_star();
	cout << endl ;
	display_space();
	cout << "你的机位是：" << numberString << endl << endl;
	display_star();
}
//显示机位分布
void Student::display_allSeat(int chooseNumber) {
	int number;
	string numberString;
	list<Computer>::iterator it;
	display_star();
	cout << endl;
	display_space();
	cout << "#：已占" << endl << endl;
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			cout << "Windows7:" << endl << endl;
		}
		if (i == 2) {
			cout << "Linux:" << endl << endl;
		}
		if (i == 6) {
			cout << "Windows7_Linux:" << endl << endl;
		}
		for (int j = 0; j < 10; j++) {
			number = i * 10 + j + 1;
			cout << "【" << number << "】\t";
		}
		cout << endl;
		for (int j = 0; j < 10; j++) {
			number = i * 10 + j + 1;
			numberString = intToString(number);
			for (it = computerList.begin(); it != computerList.end(); it++) {
				if ((*it).getComputerNumber() == numberString) {
					if (!(*it).getStudentName().empty()) {
						cout << "  #" << "\t";
					}
					else {
						cout << "  \t";
					}
				}
			}

		}
		cout << endl << endl;
	}	
	display_star();
}
//学生操作
void Student::studentOperation(string name) {
	initStudent();
	string chooseNumber;
	int operationMode = 0;
	CLEAR;
	display_operationChoose(name);
	while (cin >> chooseNumber) {
		if (chooseNumber == "1") {												//机位预定
			if (!judgeReserve()) {
				if (judgeSeatFull()) {
					MessageBox(NULL, TEXT("机位已满！"), TEXT("错误！"), MB_OK);
				}
				else {
					operationMode = 0;
					computerReserve();
					break;
				}
			}
			else {
				MessageBox(NULL, TEXT("您已预订机位，不可再预订机位！"), TEXT("错误！"), MB_OK);
			}
		}
		else if (chooseNumber == "2") {											//机位退订
			if (judgeReserve()) {
				operationMode = 1;
				computerCancel();
				break;
			}
			else {
				MessageBox(NULL, TEXT("您尚未预订机位，不可退订机位！"), TEXT("错误！"), MB_OK);
			}
		}
		else {
			MessageBox(NULL, TEXT("输入错误！请重新输入！"), TEXT("错误！"), MB_OK);
		}
		CLEAR;
		display_operationChoose(name);
	}
	writeComputerMessage(operationMode);
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
			inputMessage();
			selfAllocation();
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
	display_computerCancel();
	list<Computer>::iterator it;
	int size;
	string s;
	string().swap(s);
	Date date;
	Week week;
	Time time;
	string().swap(date.year);
	string().swap(date.month);
	string().swap(date.day);

//	Computer computer_;
	int ret = MessageBox(NULL, TEXT("你确定要退订吗？"), TEXT("CHOOSE"), MB_YESNO | MB_ICONQUESTION);
	if (ret == IDYES) {
		for (it = computerList.begin(); it != computerList.end(); it++) {
			if ((*it).getStudentName() == _student.getName()) {
				_computer.setComputerNumber((*it).getComputerNumber());
				_computer.setOSName((*it).getComputerOSName());
				break;
			}
		}
		//string save((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		//size = save.find(_computer.getComputerNumber() + "\t" + systemString) + _computer.getComputerNumber().size() + systemString.size() + 1;
		MessageBox(NULL, TEXT("退订成功！"), TEXT("成功！"), MB_OK);
	}
	
	//返回
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
		if (chooseNumber == "1"||chooseNumber=="2"||chooseNumber=="3") {
			_chooseNumber = chooseNumber.c_str();
			inputMessage();
			
			randomAllocation(atoi(_chooseNumber)-1);
			break;
		}
		else {
			MessageBox(NULL, TEXT("输入错误！请重新输入！"), TEXT("错误！"), MB_OK);
		}
		CLEAR;
		display_systemChoose();
	}
}
//输入预订信息
void Student::inputMessage() {
	Date date;
	Week week;
	Time time;
	date = inputDate();
	week = inputWeek();
	time = inputTime();
	_computer.setDate(date);
	_computer.setWeek(week);
	_computer.setTime(time);
}
//写入机房信息
void Student::writeComputerMessage(int operationMode) {
	list<Computer>::iterator it;
	string systemString;
	string dateString;
	string weekString;
	string timeString;
	string nameString;
	OS systemNumber;

	for (it = computerList.begin(); it != computerList.end(); it++) {
		if ((*it).getComputerNumber() == _computer.getComputerNumber()) {
			(*it).setDate(_computer.getDate());
			(*it).setWeek(_computer.getWeek());
			(*it).setTime(_computer.getTime());
			(*it).setStudentName(_computer.getStudentName());

			systemNumber = (*it).getComputerOSName();
			break;
		}
	}
	systemString = OSNameToString(systemNumber);
	if (operationMode == 0) {
		dateString = _computer.getDate().year + _computer.getDate().month + _computer.getDate().day;
		weekString = weekToString(_computer.getWeek());
		timeString = _computer.getTime().timeString;
		nameString = _computer.getStudentName();
	}
	ifstream in("ComputerMessage.txt");
	int size = 0;
	if (!in) {
		MessageBox(NULL, TEXT("文件打开失败！"), TEXT("错误！"), MB_OK);
		return;
	}
	string save((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	if (operationMode == 0) {
		
		size = save.find(_computer.getComputerNumber() + "\t" + systemString) + _computer.getComputerNumber().size() + systemString.size() + 1;
		if (systemString != "Linux") {
			save.insert(size, "\t" + dateString + "\t" + weekString + "\t" + timeString + "\t" + nameString);
		}
		else {
			save.insert(size, "\t\t" + dateString + "\t" + weekString + "\t" + timeString + "\t" + nameString);
		}
	}
	else {
		int size1 = 0;
		int size2 = 0;
		int computerNumber = 0;
		string computerNumberString;
		computerNumber = stringToInt(_computer.getComputerNumber());
		computerNumber++;
		computerNumberString = intToString(computerNumber);
		size1 = save.find(_computer.getComputerNumber() + "\t" + systemString) + _computer.getComputerNumber().size() + systemString.size() + 1;
		for (it = computerList.begin(); it != computerList.end(); it++) {
			if ((*it).getComputerNumber() == computerNumberString) {
				systemNumber = (*it).getComputerOSName();
				systemString = OSNameToString(systemNumber);
			}
		}
		size2 = save.find(computerNumberString + "\t" + systemString);
		size = size2 - size1 - 1;
		save.erase(size1, size);
	}
	//cout << save;
	ofstream out("ComputerMessage.txt");
	if (!out) {
		MessageBox(NULL, TEXT("文件打开失败！"), TEXT("错误！"), MB_OK);
		return;
	}
	out << save;
}
//输入日期
Date Student::inputDate() {
	Date date;
	string dateString;
	string yearString;
	string monthString;
	string dayString;
	int year;
	int month;
	int day;
	CLEAR;
	cout << "请输入日期：（如20190101）" << endl;
	while (cin >> dateString) {
		yearString.clear();
		monthString.clear();
		dayString.clear();
		if (dateString.length() != 8) {
			MessageBox(NULL, TEXT("日期格式错误！请重新输入！"), TEXT("错误！"), MB_OK);
			CLEAR;
			cout << "请输入日期：（如20190101）" << endl;
			continue;
		}
		for (int i = 0; i < dateString.length(); i++) {
			if (i >= 0 && i <= 3) {
				yearString.push_back(dateString[i]);
			}
			else if (i <= 5) {
				monthString.push_back(dateString[i]);
			}
			else {
				dayString.push_back(dateString[i]);
			}
		}
		year = stringToInt(yearString);
		month = stringToInt(monthString);
		day = stringToInt(dayString);
		if (year <= 2019) {
			if (month >= 1 && month <= 12) {
				if (day >= 1 && day <= 31) {
					break;
				}
				else {
					MessageBox(NULL, TEXT("日期输入错误！请重新输入！"), TEXT("错误！"), MB_OK);
				}
			}
			else {
				MessageBox(NULL, TEXT("月份输入错误！请重新输入！"), TEXT("错误！"), MB_OK);
			}
		}
		else {
			MessageBox(NULL, TEXT("年份输入错误！请重新输入！"), TEXT("错误！"), MB_OK);
		}
		CLEAR;
		cout << "请输入日期：（如20190101）" << endl;
	}
	date.year = yearString;
	date.month = monthString;
	date.day = dayString;
	return date;
}
//输入星期
Week Student::inputWeek() {
	Week week;
	string weekString;
	CLEAR;
	cout << "请输入星期：（如Monday）" << endl;
	while (cin >> weekString) {
		if (weekString == "Monday") {
			week = Monday;
			break;
		}
		else if (weekString == "Tuesday") {
			week = Tuesday;
			break;
		}
		else if (weekString == "Wednesday") {
			week = Wednesday;
			break;
		}
		else if (weekString == "Thursday") {
			week = Thursday;
			break;
		}
		else if (weekString == "Friday") {
			week = Friday;
			break;
		}
		else if (weekString == "Saturday") {
			week = Saturday;
			break;
		}
		else if (weekString == "Sunday") {
			week = Sunday;
			break;
		}
		else {
			MessageBox(NULL, TEXT("星期输入错误！请重新输入！"), TEXT("错误！"), MB_OK);
		}
		CLEAR;
		cout << "请输入星期：" << endl;
	}
	return week;
}
//输入时间
Time Student::inputTime() {
	Time time;
	string timeString;
	string hourString;
	string minuteString;
	int hour;
	int minute;
	CLEAR;
	cout << "请输入时间：（如：00:00）" << endl;
	while (cin >> timeString) {
		hourString.clear();
		minuteString.clear();
		if (timeString.length() != 5) {
			MessageBox(NULL, TEXT("时间格式错误！请重新输入！"), TEXT("错误！"), MB_OK);
			CLEAR;
			cout << "请输入时间：" << endl;
			continue;
		}
		if (timeString[2] != ':') {
			MessageBox(NULL, TEXT("时间格式错误！请重新输入！"), TEXT("错误！"), MB_OK);
			CLEAR;
			cout << "请输入时间：" << endl;
			continue;
		}
		for (int i = 0; i < timeString.length(); i++) {
			if (i < 2) {
				hourString.push_back(timeString[i]);
			}
			else if (i > 2 && i < 5) {
				minuteString.push_back(timeString[i]);
			}
		}
		hour = stringToInt(hourString);
		minute = stringToInt(minuteString);
		if (hour >= 0 && hour < 24) {
			if (minute >= 0 && minute < 60) {
				time.hour = hourString;
				time.minute = minuteString;
				time.timeString = hourString + ":" + minuteString;
				break;
			}
			else {
				MessageBox(NULL, TEXT("分钟格式错误！请重新输入！"), TEXT("错误！"), MB_OK);
			}
		}
		else {
			MessageBox(NULL, TEXT("小时格式错误！请重新输入！"), TEXT("错误！"), MB_OK);
		}
	}
	return time;
}
//随机分配
bool Student::randomAllocation(int chooseNumber) {
	list<Computer>::iterator it;
	int number;
	int size = 0;
	string numberString;
	bool judgeBreak = true;
	bool judgeContinue = true;
	bool judgeSuccess = false;
	srand(time(NULL));
	if (chooseNumber == 0) {
		while (1) {
			judgeBreak = true;
			number = rand() % 20 + 1;
			numberString = intToString(number);
			for (it = computerList.begin(); it != computerList.end(); it++) {
				if ((*it).getComputerNumber() == "21") {
					break;
				}
				if (!(*it).getStudentName().empty()) {
					if ((*it).getComputerNumber() == numberString) {
						judgeBreak = false;
					}
				}
			}
			if (judgeBreak) {
				judgeSuccess = true;
				break;
			}
		}
	}
	else if (chooseNumber == 1) {
		judgeContinue = true;
		while (1) {
			judgeBreak = true;
			number = rand() % 40 + 21;
			numberString = intToString(number);
			for (it = computerList.begin(); it != computerList.end(); it++) {
				if ((*it).getComputerNumber() == "21") {
					judgeContinue = false;
				}
				if (judgeContinue) {
					continue;
				}
				if ((*it).getComputerNumber() == "61") {
					break;
				}
				if (!(*it).getStudentName().empty()) {
					if ((*it).getComputerNumber() == numberString) {
						judgeBreak = false;
					}
				}
			}
			if (judgeBreak) {
				judgeSuccess = true;
				break;
			}
		}
	}
	else {
		judgeContinue = true;
		while (1) {
			judgeBreak = true;
			number = rand() % 40 + 61;
			numberString = intToString(number);
			for (it = computerList.begin(); it != computerList.end(); it++) {
				if ((*it).getComputerNumber() == "61") {
					judgeContinue = false;
				}
				if (judgeContinue) {
					continue;
				}
				if (!(*it).getStudentName().empty()) {
					if ((*it).getComputerNumber() == numberString) {
						judgeBreak = false;
					}
				}
			}
			if (judgeBreak) {
				judgeSuccess = true;
				break;
			}
		}
	}
	if (judgeSuccess) {
		CLEAR;
		display_seat(numberString);
		_student.setComputerNumber(numberString);
		_computer.setStudentName(_student.getName());
		_computer.setComputerNumber(numberString);
		return true;
	}
	else {
		MessageBox(NULL, TEXT("机位已满！"), TEXT("错误！"), MB_OK);
		return false;
	}
	//如果没有分配成功，返回到上一界面
}
//自主分配
bool Student::selfAllocation() {
	CLEAR;
	display_allSeat(0);
	int number;
	string numberString;
	bool judgeBreak = false;
	bool judgeRight = false;
	cout << "请选择你要预订的机位:" << endl;
	while (cin >> number) {
		numberString = intToString(number);
		judgeRight = false;
		list<Computer>::iterator it;
		for (it = computerList.begin(); it != computerList.end(); it++) {
			if ((*it).getComputerNumber() == numberString) {
				if (!(*it).getStudentName().empty()) {
					MessageBox(NULL, TEXT("该机位已预订！请重新选择！"), TEXT("错误！"), MB_OK);
				}
				else {
					MessageBox(NULL, TEXT("预订成功！"), TEXT("成功！"), MB_OK);
					judgeBreak = true;
				}
				judgeRight = true;
			}
		}
		if (!judgeRight) {
			MessageBox(NULL, TEXT("输入错误！请重新输入！"), TEXT("错误！"), MB_OK);
		}
		if (judgeBreak) {
			break;
		}
		CLEAR;
		display_allSeat(0);
		cout << "请选择你要预订的机位:" << endl;
	}
	_computer.setComputerNumber(numberString);
	_computer.setStudentName(_student.getName());
	return true;
}
//判断机位是否选满
bool Student::judgeSeatFull() {
	list<Computer>::iterator it;
	for (it = computerList.begin(); it != computerList.end(); it++) {
		if ((*it).getStudentName().empty()) {
			return false;
		}
	}
	return true;
}
//判断学生是否已经预订
bool Student::judgeReserve() {
	list<Computer>::iterator it;
	for (it = computerList.begin(); it != computerList.end(); it++) {
		if ((*it).getStudentName() == _student.getName()) {
			return true;
		}
	}
	return false;
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
		cout << "weekString=" << weekString << endl;
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
	int k = 0;
	while (!inFile.eof()) {
		k++;
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
			if (computer_.getComputerOSName() == Linux) {
				p = line.erase(0, s.length() + 2);
			}
			else {
				p = line.erase(0, s.length() + 1);
			}
			date.year.clear();
			date.month.clear();
			date.day.clear();
			for (int i = 0; i < p.length(); i++) {
				if (i < 4) {
					date.year.push_back(p[i]);
				}
				else if (i < 6) {
					
					date.month.push_back(p[i]);
				}
				else if( i < 8 ){
					
					date.day.push_back(p[i]);
				}
			}
			computer_.setDate(date);
			p = p.erase(0, date.year.length()+date.month.length()+date.day.length()+1);
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