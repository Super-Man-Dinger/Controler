#include"Display.h"

void display() {
	display_star();
	display_text();
	display_star();
}
void display_star() {
	for (int i = 0; i < 120; i++) {
		cout << "*";
	}
	cout << endl;
}
void display_text() {
	display_space();
	cout << "������λԤ��ϵͳ" << endl;
	display_space();
	cout << "�����������ϵͳ" << endl;
}
void display_space() {
	for (int i = 0; i < 50; i++) {
		cout << " ";
	}
}