//线程类
<<<<<<< HEAD
#include<thread>
#ifndef THREAD_H
#define THREAD_H
class Thread{
=======
#ifndef THREAD_H
#define THREAD_H
class Thread
{
>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
public:
	Thread();
	void ThreadStop();	//终止进程
	void ThreadPause();	//暂停进程
	void ThreadRun();	//继续进程
private:
<<<<<<< HEAD
	std::thread trd;	//线程
	bool state = 0;		//线程状态，0为停止，1为运行
=======
	bool state = 0;//线程状态，0为停止，1为运行
>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
};
#endif
