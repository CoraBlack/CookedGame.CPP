#include "Thread.h"
#include"statement.h"

//���캯�����������Customer���߳�
Thread::Thread(std::function <void()> func){
	//��ֵ�������ڴ�
	trdworker = nullptr;
	trdworker = new std::thread(func);
	//�����̼߳�
	threads.push_back(this);
	//�̹߳����̨
	trdworker->detach();
	return;
}
;


//������������ֹ����
Thread::~Thread(){
//�����߳��ڼ��е�λ��
	for (int i = 0; i < threads.size();) {
	//�Ƚ��߳�ID��
		if (threads[i]->trdworker->get_id() == this->GetThreadID()) {
		//�Ƴ��̼߳�
			threads.erase(threads.begin() + i);
			break;
		}
		i++;
	}
//�ͷ��߳��ڴ�
	delete trdworker;
}
;


std::thread::id Thread::GetThreadID() { return trdworker->get_id(); }





;
/*
void Thread::PauseThread(){
	mtx_pause.lock();
//ÿ0.2������ͣ״̬
	while (1) {
		if (pausestate){
			//������ָ��߳�
			mtx_pause.unlock();
			break;
		}
	}
	return;
}
;
*/