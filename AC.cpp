#include <bits/stdc++.h>
using namespace std;
//链表结点类
template<typename Elemtype>
struct LNode{
    Elemtype data;  //数据元素
    LNode* next = NULL; //结点指针
    LNode(){}
    LNode(Elemtype d)
    {   data = d; }
    void release()
    {//用递归的方法简单表达释放next所指的后续
    if(next) {
      next->release();//用递归调用
      delete next;
    }
    }
};
//链表结点类
template<typename Elemtype>
struct LinkList{
    typedef LNode<Elemtype> LNode;//通过此定义，一下视LNode为LNode<Elemtype>
    LNode header;
    int length = 0;//记录链表结点个数
    ~LinkList()
    {
          header.release();
    }
    void insert(Elemtype e)
    {//插入元素e到链表头部
        LNode *p = new LNode();
        p->data = e;
        p->next = header.next;
        header.next = p;
        length++;
    }

    void output()
    {//输出链表
        LNode *p = header.next;
        cout << "header->";
        while (p)
        {
          cout << p->data <<"->";
          p = p->next;
        }
        cout << "NULL" << endl;
    }
    void sub(LNode HL,LNode &L1,LNode &L2)
    {
        LNode *t1, *t2, *p;
        LNode *pnew;
        p = HL.next;
        LNode  *p1 = NULL, *p2 = NULL;
        while(p!=NULL) {
            if(p -> data % 2 == 0) {
                pnew = new LNode;
                pnew -> data = p ->data;
                pnew -> next = NULL;
                if(p1 == NULL) p1 = t1 = pnew;
                else {
                    t1 -> next = pnew;
                    t1 = t1 ->next;
                }
            }
            else {
                pnew = new LNode;
                pnew -> data = p ->data;
                pnew -> next = NULL;
                if(p2 == NULL) p2 = t2 = pnew;
                else {
                    t2 -> next = pnew;
                    t2 = t2 ->next;
                }
            }
            p = p->next;
        }
        L1.next = p1, L2.next = p2;
    }
};

void text(){
    srand(time(NULL));
    int n = 10;
    LinkList <int > t;
    for(int i = 0; i < n; i++) {
        int v = rand()%20;
        t.insert(v);
    }
    LinkList <int > t1, t2;
    t.sub(t.header, t1.header, t2.header);
    printf("原表\n");
    t.output();
    printf("奇数表\n");
    t1.output();
    printf("偶数表\n");
    t2.output();
}

int main()
{
    text();
    return 0;
}
