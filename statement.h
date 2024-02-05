//声明全局变量和函数的区块
//用于供其它文件引用
#include<string>
#include<thread>
#include<vector>
#include"Thread.h"
#include"Player.h"
#include"Costomer.h"
#include"Restaurant.h"
#ifndef STATEMENT_H
#define STATEMENT_H
//字体颜色
extern std::string red;
extern std::string yellow;
extern std::string green;
extern std::string white;
extern std::string blue;
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
#endif