#include<iostream>
using namespace std;
class QNode {
public:
    int data;
    QNode *qnext;
};
class Linkqueue {
public:
    void InitQueue(Linkqueue &Q);
    void IsEmpty(Linkqueue &Q);
    void EnQueue(Linkqueue &Q);
    void DeQueue(Linkqueue &Q);
    void showqueue(Linkqueue &Q);
    void findQueue(Linkqueue &Q, int value);
    int getlength(Linkqueue &Q);
    void destroyQueue(Linkqueue &Q);

private:
    QNode *front;
    QNode *rear;
};
//队列的初始化
void Linkqueue::InitQueue(Linkqueue &Q) {
    QNode *p = new QNode;
    p->qnext = NULL;
    Q.front = p;
    Q.rear = p;
}
//队列的判空
void Linkqueue::IsEmpty(Linkqueue &Q) {
    if (Q.rear == Q.front) {
        cout << "该队列为空队列";
    }
    else
        cout << "该队列不是空队列";
    cout << endl;
}
//队列节点的插入
void Linkqueue::EnQueue(Linkqueue &Q) {
    QNode *pnew = new QNode;
    pnew->qnext = NULL;
    cout << "请输入该节点的数值 = ";
    cin >> pnew->data;
    Q.rear->qnext = pnew;
    Q.rear = pnew;
}
//队列节点的删除
void Linkqueue::DeQueue(Linkqueue &Q)
{
    QNode *p;
    p = Q.front->qnext;
    Q.front->qnext = Q.front->qnext->qnext;     
    if (Q.rear == p)   
        Q.rear = Q.front;
    delete p;
}
//显示队列
void Linkqueue::showqueue(Linkqueue &Q) {
    QNode *p;
    p = Q.front->qnext;
    if (p == NULL)  
    {
        cout << "队列为空" << endl;
    }
    cout << endl;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->qnext;
    }
    cout << endl;
}
//队列查询
void Linkqueue::findQueue(Linkqueue &Q, int value) {
    QNode *ptarget;
    ptarget = Q.front;
    int n = 0;
    cout << "数据值为" << value << "的位置=";
    while (ptarget != Q.rear) {
        if (ptarget->data == value) {
            cout << n + 1 << " ";
        }
        n = n + 1;
        ptarget = ptarget->qnext;
    }
    cout << endl;
}
//计算队列长度
int Linkqueue::getlength(Linkqueue &Q) {
    int length = 0;
    QNode *p1 = Q.front;
    QNode *p2 = Q.rear;
    while (p1 != p2) {
        p1 = p1->qnext;
        length++;
    }
    cout << "队列长度=" << length << endl;
    return length;
}
//销毁队列
void Linkqueue::destroyQueue(Linkqueue &Q) {
    while (Q.front)
    {
        Q.rear = Q.front->qnext;
        delete Q.front;
        Q.front = Q.rear;
    }
}
int main() {
    Linkqueue queue;
    Linkqueue *Q;
    int n;
    Q = new Linkqueue;
    queue.InitQueue(*Q);
    cout << "请输入需要的队列节点数 = ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        queue.EnQueue(*Q);
    }
    cout << "队列节点为：";
    queue.showqueue(*Q);
    cout << "删除队首节点后为：";
    queue.DeQueue(*Q);
    queue.showqueue(*Q);
    queue.findQueue(*Q, 1);
    queue.getlength(*Q);
    queue.IsEmpty(*Q);
    queue.destroyQueue(*Q);
    return 0;
}