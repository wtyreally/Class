#include<iostream>
#include<malloc.h>
using namespace std;
typedef int QElementType;
typedef struct Node* NodePtr;
typedef struct SNode* Stack; //栈 

struct Node{       //链队列结点的结构体 
	QElementType data;
	NodePtr next;
};
struct QNode{//链队列的头结点 
	struct Node* front;//队头指针，指向第一个元素 
	struct Node* rear;//队尾指针，指向最后一个元素的下一个位置 
};

struct SNode{
	QElementType data;
	struct SNode *next;
}; 

void InitQueue(QNode &Q){
	//构造一个空队列
	Q.front=Q.rear= (NodePtr)malloc(sizeof(struct Node));
	if(!Q.front) cout<<"分配空间失败！";
	Q.front->next=NULL; 
}

void EnQueue(QNode &Q,QElementType e){//Q是头结点指针 
	//插入元素e为Q的新的队尾元素
	NodePtr p=(NodePtr)malloc(sizeof(struct Node));
	if(!p) cout<<"分配空间失败！"; 
	p->data=e; 
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;}
	
QElementType DeQueue(QNode &Q){//出队列 
	QElementType e;
	if(Q.front==Q.rear) return 0;
	NodePtr p=(NodePtr)malloc(sizeof(struct Node));
	p=Q.front->next;
	e=p->data; 
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	return e;
}

//链栈 
void Push(QElementType e,Stack S){//入栈
	Stack p=(Stack)malloc(sizeof(struct SNode));
	p->data=e;
	p->next=S->next;
	S->next=p;
}
QElementType Pop(Stack S){//出栈
	if(S){
		QElementType e;
		Stack p=(Stack)malloc(sizeof(struct SNode));
		p=S->next ;
		e=p->data;
		S->next=p->next;
		free(p);
		return e;
	} 
	
} 
int main(){
	int n; 
	cin>>n;
	QElementType e,item1,item2;
	QNode Q;
	InitQueue(Q);
	Stack S;
	S=(Stack)malloc(sizeof(struct SNode));
	S->next=NULL;

	for(int i=0;i<n;i++){
		cin>>e;
		EnQueue(Q,e);
	}
	for(int i=0;i<n;i++){
		item1=DeQueue(Q);
		Push(item1,S);
	}
	for(int i=0;i<n;i++){
		item2=Pop(S);
		cout<<item2<<" ";
	}
}
	
	
