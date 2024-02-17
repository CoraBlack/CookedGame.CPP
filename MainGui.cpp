#include "MainGui.h"
#include "statement.h"
#include "conio.h"
#include "iomanip"
;
void MainGui::GameStart() {
	system("cls");
//输出内容
	std::cout << yellow << "Cooked！" << std::endl;
	std::cout << green << "[Tab]新游戏\n[Space]读取游戏\n[Esc]设置" << white << std::endl;
//选择
	while (1) {
		int input = _getch();//获取键盘输入
		//测试用（查看输入值）
		//std::cout << input << std::endl;
		switch (input) {
		case 9://Tab
			system("cls");
			std::cout << yellow << "你真的需要创建一个新游戏吗?\n" 
					  << green << "[Tab]确定创建新游戏\n[Esc]取消创建" << std::endl;
			input = 0;//重置输入值
			//确定创建
			while (1) {
				input = _getch();
				switch (input) {
				case 9://Tab
					system("cls");
					return this->CreateNewSave();
					break;
				case 27://Esc
					input = 0;
					system("cls");
					return this->GameStart();
					break;
				default:
					break;
				}
			}
			break;
		case 32://Space
			return this->ReadSave();
			break;
		case 27://Esc
			system("cls");
			SettingMenu();
			return GameStart();
			break;
		default:
			break;
		}
	}
}
;
void MainGui::ReadSave() {
//输入文件名称
	system("cls");
	std::cout << yellow << "请输入您的存档名称(输入Exit退出输入)" << white << Back;
	getline(std::cin, save_name);
	if (save_name == "") {//防止为空
		system("cls");
		std::cerr << red << "存档名称不能为空！！！" << white << Back;
		system("pause");
		return ReadSave();
	}
	else if (save_name == "Exit") {//输入Exit时
		system("cls");
		return this->GameStart();
	}
	save_name += ".txt";
//获取文件内容输入流
	std::ifstream getfile;
	getfile.open(save_name, std::ios::in);

//存档验证
	bool check = CheckSave();
	if (!check) {
		system("pause");
		return this->ReadSave();
	}

	std::cout << yellow << "正在读取数据，存档名" << green << save_name << white << Back;
		
//读档过程
	ReadSaveAll();
//进入游戏
	std::cout << green << "存档读取完毕\n" << white;
	system("pause");
	system("cls");
//展示存档信息
	std::cout << blue << "存档信息:\n"
		<< yellow << "用户名:\t" << green << player->GetPlayerName() << Back
		<< yellow << "钱财:\t" << green << std::setprecision(2) << std::fixed << player->GetPlayerMoney() << Back
		<< yellow << "小摊:\t" << green << "Level " << restaurant->GetLevel() << Back
		<< yellow << "营业额:\t" << green << std::setprecision(2) << std::fixed << restaurant->GetTurnover() << Back
		<< white;
//验证初始化
	if (!initalize_state) {		//初始化未完成
		std::cout << "等待初始化……\n";
		while (1){
			Sleep(500);			//0.5秒检测一次初始化是否成功
			if (initalize_state) {
				return res_weight->MainResMenu();
			}
		}
	}
	system("pause");
	system("cls");
	return res_weight->MainResMenu();
}
;
void MainGui::NewGame() {
	system("cls");
//打开帮助界面
	std::cout << yellow << "在开始游戏前,您有必要看一遍游戏的帮助手册\n" << white;
	Help();
	std::cout << blue << "正在前往您的摊位\n" << white;
	Loading(10);
//新游戏引入

//转向摊子操作界面
	return res_weight->MainResMenu();
}
;
void MainGui::CreateNewSave() {
//输入新存档名称
	std::cout << yellow << "输入新的存档名称:" << white << Back;
	getline(std::cin, save_name);
//防止输入内容为空
	if (save_name == "") {
		system("cls");
		std::cerr << red << "存档名称不能为空！！！" << white << Back;
		return this->CreateNewSave();
	}
	else if (save_name == "Exit") {//禁用Exit作为存档名
		system("cls");
		std::cerr << red << "程序中借用了Exit作为程序操作字符，不可使用该字符作为存档名" << white << Back;
		save_name = "";
		return this->CreateNewSave();
	}
//补全文件格式
	save_name += ".txt";
//检查是否已存在该存档
	std::fstream savefile(save_name);
	if (savefile.good()) {
	//检测到重名文件(有bug目前)
		std::cerr << yellow << "Warning:检测到存档文件已存在，是否继续创建？\n" 
				  << green << "[Space]继续\n[Esc]返回\n" << white;
		int input = 0;
	//输入为Space时继续
		do {
			input = _getch();
			if (input == 27) {
			//输入ESC时重新创建
				system("cls");
				return this->GameStart();
			}
		} while (input != 32);//强制创建同名文件
	}
//继续创建
	std::ofstream newsave;
	newsave.open(save_name, std::ios::out);
	if (!newsave.is_open()) {
		std::cerr << red << "Wrong!文件无法创建(无法打开文件),即将返回开始菜单\n" << white;
		Sleep(3000);
	}
	else {
		//写入验证字符
		newsave << checkword;
		std::cout << green << "创建了新的存档" << yellow << save_name << Back << white;
		newsave.close();
		newsave.clear();
		system("pause");
	}
//检查初始化
	if (!initalize_state) {		//初始化未完成
		std::cout << "等待初始化……\n";
		while (1) {
			Sleep(500);			//0.5秒检测一次初始化是否成功
			if (initalize_state) {
				return this->NewGame();
			}
		}
	}
	return this->NewGame();

}
;
void MainGui::Help(){
	int input = 0;
	while (1) {
		std::cout << blue
			<< "小帮手:\n" << yellow
			<< "[1]关于摊位\n[2]关于顾客系统\n[3]关于烹饪系统\n[Esc]退出小帮手\n"
			<< white;
		input = _getch();
		switch (input){
	//[1]关于摊位的说明
		case 49:
			system("cls");
			break;
			;
	//[2]关于顾客系统的说明
		case 50:
			system("cls");
			std::cout << blue << "基本操作:\n" << white
				<< "顾客会在不定时的来到您的摊位前，向你明确它的需求\n"
				<< "您尽量要在最短的时间内出餐，您才可以是您的收益最大化\n"
				<< "您需要观察什么食品的走向最好，以便您能够更好的服务顾客且不会出现食材浪费\n"
				<< "或者不会因为食材过多导致您时间上的浪费\n"
				<< "顾客的等待时间，也就是他们的耐心，它不会显现在您的屏幕上，你只能速度!!!\n";
			system("pause");
			system("cls");
			break;
			break;
			;
	//[3]烹饪系统的说明
		case 51:
			system("cls");
			std::cout << blue << "基本操作:\n"
				<< white << "您需要带上您的食材，放在你的小摊子里出摊\n"
				<<"您要慎重考虑您应该带什么，以应对不同顾客的需求\n"
				<< "您可以在出摊前在后厨准备好您的预制食品\n"
				<< "以可以更快的出餐\n"
				<<"缩短您的出餐时间可以获得更多的额外收入喔(小费)\n"
				<<"但是，您要知道预制食品它的保存时间是很短的，您需要在一轮出餐中全部售完\n"
				<<"否则，您就要将所有预制食品丢弃，我相信，您一定是以为有素质的摊主\n"
				<< "您可以使用更高级的食材去烹饪相同的美食，以获取更高的利润和更好的口碑\n"
				<< "当然，更高的价格也意味着更少的顾客，因为消费能力是有限的\n"
				<< "您可以选择去采购预制食品，虽然可能性价比不高，但是可以很大的去缩减您的时间成本\n";
			system("pause");
			system("cls");
			break;
			;
	//[Esc]退出小帮手
		case 27:
			return;
			break;
			;
		default:
			system("cls");
			break;
		}
	}
}
;