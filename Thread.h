//�߳���
#ifndef THREAD_H
#define THREAD_H
class Thread
{
public:
	void ThreadStop();	//��ֹ����
	void ThreadPause();	//��ͣ����
	void ThreadRun();	//��������
private:
	bool state = 0;//�߳�״̬��0Ϊֹͣ��1Ϊ����
};
#endif
