#include "Restaurant.h"
void Restaurant::SetLevel(int num){level = num; return;}

void Restaurant::SetCostomerMax(int num){cosmax = num; return;}

void Restaurant::SetWareHouseMax(int num){warehouse = num; return;}

bool Restaurant::GetOpenState() { return openstate; }

void Restaurant::SetOpenState(bool set_state) { 
	//设置营业状态为开始营业
	if (set_state) {
		openstate = set_state;
		return;
	}
	;
	//设置营业状态为停止营业
	if (!set_state) {
		
		openstate = set_state;
		return;
	}
	return;
}
;
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
