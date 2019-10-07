#include"LinkQueue.h"

//�½���ʽ����
LinkQueue* Init_LinkQueue()
{ 
	LinkQueue* p;
	LQueueNode* node;
	p = (LinkQueue*)malloc(sizeof(LinkQueue));
	node = (LQueueNode*)malloc(sizeof(LQueueNode));
	node->next = NULL;
	p->front = node;
	p->rear = node;
	return p;
}

//�ж���ʽ�����Ƿ�Ϊ��
int Empty_LinkQueue(LinkQueue* lq)
{
	if (lq == NULL)
		return -1;

	if (lq->front == lq->rear)
		return 1;
	else
		return 0;
}

//��ʽ�������
int In_LinkQueue(LinkQueue* lq, LinkQueueData data)
{
	LQueueNode* New;
	if (lq == NULL)
		return 0;

	New = (LQueueNode*)malloc(sizeof(LQueueNode));
	New->data = data;
	New->next = NULL;
	lq->rear->next = New;
	lq->rear = New;
	return 1;
}

//��ʽ���г���
int Out_LinkQueue(LinkQueue* lq, LinkQueueData* data)
{
	LQueueNode* Del;
	if (lq == NULL || data == NULL)
		return 0;
	if (lq->front == lq->rear)
		return 0;

	*data = lq->front->next->data;
	Del = lq->front->next;
	lq->front->next = Del->next;
	if (lq->front->next == NULL)
		lq->rear = lq->front;
	free(Del);
	return 1;
}

//ȡ��ʽ����ͷ��Ԫ��
int	GetFront_LinkQueue(LinkQueue* lq, LinkQueueData* data)
{
	if (lq == NULL || data == NULL)
		return 0;
	if (lq->front == lq->rear)
		return 0;

	*data = lq->front->next->data;
	return 1;
}

//�����ʽ����
int Clear_LinkQueue(LinkQueue* lq)
{
	LQueueNode* Del;
	if (lq == NULL)
		return 0;

	while (Empty_LinkQueue(lq) != 1)
	{
		Del = lq->front->next;
		lq->front->next = Del->next;
		if (lq->front->next == NULL)
			lq->rear = lq->front;
		free(Del);
	}
	return 1;
}

//������ʽ����
int Destory_LinkQueue(LinkQueue** lq)
{
	if (lq == NULL)
		return 0;
	if (Clear_LinkQueue(*lq) == 0)
		return 0;

	free((*lq)->front);
	free(*lq);
	*lq = NULL;
	return 1;
}



















