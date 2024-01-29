//线程类
#ifndef THREAD_H
#define THREAD_H
class Thread
{
public:
	void ThreadStop();	//终止进程
	void ThreadPause();	//暂停进程
	void ThreadRun();	//继续进程
private:
	bool state = 0;//线程状态，0为停止，1为运行
};
#endif
