#include "Restaurant.h"
void Restaurant::Level_1(){
}
//构造函数
Restaurant::Restaurant(){
//存入食材(默认)	
	all_cuisine.push_back(fry_chicken_chops);
	return;
}
void Restaurant::SetLevel(int num){level = num; return;}

void Restaurant::SetCostomerMax(int num){cosmax = num; return;}

void Restaurant::SetWareHouseMax(int num){warehouse = num; return;}

bool Restaurant::GetOpenState() { return openstate; }

void Restaurant::SetOpenState(bool set_state) { openstate = set_state; return; }

float Restaurant::GetTurnover() { return turnover; }

void Restaurant::SetTurnover(float set) { turnover = set; return; }

void Restaurant::SwapIngredient(ingredient*& ing1, ingredient*& ing2){
	ingredient* temp_ptr = ing1;
	ing1 = ing2;
	ing2 = temp_ptr;
	return;
}
;
void Restaurant::IceBoxSort(){
	int range = ice_box.size() - 1;
	for (int i = 0; i < range;){
		for (int j = 0; j = range - i;) {
			if (ice_box[i]->name > ice_box[i + 1]->name) {
				SwapIngredient(ice_box[i], ice_box[i + 1]);
			}
			j++;
		}
		i++;
	}
	return;
}
