//主函数
#include"statement.h"
#include<thread>
#include<Windows.h>

//字体颜色
std::string red = "\033[31m";
std::string green = "\033[32m";
std::string yellow = "\033[33m";
std::string white = "\033[0m";
std::string blue = "\033[36m";

//statement.h中全局变量的定义区（防止链接器错误）
bool pausestate = 0;                    //游戏暂停状态
bool initalize_state = 0;               //默认初始化状态为否
bool autosave_state = 1;				//默认开启自动存档
unsigned int autosave_time = 300'000;	//默认自动存档时间五分钟

//顾客集合
std::vector<Customer*>customers;

//菜肴
std::vector<cuisine>all_cuisine;			//全部菜肴

//关于多线程
Thread* createtrd = nullptr;			    //用于创建顾客新对象的专用线程对象
std::mutex* mtx_pause = nullptr;            //初始化线程锁
std::mutex* mtx_autosave = nullptr;		    //用于防止自动保存反复开启的保护锁
std::mutex* mtx_save = nullptr;
std::vector<Thread*>threads;                //线程组

//存档名称
std::string save_name = "";
//用于检测文件为存档文件的标识符
const char* checkword = "CheckSave114514";
const char* checksetting = "CookedSetting";
const char* version = "1.10";

//对象实例化区
Player* player = new Player();
IngredientMarketUI* market_weight = new IngredientMarketUI();
Restaurant* restaurant = new Restaurant();
RestaurantUI* res_weight = new RestaurantUI();






//主函数
int main(){
    //后台初始化

    std::thread initialize_td(Initialize);   //创建一条线程用于处理初始化内容
    initialize_td.detach();                  //将初始化进程后台处理

    //配置文件加载
    {
        //获取设置文件中信息
        std::string settingpath = "CookedSetting.txt";
        std::ifstream ifs(settingpath);                 //输入文件流
        ifs.open(settingpath,std::ios::in);

        //检查标识符
        bool flag = (GetFileLine(1,settingpath) == checksetting);

        //设置文件不存在新建
        if (!ifs.is_open()) {

            ifs.close();

            std::ofstream newfile;         //局部输出文件流

            newfile.open(settingpath.c_str(), std::ios::in);

            newfile << checksetting << Endl;                    
            newfile << NumToString((int)autosave_state).c_str() << Endl;
            newfile << NumToString((int)autosave_time).c_str() << Endl;

            newfile.close();
            
        }

        //配置文件验证失败，覆写设置文件
        else if(!flag){

            ifs.close();

            std::ofstream newfile;                              //局部输出文件流

            newfile.open(settingpath.c_str(), std::ios::trunc | std::ios::out);

            std::cout << "Setting Config Warning:配置文件验证失败，正在为您覆写配置文件，您的设置将会恢复为默认设置\n";

            newfile << checksetting << Endl;                    //配置文件标识符
            newfile << NumToString((int)autosave_state).c_str() << Endl;
            newfile << NumToString((int)autosave_time).c_str() << Endl;

            newfile.close();
            
        }

        //文件存在且验证成功，读取设置文件
        else {
            autosave_state = (bool)StringToInt(GetFileLine(2, settingpath));        //读取自动存档状态
            autosave_time = (int)StringToInt(GetFileLine(3, settingpath));          //读取自动存档时间
            ifs.close();
            ifs.clear();    //清除文件流状态
        }
        
    }//使用作用域块自动释放内存

    //后台自动保存
    std::thread autosave_td(LaunchAutoSave);
    autosave_td.detach();

    //确定运行环境
    std::cout << "Warning:\n" 
        << "本游戏仅能在Windows平台上运行，为确保彩字能够正常运行，请确保系统在Win10以上\n"
        <<"若您的Windows版本不满足需求，您可以按下[Tab]来屏蔽所有彩字，来确保游戏的正常运行\n"
        << "若您的Windows版本能正常运行，请按下键盘上其它键以正常继续游戏\n";
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
    
    //测试键盘输入
    /*
    while (1) {
        cout << _getch() << "\n";
    }
    
    ;
    */

    
    //测试存档功能
    cout << "input\n";
    player->SetPlayerName("Cora");
    cin >> save_name;
    save_name += ".txt";
    SaveGameAll();
    

    ;
    /*
    //测试字符串流
    float fl = StringToFloat("3.1415");
    string str = NumToString(3.1415f);
    */
    ;

    /*
    //测试读档
    std::cin >> save_name;
    save_name += ".txt";
    ReadSaveAll();
    system("pause");
    */

}




void LaunchAutoSave(){

    //检查自动保存状态
    if (!autosave_state) {

        return;

    }


    //已存在自动保存的进程
    if (mtx_autosave != nullptr) {


        return;                 //退出

    }


    //上锁
    mtx_autosave = nullptr;
    mtx_autosave = new std::mutex;
    mtx_autosave->lock();


    //等待存档名被输入
    if (save_name == "") {

        //等待输入
        while (1) {

            Sleep(1000);

            if (save_name != "") {

                break;

            }

        }

    }

    
    //等待并检查[一秒检查一次]
    for (int i = 0; i < autosave_time / 1000; i++) {

        Sleep(1000);
        if (!autosave_state) {
            return;
        }

    }

    std::cout << yellow << "\nMessage:正在进行自动保存……\n" << white;
    SaveGameAll();

    //解锁并销毁
    mtx_autosave->unlock();
    delete mtx_autosave;
    mtx_autosave = nullptr;

    return;
}




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




