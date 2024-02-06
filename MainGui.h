#ifndef MAINGUI_H
#define MAINGUI_H
class MainGui{
public:
	void GameStart();					//游戏开始主菜单
	void ReadSaveFlie();				//读取存档
	void NewGame();						//新游戏
	void CreateNewSave();				//新建存档
private:

};
extern MainGui* main_weight;
#endif
