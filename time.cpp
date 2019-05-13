#include <iostream>
#include "memory.h"
#include<string>
#include<vector>
#include <stdlib.h>
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
    {//�õݹ�ķ����򵥱���ͷ�next��ָ�ĺ���
    if(next) {
      next->release();//�õݹ����
      delete next;
    }
    }
};
//��������
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

    LNode *find(Elemtype e)
    {
        LNode *p = header.next;//�ӵ�һ����㿪ʼ
        while (p)
        {
          if (p->data == e) break;//�Աȵ�ǰ���
          p = p->next;//�ƶ�ָ�뵽��һ�����
        }
        return p;//���ز��ҽ��
    }

};

#define LIST_INIT_SIZE 100  //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMNET  10   //���Ա�洢�ռ�ķ�������
template <typename ElemType>
struct SeqList{
    ElemType *items;    //�洢�ռ��ַ
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
        memcpy(items, mother.items, length*sizeof(ElemType));
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
        ElemType *newdata = new ElemType[c];
        if (items != NULL)
        {
            memcpy(newdata, items, length*sizeof(ElemType));
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

    void append(ElemType e)//׷��Ԫ��
    {
        if (length == capacity)//Ԫ�����ˣ���Ҫ������
            resize(capacity + LISTINCREMNET);
        items[length++] = e;
    }


    ElemType &operator[](int index)//��ȡindexλ�õ�Ԫ�ص�����
    {
        return items[index];
    }

    void deleteAt(int index)//ɾ��indexλ�õ�Ԫ��
    {
        if (index < 0 || index >= length) throw "illegal command";
        for (int i = index; i < length - 1; i++)
            items[i] = items[i + 1];
        length--;
    }

    void clear()//�������Ԫ��
    {
        length = 0;
        resize(LIST_INIT_SIZE);//�ͷź����·���ռ�
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
