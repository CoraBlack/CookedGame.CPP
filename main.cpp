//主函数
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
Thread* createtrd = nullptr;			    //用于创建顾客新对象的专用线程对象
std::mutex* mtx_pause = nullptr;            //初始化线程锁
std::mutex* mtx_save = nullptr;
std::vector<Thread*>threads;                //线程组
//存档名称
std::string save_name = "";
//用于检测文件为存档文件的标识符
const char* checkword = "CheckSave114514";
const char* checksetting = "CookedSetting";
const char* version = "0.62";
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
    //后台初始化

    thread initialize_td(Initialize);   //创建一条线程用于处理初始化内容
    initialize_td.detach();             //将初始化进程后台处理
    {
        //获取设置文件中信息
        std::string settingpath = "C:/Users/Public/Documents/CookedSetting.txt";
        std::ifstream ifs(settingpath);
        ifs.open(settingpath);
        //设置文件不存在新建
        if (!ifs.is_open()) {
            std::ofstream newfile(settingpath);
            newfile.open(settingpath);
            newfile << autosave_state;
            newfile << autosave_time;
            newfile.close();
            newfile.clear();
        }
        //文件存在，读取设置文件
        else {
            autosave_state = (bool)StringToInt(GetFileLine(2, settingpath));        //读取自动存档状态
        }
        ifs.close();
        ifs.clear();    //清除文件流状态
    }
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
    //主流程入口函数(流程托管)
    MainGui* main_weight = new MainGui;
    main_weight->GameStart();
    // 
    // 
    // 
    // 
    //交接测试通道
    //Test();
