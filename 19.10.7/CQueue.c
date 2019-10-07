#include"CQueue.h"

//�½�ѭ������
CQueue* Init_CQueue()
{
	CQueue* cq;
	cq = (CQueue*)malloc(sizeof(CQueue));
	cq->front = 0;
	cq->rear = 0;
	cq->num = 0;
	return cq;
}

//��ѯѭ�����еĳ���
int Count_CQueue(CQueue* cq)
{
	if (cq == NULL)
		return -1;

	return cq->num;
}

//��ѭ������
int Out_CQueue(CQueue* cq,CQueueData* Data)
{
	if (cq == NULL || Data == NULL)
		return 0;
	if (cq->num == 0)
		return 0;

	*Data = cq->Data[cq->front];
	cq->front = (cq->front + 1) % CQueueMaxSize;
	cq->num = cq->num - 1;
	return 1;
}

//��ѭ������
int In_CQueue(CQueue* cq, CQueueData Data)
{
	if (cq == NULL)
		return 0;
	if (cq->num == CQueueMaxSize)
		return 0;

	cq->Data[cq->rear] = Data;
	cq->rear = (cq->rear + 1) % CQueueMaxSize;
	cq->num = cq->num + 1;
	return 1;
}

//ȡѭ������ͷ��Ԫ��
int GetFront_CQueue(CQueue* cq,CQueueData* Data)
{
	if (cq == NULL || Data == NULL)
		return 0;
	if (cq->num == 0)
		return 0;

	*Data = cq->Data[cq->front];
	return 1;
}

//���ѭ������
int Clear_CQueue(CQueue* cq)
{
	if (cq == NULL)
		return 0;

	cq->front = 0;
	cq->rear = 0;
	cq->num = 0;
	return 1;
}

//����ѭ������
int Destory_CQueue(CQueue** cq)
{
	if (cq == NULL)
		return 0;
	if (*cq == NULL)
		return 1;

	free(*cq);
	*cq = NULL;
	return 1;

}








