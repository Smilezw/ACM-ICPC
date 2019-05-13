#include <iostream>
#include "memory.h"
#include<string>
#include<vector>
#include <stdlib.h>
using namespace std;

#define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量
#define LISTINCREMNET  10   //线性表存储空间的分配增量

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
struct LinkList{
    typedef LNode<Elemtype> LNode;
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

    LNode *find(Elemtype e)
    {
        LNode *p = header.next;//从第一个结点开始
        while (p)
        {
          if (p->data == e) break;//对比当前结点
          p = p->next;//移动指针到下一个结点
        }
        return p;//返回查找结果
    }

};

#define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量
#define LISTINCREMNET  10   //线性表存储空间的分配增量
template <typename ElemType>
struct SeqList{
    ElemType *items;    //存储空间基址
    int length;         //当前长度
    int capacity;           //当前分配的存储容量（以sizeof(ElemType)为单位)

    SeqList(int c = LIST_INIT_SIZE)//按指定容量创建顺序表
    {
        items = NULL;
        length = 0;
        resize(c);//分配初始存储空间
    }

    SeqList(const SeqList& mother)//深拷贝，否则对象复制以后，两个对象指向同一个动态申请的空间，修改和释放都会导致异常
    {
        items = NULL;
        length = mother.length;
        resize(mother.capacity);
        memcpy(items, mother.items, length*sizeof(ElemType));
    }

    ~SeqList()
    {
        if (items)
        {
            delete[]items;//释放存储空间
            items = NULL;
        }
    }

    void resize(int c)//调整存储空间大小
    {
        ElemType *newdata = new ElemType[c];
        if (items != NULL)
        {
            memcpy(newdata, items, length*sizeof(ElemType));
            delete []items;
        }
        items = newdata;
        capacity = c;
    }

    void output()//输出线性表
    {
        cout<<"List: ";
        for (int i = 0; i < length; i++)
            cout << items[i] << " ";
        cout << endl;
    }

    void append(ElemType e)//追加元素
    {
        if (length == capacity)//元素满了，需要先扩容
            resize(capacity + LISTINCREMNET);
        items[length++] = e;
    }


    ElemType &operator[](int index)//获取index位置的元素的引用
    {
        return items[index];
    }

    void deleteAt(int index)//删除index位置的元素
    {
        if (index < 0 || index >= length) throw "illegal command";
        for (int i = index; i < length - 1; i++)
            items[i] = items[i + 1];
        length--;
    }

    void clear()//清空数据元素
    {
        length = 0;
        resize(LIST_INIT_SIZE);//释放和重新分配空间
    }
};

const int mod = 1e5 + 7;
LinkList <int > _hash[mod];

void text{
	srand(time(NULL));
	SeqList <int> t;
	int n = 10;
	for(int i = 0;i < n; i++) {
		int v = rand()%10;
		t.append(v);
	}

}

int main()
{
	text();
	return 0;
}