//销毁对象
    delete player;
    delete restaurant;
    delete res_weight;
    delete market_weight;
    return 0;
}





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
    /*
    //测试键盘输入
    while (1) {
        cout << _getch() << "\n";
    }
    */
    ;
    /*
    //测试存档功能
    cout << "input\n";
    cin >> save_name;
    save_name += ".txt";
    SaveGameAll();
    */
    ;
    /*
    //测试字符串流
    float fl = StringToFloat("3.1415");
    string str = NumToString(3.1415f);
    */
    ;
    //测试读档
    save_name = "save.txt";
    ReadSaveAll();
    system("pause");
}
;
void PauseGame(){
//对全局锁上锁
    //分配内存
    mtx_pause = nullptr;
    mtx_pause = new std::mutex;
    if (mtx_pause->try_lock()) {
        //上锁成功，通告暂停
        pausestate = 1;
        std::cout << yellow << "Message:游戏已经暂停\n" << white;
    }
    else {
        //失败
        std::cerr << yellow << "Warning:游戏暂停失败，可能游戏已经暂停\n" << white;
    }
    return;
}
;
void ResumeGame() {
//锁已经锁上
    if (!mtx_pause->try_lock()) {
        mtx_pause->unlock();
        pausestate = 0;
        std::cout << yellow << "Message:游戏以恢复\n" << white;
    }
    //失败
    else {
        std::cerr << yellow << "Warning:游戏似乎已经解除暂停，现在尝试重新解除暂停\n" << white;
        mtx_pause->unlock();
        pausestate = 0;
    }
//释放内存并初始化
    delete mtx_pause;
    mtx_pause = nullptr;
    return;
}
;
void SettingMenu() {
    std::cout << yellow << "尚未开发" << white;
    system("pause");
    return;
}
;
void SaveGameAll() {
    //检查锁是否已经存在
    if (mtx_save != nullptr) {
        while (mtx_save != nullptr) {
            Sleep(100);
        }
    }
    mtx_save = nullptr;
    mtx_save = new std::mutex;

    //开始保存
    std::fstream fs;                                    //输入文件操作流
    fs.open(save_name,std::ios::in);                    //检测存档文件是否存在

    //无法打开文件
    if (!fs.is_open()) {
        std::cerr << red << "Save Error:存档打开失败或存档文件不存在！" << white;
        fs.close();
        fs.clear();                                     //重置文件流
        return;                                         //提前退出函数
    }

    //临时量
    std::string* str_temp = nullptr;                    
    str_temp = new std::string;
    fs >> *str_temp;

    //目标文件不是存档文件
    if (*str_temp != checkword) {
        std::cerr << red << "Save Error:目标文件不是存档文件!\n" << white;
        fs.close();
        fs.clear();                                     //重置文件流
        delete str_temp;
        str_temp = nullptr;                             //清理临时量
        return;
    }
    
    *str_temp = GetFileLine(2, save_name);              //获取版本号
    if (*str_temp == "wrong") {
        fs.close();
        fs.clear();
        delete str_temp;
        str_temp = nullptr;
        return;
    }

    //目标文件版本与当前游戏版本不一
    if (*str_temp != version) {
        std::cout << yellow << "Save Warning:存档版本和游戏版本不符，正在覆盖当前存档\n" << white;
    }
    else {
    //检查版本时无法打开文件
        std::cerr << red << "Save Error:无法正常打开文件" << white;
        fs.close();
        fs.clear();                                     //重置文件流
        delete str_temp;
        str_temp = nullptr;                             //清理临时量
        return;
    }
    fs.close();
    fs.clear();                                         //重置文件流
    delete str_temp;
    str_temp = nullptr;                                 //清理临时量

    fs = std::fstream(save_name);
    fs.open(save_name, std::ios::trunc, std::ios::out); //使用turnc模式清除全部内容，out模式写入内容

    //存档在写入时无法打开
    if (!fs.is_open()) {
        std::cerr << red << "Save Error:存档打开失败！无法正常进行存档操作！" << white;
        fs.close();
        fs.clear();                                     //重置文件流
        return;                                         //提前退出
    }

    //全局标识
    fs << checkword;                                    //写入验证字符
    fs << version;                                      //写入版本号

    //Player
    fs << "PlayerName";                                 //玩家名称阶段符
    fs << player->GetPlayerName();                      //存入玩家名称
    fs << "PlayerMoney";                                //玩家存款标识符
    fs << player->GetPlayerMoney();                     //存入玩家存款
    fs << "Plot";                                       //剧情通关数标识符
    fs << (int)player->GetPlayerPlot();                 //存入剧情通关数

    //Restaurant
    fs << "RestaurantTurnover";                         //餐厅营业额标识符
    fs << restaurant->GetTurnover();                    //存入餐厅营业额
    fs << "RestaurantLevel";                            //餐厅等级标识符
    fs << (int)restaurant->GetLevel();                  //存入餐厅等级
    fs << "IceBoxMax";                                  //餐厅冰箱最大存量标识符
    fs << (int)restaurant->GetIceBoxMax();              //存入冰箱最大存量

    //IceBox
    fs << "IceBox";                                     //冰箱标识符
    

    fs << "End";                                        //结束符
    fs.close();
    fs.clear();
    delete mtx_save;
    mtx_save = nullptr;
    return;
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
        //Sleep(Random(30'000, 120'000));
        for (int i = 0; i < Random(300, 1200);) {
            Sleep(100);
        //检测开门状态
            if (!restaurant->GetOpenState()) {
            //关门了提前停止
                return;
            }
        //检测暂停状态
            if (pausestate) {
            //堵塞
                mtx_pause->lock();
                mtx_pause->unlock();
            }
            i++;
        }
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

void DeleteCustomer(Customer* cusptr/*销毁的对象*/) {
    //查找自身在向量中的位置
    for (int i = 0; i < customers.size();) {
        if (cusptr == customers[i]) {
            //移出
            customers.erase(customers.begin() + i);
            break;
        }
        i++;
    }
    //销毁顾客对象的后台线程
    delete cusptr;
    //防止悬空
    cusptr = nullptr;
    return;
}
bool CheckSave() {
    //验证存档是否已输入
    if (save_name == "") {
        std::cout << red << "存档信息为空！\n" << white;
        return 0;
    }

    std::ifstream ifs(save_name);       //文件流
    std::string str;                    //暂存值

    //尝试打开
    ifs.open(save_name, std::ios::in);
    if (!ifs.is_open()) {
        std:cout << red << "Read Error:无法打开存档文件!\n" << white;
        ifs.close();
        ifs.clear();
        return 0;
    }

    //验证字符
    str = GetFileLine(1, save_name);
    if (str != checkword) {
        std::cout << red << "Read Error:目标文件不是存档文件!\n" << white;
        ifs.close();
        ifs.clear();
        return 0;
    }

    //验证版本号
    str = GetFileLine(2, save_name);
    if (str != version) {
        std::cout << "Warning:目标文件版本不一，正在尝试写入……\n" << white;
    }
    return 1;
}


void ReadSaveAll() {
    int line = 3;               //获取行数记录，从第三行开始获取（前两行为验证）
    std::string str = "";       //暂存文件字符
    while (1) {

        str = GetFileLine(line, save_name);

        //存入名称
        if (str == "PlayerName") {
            line++;
            player->SetPlayerName(GetFileLine(line, save_name));        //存入玩家名
            continue;
        }

        //存入玩家钱财
        if (str == "PlayerMoney") {
            line++;
            player->SetPlayerMoney(StringToFloat(GetFileLine(line, save_name)));
            continue;
        }

        //存入剧情通关数
        if (str == "Plot") {
            line++;
            player->SetPlayerPlot(StringToInt(GetFileLine(line, save_name)));
            continue;
        }

        //餐厅营业额
        if (str == "RestaurantTurnover") {
            line++;
            restaurant->SetTurnover(StringToFloat(GetFileLine(line, save_name)));
            continue;
        }

        //餐厅等级
        if (str == "RestaurantLevel") {
            line++;
            restaurant->SetLevel(StringToInt(GetFileLine(line, save_name)));
            continue;
        }

        //冰箱最大容量
        if (str == "IceBoxMax") {
            line++;
            restaurant->SetIceBoxMax(StringToInt(GetFileLine(line, save_name)));
            continue;
        }

        //冰箱食材
        if (str == "IceBox") {
            line++;

            continue;
        }

        //结束符
        /*哼，早就知道某些人玩这个东西肯定会改存档数据，把朕的End标识符删掉，我直接限死10000行[doge]*/
        if (str == "End" || line >= 10000) {
            break;
        }
        //均不成立下一行继续
        line++;
    }
    
    return;
}