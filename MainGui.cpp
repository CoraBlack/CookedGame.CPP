#include "MainGui.h"
#include "statement.h"
#include "conio.h"
#include <fstream>
;
;
void MainGui::GameStart() {
	system("cls");
//�������
	std::cout << yellow << "Cooked��" << std::endl;
	std::cout << green << "[Tab]����Ϸ\n[Space]��ȡ��Ϸ\n[Esc]����" << white << std::endl;
//ѡ��
	while (1) {
		int input = _getch();//��ȡ��������
		//�����ã��鿴����ֵ��
		//std::cout << input << std::endl;
		switch (input) {
		case 9://Tab
			system("cls");
			std::cout << yellow << "�������Ҫ����һ������Ϸ��?\n" 
					  << green << "[Tab]ȷ����������Ϸ\n[Esc]ȡ������" << std::endl;
			input = 0;//��������ֵ
			//ȷ������
			while (1) {
				input = _getch();
				switch (input) {
				case 9://Tab
					system("cls");
					return this->CreateNewSave();
					break;
				case 27://Esc
					input = 0;
					system("cls");
					return this->GameStart();
					break;
				default:
					break;
				}
			}
			break;
		case 32://Space
			return this->ReadSaveFlie();
			break;
		case 27://Esc
			system("cls");
			PauseMenu();
			break;
		default:
			break;
		}
	}
}
;
void MainGui::ReadSaveFlie() {
//�����ļ�����
	system("cls");
	std::cout << yellow << "���������Ĵ浵����(����Exit�˳�����)" << white << Back;
	getline(std::cin, save_name);
	if (save_name == "") {//��ֹΪ��
		system("cls");
		std::cerr << red << "�浵���Ʋ���Ϊ�գ�����" << white << Back;
		return ReadSaveFlie();
	}
	else if (save_name == "Exit") {//����Exitʱ
		system("cls");
		return this->GameStart();
	}
	save_name += ".txt";
//��ȡ�ļ�����������
	std::ifstream getfile;
	getfile.open(save_name, std::ios::in);
	std::string check_temp;//���ڴ洢�ļ���һ���ַ�����ʱ����
	getfile >> check_temp;
//��֤��ʶ��
	if (check_temp == checkword) {
		std::cout << yellow << "���ڶ�ȡ���ݣ��浵��" << green << save_name << white << Back;

	}
	else {
		//�����ļ���
		getfile.close();
		getfile.clear();
		std::cerr << red << "��ⲻ���浵�ļ��ؼ��֣�Ϊ������Ϸ������������������Ϸ������" << white << Back;
		save_name = "";//����
		return this->GameStart();
	}
	;
	;
//��������

//�����ļ���
	getfile.close();
	getfile.clear();
//������Ϸ
	std::cout << green << "�浵��ȡ���" << white;
//��֤��ʼ��
	if (!initalize_state) {		//��ʼ��δ���
		std::cout << "�ȴ���ʼ������\n";
		while (1){
			Sleep(500);			//0.5����һ�γ�ʼ���Ƿ�ɹ�
			if (initalize_state) {
				return res_weight->MainResMenu();
			}
		}
	}
	system("pause");
	system("cls");
	return res_weight->MainResMenu();
}
;
void MainGui::NewGame() {
	//����Ϸ����

	//ת�������������
	return res_weight->MainResMenu();
}
;
void MainGui::CreateNewSave() {
//�����´浵����
	std::cout << yellow << "�����µĴ浵����:" << white << Back;
	getline(std::cin, save_name);
//��ֹ��������Ϊ��
	if (save_name == "") {
		system("cls");
		std::cerr << red << "�浵���Ʋ���Ϊ�գ�����" << white << Back;
		return this->CreateNewSave();
	}
	else if (save_name == "Exit") {//����Exit��Ϊ�浵��
		system("cls");
		std::cerr << red << "�����н�����Exit��Ϊ��������ַ�������ʹ�ø��ַ���Ϊ�浵��" << white << Back;
		save_name = "";
		return this->CreateNewSave();
	}
//��ȫ�ļ���ʽ
	save_name += ".txt";
//����Ƿ��Ѵ��ڸô浵
	std::fstream savefile(save_name);
	if (savefile.good()) {
		//��⵽�����ļ�(��bugĿǰ)
		std::cerr << yellow << "Warning:��⵽�浵�ļ��Ѵ��ڣ��Ƿ����������\n" 
				  << green << "[Space]����\n[Esc]����\n" << white;
		int input = 0;
		//����ΪSpaceʱ����
		do {
			input = _getch();
			if (input == 27) {
				//����ESCʱ���´���
				system("cls");
				return this->GameStart();
			}
		} while (input != 32);//ǿ�ƴ���ͬ���ļ�
	}
//��������
	std::ofstream newsave;
	newsave.open(save_name, std::ios::out);
	if (!newsave.is_open()) {
		std::cerr << red << "Wrong!�ļ��޷�����(�޷����ļ�),�������ؿ�ʼ�˵�\n" << white;
		Sleep(3000);
	}
	else {
		//д����֤�ַ�
		newsave << checkword;
		std::cout << green << "�������µĴ浵" << yellow << save_name << Back << white;
		newsave.close();
		newsave.clear();
		system("pause");
	}
//����ʼ��
	if (!initalize_state) {		//��ʼ��δ���
		std::cout << "�ȴ���ʼ������\n";
		while (1) {
			Sleep(500);			//0.5����һ�γ�ʼ���Ƿ�ɹ�
			if (initalize_state) {
				return this->NewGame();
			}
		}
	}
	return this->NewGame();

}
;