#include "RestaurantUI.h"
#include"statement.h"
#include"conio.h"
void RestaurantUI::MainResMenu() {
	system("cls");
	std::cout << yellow << "您接下来要做什么?[您的餐馆处于" << blue << "关门" << yellow << "状态]" << Back;
	std::cout << green << "[Tab]出摊出摊!!!\n[1]食材市场\n[2]去冰箱看看\n" << white;
	//选项
	while (1) {
		int input = _getch();
		switch (input) {
	//[Tab]开门营业
		case 9:
			restaurant->SetOpenState(1);
			//切换至开门的营业界面
			system("cls");
			this->ResOpenMenu();
			return this->MainResMenu();
			break;
			;
	//[1]食材市场
		case 49:
			market_weight->IngredientMarket();
			return this->MainResMenu();
			break;
			;
	//[2]看看冰箱
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
	std::cout << blue << "Do it!顾客,正在源源不断向你进军!!!\n" << green
			  << "[Tab]收摊\n[F]制作美食\n" << white;
	int input = 0;
	while (1){
		input = _getch();
		switch (input) {
	//[Tab]收摊
		case 9:
			restaurant->SetOpenState(0);
			return;
			break;
			;
	//[F]制作美食
		case 102:

			break;
			;
/*
	//[2]移到后厨
		case 50:
			system("cls");
			this->KitchenUI();
			return this->ResOpenMenu();
			break;
			;
*/
		default:
			break;
		}
	}
}
;
/*
void RestaurantUI::KitchenUI(){
	system("cls");
	std::cout << yellow << "你需要做什么？\n" << green
			  << "[Esc]离开后厨\n[1]烹饪\n[2]冰箱\n" << white;
//冰箱的存货翻页数量
	while (1){
	//输入操作
		int input = _getch();
		switch (input){
	//[Esc] 离开后厨
		case 27:
			system("cls");
			return; //返回上一级
			break;
			;
	//[1]烹饪
		case 49:
		//停止营业不给煮饭
			if (!restaurant->GetOpenState()) {
				std::cout << yellow << "现在好像还没有开门吧(-_-)……\n";
				system("pause");
				system("cls");
				return KitchenUI();
			}
		
			break;
			;
	//[2]冰箱
		case 50:
		//跳转冰箱操作界面
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
void RestaurantUI::IceBoxUI(int page){//page为当前页，0为第一页
//冰箱空空如也？
	if (restaurant->ice_box.empty() && player->hand.empty()) {
		std::cout << yellow << "冰箱空空如也(T_T)……\n" << white;
		system("pause");
		system("cls");
		return;
	}
//打印冰箱中的全部食材
	//设置一下最大页数
	int pagemax = (restaurant->ice_box.size() % 10 == 0) ? (restaurant->ice_box.size() / 10) : ((restaurant->ice_box.size() / 10) + 1);
	//打印当前页循环的次数
	int range;
	if (( page + 1) * 10 > restaurant->ice_box.size()) {
		range = restaurant->ice_box.size() % 10;
	}
	else {
		range = 10;
	}
	//打印预览的页数
	std::cout << blue << "Page:" << page + 1 << "/" << pagemax << Back << yellow;
//打印冰箱内部物品
	if (!restaurant->ice_box.empty()) {
	//冰箱有货！
		for (int i = page * 10; i < range;) {
			std::cout << "[" << i << "]" << restaurant->ice_box[i]->name << "		存货：" << restaurant->ice_box[i]->possession << Back;
			i++;
		}
	}
	else {
	//冰箱空空如也
		std::cout << yellow << "冰箱空空如也(T_T)……\n" << white;
	}
//操作界面
	std::cout << green << "输入冰箱食材前的序数取出食材\n[Q]/[E]向前/向后翻页\n[Esc]退出冰箱\n" << white;
	//列出手持物品
	std::cout << blue << "手持：\n" << white;
	for (int i = 0; i < player->hand.size();) {
		std::cout << yellow << player->hand[i]->name << "	" << white;
		i++	;	
	}
	std::cout << Back << green << "[R]/[F]将左右手物品放回冰箱\n";
	int input = 0;
	while (1) {
		input = _getch();
	//拿取物品
		if (input >= 48 && input <= 57){
		//防止向量溢出
			if (page*10 + input - 48 >= restaurant->ice_box.size()) {
				//超出冰箱的容量大小重复循环
				continue;
			}
		//取出物品
			//手只能同时拿两个东西
			if (player->hand.size() >= 2) {
				continue;
			}
			//取出
			player->hand.push_back(restaurant->ice_box[page * 10 + input - 48]);
			restaurant->ice_box[page * 10 + input - 48]->possession -= 1;
			//取出后若该食材存有量为0则移出冰箱
			if (restaurant->ice_box[page * 10 + input - 48]->possession == 0) {
				restaurant->ice_box.erase(restaurant->ice_box.begin() + (page * 10 + input - 48));
			}
			//取出商品后若当前页为空则返回上一页
			if (page * 10 >= restaurant->ice_box.size() && page > 0) {
				page -= 1;
			}
			system("cls");
			return this->IceBoxUI(page);
		}
	//其它
		switch (input){
	//退出冰箱
		case 27:
			return;
			break;
			;
	//翻页
		//[Q]向前翻页
		case 113:
			//防止页数为0
			if (page - 1 < 0) {
				page = 0;
				continue;
			}
			page -= 1;
			system("cls");
			return this->IceBoxUI(page);
			break;
			;
		//[E]向后翻页
		case 101:
			//检查是否越界
			if ((page + 1) * 10 > restaurant->ice_box.size()) {
				continue;
			}
			page += 1;
			break;
			;
		//把手上的东西放回冰箱中
		//[R]将左手物品放回冰箱
		case 114:
			//防向量越界
			if (player->hand.size() < 1) {
				continue;
			}
		//存入
			//以加值的形式存入
			if (player->hand[0]->possession > 0) {
				player->hand[0]->possession += 1;
				player->hand.erase(player->hand.begin());
				system("cls");
				return this->IceBoxUI(page);
			}
			//以加入新元素的形式存入
			restaurant->ice_box.push_back(player->hand[0]);
			restaurant->ice_box.back()->possession += 1;
			player->hand.erase(player->hand.begin());
			system("cls");
			return this->IceBoxUI(page);
			break;
			;
		//[F]将右手物品放回冰箱
		case 102:
			//防向量越界
			if (player->hand.size() < 2) {
				continue;
			}
			//存入
				//以加值的形式存入
			if (player->hand[1]->possession != 0) {
				player->hand[1]->possession += 1;
				player->hand.erase(player->hand.begin() + 1);
				system("cls");
				return this->IceBoxUI(page);
			}
			//以加入新元素的形式存入
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

}
;