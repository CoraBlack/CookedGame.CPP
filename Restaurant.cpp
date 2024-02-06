#include "Restaurant.h"
void Restaurant::SetLevel(int num){level = num; return;}

void Restaurant::SetCostomerMax(int num){cosmax = num; return;}

void Restaurant::SetWareHouseMax(int num){warehouse = num; return;}

<<<<<<< HEAD
void Restaurant::SetOpenState(int state) { openstate = (bool)state; return; }

bool Restaurant::GetOpenState() { return openstate; }
=======
void Restaurant::SetOpenState(bool state) { open = state; return; }

bool Restaurant::GetOpenState() { return open; }
>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
