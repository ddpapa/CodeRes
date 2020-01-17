#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30
typedef struct
{
	int element[MAXSIZE];
	int front;
	int rear;
}SeqQueue;

//初始化队列
void InitQueue(SeqQueue* Q)
{
	Q->front = Q->rear = 0;
}

//判断是否溢出
bool IsFull(SeqQueue* Q)
{
	if((Q->rear+1) % MAXSIZE == Q->front)
		return true;
	else
		return false;
}

//判断队列是否为空
bool IsEmpty(SeqQueue* Q)
{
	if(Q->rear == Q->front)
		return true;
	else
		return false;
}

//入队操作
void EnterQueue(SeqQueue* Q, int x)
{
	if(IsFull(Q))
		printf("队列已满，无法入队!!\n\n");
	else
	{
		Q->element[Q->rear] = x;
		Q->rear = (Q->rear+1) % MAXSIZE;
		printf("%d入队成功!!\n",x);
	}
}

//出队操作
void DeleteQueue(SeqQueue* Q)
{
	if(IsEmpty(Q))
		printf("队列为空，出队失败!!\n");
	else
	{
		printf("%d出队!\n",Q->element[Q->front]);
		Q->front = (Q->front+1) % MAXSIZE;
	}
}

//创建队列
SeqQueue* CreateQueue()
{
	SeqQueue* Q;
	Q = (SeqQueue*)malloc(sizeof(SeqQueue));
	InitQueue(Q);
	int x;	//入队元素
	char c;	//结束标志
	while(1)
	{
		scanf("%d",&x);
		EnterQueue(Q, x);
		c = getchar();
		if(c == '\n')
			break;
	}
	printf("创建成功\n");
	return Q;
}

//销毁队列
void DisposeQueue(SeqQueue* Q)
{
	free(Q);
	Q = NULL;
}

//打印队列
void PrintQueue(SeqQueue* Q)
{
	if(IsEmpty(Q))
		printf("队列为空，打印失败!!\n");
	else
	{
		printf("打印结果：");
		int i = Q->front;
		while(1)
		{
			printf("%d\t",Q->element[i]);
			i = (i + 1) % MAXSIZE;
			if(i == Q->rear)
				break;
		}
		printf("\n打印成功!!\n");
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