//����ȫ�ֱ����ͺ���������
//���ڹ������ļ�����

#ifndef STATEMENT_H
#define STATEMENT_H
//ͷ�ļ�
#include<iostream>
#include<string>
#include<thread>
#include<vector>
#include<random>//���������
#include<Windows.h>
#include<mutex>
#include"conio.h"
#include"Thread.h"
#include"Player.h"
#include"Customer.h"
#include"Restaurant.h"
#include"RestaurantUI.h"
#include "IngredientMarketUI.h"
//�궨�廻�в���
#define Back "\n"		
;
//������ɫ
extern std::string red;
extern std::string yellow;
extern std::string green;
extern std::string white;
extern std::string blue;
;
//�˿�
extern std::vector<Customer*>customers;	//����˿͵Ĺ˿ͼ�
void CreateCustomer();					//���ɹ˿�
//ȫ�ֱ�������
extern bool pausestate;					//��Ϸ��ͣ״̬(1Ϊ��ͣ)
extern bool initalize_state;			//�Ƿ�����ɳ�ʼ��
extern std::string save_name;			//�浵����
extern bool autosave_state;				//�Ƿ����Զ�����(0Ϊ�رգ�1Ϊ����)
extern unsigned int autosave_time;		//�Զ��浵ʱ��
extern const char* checkword;			//��֤��ʶ��
;
//��������(���ڶ��߳�)
extern std::vector<Thread*>threads;			//�̼߳������ڹ������̣߳�
extern std::mutex mtx_pause;				//����ȫ����ͣ���߳���
;
//��������
void AllPause();					//ȫ����ͣ
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
//α����(����ʱ��Ϊ0.1��)
inline void Loading(float times) {
	for (int i = 0; i < times; i++){
		std::cout << "<";
	}
	std::cout << Back;
	return;
}
#endif