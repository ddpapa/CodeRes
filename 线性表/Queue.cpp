#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct QueueNode
{
	int data;	//数据域
	struct QueueNode * next;	//指针域
}LinkQueueNode;
typedef struct
{
	LinkQueueNode * front;
	LinkQueueNode * rear;
}LinkQueue;

//初始化队列，即置空队列
void InitQueue(LinkQueue* Q)
{
	Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front == NULL)
		printf("初始化失败!!\n");
	else
	{
		Q->front->next = NULL;
		Q->rear = Q->front;
		printf("初始化成功!!\n");
	}
}

//判断是否为空队列
bool IsEmpty(LinkQueue* Q)
{
	if(Q->front == Q->rear)		return true;
	else		return false;
}

//入队列
void EnterQueue(LinkQueue* Q,int x)
{
	LinkQueueNode* NewNode;
	NewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if(NewNode == NULL)
		printf("队列溢出!!\n");
	else
	{
		NewNode->data = x;
		NewNode->next = NULL;
		Q->rear->next = NewNode;
		Q->rear = NewNode;
		printf("入队成功!!\n");
	}
}

//出队列
void DeleteQueue(LinkQueue* Q)
{
	if(IsEmpty(Q))
		printf("队列为空，无法进行出队列操作!!\n");
	else
	{
		int x;
		LinkQueueNode * Node;
		Node = Q->front->next;
		Q->front->next = Node->next;
		if(Q->rear == Node)
			Q->rear = Q->front;
		x = Node->data;
		free(Node);
		printf("队列元素%d出队成功!!\n",x);
	}
}

//打印队列
void PrintQueue(LinkQueue* Q)
{
	LinkQueueNode * head;
	head = Q->front;
	if(IsEmpty(Q))
		printf("队列为空，无法打印!!\n");
	else
	{
		printf("打印结果：");
		while(head->next != NULL)
		{
			head = head->next;
			printf("%d\t",head->data);
		}
		printf("\n打印成功!!\n");
	}
}

//创建队列
void CreateQueue(LinkQueue* Q)
{
	//1.初始化一个队列

	InitQueue(Q);

	//2.循环入队

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

	//3.打印队列

	PrintQueue(Q);

	//4.创建成功

	printf("创建成功!!\n\n");
}

//销毁队列
void DisposeQueue(LinkQueue* Q)
{
	while(Q->front != Q->rear)
		DeleteQueue(Q);
	printf("队列销毁成功!!\n");
}

int main()
{
	LinkQueue L;
	CreateQueue(&L);
	EnterQueue(&L,5);
	PrintQueue(&L);
	DeleteQueue(&L);
	PrintQueue(&L);
	DisposeQueue(&L);
	return 0;
}