#ifndef MAINGUI_H
#define MAINGUI_H
class MainGui{
public:
	void GameStart();					//��Ϸ��ʼ���˵�
	void ReadSaveFlie();				//��ȡ�浵
	void NewGame();						//����Ϸ
	void CreateNewSave();				//�½��浵
	void Help();						//����
private:

};
extern MainGui* main_weight;
#endif
