//����ȫ�ֱ����ͺ���������
//���ڹ������ļ�����

#ifndef STATEMENT_H
#define STATEMENT_H
//ͷ�ļ�
#include"conio.h"
#include"Customer.h"
#include "IngredientMarketUI.h"
#include"Player.h"
#include"Restaurant.h"
#include"RestaurantUI.h"
#include"Thread.h"
#include<fstream>
#include<iostream>
#include<mutex>
#include<random>
#include<sstream>
#include<string>
#include<thread>
#include<vector>
#include<Windows.h>
//�궨�廻�в���
#define Back "\n"
#define Endl std::endl
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
void DeleteCustomer(Customer* cusptr);	//���ٹ˿�
//ȫ�ֱ�������
extern bool pausestate;					//��Ϸ��ͣ״̬(1Ϊ��ͣ)
extern bool initalize_state;			//�Ƿ�����ɳ�ʼ��
extern std::string save_name;			//�浵����
extern bool autosave_state;				//�Ƿ����Զ�����(0Ϊ�رգ�1Ϊ����)
extern unsigned int autosave_time;		//�Զ��浵ʱ��
extern const char* checkword;			//��֤��ʶ��
extern const char* checksetting;		//�����ļ�����
extern const char* version;				//�汾�ŷ�
;
//��������(���ڶ��߳�)
extern Thread* createtrd;				//���ڴ����˿��¶����ר���̶߳���
extern std::vector<Thread*>threads;		//�̼߳������ڹ������̣߳�
extern std::mutex* mtx_pause;			//����ȫ����ͣ���߳���
extern std::mutex* mtx_save;			//���ڷ�ֹ�浵�����ͻ��
extern std::mutex* mtx_autosave;		//���ڷ�ֹ�Զ����淴�������ı�����
;
//��������
void LaunchAutoSave();					//�����Զ�����
void PauseGame();						//ȫ����ͣ
void ResumeGame();						//�ָ���Ϸ
void SettingMenu();						//��Ϸ���ò˵�
bool CheckSave();						//�浵��֤
void SaveGameAll();						//ȫ�ִ浵
void ReadSaveAll();						//��ȡ�浵
void Initialize();						//��ʼ��
void ThreadTest();						//�̹߳������
void Test();							//����ͨ��
//���������Ķ���
//���ִ�ӡ
inline void PrintVerbatim(std::string str) {
	for (int i = 0; i < str.size();) {
		std::cout << str[i];
		Sleep(80);
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
	return num; 
}
;
//α����(����ʱ��Ϊ0.1��)
inline void Loading(float times) {
	for (int i = 0; i < times; i++){
		std::cout << "<";
	}
	std::cout << Back;
	return;
}
/*(�浵��)*/
//����ת�ַ�
inline std::string NumToString(int num/*��������*/) {
	std::stringstream ss;
	std::string str;
	ss << num;
	ss >> str;
	return str;
}
inline std::string NumToString(double num/*��������*/) {
	std::stringstream ss;
	std::string str;
	ss << num;
	ss >> str;
	return str;
}
//�ַ�ת����
inline int StringToInt(char ch) {
	int num = 0;
	std::stringstream ss;
	ss << ch;
	ss >> num;
	return num;
}
inline int StringToInt(std::string str) {
	int num = 0;
	std::stringstream ss;
	ss << str;
	ss >> num;
	return num;
}
inline float StringToFloat(std::string str) {
	float num = 0.0f;
	std::stringstream ss;
	ss << str;
	ss >> num;
	return num;
}
//��ȡָ��������
inline std::string GetFileLine(int line/*ָ������*/, std::string file/*�ļ���*/) {
	std::ifstream ifs;
	std::string str;
	ifs.open(file.c_str(), std::ios::in);
	if (!ifs.is_open()) {
		std::cerr << red << "Error:failed to open file!" << white;
		ifs.close();
		ifs.clear();
		return "wrong!";
	}
	for (int i = 0; i < line;) {
		getline(ifs, str);
		i++;
	}
	ifs.close();
	ifs.clear();
	return str;
}
#endif