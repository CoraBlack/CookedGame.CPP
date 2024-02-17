//������
#include"statement.h"
#include<Windows.h>
#include<thread>
using namespace std;
//������ɫ
std::string red = "\033[31m";
std::string green = "\033[32m";
std::string yellow = "\033[33m";
std::string white = "\033[0m";
std::string blue = "\033[36m";
;
//statement.h��ȫ�ֱ����Ķ���������ֹ����������
bool pausestate = 0;                    //��Ϸ��ͣ״̬
bool initalize_state = 0;               //Ĭ�ϳ�ʼ��״̬Ϊ��
bool autosave_state = 1;				//Ĭ�Ͽ����Զ��浵
unsigned int autosave_time = 300'000;	//Ĭ���Զ��浵ʱ�������

//�˿ͼ���
std::vector<Customer*>customers
;
//����
std::vector<cuisine>all_cuisine;			//ȫ������
;
//���ڶ��߳�
Thread* createtrd = nullptr;			    //���ڴ����˿��¶����ר���̶߳���
std::mutex* mtx_pause = nullptr;            //��ʼ���߳���
std::mutex* mtx_save = nullptr;
std::vector<Thread*>threads;                //�߳���
//�浵����
std::string save_name = "";
//���ڼ���ļ�Ϊ�浵�ļ��ı�ʶ��
const char* checkword = "CheckSave114514";
const char* checksetting = "CookedSetting";
const char* version = "0.62";
;
//����ʵ������
Player* player = new Player();
Restaurant* restaurant = new Restaurant();
RestaurantUI* res_weight = new RestaurantUI();
IngredientMarketUI* market_weight = new IngredientMarketUI();
;
;
;




//������
int main(){
    //��̨��ʼ��

    thread initialize_td(Initialize);   //����һ���߳����ڴ����ʼ������
    initialize_td.detach();             //����ʼ�����̺�̨����
    {
        //��ȡ�����ļ�����Ϣ
        std::string settingpath = "C:/Users/Public/Documents/CookedSetting.txt";
        std::ifstream ifs(settingpath);
        ifs.open(settingpath);
        //�����ļ��������½�
        if (!ifs.is_open()) {
            std::ofstream newfile(settingpath);
            newfile.open(settingpath);
            newfile << autosave_state;
            newfile << autosave_time;
            newfile.close();
            newfile.clear();
        }
        //�ļ����ڣ���ȡ�����ļ�
        else {
            autosave_state = (bool)StringToInt(GetFileLine(2, settingpath));        //��ȡ�Զ��浵״̬
        }
        ifs.close();
        ifs.clear();    //����ļ���״̬
    }
    //�������֣����������Σ�
    //ȷ�����л���
    cout << yellow << "Warning:\n" << white 
        << "����Ϸ������Windowsƽ̨�����У�Ϊȷ�������ܹ��������У���ȷ��ϵͳ��Win10����\n"
        <<"������Windows�汾���������������԰���[Tab]���������в��֣���ȷ����Ϸ����������\n"
        <<"������Windows�汾���������У��밴�¼�����������������������Ϸ\n";
//���β���    
    if (_getch() == 9) {
        red = "";
        yellow = "";
        green = "";
        white = "";
        blue = "";
        std::cout << "����������!";
        system("cls");
    }
    ;
    //��������ں���(�����й�)
    MainGui* main_weight = new MainGui;
    main_weight->GameStart();
    // 
    // 
    // 
    // 
    //���Ӳ���ͨ��
    //Test();
//���ٶ���
    delete player;
    delete restaurant;
    delete res_weight;
    delete market_weight;
    return 0;
}





