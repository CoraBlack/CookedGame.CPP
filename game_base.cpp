//定义游戏的基础函数
#include"statement.h"
#include<iostream>
#include<Windows.h>
std::string red = "\033[31m";
std::string green = "\033[32m";
std::string yellow = "\033[33m";
std::string white = "\033[0m";
void PrintVerbatim(std::string str) {
	for (int i = 0; i < str.size();) {
		std::cout << str[i];
		Sleep(100);
		i++;
	}
	std::cout << std::endl;
	return;
}
void GameStart() {

}
void Initialize() {
	Sleep(5000);
	//std::cout << green << "Finish to initialize!";
	return;
}