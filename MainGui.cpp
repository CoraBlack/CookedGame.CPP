#include "MainGui.h"
#include "statement.h"
#include "conio.h"
#include "iomanip"
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
			return this->ReadSave();
			break;
		case 27://Esc
			system("cls");
			SettingMenu();
			return GameStart();
			break;
		default:
			break;
		}
	}
}
;
void MainGui::ReadSave() {
//�����ļ�����
	system("cls");
	std::cout << yellow << "���������Ĵ浵����(����Exit�˳�����)" << white << Back;
	getline(std::cin, save_name);
	if (save_name == "") {//��ֹΪ��
		system("cls");
		std::cerr << red << "�浵���Ʋ���Ϊ�գ�����" << white << Back;
		system("pause");
		return ReadSave();
	}
	else if (save_name == "Exit") {//����Exitʱ
		system("cls");
		return this->GameStart();
	}
	save_name += ".txt";
//��ȡ�ļ�����������
	std::ifstream getfile;
	getfile.open(save_name, std::ios::in);

//�浵��֤
	bool check = CheckSave();
	if (!check) {
		system("pause");
		return this->ReadSave();
	}

	std::cout << yellow << "���ڶ�ȡ���ݣ��浵��" << green << save_name << white << Back;
		
//��������
	ReadSaveAll();
//������Ϸ
	std::cout << green << "�浵��ȡ���\n" << white;
	system("pause");
	system("cls");
//չʾ�浵��Ϣ
	std::cout << blue << "�浵��Ϣ:\n"
		<< yellow << "�û���:\t" << green << player->GetPlayerName() << Back
		<< yellow << "Ǯ��:\t" << green << std::setprecision(2) << std::fixed << player->GetPlayerMoney() << Back
		<< yellow << "С̯:\t" << green << "Level " << restaurant->GetLevel() << Back
		<< yellow << "Ӫҵ��:\t" << green << std::setprecision(2) << std::fixed << restaurant->GetTurnover() << Back
		<< white;
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
	system("cls");
//�򿪰�������
	std::cout << yellow << "�ڿ�ʼ��Ϸǰ,���б�Ҫ��һ����Ϸ�İ����ֲ�\n" << white;
	Help();
	std::cout << blue << "����ǰ������̯λ\n" << white;
	Loading(10);
//����Ϸ����

//ת��̯�Ӳ�������
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
void MainGui::Help(){
	int input = 0;
	while (1) {
		std::cout << blue
			<< "С����:\n" << yellow
			<< "[1]����̯λ\n[2]���ڹ˿�ϵͳ\n[3]�������ϵͳ\n[Esc]�˳�С����\n"
			<< white;
		input = _getch();
		switch (input){
	//[1]����̯λ��˵��
		case 49:
			system("cls");
			break;
			;
	//[2]���ڹ˿�ϵͳ��˵��
		case 50:
			system("cls");
			std::cout << blue << "��������:\n" << white
				<< "�˿ͻ��ڲ���ʱ����������̯λǰ��������ȷ��������\n"
				<< "������Ҫ����̵�ʱ���ڳ��ͣ����ſ����������������\n"
				<< "����Ҫ�۲�ʲôʳƷ��������ã��Ա����ܹ����õķ���˿��Ҳ������ʳ���˷�\n"
				<< "���߲�����Ϊʳ�Ĺ��ർ����ʱ���ϵ��˷�\n"
				<< "�˿͵ĵȴ�ʱ�䣬Ҳ�������ǵ����ģ�������������������Ļ�ϣ���ֻ���ٶ�!!!\n";
			system("pause");
			system("cls");
			break;
			break;
			;
	//[3]���ϵͳ��˵��
		case 51:
			system("cls");
			std::cout << blue << "��������:\n"
				<< white << "����Ҫ��������ʳ�ģ��������С̯�����̯\n"
				<<"��Ҫ���ؿ�����Ӧ�ô�ʲô����Ӧ�Բ�ͬ�˿͵�����\n"
				<< "�������ڳ�̯ǰ�ں��׼��������Ԥ��ʳƷ\n"
				<< "�Կ��Ը���ĳ���\n"
				<<"�������ĳ���ʱ����Ի�ø���Ķ��������(С��)\n"
				<<"���ǣ���Ҫ֪��Ԥ��ʳƷ���ı���ʱ���Ǻ̵ܶģ�����Ҫ��һ�ֳ�����ȫ������\n"
				<<"��������Ҫ������Ԥ��ʳƷ�����������ţ���һ������Ϊ�����ʵ�̯��\n"
				<< "������ʹ�ø��߼���ʳ��ȥ�����ͬ����ʳ���Ի�ȡ���ߵ�����͸��õĿڱ�\n"
				<< "��Ȼ�����ߵļ۸�Ҳ��ζ�Ÿ��ٵĹ˿ͣ���Ϊ�������������޵�\n"
				<< "������ѡ��ȥ�ɹ�Ԥ��ʳƷ����Ȼ�����Լ۱Ȳ��ߣ����ǿ��Ժܴ��ȥ��������ʱ��ɱ�\n";
			system("pause");
			system("cls");
			break;
			;
	//[Esc]�˳�С����
		case 27:
			return;
			break;
			;
		default:
			system("cls");
			break;
		}
	}
}
;