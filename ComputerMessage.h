#pragma once
#include"Display.h"

#define COMPUTER_NUMBER 100
//#define FILENAME "ComputerMessage.txt"

enum OS {
	Windows7=0,
	Linux,
	Windows7_Linux,
};
enum Week {
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
};
typedef struct date {
	string year;
	string month;
	string day;
}Date;
typedef struct time {
	string hour;
	string minute;
	string timeString;
}Time;
void setComputerMessage();
class Computer {
public:
	Computer();
	void setComputerNumber(string computerNumber) {
		_computerNumber = computerNumber;
	}
	void setOSName(OS OSName) {
		_OSName = OSName;
	}
	void setDate(Date date) {
		_date = date;
	}
	void setTime(Time time) {
		_time = time;
	}
	void setWeek(Week week) {
		_week = week;
	}
	void setStudentName(string studentName) {
		_studentName = studentName;
	}
	string getComputerNumber() {
		return _computerNumber;
	}
	OS getComputerOSName() {
		return _OSName;
	}
	Week getWeek() {
		return _week;
	}
	string getStudentName() {
		return _studentName;
	}
private:
	Date _date;
	Time _time;
	Week _week;
	string _computerNumber;
	OS _OSName;
	string _studentName;
};
