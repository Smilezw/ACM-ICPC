#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

template <typename Key, typename Value>
struct BST {
    struct Node {   //��
        Key key;
        Value value;
        Node  *left;
        Node *right;
        int count;
        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = NULL;
            this->right = NULL;
            count = 0;
        }
        Node(Node* node) {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
            count = node->count;
        }
    };

    Node *root;
    int Tree_size;

    BST() {
        this->root = NULL;
        this->Tree_size = 0;
    }

    Node* insert(Node* f, Key key, Value value) {   //���뺯��
        if(f == NULL) {
            Node * t =  new Node(key, value);
            t->count++;
            Tree_size++;
            return t;
        }
        if(key == f->key) {
            f->value = value;
            f->count++;
            Tree_size++;
        } else if( key < f->key) {
            f->left = insert(f->left, key, value);
        } else {
            f->right = insert(f->right, key, value);
        }
        return f;
    }

    Node* search_max(Node* root) {    //���Ҷ���
        Node *res = root;
        while(res -> right != NULL) {
            res = res->right;
        }
        return res;
    }

    int find_one(Node* f) {    //dfsͳ�Ƹ�㡣��
        int cnt = 0;
        int res = 0;
        if(f->right != NULL) {
            cnt++;
            res += find_one(f -> right);
        }
        if(f->left != NULL) {
            cnt++;
            res += find_one(f -> left);
        }
        if(cnt == 1) return res + 1;
        return res;
    }

    void output(Node *root) {
        if(root == NULL) return;
        cout << "this node key: " << root->key << " val: " << root->value << " count:  " <<  root->count << endl;
        output(root->left);
        output(root->right);
    }

};

void solve() {
    BST<int, int> p;
    int n;
    printf("����ڵ� ��key == val \n");
    printf("����ڵ�������\n(����n ����ڵ� i = 1...n  ÿ��i����������(i, i) (i, i) (-i, -i) )\n");
    cin >> n;
    for(int i = 0; i <= n; i++) {   //��������ֵ��Ϊ��ֵͬ
        p.root =  p.insert(p.root,i, i);
        p.root =  p.insert(p.root,i, i);
        p.root =  p.insert(p.root,-i, -i);
    }
    p.output(p.root);
    printf("�ؼ������Ԫ�أ��ǵݹ飩:  ");
    cout << p.search_max(p.root)->value << endl;
    printf("����֧�ڵ������� %d\n", p.find_one(p.root));
}

int main() {
    solve();
    return 0;
}
