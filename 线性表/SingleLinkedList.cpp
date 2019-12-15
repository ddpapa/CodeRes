/*单链表全部代码*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}Node,* LinkList; 
int length;		//数组长度
//尾插法建立单链表
/*void CreateList(LinkList L, int * a, int i)
{
	Node * node;
	Node * head = L;
	while(i < length)
	{
		node = (Node *)malloc(sizeof(Node));
		node->data = *(a+i);
		node->next = NULL;
		L->next = node;
		L = L->next;
		printf("%d",node->data);
		i++;
	}
	L = head;
}*/

//头插法建立单链表
void CreateList(LinkList L, int *a, int i)
{
	Node * head;
	Node * node;
	while(i < length)
	{
		node = (Node *)malloc(sizeof(Node));
		node->data = *(a + length - ++i);
		node->next = L->next;
		L->next = node;
	}
}

//打印链表
void PrintList(LinkList L)
{
	printf("打印结果：\n");
	for(int j = 0; j < length; j++)
	{
		L = L->next;
		printf("%d\t",L->data);
	}
	printf("\n");
}

//删除表
void DeleteList(LinkList L)
{
	while(L->next != NULL)
	{
		Node *t = L->next;
		L->next = L->next->next;
		free(t);
	}
	printf("删除成功\n");
}
//查找第i个结点
Node* GetNode(LinkList L, int i)
{
	for(int j = 0; j < i; j++)
	{
		L = L->next;
	}
	return L;
}

//查找结点位置
int Locate(LinkList L, int x)
{
	for(int j = 0; j < length; j++)
	{
		L = L->next;
		if(L->data == x)
			break;
	}
	return ++j;
}

//插入结点
void Insert(LinkList L, int i, int x)
{
	Node *node;
	node = (Node *)malloc(sizeof(Node));
	node->data = x;
	for(int j = 0; j < i - 1; j++)
	{
		L = L->next;
	}
	Node *t;
	t = L->next;
	L->next = node;
	node->next = t;
	length++;
}

//删除指定位置结点
void DeleteNode(LinkList L, int i)
{
	for(int j = 0; j < i - 1; j++)
	{
		L = L->next;
	}
	Node *t;
	t = L->next;
	L->next = L->next->next;
	free(t);
	length--;
}

//删除指定结点
void DeleteData(LinkList L, int x)
{
	int i = Locate(L, x);
	if(i > length)
		printf("删除元素不存在");
	else
		DeleteNode(L, i);
}

int main()
{
	int a[100];
	int i = 0;
	int x;		//需要查找的元素
	Node *node;
	LinkList L;		//建立一个头结点
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;
	printf("请输入链表的长度：\n");
	scanf("%d",&length);
	for(; i < length; i++)
	{
		scanf("%d",&a[i]);
		if(getchar() == '\n')
			break;
	}
	//建立链表
	CreateList(L, a, 0);
	PrintList(L);

	//查找结点
	printf("请输入查找的节点位置：\n");
	scanf("%d",&i);
	node = GetNode(L, i);
	printf("查找结果：%d\n",node->data);

	//定位结点
	printf("请输入查找的元素：\n");
	scanf("%d",&x);
	if(Locate(L,x) > length)
		printf("元素不存在!\n");
	else
		printf("查找结果：%d\n",Locate(L, x));

	//插入结点
	printf("请输入要插入的位置和插入结点：\n");
	scanf("%d%d",&i,&x);
	Insert(L, i, x);
	PrintList(L);

	//删除指定位置元素
	printf("请输入删除的位置：\n");
	scanf("%d",&i);
	DeleteNode(L, i);
	PrintList(L);

	//删除元素
	printf("请输入删除的元素：\n");
	scanf("%d",&x);
	DeleteData(L, x);
	PrintList(L);

	//删除表
	DeleteList(L);
	return 0;
}

