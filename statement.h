//����ȫ�ֱ����ͺ���������
//���ڹ������ļ�����
#include<string>
#include<thread>
#include<vector>
#include"Thread.h"
#ifndef STATEMENT_H
#define STATEMENT_H
//������ɫ
extern std::string red;
extern std::string yellow;
extern std::string green;
extern std::string white;
extern std::string blue;
//��������
extern std::vector<Thread>threads;				//�̼߳������ڹ������̣߳�
;
extern struct ingredient;//ʳ����Ϣ�ṹ��
extern std::vector<ingredient>vegetable;		//�߲���ʳ��
extern std::vector<ingredient>meat;				//����ʳ��
extern std::vector <std::vector<ingredient>>all_ingredient;	//ȫ��ʳ��
;
extern struct cuisine;//������Ϣ�ṹ��
extern std::vector<cuisine>all_cuisine;			//ȫ������
;
//ʳ�Ĺ��ﳵ
std::vector<ingredient>shopping_cart;
//��������
void PauseMenu();//��ͣ����
void SettingMenu();//��Ϸ���ò˵�
void GameStart();
void CreateNewSave();//�½��浵
void ReadSaveFlie();//��ȡ�浵
void NewGame();//����Ϸ
void OpenResMenu();//Ӫҵʱ�Բ����Ĳ���
void CloseResMenu();//��ͣӪҵ������������
void IngredientMarket();//ʳ���г�
void PrintVerbatim(std::string str);//���ִ�ӡ
void Initialize();	//��ʼ��
void CreateMainGui();//��ҪUI��������
void ThreadTest();//�̹߳������
#endif