//ȫ�ֺ���������
//����ͨ��
void Test() {
    //������Բ��õ�
    using namespace std;

    //�������������
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
    //���Լ�������
    while (1) {
        cout << _getch() << "\n";
    }
    */
    ;
    /*
    //���Դ浵����
    cout << "input\n";
    cin >> save_name;
    save_name += ".txt";
    SaveGameAll();
    */
    ;
    /*
    //�����ַ�����
    float fl = StringToFloat("3.1415");
    string str = NumToString(3.1415f);
    */
    ;
    //���Զ���
    save_name = "save.txt";
    ReadSaveAll();
    system("pause");
}
;
void PauseGame(){
//��ȫ��������
    //�����ڴ�
    mtx_pause = nullptr;
    mtx_pause = new std::mutex;
    if (mtx_pause->try_lock()) {
        //�����ɹ���ͨ����ͣ
        pausestate = 1;
        std::cout << yellow << "Message:��Ϸ�Ѿ���ͣ\n" << white;
    }
    else {
        //ʧ��
        std::cerr << yellow << "Warning:��Ϸ��ͣʧ�ܣ�������Ϸ�Ѿ���ͣ\n" << white;
    }
    return;
}
;
void ResumeGame() {
//���Ѿ�����
    if (!mtx_pause->try_lock()) {
        mtx_pause->unlock();
        pausestate = 0;
        std::cout << yellow << "Message:��Ϸ�Իָ�\n" << white;
    }
    //ʧ��
    else {
        std::cerr << yellow << "Warning:��Ϸ�ƺ��Ѿ������ͣ�����ڳ������½����ͣ\n" << white;
        mtx_pause->unlock();
        pausestate = 0;
    }
//�ͷ��ڴ沢��ʼ��
    delete mtx_pause;
    mtx_pause = nullptr;
    return;
}
;
void SettingMenu() {
    std::cout << yellow << "��δ����" << white;
    system("pause");
    return;
}
;
void SaveGameAll() {
    //������Ƿ��Ѿ�����
    if (mtx_save != nullptr) {
        while (mtx_save != nullptr) {
            Sleep(100);
        }
    }
    mtx_save = nullptr;
    mtx_save = new std::mutex;

    //��ʼ����
    std::fstream fs;                                    //�����ļ�������
    fs.open(save_name,std::ios::in);                    //���浵�ļ��Ƿ����

    //�޷����ļ�
    if (!fs.is_open()) {
        std::cerr << red << "Save Error:�浵��ʧ�ܻ�浵�ļ������ڣ�" << white;
        fs.close();
        fs.clear();                                     //�����ļ���
        return;                                         //��ǰ�˳�����
    }

    //��ʱ��
    std::string* str_temp = nullptr;                    
    str_temp = new std::string;
    fs >> *str_temp;

    //Ŀ���ļ����Ǵ浵�ļ�
    if (*str_temp != checkword) {
        std::cerr << red << "Save Error:Ŀ���ļ����Ǵ浵�ļ�!\n" << white;
        fs.close();
        fs.clear();                                     //�����ļ���
        delete str_temp;
        str_temp = nullptr;                             //������ʱ��
        return;
    }
    
    *str_temp = GetFileLine(2, save_name);              //��ȡ�汾��
    if (*str_temp == "wrong") {
        fs.close();
        fs.clear();
        delete str_temp;
        str_temp = nullptr;
        return;
    }

    //Ŀ���ļ��汾�뵱ǰ��Ϸ�汾��һ
    if (*str_temp != version) {
        std::cout << yellow << "Save Warning:�浵�汾����Ϸ�汾���������ڸ��ǵ�ǰ�浵\n" << white;
    }
    else {
    //���汾ʱ�޷����ļ�
        std::cerr << red << "Save Error:�޷��������ļ�" << white;
        fs.close();
        fs.clear();                                     //�����ļ���
        delete str_temp;
        str_temp = nullptr;                             //������ʱ��
        return;
    }
    fs.close();
    fs.clear();                                         //�����ļ���
    delete str_temp;
    str_temp = nullptr;                                 //������ʱ��

    fs = std::fstream(save_name);
    fs.open(save_name, std::ios::trunc, std::ios::out); //ʹ��turncģʽ���ȫ�����ݣ�outģʽд������

    //�浵��д��ʱ�޷���
    if (!fs.is_open()) {
        std::cerr << red << "Save Error:�浵��ʧ�ܣ��޷��������д浵������" << white;
        fs.close();
        fs.clear();                                     //�����ļ���
        return;                                         //��ǰ�˳�
    }

    //ȫ�ֱ�ʶ
    fs << checkword;                                    //д����֤�ַ�
    fs << version;                                      //д��汾��

    //Player
    fs << "PlayerName";                                 //������ƽ׶η�
    fs << player->GetPlayerName();                      //�����������
    fs << "PlayerMoney";                                //��Ҵ���ʶ��
    fs << player->GetPlayerMoney();                     //������Ҵ��
    fs << "Plot";                                       //����ͨ������ʶ��
    fs << (int)player->GetPlayerPlot();                 //�������ͨ����

    //Restaurant
    fs << "RestaurantTurnover";                         //����Ӫҵ���ʶ��
    fs << restaurant->GetTurnover();                    //�������Ӫҵ��
    fs << "RestaurantLevel";                            //�����ȼ���ʶ��
    fs << (int)restaurant->GetLevel();                  //��������ȼ�
    fs << "IceBoxMax";                                  //����������������ʶ��
    fs << (int)restaurant->GetIceBoxMax();              //�������������

    //IceBox
    fs << "IceBox";                                     //�����ʶ��
    

    fs << "End";                                        //������
    fs.close();
    fs.clear();
    delete mtx_save;
    mtx_save = nullptr;
    return;
}
;
void Initialize() {
    //���ó�ʼ��״̬
    initalize_state = 1;
    //����������
    Sleep(1000);

    //std::cout << green << "Finish to initialize!" << white;
    return;
}
;
void ThreadTest() {

}
;
//���ɹ˿�
void CreateCustomer() {
//���ɶ����ѭ��
    while (restaurant->GetOpenState()) {
    //�����ʮ�뵽�����Ӵ���һ���˿�
        //Sleep(Random(30'000, 120'000));
        for (int i = 0; i < Random(300, 1200);) {
            Sleep(100);
        //��⿪��״̬
            if (!restaurant->GetOpenState()) {
            //��������ǰֹͣ
                return;
            }
        //�����ͣ״̬
            if (pausestate) {
            //����
                mtx_pause->lock();
                mtx_pause->unlock();
            }
            i++;
        }
    //���״̬�Ƿ��������
        if (restaurant->GetOpenState()) {
            Customer* newcus = nullptr;
            newcus = new Customer;
            continue;
        }
    //���ٴ����˿�
        //�ȴ��˿����
        while (!customers.empty()) { }
        break;
    }
}

