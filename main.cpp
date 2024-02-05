//主函数
#include <iostream>
#include"statement.h"
#include<Windows.h>
#include<thread>
using namespace std;
int main(){
    thread initialize(Initialize);//创建一条线程用于处理初始化内容
    initialize.detach();//将初始化进程后台处理

    //开场文字（调试先屏蔽）
    /*
    PrintVerbatim("Hello,Dear Player!\nI am so proud of that you can play my game");
    PrintVerbatim("允许我介绍一边自己：\nCoca Cora");
    Sleep(1000);
    PrintVerbatim("and my good friend AF!!!!!!!!\nWell have a good time!!!");
    system("pause");
    system("cls");
    */
    GameStart();
    return 0;
}
