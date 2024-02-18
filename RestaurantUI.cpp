#include "RestaurantUI.h"
#include"statement.h"
#include"conio.h"
void RestaurantUI::MainResMenu() {
	system("cls");
	std::cout << yellow << "��������Ҫ��ʲô?[���Ĳ͹ݴ���" << blue << "����" << yellow << "״̬]" << Back;
	std::cout << green << "[Tab]��̯��̯!!!\n[1]ʳ���г�\n[2]ȥ���俴��\n" << white;
	//ѡ��
	while (1) {
		int input = _getch();
		switch (input) {
	//[Tab]����Ӫҵ
		case 9:
		//�½���̨�˿��߳�
			//����߳��Ƿ��Ѵ���
			if (createtrd == nullptr) {
				createtrd = nullptr;
				createtrd = new Thread(CreateCustomer);
			}
		//����Ӫҵ״̬
			restaurant->SetOpenState(1);
		//�л������ŵ�Ӫҵ����
			system("cls");
			this->ResOpenMenu();
			return this->MainResMenu();
			break;
			;
	//[1]ʳ���г�
		case 49:
			market_weight->IngredientMarket();
			return this->MainResMenu();
			break;
			;
	//[2]��������
		case 50:
			this->IceBoxUI(0);
			return this->MainResMenu();
			break;
			;
		default:
			break;
		}
	}
	return;
}
;
void RestaurantUI::ResOpenMenu(){
	std::cout << blue << "Do it!�˿�,����ԴԴ�����������!!!\n" << green
			  << "[Tab]�л�Ӫҵ״̬\n[F]������ʳ\n[R]�˿�����\n[Esc]��ͣ��Ϸ\n" << white;
	int input = 0;
	while (1){
		input = _getch();
		switch (input) {
	//[Tab]��̯
		case 9:
		//Ӫҵ״̬��ǰΪӪҵʱ
			if (restaurant->GetOpenState()) {
			//����ΪֹͣӪҵ
				restaurant->SetOpenState(0);
			//�˿�δ���
				if (!customers.empty()) {
					std::cout << yellow << "�����п���δ�뿪!�����Ѿ�����Ӫҵ״̬Ϊֹͣ���ȴ�����ȫ���뿪\n" << white;
					//��ʼ������ֵ
					input = 0;
				//�ظ�ѭ��
					continue;
				}
			//�˿������
				//����̼߳�
				for (int i = 0; i < threads.size();) {
					delete threads[i];
					i++;
				}
				return;
			}

		//Ӫҵ״̬ΪֹͣӪҵʱ
			//����״̬ΪӪҵ
			restaurant->SetOpenState(1);
		//�����˿����ɳ���
			//������ɳ����Ѿ�����
			if (createtrd != nullptr) {	
				continue;
			}
			//���ɳ����߳�ָ��Ϊ��,��������
			createtrd = nullptr;
			createtrd = new Thread(CreateCustomer);
			break;
			;
	//[F]������ʳ
		case 102:
			CookedUI();
			return this->ResOpenMenu();
			break;
			;

	//[R]
		case 114:
			ProcessRequit();
			return this->ResOpenMenu();
			break;

	//[Esc]
		case 27:

		//��Ϸ��������
			if (!pausestate){
				PauseGame();
			}
			else {
		//��Ϸ����ͣ
				ResumeGame();
			}
			break;
			;
		default:
			break;
		}
	}
}
;
/*
void RestaurantUI::KitchenUI(){
	system("cls");
	std::cout << yellow << "����Ҫ��ʲô��\n" << green
			  << "[Esc]�뿪���\n[1]���\n[2]����\n" << white;
//����Ĵ����ҳ����
	while (1){
	//�������
		int input = _getch();
		switch (input){
	//[Esc] �뿪���
		case 27:
			system("cls");
			return; //������һ��
			break;
			;
	//[1]���
		case 49:
		//ֹͣӪҵ������
			if (!restaurant->GetOpenState()) {
				std::cout << yellow << "���ں���û�п��Ű�(-_-)����\n";
				system("pause");
				system("cls");
				return KitchenUI();
			}
		
			break;
			;
	//[2]����
		case 50:
		//��ת�����������
			system("cls");
			this->IceBoxUI(0);
			return this->KitchenUI();
			break;
			;
		default:
			break;
		}
	}
}
*/
void RestaurantUI::IceBoxUI(int page){//pageΪ��ǰҳ��0Ϊ��һҳ
//����տ���Ҳ��
	if (restaurant->ice_box.empty() && player->hand.empty()) {
		std::cout << yellow << "����տ���Ҳ(T_T)����\n" << white;
		system("pause");
		system("cls");
		return;
	}
//��ӡ�����е�ȫ��ʳ��
	//����һ�����ҳ��
	int pagemax = (restaurant->ice_box.size() % 10 == 0) ? (restaurant->ice_box.size() / 10) : ((restaurant->ice_box.size() / 10) + 1);
	//��ӡ��ǰҳѭ���Ĵ���
	int range;
	if (( page + 1) * 10 > restaurant->ice_box.size()) {
		range = restaurant->ice_box.size() % 10;
	}
	else {
		range = 10;
	}
	//��ӡԤ����ҳ��
	std::cout << blue << "Page:" << page + 1 << "/" << pagemax << Back << yellow;
//��ӡ�����ڲ���Ʒ
	if (!restaurant->ice_box.empty()) {
	//�����л���
		for (int i = page * 10; i < range;) {
			std::cout << "[" << i << "]" << restaurant->ice_box[i]->name << "		�����" << restaurant->ice_box[i]->possession << Back;
			i++;
		}
	}
	else {
	//����տ���Ҳ
		std::cout << yellow << "����տ���Ҳ(T_T)����\n" << white;
	}
//��������
	std::cout << green << "�������ʳ��ǰ������ȡ��ʳ��\n[Q]/[E]��ǰ/���ҳ\n[Esc]�˳�����\n" << white;
	//�г��ֳ���Ʒ
	std::cout << blue << "�ֳ֣�\n" << white;
	for (int i = 0; i < player->hand.size();) {
		std::cout << yellow << player->hand[i]->name << "	" << white;
		i++	;	
	}
	std::cout << Back << green << "[R]/[F]����������Ʒ�Żر���\n";
	int input = 0;
	while (1) {
		input = _getch();
	//��ȡ��Ʒ
		if (input >= 48 && input <= 57){
		//��ֹ�������
			if (page*10 + input - 48 >= restaurant->ice_box.size()) {
				//���������������С�ظ�ѭ��
				continue;
			}
		//ȡ����Ʒ
			//��ֻ��ͬʱ����������
			if (player->hand.size() >= 2) {
				continue;
			}
			//ȡ��
			player->hand.push_back(restaurant->ice_box[page * 10 + input - 48]);
			restaurant->ice_box[page * 10 + input - 48]->possession -= 1;
			//ȡ��������ʳ�Ĵ�����Ϊ0���Ƴ�����
			if (restaurant->ice_box[page * 10 + input - 48]->possession == 0) {
				restaurant->ice_box.erase(restaurant->ice_box.begin() + (page * 10 + input - 48));
			}
			//ȡ����Ʒ������ǰҳΪ���򷵻���һҳ
			if (page * 10 >= restaurant->ice_box.size() && page > 0) {
				page -= 1;
			}
			system("cls");
			return this->IceBoxUI(page);
		}
	//����
		switch (input){
	//�˳�����
		case 27:
			return;
			break;
			;
	//��ҳ
		//[Q]��ǰ��ҳ
		case 113:
			//��ֹҳ��Ϊ0
			if (page - 1 < 0) {
				page = 0;
				continue;
			}
			page -= 1;
			system("cls");
			return this->IceBoxUI(page);
			break;
			;
		//[E]���ҳ
		case 101:
			//����Ƿ�Խ��
			if ((page + 1) * 10 > restaurant->ice_box.size()) {
				continue;
			}
			page += 1;
			break;
			;
		//�����ϵĶ����Żر�����
		//[R]��������Ʒ�Żر���
		case 114:
			//������Խ��
			if (player->hand.size() < 1) {
				continue;
			}
		//����
			//�Լ�ֵ����ʽ����
			if (player->hand[0]->possession > 0) {
				player->hand[0]->possession += 1;
				player->hand.erase(player->hand.begin());
				system("cls");
				return this->IceBoxUI(page);
			}
			//�Լ�����Ԫ�ص���ʽ����
			restaurant->ice_box.push_back(player->hand[0]);
			restaurant->ice_box.back()->possession += 1;
			player->hand.erase(player->hand.begin());
			system("cls");
			return this->IceBoxUI(page);
			break;
			;
		//[F]��������Ʒ�Żر���
		case 102:
			//������Խ��
			if (player->hand.size() < 2) {
				continue;
			}
			//����
				//�Լ�ֵ����ʽ����
			if (player->hand[1]->possession != 0) {
				player->hand[1]->possession += 1;
				player->hand.erase(player->hand.begin() + 1);
				system("cls");
				return this->IceBoxUI(page);
			}
			//�Լ�����Ԫ�ص���ʽ����
			restaurant->ice_box.push_back(player->hand[1]);
			player->hand.erase(player->hand.begin() + 1);
			system("cls");
			return this->IceBoxUI(page);
			break;
			;
		default:
			break;
		}
	}
}

