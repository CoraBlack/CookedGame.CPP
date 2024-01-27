//声明全局变量和函数的区块
//用于供其它文件引用
#include<string>
#ifndef STATEMENT_H
#define STATEMENT_H
//字体颜色
extern std::string red;
extern std::string yellow;
extern std::string green;
extern std::string white;
//函数声明
void PauseMenu();//暂停界面
void SettingMenu();//游戏设置菜单
void GameStart();
void NewGame();//新游戏
void PrintVerbatim(std::string str);//逐字打印
void Initialize();	//初始化
#endif