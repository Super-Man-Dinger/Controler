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
	cout << "机房机位预定系统" << endl;
	display_space();
	cout << "按任意键进入系统" << endl;
}
void display_space() {
	for (int i = 0; i < 50; i++) {
		cout << " ";
	}
}