#include "Restaurant.h"
void Restaurant::SetLevel(int num){level = num; return;}

void Restaurant::SetCostomerMax(int num){cosmax = num; return;}

void Restaurant::SetWareHouseMax(int num){warehouse = num; return;}

void Restaurant::SetOpenState(bool state) { open = state; return; }

bool Restaurant::GetOpenState() { return open; }
