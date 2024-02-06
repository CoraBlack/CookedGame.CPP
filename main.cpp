//主函数
#include <iostream>
#include"statement.h"
#include<Windows.h>
#include<thread>
using namespace std;
//字体颜色
std::string red = "\033[31m";
std::string green = "\033[32m";
std::string yellow = "\033[33m";
std::string white = "\033[0m";
std::string blue = "\033[36m";
;
//statement.h中全局变量的定义区（防止链接器错误）
bool initalize_state = 0;               //默认初始化状态为否
bool autosave_state = 1;				//默认开启自动存档
unsigned int autosave_time = 300'000;	//默认自动存档时间五分钟

//顾客集合
std::vector<Customer*>customers
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
//对象实例化区
Player* player = new Player();
Restaurant* restaurant = new Restaurant();
RestaurantUI* res_weight = new RestaurantUI();
IngredientMarketUI* market_weight = new IngredientMarketUI();
;
;
;
//主函数
int main(){
<<<<<<< HEAD
    thread initialize_td(Initialize);//创建一条线程用于处理初始化内容
    initialize_td.detach();//将初始化进程后台处理
    /*
    //Class对象
    Player* player;
    Restaurant* restaurant;
    Customer* customer;
    RestaurantUI* res_weight;
    IngredientMarketUI* market_weight;
    */
 //实例化对象
    
    ;
=======
    thread initialize(Initialize);//创建一条线程用于处理初始化内容
    initialize.detach();//将初始化进程后台处理

>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
    //开场文字（调试先屏蔽）
    /*
    cout << yellow << "Warning：\n" << white << "本游戏仅能在Windows平台上运行，且版本不低于Win10，望周知！\n";
    system("pause");
    ;
    PrintVerbatim("Hello,Dear Player!\nI am so proud of that you can play my game");
    PrintVerbatim("允许我介绍一边自己：\nCoca Cora");
    Sleep(1000);
    PrintVerbatim("and my good friend AF!!!!!!!!\nWell have a good time!!!");
    system("pause");
    system("cls");
    */
    ;
    //主流程入口函数(流程托管)
    MainGui* main_weight = new MainGui;
    main_weight->GameStart();
    // 
    // 
    // 
    // 
    //交接测试通道
    //Test();
    return 0;
}
;
;
;
//全局函数定义区
//测试通道
void Test() {
    //方便测试才敲得
    using namespace std;

    //测试随机数引擎
   //cout << Random(1, 100);
    ;
    /*
    Costomer* cos1 = new Costomer;
    costomers.push_back(cos1);
    cout << costomers.size() << "\n";
    delete cos1;
    cout << costomers.size();
    system("pause");
    */
    ;
    //测试键盘输入
    while (1) {
        cout << _getch() << "\n";
    }
}
;
void PauseMenu() {
//打印操作列表
    std::cout << green << "[Esc]返回\n[Tab]设置\n[Back]退出游戏\n";
    while (1) {
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



void AutoSave(bool mode /* 手动存档(0) 还是 自动存档(1) */) {
    //自动存档模式
    if (mode) {
        //是否开启自动存档
        if (autosave_state) {
            //休眠，等待存档
            Sleep(autosave_time);

        }
    }
    //手动存档
    //存档主体流程（共用）
}
;
void Initialize() {
    //设置初始化状态
    initalize_state = 1;
    //测试用文字
    Sleep(1000);

    //std::cout << green << "Finish to initialize!" << white;
    return;
}
;
void ThreadTest() {

}
;