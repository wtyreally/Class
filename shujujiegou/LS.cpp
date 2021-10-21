#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//定义链式存储线性表的结构
typedef struct Node
{
    int data;
    struct Node * next; 
} Node,*LinkList;

//双向链表 
typedef struct DoubleNode
{
	struct DoubleNode *pre;
	int data;
	struct DoubleNode *next;
}*DoubleLinkList;

//初始化链表
void InitList(LinkList &head)
{
	head=(Node*)malloc(sizeof(Node));
	if(head==NULL)
	{
		printf("失败!\n");
		exit(-1);
	} 
	head->next=NULL;
	printf("成功!\n");
}

//输出链表
void PrintList(LinkList &head)
{
	Node *p=head;
	Node *s=NULL;
	printf("链表为:\n");
	while(p->next!=NULL)
	{
		s=p->next;
		p=s;
		printf("%d\t",s->data);
	}
	printf("\n");
}

//初始化双向链表
void InitDoubleList(DoubleLinkList &dhead)
{
    dhead=(DoubleLinkList)malloc(sizeof(DoubleNode));
    if(dhead)
    {
    	dhead->pre=dhead->next=dhead;
    	printf("初始化成功!\n");
    }
    else printf("初始化失败!\n");
}

//输出双向链表
void PrintfDoubleList(DoubleLinkList &dhead)
{
	DoubleNode *p=dhead->next , *s=NULL;
	printf("双链表为:\n");
	do
	{
		printf("%d\t",p->data);
		s=p;
		p=p->next;
		p->pre=s;
		s->next=p;
	}while(p!=dhead);
	printf("\n");
}

//创建链表，读入五个整数 
void Create5NumList(Node *head)
{
	Node *p=head,*s; 
	int i;
	printf("输入5个数字:\n");
	for(i=0;i<5;i++)
	{
		s=(Node*)malloc(sizeof(Node));
		scanf("%d",&s->data);
		p->next=s;
		p=s;
	}
	p->next=NULL;
	printf("完成!\n");
	PrintList(head);
}

//创建双向链表
void CreatDoubleList(DoubleLinkList &dhead)
{
	int data=1;
	DoubleNode *p=dhead,*s=NULL;
	printf("请输入双链表数据(end with 0):\n");
	while(data!=0)
	{
		scanf("%d",&data);
		if(data!=0)
		{
			s=(DoubleLinkList)malloc(sizeof(DoubleNode));
			s->data=data;
			s->pre=p;
			p->next=s;
			p=s;
		}
		else
		{
			s->next=dhead;
			dhead->pre=s;
		}
	}
	printf("成功!\n");
	PrintfDoubleList(dhead);
}

//插入元素
int InsertData(LinkList &head)
{
	int pos,data;
	Node *s=NULL,*p=head;
	int i=0;
	printf("请输入插入数据和位置:\n");
	scanf("%d %d",&data,&pos);
	while(p->next!=NULL && i<pos-1)
	{
		p=p->next;
		i++;
	}
	if(!p)
	{
		printf("失败!\n");
		return 0;
	}
	s=(Node*)malloc(sizeof(Node));
	s->data=data;
	s->next=p->next;
	p->next=s;
	printf("成功!\n");
	PrintList(head);
	return 1; 
} 

//删除元素
int  DeleteData(LinkList &head)
{
	int i=0;
	int pos;
	Node *s,*p=head;
	printf("删除想删除位置的元素(pos):\n");
	scanf("%d",&pos);
	while(p->next!=NULL && i<pos-1)
	{
		p=p->next;
		i++;
	}
	if(!p)
	{
		printf("删除错误!\n");
		return 0;
	}
	s=p->next;
	p->next=s->next;
	free(s);
	printf("删除成功!\n");
	PrintList(head);
}

//创建一个单链表，其数据元素为整数，从键盘输入，输入0结束 
void CreatList(LinkList &head)
{
	Node *p=head,*s=NULL;
	int data=1;
	printf("请输入链表数据(end with 0):\n");
	while(data!=0)
	{
		scanf("%d",&data);
		if(data!=0)
		{
			s=(Node*)malloc(sizeof(Node));
			s->data=data;
			p->next=s;
			p=s;
		}
		else
		{
			p->next=NULL;
		}
	}
	printf("Create success!\n");
	PrintList(head);
}

//在链尾插入元素
int InsertDataAtEnd(LinkList &head,int data)
{
	Node *s=NULL,*p=head;
	if(!p)
	{
		printf("链表为空!\n");
		return 0;
	}
	while(p->next!=NULL)
	{
		p=p->next;
	}
	s=(Node*)malloc(sizeof(Node));
	s->data=data;
	s->next=p->next;
	p->next=s;
	return 1;
}

//查询、插入与删除
void SeekInsertDelete(LinkList &head)
{
	Node *p=head,*r=NULL;
	int data;
	int i=0;
	if(!p)
	{
		printf("链表为空!\n");
		exit(-1);
	}
	printf("输入想查询的数据:\n");
	scanf("%d",&data);
	p=p->next;
	while(p->next!=NULL)
	{
		if(p->data=data)
		{
			r=p;
			p=p->next;
			free(r);
			i=1;
			printf("成功!\n");
			PrintList(head);
		}
		else
		p=p->next;
		if(i=0)
		{
			printf("无此数据!\n");
			InsertDataAtEnd(head,data);
			PrintList(head);
		}
	} 
} 

//双向链表排序
void SortDoubleList(DoubleLinkList &dhead)
{
	DoubleNode *p=dhead->next,*s=p->next,*snext;
	int count=0,i=0,j=0;
	while(p!=dhead)
	{
		count++;
		p=p->next;
	}
	p=dhead->next;
	for(i=0;i<count-1;i++)
	{
		for(j=0;j<count-i-1;j++)
		{
			if(p->data>s->data)
			{
				p->pre->next=s;
				s->next->pre=p;
				s->pre=p->pre;
				snext=s->next;
				s->next=p;
				p->pre=s;
				p->next=snext;
				s=p->next;
			}
			else
			{
				p=p->next;
				s=s->next;
			}
		}
		p=dhead->next;
		s=p->next;
	}
	printf("成功!\n");
	PrintfDoubleList(dhead);
}

//主函数
int main()
{
	LinkList head1,head2;
	DoubleLinkList dhead;
	InitList(head1);
	Create5NumList(head1);
	InsertData(head1);
	DeleteData(head1);
	InitList(head2);
	CreatList(head2);
	InitDoubleList(dhead);
	CreatDoubleList(dhead);
	SortDoubleList(dhead);
	return 0;
} 
