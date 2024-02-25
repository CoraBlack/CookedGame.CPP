//声明全局变量和函数的区块
//用于供其它文件引用

#ifndef STATEMENT_H
#define STATEMENT_H
//头文件
#include"conio.h"
#include"Customer.h"
#include "IngredientMarketUI.h"
#include"Player.h"
#include"Restaurant.h"
#include"RestaurantUI.h"
#include"Thread.h"
#include<fstream>
#include<iostream>
#include<mutex>
#include<random>
#include<sstream>
#include<string>
#include<thread>
#include<vector>
#include<Windows.h>
//宏定义换行操作
#define Back "\n"
#define Endl std::endl
;
//字体颜色
extern std::string red;
extern std::string yellow;
extern std::string green;
extern std::string white;
extern std::string blue;
;
//顾客
extern std::vector<Customer*>customers;	//管理顾客的顾客集
void CreateCustomer();					//生成顾客
void DeleteCustomer(Customer* cusptr);	//销毁顾客
//全局变量声明
extern bool pausestate;					//游戏暂停状态(1为暂停)
extern bool initalize_state;			//是否已完成初始化
extern std::string save_name;			//存档名称
extern bool autosave_state;				//是否开启自动保存(0为关闭，1为开启)
extern unsigned int autosave_time;		//自动存档时间
extern const char* checkword;			//验证标识符
extern const char* checksetting;		//设置文件检查符
extern const char* version;				//版本号符
;
//变量声明(关于多线程)
extern Thread* createtrd;				//用于创建顾客新对象的专用线程对象
extern std::vector<Thread*>threads;		//线程集（用于管理子线程）
extern std::mutex* mtx_pause;			//用于全局暂停的线程锁
extern std::mutex* mtx_save;			//用于防止存档保存冲突锁
extern std::mutex* mtx_autosave;		//用于防止自动保存反复开启的保护锁
;
//函数声明
void LaunchAutoSave();					//启动自动保存
void PauseGame();						//全局暂停
void ResumeGame();						//恢复游戏
void SettingMenu();						//游戏设置菜单
bool CheckSave();						//存档验证
void SaveGameAll();						//全局存档
void ReadSaveAll();						//读取存档
void Initialize();						//初始化
void ThreadTest();						//线程管理测试
void Test();							//测试通道
//内联函数的定义
//逐字打印
inline void PrintVerbatim(std::string str) {
	for (int i = 0; i < str.size();) {
		std::cout << str[i];
		Sleep(80);
		i++;
	}
	std::cout << Back;
	return;
}
;
//随机数
inline int Random(int min, int max) { 
	std::random_device seed;								//随机数种子驱动
	std::default_random_engine rd_eg(seed());				//绑定了seed种子的随机数引擎
	std::uniform_int_distribution <int> rand_num(min, max);	//int初始化distribution对象
	int num = rand_num(rd_eg);								//将使用rd_eg引擎的int的初始化对象赋值给num
	return num; 
}
;
//伪加载(输入时间为0.1秒)
inline void Loading(float times) {
	for (int i = 0; i < times; i++){
		std::cout << "<";
	}
	std::cout << Back;
	return;
}
/*(存档用)*/
//数字转字符
inline std::string NumToString(int num/*整形重载*/) {
	std::stringstream ss;
	std::string str;
	ss << num;
	ss >> str;
	return str;
}
inline std::string NumToString(double num/*浮点重载*/) {
	std::stringstream ss;
	std::string str;
	ss << num;
	ss >> str;
	return str;
}
//字符转数字
inline int StringToInt(char ch) {
	int num = 0;
	std::stringstream ss;
	ss << ch;
	ss >> num;
	return num;
}
inline int StringToInt(std::string str) {
	int num = 0;
	std::stringstream ss;
	ss << str;
	ss >> num;
	return num;
}
inline float StringToFloat(std::string str) {
	float num = 0.0f;
	std::stringstream ss;
	ss << str;
	ss >> num;
	return num;
}
//获取指定行内容
inline std::string GetFileLine(int line/*指定行列*/, std::string file/*文件名*/) {
	std::ifstream ifs;
	std::string str;
	ifs.open(file.c_str(), std::ios::in);
	if (!ifs.is_open()) {
		std::cerr << red << "Error:failed to open file!" << white;
		ifs.close();
		ifs.clear();
		return "wrong!";
	}
	for (int i = 0; i < line;) {
		getline(ifs, str);
		i++;
	}
	ifs.close();
	ifs.clear();
	return str;
}
#endif