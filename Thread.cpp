#include "Thread.h"
#include"statement.h"

//���캯�����������Customer���߳�
Thread::Thread(std::function <void()> func){
	//��lambda���ʽ��ֵ�������ڴ�
	trdworker = new std::thread(func);
	//�����̼߳�
	threads.push_back(this);
	//��Ϊ�ػ��߳�
	trdworker->detach();
	return;
}
;
//��ֹ����
void Thread::StopThread(){
//�����߳��ڼ��е�λ��
	for (int i = 0; i < threads.size();) {
	//�Ƚ��߳�ID��
		if (threads[i]->trdworker->get_id() == this->trdworker->get_id()) {
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
void Thread::PauseThread(){
	mtx.lock();
//ÿ0.2������ͣ״̬
	while (1) {
		if (pausestate){
			//������ָ��߳�
			mtx.unlock();
			break;
		}
	}
	return;
}
;