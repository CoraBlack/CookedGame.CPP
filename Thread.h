//�߳���
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
	void ThreadStop();	//��ֹ����
	void ThreadPause();	//��ͣ����
	void ThreadRun();	//��������
private:
<<<<<<< HEAD
	std::thread trd;	//�߳�
	bool state = 0;		//�߳�״̬��0Ϊֹͣ��1Ϊ����
=======
	bool state = 0;//�߳�״̬��0Ϊֹͣ��1Ϊ����
>>>>>>> c903271ae81cd1d839576afdfa3e32bd9ddd82a0
};
#endif
