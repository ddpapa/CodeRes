#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct
{
	//顺序表数据结构
	int elem[MAX_SIZE];
	int last;
}SeqList;


/*****************对表的操作*****************/
//创建表
SeqList *CreateList()
{
	SeqList *seqList;
	int length,i;
	printf("请输入顺序表的长度：");
	scanf("%d",&length);
	if(length > MAX_SIZE)
	{
		printf("输入不合法\n");
	}
	else
	{
		seqList = (SeqList *)malloc(sizeof(SeqList));
		seqList->last = length;
		for(i = 0; i < length; i++)
		{
			scanf("%d",&seqList->elem[i]);
		}
		printf("创建成功!\n");
		return seqList;
	}
	
}

//判断是否为空
bool IsEmpty(SeqList *L)
{
	if(L->last == 0)		return true;
	else		return false;
}

//打印表
void PrintList(SeqList *L)
{	
	int i;
	if(IsEmpty(L))
	{
		printf("顺序表为空!\n");
	}
	else
	{
		printf("输出顺序表：\n");
		for(i = 0; i < L->last; i++)
		{
			printf("%d ",L->elem[i]);
		}
		printf("\n");
	}
}

//删除表
void DestroyList(SeqList *L)
{
	free(L);
	printf("删除成功!\n");
}

//置空表
void ClearList(SeqList *L)
{
	L->last = 0;
	printf("置空完成!\n");
}


/*****************对数据元素进行操作*****************/
//定位元素
void Locate(SeqList *L, int x)
{
	int i;
	for(i = 0; i < L->last; i++)
	{
		if(L->elem[i] == x)
			break;
	}
	if(i == L->last)
	{
		printf("未找到元素!\n");
	}
	else
	{
		printf("查找结果：%d\n",i+1);
	}
}

//查找元素
void GetData(SeqList *L, int i)
{
	if(i >= L->last || i <= 0)
	{
		printf("查找位置不合法!\n");
	}
	else
	{
		printf("查找结果：%d\n",L->elem[i-1]);
	}
}

//插入元素
void InsList(SeqList *L, int i, int x)
{
	if(L->last+1 > MAX_SIZE)
	{
		printf("无法插入元素!\n");
	}
	else
	{
		if(i > L->last+1)
		{
			printf("插入位置错误，无法插入!!\n");
		}
		else
		{
			int j;
			for(j = L->last; j >= i; j-- )
			{
				L->elem[j] = L->elem[j-1];
			}
			L->elem[i-1] = x;
			L->last++;
			printf("插入成功!\n");
		}
	}
}

//删除指定位置元素
void DelList(SeqList *L, int i)
{
	if(i >= L->last || i <= 0)
	{
		printf("删除位置不合法!\n");
	}
	else
	{
		for(; i < L->last; i++)
		{
			L->elem[i - 1] = L->elem[i];
		}
		L->last--;
		printf("删除成功!\n");

	}
}

//删除指定元素
void DelData(SeqList *L, int x)
{
	int i;
	for(i = 0; i < L->last; i++)
	{
		if(L->elem[i] == x)
			break;
	}
	if(i == L->last)
	{
		printf("未找到删除的元素!\n");
	}
	else
	{
		for(i ; i < L->last-1; i++)
		{
			L->elem[i] = L->elem[i+1];
		}
		L->last--;
		printf("删除成功!\n");
	}
}

/*****************主函数*****************/
int main(){
	int i,x,m;
	SeqList *L = NULL;
	while(1)
	{
		printf("######################################################\n");
		printf("#1 创建表                2 打印表                    #\n");
		printf("#3 删除表                4 置空表                    #\n");
		printf("#5 定位元素              6 查找元素                  #\n");
		printf("#7 插入元素              8 删除元素(指定位置)        #\n");
		printf("#9 删除元素(指定元素)    10 退出                     #\n");
		printf("######################################################\n");
		scanf("%d",&m);
		if( L == NULL && m != 1)
		{
			m = 1;
			printf("请创建表后，进行操作!\n");
		}
		if(m == 1){
			//创建表
			L = CreateList();
		}else if(m == 2){
			//打印表
			PrintList(L);
		}else if(m == 3){
			//删除表
			DestroyList(L);
			L = NULL;
		}else if(m == 4){
			//置空表
			ClearList(L);
		}else if(m == 5){
			//定位元素
			if(IsEmpty(L))
			{
				printf("顺序表为空!\n");
			}
			else
			{
				printf("请输入查找的元素：");
				scanf("%d",&x);
				Locate(L, x);
			}
		}else if(m == 6){
			//查找元素
			if(IsEmpty(L))
			{
				printf("顺序表为空!\n");
			}
			else
			{
				printf("请输入查找元素：\n");
				scanf("%d",&i);
				GetData(L,i);
			}
		}else if(m == 7){
			//插入元素
			if(IsEmpty(L))
			{
				printf("顺序表为空!\n");
			}
			else
			{
				printf("请输入插入位置和插入元素：\n");
				scanf("%d%d",&i,&x);
				InsList(L, i, x);
			}
		}else if(m == 8)
		{
			//删除指定位置的元素
			if(IsEmpty(L))
			{
				printf("顺序表为空!\n");
			}
			else
			{
				printf("请输入元素的位置：\n");
				scanf("%d",&i);
				DelList(L, i);
			}
		}else if(m == 9){
			//删除指定元素
			if(IsEmpty(L))
			{
				printf("顺序表为空!\n");
			}
			else
			{
				printf("请输入元素的位置：\n");
				scanf("%d",&x);
				DelData(L, x);
			}
		}else if(m == 10){
			DestroyList(L);
			L = NULL;
			exit(0);
		}else{
			printf("请选择功能!\n");	
		}
	}
	return 0;
}
