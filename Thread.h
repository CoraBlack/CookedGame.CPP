//线程类
#ifndef THREAD_H
#define THREAD_H
#include<thread>
#include<mutex>
#include <functional> 
class Thread{
public:
	Thread(std::function <void()> func);			//构造函数，构造后台线程
	std::thread::id GetThreadID();					//获取线程的ID
	~Thread();										//析构函数，终止进程
private:
	std::thread* trdworker;						//线程
	bool state = 0;								//线程状态，0为停止，1为运行
};
#endif
