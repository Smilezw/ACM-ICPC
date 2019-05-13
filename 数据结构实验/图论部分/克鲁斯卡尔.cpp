#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

const int N = 1e5 + 5;
const int M = 1e5 + 5;

struct Edge{
    int u, v, w;
};

struct KRUSKAL {
    int n, m;
    Edge edge[M], tree[M];    //ͼ�ı߼�  �������ı߼�

    void creat() {   //����߼�
        printf("����ͼ�Ľڵ����ͱ�����n m \n");
        cin >> n >> m;
        printf("��Ȩֵ����˳������߼�\n ���u  �յ�v  Ȩֵw\n");
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edge[i] = (Edge){u, v, w};
        }
    }

    int f[N];

    int find(int x) {
    	return f[x] == x ? x : f[x] = find(f[x]);  //·��ѹ��һ��
    }

    int init(int n) {
        for(int i = 0; i <= n ; i++) f[i] = i;
    }

    //�㷨����
    void Kruskal() {
        init(n);
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            int u = edge[i].u, v = edge[i].v;
            int fu = find(u), fv = find(v);
            if(fu != fv) {   //����һ������
                f[fu] = fv;
                tree[cnt++] = edge[i];
            }
        }
    }

    void output() {
        printf("Minimum Spanning Tree: \n");
        for(int i = 0; i < n-1; i++) {
            printf("the edge: %d -> %d  cost: %d\n", tree[i].u, tree[i].v, tree[i].w);
        }
    }
}text;

int main() {
    text.creat();
    text.Kruskal();
    text.output();
	return 0;
}

//�������������

/*
4 8
1 3 0
3 2 0
2 1 0
3 2 1
1 2 1
1 3 1
3 0 1
2 3 2
*/

/*
10 25
0 7 0
5 9 1
4 9 1
4 2 2
0 6 2
7 1 2
8 2 2
6 0 3
6 4 4
6 0 4
4 2 5
5 9 5
9 3 5
9 8 6
2 6 6
9 0 6
3 6 6
8 1 7
2 1 7
10 4 7
3 0 8
0 2 8
5 8 9
0 9 9
7 1 9
*/
