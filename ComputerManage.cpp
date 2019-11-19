#include"ComputerManage.h"
#include"ComputerMessage.h"
Student _student;
std::list<Computer>computerList;
std::list<Student>studentList;
Student::Student() {

}
Manager::Manager() {

}
//����ת�ַ���
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
//�ַ���ת����
int Student::stringToInt(string s) {
	int number = 0;
	int n;
	bool judgeRight = true;
	for (int i = 0; i < s.length(); i++) {
		n = s[i];
		if (n<'0' || n>'9'){
			MessageBox(NULL, TEXT("�ַ����޷�ת��Ϊ���ͣ�"), TEXT("����"), MB_OK);
			return -1;
		}
		else {
			n -= 48;
			number = number + n * pow(10, s.length() - i - 1);
		}
	}
	return number;
}
//����ö�ٻ��ַ���
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
//ϵͳö��ת�ַ���
string Student::OSNameToString(OS systemNumber) {
	switch (systemNumber) {
	case 0:return "Windows7";
	case 1:return "Linux";
	case 2:return "Windows7_Linux";
	}
}
//ѧ����Ϣ��ʼ��
void Student::initStudent() {
	_student.setName(_name);
	_student.setPassWords(_passWords);
	_student.setJudgeLogin(_judgeLogin);
	_student.setJudgeSet(_judgeSet);
}
//��ʾ��λԤ��
void Student::display_computerReserve() {
	display_star();
	display_space();
	cout << "����λԤ����" << endl << endl << endl;
	display_space();
	cout << "��1���������" << endl;
	display_space();
	cout << "��2������ѡ��" << endl;
	display_star();
}
//��ʾ��λ�˶�
void Student::display_computerCancel() {
	list<Computer>::iterator it;
	string systemString;
	Computer computer_;
	CLEAR;
	display_star();
	display_space();
	cout << "���Ļ�λ��ϢΪ��" << endl;
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
	cout << "��λ�ţ�" << computer_.getComputerNumber() << endl;
	display_space();
	cout << "ϵͳ��" << systemString << endl;
	display_space();
	cout << "���ڣ�" << computer_.getDate().year << computer_.getDate().month << computer_.getDate().day << endl;
	display_space();
	cout << "���ڣ�" << weekToString(computer_.getWeek()) << endl;
	display_space();
	cout << "ʱ�䣺" << computer_.getTime().timeString << endl;
	display_star();
}
//��ʾϵͳѡ��
void Student::display_systemChoose() {
	display_star();
	display_space();
	cout << "��ѡ������Ҫ��ϵͳ��" << endl << endl << endl;
	display_space();
	cout << "��1��Windows7" << endl;
	display_space();
	cout << "��2��Linux" << endl;
	display_space();
	cout << "��3��Windows7&&Linux" << endl;
	display_star();
}
//��ʾ����ѡ��ѧ�����棩
void Student::display_operationChoose(string name) {
	display_star();
	display_space();
	cout << name << "ͬѧ����ã�" << endl;
	display_space();
	cout << "��ѡ����Ҫ���еĲ���" << endl << endl << endl;
	display_space();
	cout << "��1����λԤ��" << endl;
	display_space();
	cout << "��2����λ�˶�" << endl;
	display_star();
}
//��ʾ��λ
void Student::display_seat(string numberString) {
	display_star();
	cout << endl ;
	display_space();
	cout << "��Ļ�λ�ǣ�" << numberString << endl << endl;
	display_star();
}
//��ʾ��λ�ֲ�
void Student::display_allSeat(int chooseNumber) {
	int number;
	string numberString;
	list<Computer>::iterator it;
	display_star();
	cout << endl;
	display_space();
	cout << "#����ռ" << endl << endl;
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
			cout << "��" << number << "��\t";
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
//ѧ������
void Student::studentOperation(string name) {
	initStudent();
	string chooseNumber;
	int operationMode = 0;
	CLEAR;
	display_operationChoose(name);
	while (cin >> chooseNumber) {
		if (chooseNumber == "1") {												//��λԤ��
			if (!judgeReserve()) {
				if (judgeSeatFull()) {
					MessageBox(NULL, TEXT("��λ������"), TEXT("����"), MB_OK);
				}
				else {
					operationMode = 0;
					computerReserve();
					break;
				}
			}
			else {
				MessageBox(NULL, TEXT("����Ԥ����λ��������Ԥ����λ��"), TEXT("����"), MB_OK);
			}
		}
		else if (chooseNumber == "2") {											//��λ�˶�
			if (judgeReserve()) {
				operationMode = 1;
				computerCancel();
				break;
			}
			else {
				MessageBox(NULL, TEXT("����δԤ����λ�������˶���λ��"), TEXT("����"), MB_OK);
			}
		}
		else {
			MessageBox(NULL, TEXT("����������������룡"), TEXT("����"), MB_OK);
		}
		CLEAR;
		display_operationChoose(name);
	}
	writeComputerMessage(operationMode);
}
//��λԤ��
void Student::computerReserve() {
	CLEAR;
	display_computerReserve();
	string chooseNumber;
	while (cin >> chooseNumber) {
		if (chooseNumber == "1") {															//�������
			systemChoose();
			break;
		}
		else if (chooseNumber == "2") {														//�Լ�ѡ��
			inputMessage();
			selfAllocation();
			break;
		}
		else {
			MessageBox(NULL, TEXT("����������������룡"), TEXT("����"), MB_OK);
		}
		CLEAR;
		display_computerReserve();
	}
}
//��λ�˶�
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
	int ret = MessageBox(NULL, TEXT("��ȷ��Ҫ�˶���"), TEXT("CHOOSE"), MB_YESNO | MB_ICONQUESTION);
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
		MessageBox(NULL, TEXT("�˶��ɹ���"), TEXT("�ɹ���"), MB_OK);
	}
	
	//����
}
//ϵͳѡ��
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
			MessageBox(NULL, TEXT("����������������룡"), TEXT("����"), MB_OK);
		}
		CLEAR;
		display_systemChoose();
	}
}
//����Ԥ����Ϣ
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
//д�������Ϣ
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
		MessageBox(NULL, TEXT("�ļ���ʧ�ܣ�"), TEXT("����"), MB_OK);
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
		MessageBox(NULL, TEXT("�ļ���ʧ�ܣ�"), TEXT("����"), MB_OK);
		return;
	}
	out << save;
}
//��������
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
	cout << "���������ڣ�����20190101��" << endl;
	while (cin >> dateString) {
		yearString.clear();
		monthString.clear();
		dayString.clear();
		if (dateString.length() != 8) {
			MessageBox(NULL, TEXT("���ڸ�ʽ�������������룡"), TEXT("����"), MB_OK);
			CLEAR;
			cout << "���������ڣ�����20190101��" << endl;
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
					MessageBox(NULL, TEXT("��������������������룡"), TEXT("����"), MB_OK);
				}
			}
			else {
				MessageBox(NULL, TEXT("�·�����������������룡"), TEXT("����"), MB_OK);
			}
		}
		else {
			MessageBox(NULL, TEXT("�������������������룡"), TEXT("����"), MB_OK);
		}
		CLEAR;
		cout << "���������ڣ�����20190101��" << endl;
	}
	date.year = yearString;
	date.month = monthString;
	date.day = dayString;
	return date;
}
//��������
Week Student::inputWeek() {
	Week week;
	string weekString;
	CLEAR;
	cout << "���������ڣ�����Monday��" << endl;
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
			MessageBox(NULL, TEXT("��������������������룡"), TEXT("����"), MB_OK);
		}
		CLEAR;
		cout << "���������ڣ�" << endl;
	}
	return week;
}
//����ʱ��
Time Student::inputTime() {
	Time time;
	string timeString;
	string hourString;
	string minuteString;
	int hour;
	int minute;
	CLEAR;
	cout << "������ʱ�䣺���磺00:00��" << endl;
	while (cin >> timeString) {
		hourString.clear();
		minuteString.clear();
		if (timeString.length() != 5) {
			MessageBox(NULL, TEXT("ʱ���ʽ�������������룡"), TEXT("����"), MB_OK);
			CLEAR;
			cout << "������ʱ�䣺" << endl;
			continue;
		}
		if (timeString[2] != ':') {
			MessageBox(NULL, TEXT("ʱ���ʽ�������������룡"), TEXT("����"), MB_OK);
			CLEAR;
			cout << "������ʱ�䣺" << endl;
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
				MessageBox(NULL, TEXT("���Ӹ�ʽ�������������룡"), TEXT("����"), MB_OK);
			}
		}
		else {
			MessageBox(NULL, TEXT("Сʱ��ʽ�������������룡"), TEXT("����"), MB_OK);
		}
	}
	return time;
}
//�������
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
		MessageBox(NULL, TEXT("��λ������"), TEXT("����"), MB_OK);
		return false;
	}
	//���û�з���ɹ������ص���һ����
}
//��������
bool Student::selfAllocation() {
	CLEAR;
	display_allSeat(0);
	int number;
	string numberString;
	bool judgeBreak = false;
	bool judgeRight = false;
	cout << "��ѡ����ҪԤ���Ļ�λ:" << endl;
	while (cin >> number) {
		numberString = intToString(number);
		judgeRight = false;
		list<Computer>::iterator it;
		for (it = computerList.begin(); it != computerList.end(); it++) {
			if ((*it).getComputerNumber() == numberString) {
				if (!(*it).getStudentName().empty()) {
					MessageBox(NULL, TEXT("�û�λ��Ԥ����������ѡ��"), TEXT("����"), MB_OK);
				}
				else {
					MessageBox(NULL, TEXT("Ԥ���ɹ���"), TEXT("�ɹ���"), MB_OK);
					judgeBreak = true;
				}
				judgeRight = true;
			}
		}
		if (!judgeRight) {
			MessageBox(NULL, TEXT("����������������룡"), TEXT("����"), MB_OK);
		}
		if (judgeBreak) {
			break;
		}
		CLEAR;
		display_allSeat(0);
		cout << "��ѡ����ҪԤ���Ļ�λ:" << endl;
	}
	_computer.setComputerNumber(numberString);
	_computer.setStudentName(_student.getName());
	return true;
}
//�жϻ�λ�Ƿ�ѡ��
bool Student::judgeSeatFull() {
	list<Computer>::iterator it;
	for (it = computerList.begin(); it != computerList.end(); it++) {
		if ((*it).getStudentName().empty()) {
			return false;
		}
	}
	return true;
}
//�ж�ѧ���Ƿ��Ѿ�Ԥ��
bool Student::judgeReserve() {
	list<Computer>::iterator it;
	for (it = computerList.begin(); it != computerList.end(); it++) {
		if ((*it).getStudentName() == _student.getName()) {
			return true;
		}
	}
	return false;
}
//����ѡ��
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
		MessageBox(NULL, TEXT("���ڶ�ȡ����"), TEXT("����"), MB_OK);
	}
	return week;
}
//ʱ��ѡ��
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
	MessageBox(NULL, TEXT("ʱ���ʽ����"), TEXT("����"), MB_OK);
	return time;
}
//����Ա����
void Manager::managerOperation(string name) {

}
//���������Ϣ
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
		MessageBox(NULL, TEXT("�ļ���ʧ�ܣ�"), TEXT("����"), MB_OK);
		return;
	}
	inFile.seekg(sizeof("���	ϵͳ		����		����	ʱ��	ѧ��"), ios::cur);
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
//��ӡ
void printOut() {
	list<Computer>::iterator i;
	
	for (i=computerList.begin(); i != computerList.end(); i++) {
		cout << (*i).getComputerNumber() << "--" << (*i).getComputerOSName() << endl;
	}
	cout << "===" << computerList.size() << endl;
}