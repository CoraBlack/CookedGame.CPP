#include "RestaurantUI.h"
#include"statement.h"
#include"conio.h"
void RestaurantUI::MainResMenu() {
	system("cls");
	std::cout << yellow << "您接下来要做什么?[您的餐馆处于" << blue << "关门" << yellow << "状态]" << Back;
	std::cout << green << "[Tab]开店\n[1]食材市场\n[2]店面布设\n" << white;
	//选项
	while (1) {
		int input = _getch();
		switch (input) {
		case 9://Tab
			restaurant->SetOpenState(1);
			//切换至开门的营业界面
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