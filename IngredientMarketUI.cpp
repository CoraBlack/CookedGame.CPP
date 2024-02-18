#include "IngredientMarketUI.h"
#include"statement.h"
#include<iomanip>
#include"conio.h"
IngredientMarketUI::IngredientMarketUI() {
	all_ingredient.push_back(vegetable);
	all_ingredient.push_back(meat);
	all_ingredient.push_back(cereals);
	return;
}

void IngredientMarketUI::IngredientMarket() {
	system("cls");
	std::cout << blue << "Welcome to Ingredient Market!" << Back;
	std::cout << yellow << "[Esc]����С�͹�(�ǵø����!)\n[Tab]����\n[Space]���ﳵ\n" 
			  << green << "[0]ȫ��ʳ����Ʒ\n[1]�߲�\n[2]����\n[3]������Ʒ\n[4]��ζƷ\n";
	while (1) {
		int input = _getch();
		switch (input) {
	//��Ʒѡ�����
		case 48:

			break;

		case 49://�߲���
			system("cls");
			return this->ChooseSomeIngredient(this->vegetable);
			break;

		case 50://����
			system("cls");
			return this->ChooseSomeIngredient(this->meat);
			return this->IngredientMarket();
			break;

		case 51:
			return this->ChooseSomeIngredient(this->cereals);
			break;

	//��Ϊ����
		case 32://Space  ���ﳵ
			//���ﳵ����Ϊ��
			if (this->shopping_cart.empty()) {
				system("cls");
				std::cout << yellow << "����û�н����������Ʒ���뵽���ﳵ��\n" << white;
				system("pause");
				system("cls");
				return this->IngredientMarket();
			}
			;
			this->page = 0;
			system("cls");
			return this->ShoppingCartOperator();
			break;


		case 9://Tab     ����
			//���ﳵΪ������
			if (shopping_cart.empty()) {
				system("cls");
				std::cout << yellow << "����û����ѡ������Ҫ����Ʒ\n"<< white;
				input = 0;
				system("pause");
				return this->IngredientMarket();
			}
			;
			//�г������Ѽ��빺�ﳵ����Ʒ
			system("cls");
			std::cout << blue << "���Ĺ��ﳵ��\n" << yellow;
			for (int i = 0; i < shopping_cart.size();) {
				std::cout << "[" << i + 1 << "]" << shopping_cart[i]->name << "		���ۣ�" << shopping_cart[i]->price << "\n";
				i++;
			}
			//�г��ܼۺͲ�������
			std::cout << "�ܹ���֧��" << green << std::setprecision(2) << std::fixed << this->total_price << yellow << "Ԫ\n" << green;
			std::cout << "[Space]֧����ǰ��Ʒ\n[Tab]���\n[Esc]������һ��\n" << white;


			//�����˵�
			while (1){
				input = _getch();
				switch (input){
			
			//Space ����
				case 32:
				//Ǯ����
					if (this->total_price > player->GetPlayerMoney()) {
						std::cout << red << "��û���㹻��Ǯ֧������ѡ����Ʒ\n";
						system("pause");
						system("cls");
						return this->IngredientMarket();
					}
				//����
					std::cout << yellow << "���ڸ�����ٴ�������\n" << white;
				//�������
					player->SetPlayerMoney(player->GetPlayerMoney() - total_price);
				//�ѹ��ﳵ�е���ƷŲ��������
					for (int i = 0; i < shopping_cart.size();) {
					//�ж��Ƿ�Ӧ�ý����ݴ��뻹�����Ӵ����
						//��Ӵ����
						if (shopping_cart[i]->possession != 0) {
							shopping_cart[i]->possession += 1;
							i++;
							continue;
						}
						//�������(��Ԫ��)
						restaurant->ice_box.push_back(shopping_cart[i]);
						shopping_cart[i]->possession += 1;
						i++;
					}
					system("cls");
					std::cout << yellow << "��ӭ�´ι��٣��������" << green << player->GetPlayerMoney() << "Ԫ\n";
					system("pause");
				//��չ��ﳵ
					this->shopping_cart.clear();
					return this->IngredientMarket();
					break;
			
			//Tab ��չ��ﳵ
				case 9:
					std::cout << yellow << "�Ƿ���Ҫ��չ��ﳵ?\n" 
						<< green << "[Space]��չ��ﳵ\n[Esc]����"  << white;
					do {
						input = _getch();
						if (input  == 27) {
							return this->IngredientMarket();
						}
					} while (input != 32 );
					this->total_price = 0;
					this->shopping_cart.clear();
					return this->IngredientMarket();
					break;
			
			//Esc������һ��
				case 27:
					return this->IngredientMarket();
					break;

				default:
					break;
				}
			}
			break;
			;
		case 27://Esc   ������һ��
			//��鹺�ﳵ�Ƿ�Ϊ��
			if (shopping_cart.empty()) {
				return;
			}
			else {
				//���ﳵ��Ϊ��
				system("cls");
				std::cout << yellow 
					<< "���Ĺ��ﳵ����δ�����ʳ����Ʒ��\n";
				system("pause");
				return this->IngredientMarket();
			}
			break;
		default:
			break;
		}
	}
	return this->IngredientMarket();
}
;
void IngredientMarketUI::ShoppingCartOperator(){
//�г����ﳵ�嵥
//���ҳ��
	int pagemax = (shopping_cart.size() % 10 == 0) ? (shopping_cart.size() / 10) : ((shopping_cart.size() / 10) + 1);
	std::cout << blue << "Page��" << green << page + 1 << "/"
		<< pagemax << yellow << Back;
//��ֹ����Խ�磨��ֹ��ӡ�������ݣ�
	int range;	//��ӡ����
	if ( ( page + 1 ) * 10 > shopping_cart.size()) {
		range = shopping_cart.size() % 10;
	}
	else {
		range = 10;
	}
//��ӡ��ǰҳ��Ʒ
	for (int i = 0; i < range;) {
		std::cout << "[" << i << "]" << shopping_cart[page*10 + i]->name << "		" 
			      << "���ۣ�" << shopping_cart[page*10 + i]->price << Back;
		i++;
	}
	;
//�г�������ʾ
	std::cout << green
		<< "ѡ��ǰ�б���Ʒǰ�������ӹ��ﳵ���Ƴ�\n[Q]/[E]��ǰ/���ҳ\n"
		<< "[Esc]������һ��\n" << white;
	;
//�Ƴ�����
	int input = _getch();
	if (input >= 48 && input <= 57) {
		int choose_temp = this->page * 10 + input - 48;
	//��ֹ����Խ��
		if (choose_temp >= shopping_cart.size()) {
			system("cls");
			return this->ShoppingCartOperator();
		}
	//�Ƴ�ָ��Ԫ��
		total_price -= shopping_cart[choose_temp]->price;
		this->shopping_cart.erase(shopping_cart.begin() + choose_temp );
	//ɾ��������ǰҳԪ����ȫ��ɾ��������ǰ�Զ���ҳ
		if (shopping_cart.size() <= page * 10 && page > 0) {
			page--;
		}
	//ɾ����Ԫ�غ������ﳵ����գ��򷵻ص���һ��
		else if(shopping_cart.empty())
		{
			system("cls");
			std::cout << yellow << "���ﳵ�ѱ���գ���ȥ��ĵط����ư�!\n" << white;
			system("pause");
			system("cls");
			return this->IngredientMarket();
		}
		system("cls");
		return this->ShoppingCartOperator();
	}
//��ҳ�뷵��
	switch (input) {
	case 101:		//[E]���ҳ
	//����Ƿ�Խ��
		if ((page + 1) * 10 >= shopping_cart.size()) {
			system("cls");
			return this->ShoppingCartOperator();
		}
		page += 1;
		system("cls");
		return this->ShoppingCartOperator();
		break;
	case 113:		//[Q]��ǰ��ҳ
		if (page - 1 < 0) {
			page = 0;
			system("cls");
			return this->ShoppingCartOperator();
		}
		page -= 1;
		system("cls");
		return this->ShoppingCartOperator();
		break;
	case 27:		//[Esc]
		this->page = 0;	//����ҳ��
		return this->IngredientMarket();
		break;
	default:
		break;
	}
}
;