void DeleteCustomer(Customer* cusptr/*���ٵĶ���*/) {
    //���������������е�λ��
    for (int i = 0; i < customers.size();) {
        if (cusptr == customers[i]) {
            //�Ƴ�
            customers.erase(customers.begin() + i);
            break;
        }
        i++;
    }
    //���ٹ˿Ͷ���ĺ�̨�߳�
    delete cusptr;
    //��ֹ����
    cusptr = nullptr;
    return;
}
bool CheckSave() {
    //��֤�浵�Ƿ�������
    if (save_name == "") {
        std::cout << red << "�浵��ϢΪ�գ�\n" << white;
        return 0;
    }

    std::ifstream ifs(save_name);       //�ļ���
    std::string str;                    //�ݴ�ֵ

    //���Դ�
    ifs.open(save_name, std::ios::in);
    if (!ifs.is_open()) {
        std:cout << red << "Read Error:�޷��򿪴浵�ļ�!\n" << white;
        ifs.close();
        ifs.clear();
        return 0;
    }

    //��֤�ַ�
    str = GetFileLine(1, save_name);
    if (str != checkword) {
        std::cout << red << "Read Error:Ŀ���ļ����Ǵ浵�ļ�!\n" << white;
        ifs.close();
        ifs.clear();
        return 0;
    }

    //��֤�汾��
    str = GetFileLine(2, save_name);
    if (str != version) {
        std::cout << "Warning:Ŀ���ļ��汾��һ�����ڳ���д�롭��\n" << white;
    }
    return 1;
}


void ReadSaveAll() {
    int line = 3;               //��ȡ������¼���ӵ����п�ʼ��ȡ��ǰ����Ϊ��֤��
    std::string str = "";       //�ݴ��ļ��ַ�
    while (1) {

        str = GetFileLine(line, save_name);

        //��������
        if (str == "PlayerName") {
            line++;
            player->SetPlayerName(GetFileLine(line, save_name));        //���������
            continue;
        }

        //�������Ǯ��
        if (str == "PlayerMoney") {
            line++;
            player->SetPlayerMoney(StringToFloat(GetFileLine(line, save_name)));
            continue;
        }

        //�������ͨ����
        if (str == "Plot") {
            line++;
            player->SetPlayerPlot(StringToInt(GetFileLine(line, save_name)));
            continue;
        }

        //����Ӫҵ��
        if (str == "RestaurantTurnover") {
            line++;
            restaurant->SetTurnover(StringToFloat(GetFileLine(line, save_name)));
            continue;
        }

        //�����ȼ�
        if (str == "RestaurantLevel") {
            line++;
            restaurant->SetLevel(StringToInt(GetFileLine(line, save_name)));
            continue;
        }

        //�����������
        if (str == "IceBoxMax") {
            line++;
            restaurant->SetIceBoxMax(StringToInt(GetFileLine(line, save_name)));
            continue;
        }

        //����ʳ��
        if (str == "IceBox") {
            line++;

            continue;
        }

        //������
        /*�ߣ����֪��ĳЩ������������϶���Ĵ浵���ݣ����޵�End��ʶ��ɾ������ֱ������10000��[doge]*/
        if (str == "End" || line >= 10000) {
            break;
        }
        //����������һ�м���
        line++;
    }
    
    return;
}