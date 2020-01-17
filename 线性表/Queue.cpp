#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct QueueNode
{
	int data;	//������
	struct QueueNode * next;	//ָ����
}LinkQueueNode;
typedef struct
{
	LinkQueueNode * front;
	LinkQueueNode * rear;
}LinkQueue;

//��ʼ�����У����ÿն���
void InitQueue(LinkQueue* Q)
{
	Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front == NULL)
		printf("��ʼ��ʧ��!!\n");
	else
	{
		Q->front->next = NULL;
		Q->rear = Q->front;
		printf("��ʼ���ɹ�!!\n");
	}
}

//�ж��Ƿ�Ϊ�ն���
bool IsEmpty(LinkQueue* Q)
{
	if(Q->front == Q->rear)		return true;
	else		return false;
}

//�����
void EnterQueue(LinkQueue* Q,int x)
{
	LinkQueueNode* NewNode;
	NewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if(NewNode == NULL)
		printf("�������!!\n");
	else
	{
		NewNode->data = x;
		NewNode->next = NULL;
		Q->rear->next = NewNode;
		Q->rear = NewNode;
		printf("��ӳɹ�!!\n");
	}
}

//������
void DeleteQueue(LinkQueue* Q)
{
	if(IsEmpty(Q))
		printf("����Ϊ�գ��޷����г����в���!!\n");
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
		printf("����Ԫ��%d���ӳɹ�!!\n",x);
	}
}

//��ӡ����
void PrintQueue(LinkQueue* Q)
{
	LinkQueueNode * head;
	head = Q->front;
	if(IsEmpty(Q))
		printf("����Ϊ�գ��޷���ӡ!!\n");
	else
	{
		printf("��ӡ�����");
		while(head->next != NULL)
		{
			head = head->next;
			printf("%d\t",head->data);
		}
		printf("\n��ӡ�ɹ�!!\n");
	}
}

//��������
void CreateQueue(LinkQueue* Q)
{
	//1.��ʼ��һ������

	InitQueue(Q);

	//2.ѭ�����

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

	//3.��ӡ����

	PrintQueue(Q);

	//4.�����ɹ�

	printf("�����ɹ�!!\n\n");
}

//���ٶ���
void DisposeQueue(LinkQueue* Q)
{
	while(Q->front != Q->rear)
		DeleteQueue(Q);
	printf("�������ٳɹ�!!\n");
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