void SettingMenu() {
    std::cout << yellow << "尚未开发" << white;
    system("pause");
    return;
}




void SaveGameAll() {

    //检查锁是否已经存在
    if (mtx_save != nullptr) {
        std::cout << red + "已有正在进行的存档操作！可能它来自正在进行的自动保存……\n" + white;
        return;                                              //存档正在进行，跳出
    }

    mtx_save = nullptr;
    mtx_save = new std::mutex;
    mtx_save->lock();
    

    {
        //开始保存
        std::ifstream* ifs = nullptr;                        //输入文件操作流指针，方便销毁
        ifs = new std::ifstream(save_name.c_str());
        ifs->open(save_name.c_str(), std::ios::in);          //检测存档文件是否存在

        //无法打开文件
        if (!ifs->is_open()) {

            std::cerr << red << "Save Error:存档打开失败或存档文件不存在！" << white;

            ifs->close();
            ifs->clear();                                    //重置文件流

            //释放锁
            mtx_save->unlock();
            delete mtx_save;
            mtx_save = nullptr;

            return;                                          //提前退出函数
        }

        ifs->close();
        ifs->clear();

        delete ifs;
        ifs = nullptr;
    }

    std::ofstream ofs;

    ofs.open(save_name.c_str(), std::ios::trunc | std::ios::out);

    if (!ofs.is_open()) {                                   //文件打开失败

        std::cerr << red << "Wrong!Falied to open File When save something!\n" + white;

        //释放锁
        mtx_save->unlock();
        delete mtx_save;
        mtx_save = nullptr;

        return;

    }
    
    //标识符和版本号
    ofs << checkword << Endl;
    ofs << version << Endl;

    //Player
    ofs << "PlayerName" << Endl;
    ofs << player->GetPlayerName().c_str() << Endl;

    ofs << "PlayerMoney" << Endl;
    ofs << NumToString(player->GetPlayerMoney()).c_str() << Endl;

    ofs << "Plot" << Endl;
    ofs << NumToString((int)player->GetPlayerPlot()).c_str() << Endl;

    //Restaurant
    ofs << "RestaurantTurnover" << Endl;
    ofs << NumToString(restaurant->GetTurnover()).c_str() << Endl;

    ofs << "RestaurantLevel" << Endl;
    ofs << NumToString((int)restaurant->GetLevel()).c_str() << Endl;

    ofs << "IceBoxMax" << Endl;
    ofs << NumToString((int)restaurant->GetIceBoxMax()).c_str() << Endl;

    //Ingredient
    for (int i = 0; i < market_weight->all_ingredient.size();) {

        ofs << "Ingredient_" << NumToString(i) << Endl;     //阶段标识符

        for (int j = 0; j < market_weight->all_ingredient[i].size();) {

            ofs << NumToString(market_weight->all_ingredient[i][j]->possession).c_str() << Endl;

            j++;

        }

        ofs << "Break" << Endl;

        i++;
    }

    ofs << "End" << Endl;

    ofs.close();

    //释放锁
    mtx_save->unlock();
    delete mtx_save;
    mtx_save = nullptr;

    std::cout << yellow << "\nMessage:存档成功！\n" << white;

    return;
}




void Initialize() {
    //设置初始化状态
    initalize_state = 1;

    //测试用文字

    //std::cout << green << "Finish to initialize!" << white;
    return;
}





void ThreadTest() {

}




void CreateCustomer() {
//生成对象的循环
    while (restaurant->GetOpenState()) {
    //随机三十秒到两分钟创建一个顾客
        //Sleep(Random(30'000, 120'000));
        for (int i = 0; i < Random(200, 600);) {
            Sleep(100);
        //检测开门状态
            if (!restaurant->GetOpenState()) {
            //关门了提前停止
                delete createtrd;
                createtrd = nullptr;
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
        std::cout << red << "Read Error:无法打开存档文件!\n" << white;
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

        //清空冰箱
        restaurant->ice_box.clear();

        //食材
        if (str.size() >= 11 && str.substr(0, 11) == "Ingredient_" && StringToInt(str.back()) <= market_weight->all_ingredient.size()) {

            line++;

            for (int i = 0; i < market_weight->all_ingredient[StringToInt(str.back())].size();) {
                

                if (GetFileLine(line, save_name) == "Break") {
                    break;
                }


                //存入数据
                market_weight->all_ingredient[StringToInt(str.back())][i]->possession = StringToInt(GetFileLine(line, save_name));
                
                i++;

            }
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

    //存入冰箱食材
    for (int i = 0; i < market_weight->all_ingredient.size();) {

        for (int j = 0; j < market_weight->all_ingredient[i].size();) {

            if (market_weight->all_ingredient[i][j]->possession != 0) {
                restaurant->ice_box.push_back(market_weight->all_ingredient[i][j]);
            }

            j++;

        }

        i++;

    }

    
    return;
}