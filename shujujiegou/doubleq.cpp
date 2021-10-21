#include<assert.h>
#include<iostream>
using namespace std;
//双端队列
template<class T>
struct LinkNode
{
    LinkNode<T> * _pNext;
    T _pDate;

    LinkNode(const T& x)
        :_pNext(NULL)
        , _pDate(x)
    {}
};


template<class T>
class Deque
{
public:
    //构造函数
    Deque()
        :Head(NULL)
        , Tail(NULL)
    {}

    //析构函数

    //队列判空
    bool IsEmpty()
    {
        if (Head == NULL && Tail == NULL)
            return true;
        return false;
    }

    //插入队头
    bool enQueueHead(const T& x)
    {
        if (IsEmpty())
        {
            Head = Tail = new LinkNode<T>(x);
            return true;
        }

        LinkNode<T> * s = new LinkNode<T>(x);
        s->_pNext = Head;
        s->_pDate = x;
        Head = s;
        return true;
    }

    //删除队头
    bool delQueueHead()
    {
        if (IsEmpty())
            return false;

        LinkNode<T> * del = new LinkNode<T>;
        if (del == NULL)
            return false;
        del = Head;
        Head = Head->_pNext;
        delete del;

    }

    //插入队尾
    bool enQueueTail(const T& x)
    {
        if (IsEmpty())
        {
            Head = Tail = new LinkNode<T>(x);
            return true;
        }

        Tail->_pNext = new LinkNode<T>(x);
        if (Tail->_pNext == NULL)
        Tail = Tail->_pNext;
        return true;
    }

    //删除队尾
    bool delQueueTail()
    {
        if (IsEmpty())
            return false;

        LinkNode<T> * del;
        del = Head;
        while (del->_pNext != Tail)
        {
            del = del->_pNext;
        }
        Tail = del;
        del = del->_pNext;
        delete del;

    }

    //得到队头
    bool getHead( T& x)
    {
        if (Head == NULL)
            return false;

        x = Head->_pDate;
        return true;
    }
    //得到队尾
    bool getTail(T& x)
    {
        if (Tail == NULL)
            return false;

        x = Tail->_pDate;
        return true;
    }
    //置空队列
    void makeEmpty()
    {
        LinkNode<T> * del;
        while (Head != Tail)
        {
            del = Head;
            Head = Head->_pNext;
            delete del;
        }
        return;
    }


private:
    LinkNode<T> * Head;
    LinkNode<T> * Tail;

};

int main()
{
    Deque<int> s;
    int a, b;
    s.enQueueTail(3);
    s.enQueueHead(2);
    s.getHead(a);
    s.getTail(b);
    cout << a << b << endl;

    s.enQueueHead(1);
    s.delQueueTail();
    s.getHead(a);
    s.getTail(b);
    cout << a << b << endl;

    s.enQueueHead(0);
    s.delQueueTail();
    s.getHead(a);
    s.getTail(b);
    cout << a << b << endl;
    return 0;
}