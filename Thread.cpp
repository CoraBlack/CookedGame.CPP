#include "Thread.h"
#include"statement.h"

//构造函数，构造关于Customer的线程
Thread::Thread(std::function <void()> func){
	//传值并分配内存
	trdworker = nullptr;
	trdworker = new std::thread(func);
	//加入线程集
	threads.push_back(this);
	//线程挂入后台
	trdworker->detach();
	return;
}
;


//析构函数，终止进程
Thread::~Thread(){
//检索线程在集中的位置
	for (int i = 0; i < threads.size();) {
	//比较线程ID法
		if (threads[i]->trdworker->get_id() == this->GetThreadID()) {
		//移出线程集
			threads.erase(threads.begin() + i);
			break;
		}
		i++;
	}
//释放线程内存
	delete trdworker;
}
;


std::thread::id Thread::GetThreadID() { return trdworker->get_id(); }





;
/*
void Thread::PauseThread(){
	mtx_pause.lock();
//每0.2秒检查暂停状态
	while (1) {
		if (pausestate){
			//解除锁恢复线程
			mtx_pause.unlock();
			break;
		}
	}
	return;
}
;
*/