//ȱһ����������
void IngredientMarketUI::ChooseSomeIngredient(std::vector<ingredient*>&vec){
	std::cout << blue << "Page:" << green << this->page + 1 << yellow << Back;
//�г���ǰҳʳ��
	for (int i = 0; i < vec.size();) {
		std::cout << "[" << i << "]" << vec[i]->name << "		" << "���ۣ�" << vec[i]->price << Back;
		i++;
	}
//�г�����
	std::cout << green 
		<< "ѡ����Ʒǰ��������������ﳵ\n[Q]/[E]��ǰ/���ҳ\n"
		<< "[Esc]������һ��\n" << white;


	while (1){
		int input = _getch();
	//ѡ����Ʒ
		if (input >= 48 && input <= 57) {
			int choose_temp = this->page*10 + input - 48;
		//��ֹ����Խ��
			if (choose_temp >= vec.size()) {
				continue;
			}
		//���빺�ﳵ
			total_price += vec[choose_temp]->price;
			shopping_cart.push_back(vec[choose_temp]);
			system("cls");
			std::cout << yellow << "�ѽ�" << green << vec[choose_temp]->name
				<< yellow << "*1 ��ӽ����ﳵ��" << white << Back;
			return this->ChooseSomeIngredient(vec);
		}


	//��������
		switch (input){
		case 101://[E]���ҳ
		//����Ƿ�Խ��
			if ( (page + 1) * 10 > vec.size()) {
				continue;
			}
			page += 1;
			break;
		case 113://[Q]��ǰ��ҳ
		//ҳ������С����
			if (page - 1 < 0) {
				page = 0;
				continue;
			}
			page -= 1;
			system("cls");
			return this->ChooseSomeIngredient(vec);
			break;
		case 27://[Esc]
			this->page = 0;	//����ҳ��
			return this->IngredientMarket();
			break;
		default:
			break;
		}
	}
}
;