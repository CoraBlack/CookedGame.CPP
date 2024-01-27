//定义游戏的基础函数
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
	std::cout << "[Esc]返回\n[Tab]设置\n[Back]退出游戏\n";
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
	std::cout << yellow << "Cooked！" << std::endl;
	std::cout << green << "[Tab]新游戏\n[Space]读取游戏\n[Esc]设置" << white << std::endl;
	while (1) {
		int input = _getch();//获取键盘输入
		//测试用（查看输入值）
		std::cout << input << std::endl;
		switch (input) {
		case 9://Tab
			system("cls");
			std::cout << yellow << "你真的需要创建一个新游戏吗?\n" << green << "[Tab]确定创建新游戏\n[Esc]取消创建" << std::endl;
			input = 0;//重置输入值
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