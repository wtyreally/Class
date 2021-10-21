#include<stddef.h>

#define SeqQueueMaxSize 1000//队列的最大长度
typedef char SeqQueueType;
typedef struct SeqQueue
{
    SeqQueueType data[SeqQueueMaxSize];
    size_t head;
    size_t tail;
    size_t size;
}SeqQueue;

void SeqQueueInit(SeqQueue* q);//初始化

void SeqQueueDestroy(SeqQueue* q);//销毁

void SeqQueuePush(SeqQueue* q,SeqQueueType value);//入队列

void SeqQueuePop(SeqQueue* q);//出队列

int SeqQueueFront(SeqQueue* q,SeqQueueType* value);//取队首元素

void SeqQueueInit(SeqQueue* q)
{
    if(q == NULL)
    {
        return;    //非法输入
    }
    q->head = 0;
    q->tail= 0;
    q->size = 0;
    return;
}

void SeqQueueDestroy(SeqQueue* q)
{
    if(q == NULL)
    {
        return; //非法输入
    }
    q->head = 0;
    q->tail = 0;
    q->size = 0;
}

void SeqQueuePush(SeqQueue* q,SeqQueueType value)
{
    if(q == NULL)
    {
        return;//非法输入
    }
    if(q->size >= SeqQueueMaxSize)
    {
        return;//队列已满
    }
    q->data[q->tail++] = value;//将value赋给tail指向的位置，tail指向它的下一个位置

    if(q->tail == SeqQueueMaxSize)//如果尾指针指向的位置大于队列最大容量，则将它指向下标为0的位置
    {
        q->tail = 0;
    }
    q->size++;
}

void SeqQueuePop(SeqQueue* q)
{
    if(q == NULL)
    {
        return;//非法输入
    }
    if(q->size == 0)
    {
        return;//空列表
    }
    ++q->head;

    if(q->head == SeqQueueMaxSize)
    {
        q->head = 0;
    }
    --q->size;
    return;
}

int SeqQueueFront(SeqQueue* q,SeqQueueType* value)
{
    if(q == NULL||value == NULL)
    {
        return 0;//非法输入
    }
    if(q->size == 0)
    {
        return 0;//空队列
    }
    *value = q->data[q->head];
    return 1;
}
#if 1
#include<stdio.h>
void TestQueue()
{
    SeqQueue queue;
    SeqQueueInit(&queue);
    SeqQueuePush(&queue,'a');
    SeqQueuePush(&queue,'b');
    SeqQueuePush(&queue,'c');
    SeqQueuePush(&queue,'d');

    SeqQueueType value;
    int ret = SeqQueueFront(&queue,&value);
    printf("ret expected 1,actual %d\n",ret);
    printf("value expected a,actual %c\n",value);

    SeqQueuePop(&queue);
    SeqQueuePop(&queue);
    ret = SeqQueueFront(&queue,&value);
    printf("ret expected 1,actual %d\n",ret);
    printf("value expected c,actual %c\n",value);

    SeqQueuePop(&queue);
    SeqQueuePop(&queue);
    ret = SeqQueueFront(&queue,&value);
    printf("ret expected 0,actual %d\n",ret);

}
int main()
{
    TestQueue();
    printf("\n");
    return 0;
}
#endif