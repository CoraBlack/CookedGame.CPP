//������
#include"statement.h"
#include<thread>
#include<Windows.h>

//������ɫ
std::string red = "\033[31m";
std::string green = "\033[32m";
std::string yellow = "\033[33m";
std::string white = "\033[0m";
std::string blue = "\033[36m";

//statement.h��ȫ�ֱ����Ķ���������ֹ����������
bool pausestate = 0;                    //��Ϸ��ͣ״̬
bool initalize_state = 0;               //Ĭ�ϳ�ʼ��״̬Ϊ��
bool autosave_state = 1;				//Ĭ�Ͽ����Զ��浵
unsigned int autosave_time = 300'000;	//Ĭ���Զ��浵ʱ�������

//�˿ͼ���
std::vector<Customer*>customers;

//����
std::vector<cuisine>all_cuisine;			//ȫ������

//���ڶ��߳�
Thread* createtrd = nullptr;			    //���ڴ����˿��¶����ר���̶߳���
std::mutex* mtx_pause = nullptr;            //��ʼ���߳���
std::mutex* mtx_autosave = nullptr;		    //���ڷ�ֹ�Զ����淴�������ı�����
std::mutex* mtx_save = nullptr;
std::vector<Thread*>threads;                //�߳���

//�浵����
std::string save_name = "";
//���ڼ���ļ�Ϊ�浵�ļ��ı�ʶ��
const char* checkword = "CheckSave114514";
const char* checksetting = "CookedSetting";
const char* version = "1.10";

//����ʵ������
Player* player = new Player();
IngredientMarketUI* market_weight = new IngredientMarketUI();
Restaurant* restaurant = new Restaurant();
RestaurantUI* res_weight = new RestaurantUI();






//������
int main(){
    //��̨��ʼ��

    std::thread initialize_td(Initialize);   //����һ���߳����ڴ����ʼ������
    initialize_td.detach();                  //����ʼ�����̺�̨����

    //�����ļ�����
    {
        //��ȡ�����ļ�����Ϣ
        std::string settingpath = "CookedSetting.txt";
        std::ifstream ifs(settingpath);                 //�����ļ���
        ifs.open(settingpath,std::ios::in);

        //����ʶ��
        bool flag = (GetFileLine(1,settingpath) == checksetting);

        //�����ļ��������½�
        if (!ifs.is_open()) {

            ifs.close();

            std::ofstream newfile;         //�ֲ�����ļ���

            newfile.open(settingpath.c_str(), std::ios::in);

            newfile << checksetting << Endl;                    
            newfile << NumToString((int)autosave_state).c_str() << Endl;
            newfile << NumToString((int)autosave_time).c_str() << Endl;

            newfile.close();
            
        }

        //�����ļ���֤ʧ�ܣ���д�����ļ�
        else if(!flag){

            ifs.close();

            std::ofstream newfile;                              //�ֲ�����ļ���

            newfile.open(settingpath.c_str(), std::ios::trunc | std::ios::out);

            std::cout << "Setting Config Warning:�����ļ���֤ʧ�ܣ�����Ϊ����д�����ļ����������ý���ָ�ΪĬ������\n";

            newfile << checksetting << Endl;                    //�����ļ���ʶ��
            newfile << NumToString((int)autosave_state).c_str() << Endl;
            newfile << NumToString((int)autosave_time).c_str() << Endl;

            newfile.close();
            
        }

        //�ļ���������֤�ɹ�����ȡ�����ļ�
        else {
            autosave_state = (bool)StringToInt(GetFileLine(2, settingpath));        //��ȡ�Զ��浵״̬
            autosave_time = (int)StringToInt(GetFileLine(3, settingpath));          //��ȡ�Զ��浵ʱ��
            ifs.close();
            ifs.clear();    //����ļ���״̬
        }
        
    }//ʹ����������Զ��ͷ��ڴ�

    //��̨�Զ�����
    std::thread autosave_td(LaunchAutoSave);
    autosave_td.detach();

    //ȷ�����л���
    std::cout << "Warning:\n" 
        << "����Ϸ������Windowsƽ̨�����У�Ϊȷ�������ܹ��������У���ȷ��ϵͳ��Win10����\n"
        <<"������Windows�汾���������������԰���[Tab]���������в��֣���ȷ����Ϸ����������\n"
        << "������Windows�汾���������У��밴�¼�����������������������Ϸ\n";
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
    
    //���Լ�������
    /*
    while (1) {
        cout << _getch() << "\n";
    }
    
    ;
    */

    
    //���Դ浵����
    cout << "input\n";
    player->SetPlayerName("Cora");
    cin >> save_name;
    save_name += ".txt";
    SaveGameAll();
    

    ;
    /*
    //�����ַ�����
    float fl = StringToFloat("3.1415");
    string str = NumToString(3.1415f);
    */
    ;

    /*
    //���Զ���
    std::cin >> save_name;
    save_name += ".txt";
    ReadSaveAll();
    system("pause");
    */

}




