//������Ϸ�Ļ�������
#include"statement.h"
#include<iostream>
#include<Windows.h>
#include"conio.h"
#include"Restaurant.h"
#include"Player.h"
#include<fstream>
std::string red = "\033[31m";
std::string green = "\033[32m";
std::string yellow = "\033[33m";
std::string white = "\033[0m";
;
//Classʵ����
Restaurant myres;
Player player;
;
//�浵����
std::string save_name = "";
const char* checkword = "CheckWord114514";//���ڼ���ļ�Ϊ�浵�ļ��ı�ʶ��
void PrintVerbatim(std::string str) {
	for (int i = 0; i < str.size();) {
		std::cout << str[i];
		Sleep(100);
		i++;
	}
	std::cout << std::endl;
	return;
}
;
void PauseMenu() {
	std::cout << "[Esc]����\n[Tab]����\n[Back]�˳���Ϸ\n";
	while (1){
		int input = _getch();
		switch (input) {
		case 9://Tab

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
void GameStart() {
	std::cout << yellow << "Cooked��" << std::endl;
	std::cout << green << "[Tab]����Ϸ\n[Space]��ȡ��Ϸ\n[Esc]����" << white << std::endl;
	while (1) {
		int input = _getch();//��ȡ��������
		//�����ã��鿴����ֵ��
		//std::cout << input << std::endl;
		switch (input) {
		case 9://Tab
			system("cls");
			std::cout << yellow << "�������Ҫ����һ������Ϸ��?\n" << green << "[Tab]ȷ����������Ϸ\n[Esc]ȡ������" << std::endl;
			input = 0;//��������ֵ
			while (1){
				input = _getch();
				switch (input) {
				case 9://Tab
					system("cls");
					return CreateNewSave();
					break;
				case 27://Esc
					input = 0;
					system("cls");
					return GameStart();
					break;
				default:
					break;
				}
			}
			break;
		case 32://Space

			break;
		case 27://Esc

			break;
		default:
			break;
		}
	}
}
void CreateNewSave(){
	//�����´浵����
	std::cout << yellow << "�����µĴ浵����:" << green << std::endl;
	getline(std::cin, save_name);
	save_name += ".txt";
	//����Ƿ��Ѵ��ڸô浵
	std::ifstream check;
	check.open(save_name, std::ios::trunc);
	if (check.is_open()) {
		//��⵽�����ļ�(��bugĿǰ)
		std::cerr << yellow << "Warning:��⵽�浵�ļ��Ѵ��ڣ��Ƿ����������" << white << "[Space]����\n[Esc]����\n";
		int input = 0;
		//����ΪSpaceʱ����
		do {
			input = _getch();
			if (input == 27) {
				//����ESCʱ���´���
				return GameStart();
			}
		} while (input != 32);
	}
	//��������
	std::ofstream newsave;
	newsave.open(save_name,std::ios::out);
	if (!newsave.is_open()) {
		std::cerr << red << "Wrong!�ļ��޷�����,�������ؿ�ʼ�˵�\n" << white;
		Sleep(3000);
	}else{
		//д����֤�ַ�
		newsave << checkword;
		std::cout << green << "�������µĴ浵" << yellow << save_name << white;
		system("pause");
	}
	return NewGame();
}
;
void NewGame() {

}
;
void Initialize() {
	Sleep(5000);
	//std::cout << green << "Finish to initialize!";
	return;
}

void CreateMainGui(){
	for (int i = 0; i < 60;) {
		std::cout << "_";
		i++;
	}
	std::cout << std::endl;
	for (int i = 0; i < 28;) {
		std::cout << "|";
		for (int j = 0; j < 58;) {
			std::cout << " ";
			j++;
		}
		std::cout << "|" << std::endl;
		i++;
	}
	for (int i = 0; i < 60;) {
		std::cout << "_";
		i++;
	}
}
