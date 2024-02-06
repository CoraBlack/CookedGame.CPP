//声明全局变量和函数的区块
//用于供其它文件引用
#include<iostream>
#include<string>
#include<thread>
#include<vector>
<<<<<<< HEAD
#include<random>//随机数引擎
#include<Windows.h>
#include"conio.h"
#include"Thread.h"
#include"Player.h"
#include"Customer.h"
#include"Restaurant.h"
#include"RestaurantUI.h"
#include "IngredientMarketUI.h"
=======
#include"Thread.h"
#include"Player.h"
#include"Costomer.h"
#include"Restaurant.h"
>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
#ifndef STATEMENT_H
#define STATEMENT_H
#define Back "\n"		//宏定义换行操作
;
//字体颜色
extern std::string red;
extern std::string yellow;
extern std::string green;
extern std::string white;
extern std::string blue;
<<<<<<< HEAD
;

//顾客集合
extern std::vector<Customer*>customers;
//全局变量声明
extern bool initalize_state;			//是否已完成初始化
extern std::string save_name;			//存档名称
extern bool autosave_state;				//是否开启自动保存(0为关闭，1为开启)
extern unsigned int autosave_time;		//自动存档时间
extern const char* checkword;			//验证标识符
;
//结构体定义

=======
//Class对象
extern Player *player;
extern Restaurant *restaurant;
extern Costomer *costomer;
//结构体定义
//食材
struct ingredient {
	std::string name;
	int price;				//价格
	int possession;			//拥有量
};
;
extern std::vector<ingredient>shopping_cart;	//食材购物车
extern std::vector<ingredient>vegetable;		//蔬菜类食材
extern std::vector<ingredient>meat;				//肉类食材
extern std::vector <std::vector<ingredient>>all_ingredient;	//全部食材
;
>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
//菜肴
struct cuisine {
	std::string name;
	int price;				//价格
};
extern std::vector<cuisine>all_cuisine;			//全部菜肴
;
//变量声明
extern std::vector<Thread>threads;				//线程集（用于管理子线程）
;
//函数声明
<<<<<<< HEAD

void PauseMenu();					//暂停界面
void SettingMenu();					//游戏设置菜单
void AutoSave(bool mode);			//自动存档
void Initialize();					//初始化
void ThreadTest();					//线程管理测试
void Test();						//测试通道
//内联函数的定义
//逐字打印
inline void PrintVerbatim(std::string str) {
	for (int i = 0; i < str.size();) {
		std::cout << str[i];
		Sleep(100);
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
	return num; }
=======
int Random(int min, int max);		//随机数
void PauseMenu();					//暂停界面
void SettingMenu();					//游戏设置菜单
void GameStart();					//游戏开始主菜单
void CreateNewSave();				//新建存档
void ReadSaveFlie();				//读取存档
void NewGame();						//新游戏
void OpenResMenu();					//营业时对餐厅的操作
void CloseResMenu();				//暂停营业餐厅操作界面
void IngredientMarket();			//食材市场
void PrintVerbatim(std::string str);//逐字打印
void Initialize();					//初始化
void CreateMainGui();				//主要UI操作界面
void ThreadTest();					//线程管理测试
>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
#endif