//������Ϸ�Ļ�������
#include"statement.h"
#include<iostream>
#include<Windows.h>
#include"conio.h"
std::string red = "\033[31m";
std::string green = "\033[32m";
std::string yellow = "\033[33m";
std::string white = "\033[0m";
;
void PrintVerbatim(std::string str) {
	for (int i = 0; i < str.size();) {
		std::cout << str[i];
		Sleep(100);
		i++;
	}
	std::cout << std::endl;
	return;
}
;
void PauseMenu() {
	std::cout << "[Esc]����\n[Tab]����\n[Back]�˳���Ϸ\n";
	while (1){
		int input = _getch();
		switch (input) {
		case 9://Tab

			break;
		case 27://Esc

			break;
		case 8://Back

			break;
		default:
			break;
		}
	}
}
;
void SettingMenu() {
	
}
;
void GameStart() {
	std::cout << yellow << "Cooked��" << std::endl;
	std::cout << green << "[Tab]����Ϸ\n[Space]��ȡ��Ϸ\n[Esc]����" << white << std::endl;
	while (1) {
		int input = _getch();//��ȡ��������
		//�����ã��鿴����ֵ��
		std::cout << input << std::endl;
		switch (input) {
		case 9://Tab
			system("cls");
			std::cout << yellow << "�������Ҫ����һ������Ϸ��?\n" << green << "[Tab]ȷ����������Ϸ\n[Esc]ȡ������" << std::endl;
			input = 0;//��������ֵ
			while (1){
				input = _getch();
				switch (input) {
				case 9://Tab
					return NewGame();
					break;
				case 27://Esc
					input = 0;
					system("cls");
					return GameStart();
					break;
				default:
					break;
				}
			}
			break;
		case 32://Space

			break;
		case 27://Esc

			break;
		default:
			break;
		}
	}
}
;
void NewGame() {

}
;
void Initialize() {
	Sleep(5000);
	//std::cout << green << "Finish to initialize!";
	return;
}