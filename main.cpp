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
//�߳���
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
    cout << yellow << "Warning��\n" << white 
        << "����Ϸ������Windowsƽ̨�����У�Ϊȷ�������ܹ��������У���ȷ��ϵͳ��Win10����\n"
        <<"������Windows�汾���������������԰���[Tab]���������в��֣���ȷ����Ϸ����������\n"
        <<"������Windows�汾���������У��밴�¼�����������������������Ϸ\n";
    int input = _getch();
//���β���    
    if (input == 9) {
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
void PauseMenu() {
//��ӡ�����б�
    std::cout << green << "[Esc]����\n[Tab]����\n[Back]�˳���Ϸ\n";
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