//����ȫ�ֱ����ͺ���������
//���ڹ������ļ�����
#include<iostream>
#include<string>
#include<thread>
#include<vector>
<<<<<<< HEAD
#include<random>//���������
#include<Windows.h>
#include"conio.h"
#include"Thread.h"
#include"Player.h"
#include"Customer.h"
#include"Restaurant.h"
#include"RestaurantUI.h"
#include "IngredientMarketUI.h"
=======
#include"Thread.h"
#include"Player.h"
#include"Costomer.h"
#include"Restaurant.h"
>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
#ifndef STATEMENT_H
#define STATEMENT_H
#define Back "\n"		//�궨�廻�в���
;
//������ɫ
extern std::string red;
extern std::string yellow;
extern std::string green;
extern std::string white;
extern std::string blue;
<<<<<<< HEAD
;

//�˿ͼ���
extern std::vector<Customer*>customers;
//ȫ�ֱ�������
extern bool initalize_state;			//�Ƿ�����ɳ�ʼ��
extern std::string save_name;			//�浵����
extern bool autosave_state;				//�Ƿ����Զ�����(0Ϊ�رգ�1Ϊ����)
extern unsigned int autosave_time;		//�Զ��浵ʱ��
extern const char* checkword;			//��֤��ʶ��
;
//�ṹ�嶨��

=======
//Class����
extern Player *player;
extern Restaurant *restaurant;
extern Costomer *costomer;
//�ṹ�嶨��
//ʳ��
struct ingredient {
	std::string name;
	int price;				//�۸�
	int possession;			//ӵ����
};
;
extern std::vector<ingredient>shopping_cart;	//ʳ�Ĺ��ﳵ
extern std::vector<ingredient>vegetable;		//�߲���ʳ��
extern std::vector<ingredient>meat;				//����ʳ��
extern std::vector <std::vector<ingredient>>all_ingredient;	//ȫ��ʳ��
;
>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
//����
struct cuisine {
	std::string name;
	int price;				//�۸�
};
extern std::vector<cuisine>all_cuisine;			//ȫ������
;
//��������
extern std::vector<Thread>threads;				//�̼߳������ڹ������̣߳�
;
//��������
<<<<<<< HEAD

void PauseMenu();					//��ͣ����
void SettingMenu();					//��Ϸ���ò˵�
void AutoSave(bool mode);			//�Զ��浵
void Initialize();					//��ʼ��
void ThreadTest();					//�̹߳������
void Test();						//����ͨ��
//���������Ķ���
//���ִ�ӡ
inline void PrintVerbatim(std::string str) {
	for (int i = 0; i < str.size();) {
		std::cout << str[i];
		Sleep(100);
		i++;
	}
	std::cout << Back;
	return;
}
;
//�����
inline int Random(int min, int max) { 
	std::random_device seed;								//�������������
	std::default_random_engine rd_eg(seed());				//����seed���ӵ����������
	std::uniform_int_distribution <int> rand_num(min, max);	//int��ʼ��distribution����
	int num = rand_num(rd_eg);								//��ʹ��rd_eg�����int�ĳ�ʼ������ֵ��num
	return num; }
=======
int Random(int min, int max);		//�����
void PauseMenu();					//��ͣ����
void SettingMenu();					//��Ϸ���ò˵�
void GameStart();					//��Ϸ��ʼ���˵�
void CreateNewSave();				//�½��浵
void ReadSaveFlie();				//��ȡ�浵
void NewGame();						//����Ϸ
void OpenResMenu();					//Ӫҵʱ�Բ����Ĳ���
void CloseResMenu();				//��ͣӪҵ������������
void IngredientMarket();			//ʳ���г�
void PrintVerbatim(std::string str);//���ִ�ӡ
void Initialize();					//��ʼ��
void CreateMainGui();				//��ҪUI��������
void ThreadTest();					//�̹߳������
>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
#endif