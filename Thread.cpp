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
	//�Ƚ��߳��Զ�����ָ���ַȷ��λ��
		if (threads[i] == this) {
		//�Ƴ��̼߳�
			threads.erase(threads.begin() + i);
		//����
			break;
		}
		i++;
	}
//�ͷ��߳��ڴ�
	delete trdworker;
//��ֹ����
	trdworker = nullptr;
	return;
}
;


std::thread::id Thread::GetThreadID() { return trdworker->get_id(); }