#include "RestaurantUI.h"
#include"statement.h"
#include"conio.h"
void RestaurantUI::MainResMenu() {
	system("cls");
	std::cout << yellow << "��������Ҫ��ʲô?[���Ĳ͹ݴ���" << blue << "����" << yellow << "״̬]" << Back;
	std::cout << green << "[Tab]����\n[1]ʳ���г�\n[2]���沼��\n" << white;
	//ѡ��
	while (1) {
		int input = _getch();
		switch (input) {
		case 9://Tab
			restaurant->SetOpenState(1);
			//�л������ŵ�Ӫҵ����
			return this->ResOpenMenu();
			break;
		case 49://1
			market_weight->IngredientMarket();
			break;
		case 50://2

			break;
		default:
			break;
		}
	}
}
void RestaurantUI::ResOpenMenu(){

}
;