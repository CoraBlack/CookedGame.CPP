//������
#include <iostream>
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
std::vector<Thread*>threads;
//�浵����
std::string save_name = "";
//���ڼ���ļ�Ϊ�浵�ļ��ı�ʶ��
const char* checkword = "CheckSave114514";
int (*fucptr) ();
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
    thread initialize_td(Initialize);//����һ���߳����ڴ����ʼ������
    initialize_td.detach();//����ʼ�����̺�̨����
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
    /*
    PrintVerbatim("Hello,Dear Player!\nI am so proud of that you can play my game");
    PrintVerbatim("�����ҽ���һ���Լ���\nCoca Cora");
    Sleep(1000);
    PrintVerbatim("and my good friend AF!!!!!!!!\nWell have a good time!!!");
    system("pause");
    system("cls");
    */
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
    return 0;
}
;
;
;
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
    while (1) {
        cout << _getch() << "\n";
    }
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
void AutoSave(bool mode /* �ֶ��浵(0) ���� �Զ��浵(1) */) {
    //�Զ��浵ģʽ
    if (mode) {
        //�Ƿ����Զ��浵
        if (autosave_state) {
            //���ߣ��ȴ��浵
            Sleep(autosave_time);

        }
    }
    //�ֶ��浵
    //�浵�������̣����ã�
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
