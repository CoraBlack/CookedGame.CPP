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
		//新建后台顾客线程
			//检测线程是否已存在
			if (createtrd == nullptr) {
				createtrd = nullptr;
				createtrd = new Thread(CreateCustomer);
			}
		//设置营业状态
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
			  << "[Tab]切换营业状态\n[F]制作美食\n[R]顾客请求\n[Esc]暂停游戏\n" << white;
	int input = 0;
	while (1){
		input = _getch();
		switch (input) {
	//[Tab]收摊
		case 9:
		//营业状态当前为营业时
			if (restaurant->GetOpenState()) {
			//设置为停止营业
				restaurant->SetOpenState(0);
			//顾客未清空
				if (!customers.empty()) {
					std::cout << yellow << "您还有客人未离开!我们已经调整营业状态为停止，等待客人全部离开\n" << white;
					//初始化输入值
					input = 0;
				//重复循环
					continue;
				}
			//顾客已清空
				//清空线程集
				for (int i = 0; i < threads.size();) {
					delete threads[i];
					i++;
				}
				return;
			}

		//营业状态为停止营业时
			//设置状态为营业
			restaurant->SetOpenState(1);
		//启动顾客生成程序
			//检测生成程序已经存在
			if (createtrd != nullptr) {	
				continue;
			}
			//生成程序线程指针为空,重新生成
			createtrd = nullptr;
			createtrd = new Thread(CreateCustomer);
			break;
			;
	//[F]制作美食
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

		//游戏正在运行
			if (!pausestate){
				PauseGame();
			}
			else {
		//游戏已暂停
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
	system("cls");
	while (1) {
		std::cout << blue << "烹饪!\n" << white;
		std::cout << green << "[Tab]烹饪手册\n[F]返回\n[Esc]暂停\n" << white;
		switch ((int)_getch()){
		//[Tab]烹饪手册
		case 9:
			HandBookUI();
			return this->CookedUI();
			break;

		//[F]返回
		case 102:
			system("cls");
			return;
			break;

		//[Esc]暂停游戏
		case 27:
			//游戏正在运行
			if (!pausestate) {
				PauseGame();
			}
			else {
				//游戏已暂停
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

	//没有顾客
	if (customers.empty()) {
		system("cls");
		std::cout << yellow << "还没有客人，再等等吧……\n";
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
	std::cout << green << "选择选项前的数字以对目标顾客进行操作\n"
		<< "[Esc]返回\n" << white;

	int input = _getch();

	//选择
	if (input >= 48 && input <= 57) {
		if (input - 48 >= customers.size()) {
			return this->ProcessRequit();
		}

		for (int i = 0; i < customers[input - 48]->needs.size();) {
			std::cout << yellow << customers[input - 48]->needs[i].name << "	\n" << white;
			i++;
		}

		std::cout << green << "[Space]提交\n[Esc]返回\n";


		while (1){

			int input2 = _getch();

			//提交
			if (input2 == 32) {
				std::vector<int>nums;

				//检索
				for (int i = 0; i < customers[input - 48]->needs.size();) {
					for (int j = 0; j < finish.size();) {
						//检索成功
						if (finish[j].name == customers[input - 48]->needs[i].name) {
							nums.push_back(j);
							break;
						}
						j++;
					}
					//当前层检索不到
					if (i + 1 != nums.size()) {
						std::cout << yellow << "您还没有准备好这名顾客所需的食物\n";
						system("pause");
						return this->ProcessRequit();
					}
					i++;
				}
				
				//循环正常完成(开始处理数据）
				for (int i = 0; i < nums.size();) {
					finish.erase(finish.begin() + nums[i] - 1);
					i++;
				}
				nums.clear();
				customers[input - 48]->SetNeedsState(1);
				std::cout << green << "提交成功！\n";
				system("cls");
				system("pause");
				return this->ResOpenMenu();
			}

			//返回
			if (input2 == 27) {
				system("cls");
				return this->ProcessRequit();
			}

		}

	}

	//返回
	if (input == 27) {
		return;
	}

	return this->ProcessRequit();
}
;