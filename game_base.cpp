//定义游戏的基础函数
#include"statement.h"
#include<iostream>
#include<Windows.h>
#include"conio.h"
#include<fstream>
//字体颜色
std::string red = "\033[31m";
std::string green = "\033[32m";
std::string yellow = "\033[33m";
std::string white = "\033[0m";
std::string blue = "\033[36m";
;
//statement.h中全局变量的定义区（防止链接器错误）
//Class对象
Player* player;
Restaurant* restaurant;
Costomer* costomer;
;
//食材
std::vector<ingredient>shopping_cart;	//食材购物车
std::vector<ingredient>vegetable;		//蔬菜类食材
std::vector<ingredient>meat;				//肉类食材
std::vector <std::vector<ingredient>>all_ingredient;	//全部食材
;
//菜肴
std::vector<cuisine>all_cuisine;			//全部菜肴
;
//线程组
std::vector<Thread>threads;
//存档名称
std::string save_name = "";
//用于检测文件为存档文件的标识符
const char* checkword = "CheckSave114514";
int (*fucptr) ();
;
//函数定义区
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
int Random(int min, int max){
	int num = rand() % max - min;
	return num;
}
;
void PauseMenu() {
	std::cout << green << "[Esc]返回\n[Tab]设置\n[Back]退出游戏\n";
	while (1){
		int input = _getch();
		switch (input) {
		case 9://Tab
			return;
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
	system("cls");
	//输出内容
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
			system("cls");
			PauseMenu();
			break;
		default:
			break;
		}
	}
}
;
void CreateNewSave(){
	//输入新存档名称
	std::cout << yellow << "输入新的存档名称:" << white << std::endl;
	getline(std::cin, save_name);
	//防止输入内容为空
	if (save_name == "") {
		system("cls");
		std::cerr << red << "存档名称不能为空！！！" << white << std::endl;
		return CreateNewSave();
	}else if (save_name == "Exit") {//禁用Exit作为存档名
		system("cls");
		std::cerr << red << "程序中借用了Exit作为程序操作字符，不可使用该字符作为存档名" << white << std::endl;
		save_name = "";
		return CreateNewSave();
	}
	//补全文件格式
	save_name += ".txt";
	//检查是否已存在该存档
	std::fstream savefile(save_name);
	if (savefile.good()) {
		//检测到重名文件(有bug目前)
		std::cerr << yellow << "Warning:检测到存档文件已存在，是否继续创建？\n" << white << green << "[Space]继续\n[Esc]返回\n" << white;
		int input = 0;
		//输入为Space时继续
		do {
			input = _getch();
			if (input == 27) {
				//输入ESC时重新创建
				system("cls");
				return GameStart();
			}
		} while (input != 32);//强制创建同名文件
	}
		//继续创建
		std::ofstream newsave;
		newsave.open(save_name, std::ios::out);
		if (!newsave.is_open()) {
			std::cerr << red << "Wrong!文件无法创建(无法打开文件),即将返回开始菜单\n" << white;
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
;
void ReadSaveFlie(){
	//输入文件名称
	system("cls");
	std::cout << yellow << "请输入您的存档名称(输入Exit退出输入)" << white <<std::endl;
	getline(std::cin, save_name);
	if (save_name == "") {//防止为空
		system("cls");
		std::cerr << red << "存档名称不能为空！！！" << white << std::endl;
		return ReadSaveFlie();
	}else if (save_name == "Exit"){//输入Exit时
		system("cls");
		return GameStart();
	}
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
		return GameStart();
	}
	;
	;
	//读档过程


	//进入游戏
	std::cout << green << "存档读取完毕" << white;
	system("pause");
	system("cls");
	return CloseResMenu();
}
;
void NewGame() {
	return CloseResMenu();
}
;
void OpenResMenu(){

}
;
void CloseResMenu(){
	system("cls");
	std::cout << yellow <<  "您接下来要做什么?[您的餐馆处于" << blue << "关门" << yellow << "状态]" << std::endl;
	std::cout << green << "[Tab]开店\n[1]食材市场\n[2]店面布设\n" << white << std::endl;
	//选项
	while (1) {
		int input = _getch();
		switch (input) {
		case 9://Tab
			restaurant->SetOpenState(1);
			return OpenResMenu();
			break;
		case 49://1
			return IngredientMarket();
			break;
		case 50://2

			break;
		default:
			break;
		}
	}
}
;
void IngredientMarket(){
	std::cout << blue << "Welcome to Ingredient Market!" << std::endl;
	std::cout << yellow << "[Esc]返回小餐馆(记得付款喔!)\n[Tab]结账\n[Space]购物车\n" << green << "[1]蔬菜\n[2]肉类\n[3]蛋奶制品\n[4]调味品\n";
	while (1) {
		int input = _getch();
		switch (input){
		case 9://Tab

			break;
		case 27://Esc
			//检查购物车是否为空
			if (shopping_cart.empty()) {
				return CloseResMenu();
			}
			else {
				//购物车不为空
				system("cls");
				std::cout << yellow << "您的购物车还有未付款的食材商品！\n";
				return IngredientMarket();
			}
			break;
		default:
			break;
		}
	}
	return;
}
;
void Initialize() {
	//实例化对象
	Player *player = new Player();
	Restaurant *restaurant = new Restaurant;
	Costomer *costomer = new Costomer;
	//std::cout << green << "Finish to initialize!";
	return;
}
;
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
;
void ThreadTest(){
	
}

