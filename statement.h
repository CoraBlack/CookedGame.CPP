//声明全局变量和函数的区块
//用于供其它文件引用
#include<string>
#ifndef STATEMENT_H
#define STATEMENT_H
extern std::string red;
extern std::string yellow;
extern std::string green;
extern std::string white;
void GameStart();
void PrintVerbatim(std::string str);
void Initialize();	
#endif