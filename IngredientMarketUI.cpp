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
	std::cout << yellow << "[Esc]返回小餐馆(记得付款喔!)\n[Tab]结账\n[Space]购物车\n" 
			  << green << "[0]全部食材商品\n[1]蔬菜\n[2]肉类\n[3]谷物制品\n[4]调味品\n";
	while (1) {
		int input = _getch();
		switch (input) {
	//商品选择操作
		case 48:

			break;

		case 49://蔬菜类
			system("cls");
			return this->ChooseSomeIngredient(this->vegetable);
			break;

		case 50://肉类
			system("cls");
			return this->ChooseSomeIngredient(this->meat);
			return this->IngredientMarket();
			break;

		case 51:
			return this->ChooseSomeIngredient(this->cereals);
			break;

	//行为操作
		case 32://Space  购物车
			//购物车不能为空
			if (this->shopping_cart.empty()) {
				system("cls");
				std::cout << yellow << "您还没有将您所需的商品加入到购物车中\n" << white;
				system("pause");
				system("cls");
				return this->IngredientMarket();
			}
			;
			this->page = 0;
			system("cls");
			return this->ShoppingCartOperator();
			break;


		case 9://Tab     结账
			//购物车为空跳回
			if (shopping_cart.empty()) {
				system("cls");
				std::cout << yellow << "您还没有挑选您所需要的商品\n"<< white;
				input = 0;
				system("pause");
				return this->IngredientMarket();
			}
			;
			//列出所有已加入购物车的商品
			system("cls");
			std::cout << blue << "您的购物车：\n" << yellow;
			for (int i = 0; i < shopping_cart.size();) {
				std::cout << "[" << i + 1 << "]" << shopping_cart[i]->name << "		单价：" << shopping_cart[i]->price << "\n";
				i++;
			}
			//列出总价和操作内容
			std::cout << "总共需支付" << green << std::setprecision(2) << std::fixed << this->total_price << yellow << "元\n" << green;
			std::cout << "[Space]支付当前商品\n[Tab]清空\n[Esc]返回上一级\n" << white;


			//操作菜单
			while (1){
				input = _getch();
				switch (input){
			
			//Space 付款
				case 32:
				//钱不够
					if (this->total_price > player->GetPlayerMoney()) {
						std::cout << red << "您没有足够的钱支付您的选购商品\n";
						system("pause");
						system("cls");
						return this->IngredientMarket();
					}
				//加载
					std::cout << yellow << "正在给你加速处理！！！\n" << white;
				//结算余额
					player->SetPlayerMoney(player->GetPlayerMoney() - total_price);
				//把购物车中的商品挪到冰箱中
					for (int i = 0; i < shopping_cart.size();) {
					//判断是否应该将内容存入还是增加存货量
						//添加存货量
						if (shopping_cart[i]->possession != 0) {
							shopping_cart[i]->possession += 1;
							i++;
							continue;
						}
						//存入冰箱(新元素)
						restaurant->ice_box.push_back(shopping_cart[i]);
						shopping_cart[i]->possession += 1;
						i++;
					}
					system("cls");
					std::cout << yellow << "欢迎下次光临！您的余额" << green << player->GetPlayerMoney() << "元\n";
					system("pause");
				//清空购物车
					this->shopping_cart.clear();
					return this->IngredientMarket();
					break;
			
			//Tab 清空购物车
				case 9:
					std::cout << yellow << "是否需要清空购物车?\n" 
						<< green << "[Space]清空购物车\n[Esc]返回"  << white;
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
			
			//Esc返回上一级
				case 27:
					return this->IngredientMarket();
					break;

				default:
					break;
				}
			}
			break;
			;
		case 27://Esc   返回上一级
			//检查购物车是否为空
			if (shopping_cart.empty()) {
				return;
			}
			else {
				//购物车不为空
				system("cls");
				std::cout << yellow 
					<< "您的购物车还有未付款的食材商品！\n";
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
//列出购物车清单
//最大翻页量
	int pagemax = (shopping_cart.size() % 10 == 0) ? (shopping_cart.size() / 10) : ((shopping_cart.size() / 10) + 1);
	std::cout << blue << "Page：" << green << page + 1 << "/"
		<< pagemax << yellow << Back;
//防止向量越界（防止打印到空内容）
	int range;	//打印次数
	if ( ( page + 1 ) * 10 > shopping_cart.size()) {
		range = shopping_cart.size() % 10;
	}
	else {
		range = 10;
	}
//打印当前页商品
	for (int i = 0; i < range;) {
		std::cout << "[" << i << "]" << shopping_cart[page*10 + i]->name << "		" 
			      << "单价：" << shopping_cart[page*10 + i]->price << Back;
		i++;
	}
	;
//列出操作提示
	std::cout << green
		<< "选择当前列表商品前的序数从购物车中移除\n[Q]/[E]向前/向后翻页\n"
		<< "[Esc]返回上一级\n" << white;
	;
//移除操作
	int input = _getch();
	if (input >= 48 && input <= 57) {
		int choose_temp = this->page * 10 + input - 48;
	//防止向量越界
		if (choose_temp >= shopping_cart.size()) {
			system("cls");
			return this->ShoppingCartOperator();
		}
	//移除指定元素
		total_price -= shopping_cart[choose_temp]->price;
		this->shopping_cart.erase(shopping_cart.begin() + choose_temp );
	//删除后若当前页元素完全被删除，则向前自动翻页
		if (shopping_cart.size() <= page * 10 && page > 0) {
			page--;
		}
	//删除完元素后若购物车被清空，则返回到上一级
		else if(shopping_cart.empty())
		{
			system("cls");
			std::cout << yellow << "购物车已被清空，再去别的地方瞧瞧吧!\n" << white;
			system("pause");
			system("cls");
			return this->IngredientMarket();
		}
		system("cls");
		return this->ShoppingCartOperator();
	}
//翻页与返回
	switch (input) {
	case 101:		//[E]向后翻页
	//检查是否越界
		if ((page + 1) * 10 >= shopping_cart.size()) {
			system("cls");
			return this->ShoppingCartOperator();
		}
		page += 1;
		system("cls");
		return this->ShoppingCartOperator();
		break;
	case 113:		//[Q]向前翻页
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
		this->page = 0;	//重置页数
		return this->IngredientMarket();
		break;
	default:
		break;
	}
}
;

//缺一个检索功能
void IngredientMarketUI::ChooseSomeIngredient(std::vector<ingredient*>&vec){
	std::cout << blue << "Page:" << green << this->page + 1 << yellow << Back;
//列出当前页食材
	for (int i = 0; i < vec.size();) {
		std::cout << "[" << i << "]" << vec[i]->name << "		" << "单价：" << vec[i]->price << Back;
		i++;
	}
//列出操作
	std::cout << green 
		<< "选择商品前的序数添加至购物车\n[Q]/[E]向前/向后翻页\n"
		<< "[Esc]返回上一级\n" << white;


	while (1){
		int input = _getch();
	//选中商品
		if (input >= 48 && input <= 57) {
			int choose_temp = this->page*10 + input - 48;
		//防止向量越界
			if (choose_temp >= vec.size()) {
				continue;
			}
		//存入购物车
			total_price += vec[choose_temp]->price;
			shopping_cart.push_back(vec[choose_temp]);
			system("cls");
			std::cout << yellow << "已将" << green << vec[choose_temp]->name
				<< yellow << "*1 添加进购物车中" << white << Back;
			return this->ChooseSomeIngredient(vec);
		}


	//其它操作
		switch (input){
		case 101://[E]向后翻页
		//检查是否越界
			if ( (page + 1) * 10 > vec.size()) {
				continue;
			}
			page += 1;
			break;
		case 113://[Q]向前翻页
		//页数不能小于零
			if (page - 1 < 0) {
				page = 0;
				continue;
			}
			page -= 1;
			system("cls");
			return this->ChooseSomeIngredient(vec);
			break;
		case 27://[Esc]
			this->page = 0;	//重置页数
			return this->IngredientMarket();
			break;
		default:
			break;
		}
	}
}
;