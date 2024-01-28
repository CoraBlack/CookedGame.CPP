﻿//定义游戏的基础函数
#include"statement.h"
#include<iostream>
#include<Windows.h>
#include"conio.h"
#include"Restaurant.h"
#include"Player.h"
#include<fstream>
std::string red = "\033[31m";
std::string green = "\033[32m";
std::string yellow = "\033[33m";
std::string white = "\033[0m";
;
//Class实例化
Restaurant myres;
Player player;
;
//存档名称
std::string save_name = "";
const char* checkword = "CheckSave114514";//用于检测文件为存档文件的标识符
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
		//std::cout << input << std::endl;
		switch (input) {
		case 9://Tab
			system("cls");
			std::cout << yellow << "你真的需要创建一个新游戏吗?\n" << green << "[Tab]确定创建新游戏\n[Esc]取消创建" << std::endl;
			input = 0;//重置输入值
			while (1){
				input = _getch();
				switch (input) {
				case 9://Tab
					system("cls");
					return CreateNewSave();
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
			return ReadSaveFlie();
			break;
		case 27://Esc

			break;
		default:
			break;
		}
	}
}
;
void CreateNewSave(){
	//输入新存档名称
	std::cout << yellow << "输入新的存档名称:" << green << std::endl;
	getline(std::cin, save_name);
	//防止输入内容为空
	if (save_name == "") {
		std::cerr << "存档名称不能为空！！！" << white << std::endl;
		Sleep(2000);
		return CreateNewSave();
	}
	//补全文件格式
	save_name += ".txt";
	//检查是否已存在该存档
	std::fstream check;
	check.open(save_name, std::ios::trunc);
	if (check.is_open()) {
		//检测到重名文件(有bug目前)
		std::cerr << yellow << "Warning:检测到存档文件已存在，是否继续创建？" << white << "[Space]继续\n[Esc]返回\n";
		int input = 0;
		//输入为Space时继续
		do {
			input = _getch();
			if (input == 27) {
				//输入ESC时重新创建
				check.close();
				check.clear();
				return GameStart();
			}
		} while (input != 32);
	}
	else {
		//继续创建
		std::ofstream newsave;
		newsave.open(save_name, std::ios::out);
		if (!newsave.is_open()) {
			std::cerr << red << "Wrong!文件无法创建,即将返回开始菜单\n" << white;
			Sleep(3000);
		}
		else {
			//写入验证字符
			newsave << checkword;
			std::cout << green << "创建了新的存档" << yellow << save_name << std::endl << white;
			newsave.close();
			newsave.clear();
			system("pause");
		}
		return NewGame();
	}
}
;
void ReadSaveFlie(){
	//输入文件名称
	std::cout << yellow << "请输入您的存档名称" << std::endl;
	getline(std::cin, save_name);
	save_name += ".txt";
	//获取文件内容输入流
	std::ifstream getfile;
	getfile.open(save_name, std::ios::in);
	std::string check_temp;//用于存储文件第一行字符的临时变量
	getfile >> check_temp;
	//验证标识符
	if (check_temp == checkword) {
		std::cout << yellow << "正在读取数据，存档名" << green << save_name <<white << std::endl;

	}else {
		std::cerr << red << "检测不到存档文件关键字，为保护游戏运行正常，将返回游戏主界面" << white << std::endl;
		save_name = "";//重置

	}
	return;
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

void CreateMainGui(){
	for (int i = 0; i < 60;) {
		std::cout << "_";
		i++;
	}
	std::cout << std::endl;
	for (int i = 0; i < 28;) {
		std::cout << "|";
		for (int j = 0; j < 58;) {
			std::cout << " ";
			j++;
		}
		std::cout << "|" << std::endl;
		i++;
	}
	for (int i = 0; i < 60;) {
		std::cout << "_";
		i++;
	}
}