void LaunchAutoSave(){

    //����Զ�����״̬
    if (!autosave_state) {

        return;

    }


    //�Ѵ����Զ�����Ľ���
    if (mtx_autosave != nullptr) {


        return;                 //�˳�

    }


    //����
    mtx_autosave = nullptr;
    mtx_autosave = new std::mutex;
    mtx_autosave->lock();


    //�ȴ��浵��������
    if (save_name == "") {

        //�ȴ�����
        while (1) {

            Sleep(1000);

            if (save_name != "") {

                break;

            }

        }

    }

    
    //�ȴ������[һ����һ��]
    for (int i = 0; i < autosave_time / 1000; i++) {

        Sleep(1000);
        if (!autosave_state) {
            return;
        }

    }

    std::cout << yellow << "\nMessage:���ڽ����Զ����桭��\n" << white;
    SaveGameAll();

    //����������
    mtx_autosave->unlock();
    delete mtx_autosave;
    mtx_autosave = nullptr;

    return;
}




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




void SettingMenu() {
    std::cout << yellow << "��δ����" << white;
    system("pause");
    return;
}




void SaveGameAll() {

    //������Ƿ��Ѿ�����
    if (mtx_save != nullptr) {
        std::cout << red + "�������ڽ��еĴ浵�������������������ڽ��е��Զ����桭��\n" + white;
        return;                                              //�浵���ڽ��У�����
    }

    mtx_save = nullptr;
    mtx_save = new std::mutex;
    mtx_save->lock();
    

    {
        //��ʼ����
        std::ifstream* ifs = nullptr;                        //�����ļ�������ָ�룬��������
        ifs = new std::ifstream(save_name.c_str());
        ifs->open(save_name.c_str(), std::ios::in);          //���浵�ļ��Ƿ����

        //�޷����ļ�
        if (!ifs->is_open()) {

            std::cerr << red << "Save Error:�浵��ʧ�ܻ�浵�ļ������ڣ�" << white;

            ifs->close();
            ifs->clear();                                    //�����ļ���

            //�ͷ���
            mtx_save->unlock();
            delete mtx_save;
            mtx_save = nullptr;

            return;                                          //��ǰ�˳�����
        }

        ifs->close();
        ifs->clear();

        delete ifs;
        ifs = nullptr;
    }

    std::ofstream ofs;

    ofs.open(save_name.c_str(), std::ios::trunc | std::ios::out);

    if (!ofs.is_open()) {                                   //�ļ���ʧ��

        std::cerr << red << "Wrong!Falied to open File When save something!\n" + white;

        //�ͷ���
        mtx_save->unlock();
        delete mtx_save;
        mtx_save = nullptr;

        return;

    }
    
    //��ʶ���Ͱ汾��
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

        ofs << "Ingredient_" << NumToString(i) << Endl;     //�׶α�ʶ��

        for (int j = 0; j < market_weight->all_ingredient[i].size();) {

            ofs << NumToString(market_weight->all_ingredient[i][j]->possession).c_str() << Endl;

            j++;

        }

        ofs << "Break" << Endl;

        i++;
    }

    ofs << "End" << Endl;

    ofs.close();

    //�ͷ���
    mtx_save->unlock();
    delete mtx_save;
    mtx_save = nullptr;

    std::cout << yellow << "\nMessage:�浵�ɹ���\n" << white;

    return;
}




void Initialize() {
    //���ó�ʼ��״̬
    initalize_state = 1;

    //����������

    //std::cout << green << "Finish to initialize!" << white;
    return;
}





void ThreadTest() {

}




void CreateCustomer() {
//���ɶ����ѭ��
    while (restaurant->GetOpenState()) {
    //�����ʮ�뵽�����Ӵ���һ���˿�
        //Sleep(Random(30'000, 120'000));
        for (int i = 0; i < Random(200, 600);) {
            Sleep(100);
        //��⿪��״̬
            if (!restaurant->GetOpenState()) {
            //��������ǰֹͣ
                delete createtrd;
                createtrd = nullptr;
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
        std::cout << red << "Read Error:�޷��򿪴浵�ļ�!\n" << white;
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

        //��ձ���
        restaurant->ice_box.clear();

        //ʳ��
        if (str.size() >= 11 && str.substr(0, 11) == "Ingredient_" && StringToInt(str.back()) <= market_weight->all_ingredient.size()) {

            line++;

            for (int i = 0; i < market_weight->all_ingredient[StringToInt(str.back())].size();) {
                

                if (GetFileLine(line, save_name) == "Break") {
                    break;
                }


                //��������
                market_weight->all_ingredient[StringToInt(str.back())][i]->possession = StringToInt(GetFileLine(line, save_name));
                
                i++;

            }
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

    //�������ʳ��
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