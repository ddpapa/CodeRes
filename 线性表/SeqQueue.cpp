#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct
{
	int element[MAXSIZE];
	int front;
	int rear;
}SeqQueue;

//��ʼ������
void InitQueue(SeqQueue* Q)
{
	Q->front = Q->rear = 0;
}

//�ж��Ƿ����
bool IsFull(SeqQueue* Q)
{
	if((Q->rear+1) % MAXSIZE == Q->front)
		return true;
	else
		return false;
}

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(SeqQueue* Q)
{
	if(Q->rear == Q->front)
		return true;
	else
		return false;
}

//��Ӳ���
void EnterQueue(SeqQueue* Q, int x)
{
	if(IsFull(Q))
		printf("�����������޷����!!\n\n");
	else
	{
		Q->element[Q->rear] = x;
		Q->rear = (Q->rear+1) % MAXSIZE;
		printf("%d��ӳɹ�!!\n",x);
	}
}

//���Ӳ���
void DeleteQueue(SeqQueue* Q)
{
	if(IsEmpty(Q))
		printf("����Ϊ�գ�����ʧ��!!\n");
	else
	{
		printf("%d����!\n",Q->element[Q->front]);
		Q->front = (Q->front+1) % MAXSIZE;
	}
}

//��������
SeqQueue* CreateQueue()
{
	SeqQueue* Q;
	Q = (SeqQueue*)malloc(sizeof(SeqQueue));
	InitQueue(Q);
	int x;	//���Ԫ��
	char c;	//������־
	while(1)
	{
		scanf("%d",&x);
		EnterQueue(Q, x);
		c = getchar();
		if(c == '\n')
			break;
	}
	printf("�����ɹ�\n");
	return Q;
}

//���ٶ���
void DisposeQueue(SeqQueue* Q)
{
	free(Q);
	Q = NULL;
}

//��ӡ����
void PrintQueue(SeqQueue* Q)
{
	if(IsEmpty(Q))
		printf("����Ϊ�գ���ӡʧ��!!\n");
	else
	{
		printf("��ӡ�����");
		int i = Q->front;
		while(1)
		{
			printf("%d\t",Q->element[i]);
			i = (i + 1) % MAXSIZE;
			if(i == Q->rear)
				break;
		}
		printf("\n��ӡ�ɹ�!!\n");
	}
}
int main()
{
	SeqQueue* L;
	L = CreateQueue();
	PrintQueue(L);
	EnterQueue(L,5);
	PrintQueue(L);
	DeleteQueue(L);
	PrintQueue(L);
	DisposeQueue(L);
	return 0;
}