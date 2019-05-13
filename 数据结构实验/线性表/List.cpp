#include <bits/stdc++.h>
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
    {
        if(next) {
            next->release();//用递归调用
            delete next;
        }
    }
};

template<typename Elemtype>
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
};

const int mod = 1e5 + 7;

template<typename Elemtype>
struct Hash {
    LinkList <Elemtype> _hash[mod];   //哈希表

    bool _find(Elemtype x) {
        int v = x%mod;
        LNode <Elemtype> *p = _hash[v].header.next;
        while(p) {
            if(p->data == x) return 1;
        }
        return 0;
    }

    void insert(Elemtype x) {
        if(_find(x)) return;
        int v = x%mod;
        _hash[v].insert(x);
    }
};

#define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量
#define LISTINCREMNET  10   //线性表存储空间的分配增量
template<typename Elemtype>
struct SeqList {
    Elemtype *items;    //存储空间基址
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
        memcpy(items, mother.items, length*sizeof(Elemtype));
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
        Elemtype *newdata = new Elemtype[c];
        if (items != NULL)
        {
            memcpy(newdata, items, length*sizeof(Elemtype));
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

    void append(Elemtype e)//追加元素
    {
        if (length == capacity)//元素满了，需要先扩容
            resize(capacity + LISTINCREMNET);
        items[length++] = e;
    }

    Elemtype &operator[](int index)//获取index位置的元素的引用
    {
        return items[index];
    }

    void clear()//清空数据元素
    {
        length = 0;
        resize(LIST_INIT_SIZE);//释放和重新分配空间
    }

    void Copy(SeqList <Elemtype> t) {
        this->length = t.length;
        this->resize(t.capacity);
        for(int i = 0; i < length; i++) {
            items[i] = t.items[i];
        }
    }

    void unique() {
        Hash <Elemtype> mpt;
        for(int i = 0; i < length; i++) mpt.insert(items[i]);
        SeqList <Elemtype> t;
        for(int i = 0; i < mod; i++) {
            LNode <Elemtype> *p = mpt._hash[i].header.next;
            while(p) {
                Elemtype v = p->data;
                t.append(v);
                p = p -> next;
            }
        }
        Copy(t);
    }
};

void text() {
	srand(time(NULL));
	SeqList <int> t;
	int n = 5;
	for(int i = 0; i < n; i++) {
		int v = rand()%50000000;
		t.append(v);
        t.append(v);
        t.append(v);
	}
    printf("原表\n");
    t.output();
    t.unique();
    printf("去重后\n");
    t.output();
}

int main()
{
	text();
	return 0;
}
