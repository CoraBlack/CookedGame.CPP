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
bool pausestate = 0;                    //游戏暂停状态
bool initalize_state = 0;               //默认初始化状态为否
bool autosave_state = 1;				//默认开启自动存档
unsigned int autosave_time = 300'000;	//默认自动存档时间五分钟

//顾客集合
std::vector<Customer*>customers
;
//菜肴
std::vector<cuisine>all_cuisine;			//全部菜肴
;
//关于多线程
std::mutex mtx_pause;
std::vector<Thread*>threads;
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
    thread initialize_td(Initialize);//创建一条线程用于处理初始化内容
    initialize_td.detach();//将初始化进程后台处理
    //开场文字（调试先屏蔽）
//确定运行环境
    cout << yellow << "Warning:\n" << white 
        << "本游戏仅能在Windows平台上运行，为确保彩字能够正常运行，请确保系统在Win10以上\n"
        <<"若您的Windows版本不满足需求，您可以按下[Tab]来屏蔽所有彩字，来确保游戏的正常运行\n"
        <<"若您的Windows版本能正常运行，请按下键盘上其它键以正常继续游戏\n";
//屏蔽彩字    
    if (_getch() == 9) {
        red = "";
        yellow = "";
        green = "";
        white = "";
        blue = "";
        std::cout << "彩字已屏蔽!";
        system("cls");
    }
    ;
    /*
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
void AllPause(){
//对全局锁上锁
    mtx_pause.lock();
//对子线程上锁
    if (!threads.empty()) {
        for (int i = 0; i < threads.size();) {
            threads[i]->mtx.lock();
            i++;
        }
    }
//通告暂停
    std::cout << yellow << "\n游戏已经暂停\n" << white;
//等待解锁(每0.1s检测一次)
    while (pausestate) { Sleep(100); }
//暂停取消后越过循环
//解锁子线程锁
    if (!threads.empty()) {
        for (int i = 0; i < threads.size();) {
            threads[i]->mtx.unlock();
            i++;
        }
    }
//全局锁解锁
    mtx_pause.unlock();
    std::cout << yellow << "游戏已回复\n" << white;
    return;
}
;
void SettingMenu() {
    std::cout << yellow << "尚未开发" << white;
    system("pause");
    return;
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
//生成顾客
void CreateCustomer() {
//生成对象的循环
    while (restaurant->GetOpenState()) {
    //随机三十秒到两分钟创建一个顾客
        Sleep(Random(30'000, 120'000));
    //检测状态是否继续创建
        if (restaurant->GetOpenState()) {
            Customer* newcus = nullptr;
            newcus = new Customer;
            continue;
        }
    //不再创建顾客
        //等待顾客清空
        while (!customers.empty()) { }
        break;
    }
}