#include"CQueue.h"

//新建循环队列
CQueue* Init_CQueue()
{
	CQueue* cq;
	cq = (CQueue*)malloc(sizeof(CQueue));
	cq->front = 0;
	cq->rear = 0;
	cq->num = 0;
	return cq;
}

//查询循环队列的长度
int Count_CQueue(CQueue* cq)
{
	if (cq == NULL)
		return -1;

	return cq->num;
}

//出循环队列
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

//入循环队列
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

//取循环队列头部元素
int GetFront_CQueue(CQueue* cq,CQueueData* Data)
{
	if (cq == NULL || Data == NULL)
		return 0;
	if (cq->num == 0)
		return 0;

	*Data = cq->Data[cq->front];
	return 1;
}

//清空循环队列
int Clear_CQueue(CQueue* cq)
{
	if (cq == NULL)
		return 0;

	cq->front = 0;
	cq->rear = 0;
	cq->num = 0;
	return 1;
}

//销毁循环队列
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








