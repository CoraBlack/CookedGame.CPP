//����ȫ�ֱ����ͺ���������
//���ڹ������ļ�����
#include<string>
#ifndef STATEMENT_H
#define STATEMENT_H
//������ɫ
extern std::string red;
extern std::string yellow;
extern std::string green;
extern std::string white;
//ȫ�ֱ���

//��������
void PauseMenu();//��ͣ����
void SettingMenu();//��Ϸ���ò˵�
void GameStart();
void CreateNewSave();//�½��浵
void ReadSaveFlie();//��ȡ�浵
void NewGame();//����Ϸ
void PrintVerbatim(std::string str);//���ִ�ӡ
void Initialize();	//��ʼ��
void CreateMainGui();//��ҪUI��������
#endif