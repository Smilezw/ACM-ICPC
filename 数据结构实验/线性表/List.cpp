#include <bits/stdc++.h>
using namespace std;

#define LIST_INIT_SIZE 100  //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMNET  10   //���Ա�洢�ռ�ķ�������

//��������
template<typename Elemtype>
struct LNode{
    Elemtype data;  //����Ԫ��
    LNode* next = NULL; //���ָ��
    LNode(){}
    LNode(Elemtype d)
    {   data = d; }
    void release()
    {
        if(next) {
            next->release();//�õݹ����
            delete next;
        }
    }
};

template<typename Elemtype>
struct LinkList{
    typedef LNode<Elemtype> LNode;
    LNode header;
    int length = 0;//��¼���������
    ~LinkList()
    {
          header.release();
    }
    void insert(Elemtype e)
    {//����Ԫ��e������ͷ��
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
    LinkList <Elemtype> _hash[mod];   //��ϣ��

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

#define LIST_INIT_SIZE 100  //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMNET  10   //���Ա�洢�ռ�ķ�������
template<typename Elemtype>
struct SeqList {
    Elemtype *items;    //�洢�ռ��ַ
    int length;         //��ǰ����
    int capacity;           //��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ)

    SeqList(int c = LIST_INIT_SIZE)//��ָ����������˳���
    {
        items = NULL;
        length = 0;
        resize(c);//�����ʼ�洢�ռ�
    }

    SeqList(const SeqList& mother)//���������������Ժ���������ָ��ͬһ����̬����Ŀռ䣬�޸ĺ��ͷŶ��ᵼ���쳣
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
            delete[]items;//�ͷŴ洢�ռ�
            items = NULL;
        }
    }

    void resize(int c)//�����洢�ռ��С
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

    void output()//������Ա�
    {
        cout<<"List: ";
        for (int i = 0; i < length; i++)
            cout << items[i] << " ";
        cout << endl;
    }

    void append(Elemtype e)//׷��Ԫ��
    {
        if (length == capacity)//Ԫ�����ˣ���Ҫ������
            resize(capacity + LISTINCREMNET);
        items[length++] = e;
    }

    Elemtype &operator[](int index)//��ȡindexλ�õ�Ԫ�ص�����
    {
        return items[index];
    }

    void clear()//�������Ԫ��
    {
        length = 0;
        resize(LIST_INIT_SIZE);//�ͷź����·���ռ�
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
    printf("ԭ��\n");
    t.output();
    t.unique();
    printf("ȥ�غ�\n");
    t.output();
}

int main()
{
	text();
	return 0;
}