void RestaurantUI::CookedUI(){
	system("cls");
	while (1) {
		std::cout << blue << "���!\n" << white;
		std::cout << green << "[Tab]����ֲ�\n[F]����\n[Esc]��ͣ\n" << white;
		switch ((int)_getch()){
		//[Tab]����ֲ�
		case 9:
			HandBookUI();
			return this->CookedUI();
			break;

		//[F]����
		case 102:
			system("cls");
			return;
			break;

		//[Esc]��ͣ��Ϸ
		case 27:
			//��Ϸ��������
			if (!pausestate) {
				PauseGame();
			}
			else {
				//��Ϸ����ͣ
				ResumeGame();
			}
			break;

		default:
			break;
		}
	}
}

void RestaurantUI::HandBookUI(){
	
}

void RestaurantUI::ProcessRequit(){
	system("cls");

	//û�й˿�
	if (customers.empty()) {
		system("cls");
		std::cout << yellow << "��û�п��ˣ��ٵȵȰɡ���\n";
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < customers.size();) {
		std::cout << blue << "[" << i << "]" << "Customer:  " << white;
		for (int j = 0; j < customers[i]->needs.size();) {
			std::cout << yellow << customers[i]->needs[j].name << white;
			j++;
		}
		std::cout << Back;
		i++;
	}
	std::cout << green << "ѡ��ѡ��ǰ�������Զ�Ŀ��˿ͽ��в���\n"
		<< "[Esc]����\n" << white;

	int input = _getch();

	//ѡ��
	if (input >= 48 && input <= 57) {
		if (input - 48 >= customers.size()) {
			return this->ProcessRequit();
		}

		for (int i = 0; i < customers[input - 48]->needs.size();) {
			std::cout << yellow << customers[input - 48]->needs[i].name << "	\n" << white;
			i++;
		}

		std::cout << green << "[Space]�ύ\n[Esc]����\n";


		while (1){

			int input2 = _getch();

			//�ύ
			if (input2 == 32) {
				std::vector<int>nums;

				//����
				for (int i = 0; i < customers[input - 48]->needs.size();) {
					for (int j = 0; j < finish.size();) {
						//�����ɹ�
						if (finish[j].name == customers[input - 48]->needs[i].name) {
							nums.push_back(j);
							break;
						}
						j++;
					}
					//��ǰ���������
					if (i + 1 != nums.size()) {
						std::cout << yellow << "����û��׼���������˿������ʳ��\n";
						system("pause");
						return this->ProcessRequit();
					}
					i++;
				}
				
				//ѭ���������(��ʼ�������ݣ�
				for (int i = 0; i < nums.size();) {
					finish.erase(finish.begin() + nums[i] - 1);
					i++;
				}
				nums.clear();
				customers[input - 48]->SetNeedsState(1);
				std::cout << green << "�ύ�ɹ���\n";
				system("cls");
				system("pause");
				return this->ResOpenMenu();
			}

			//����
			if (input2 == 27) {
				system("cls");
				return this->ProcessRequit();
			}

		}

	}

	//����
	if (input == 27) {
		return;
	}

	return this->ProcessRequit();
}
;