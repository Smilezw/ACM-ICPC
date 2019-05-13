#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;

const int N = 8;
const int W = 10;

struct Graph_theory {
    int mpt[N][N];
    int n;  //�������

    void init() {
        printf("������õ��ڽӾ���\n");
        n = rand()%N;
        printf("�����С�� %d*%d\n�������£�\n", n, n);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                mpt[i][j] = rand()%W;
                cout << mpt[i][j] << " ";
            }
            cout << endl;
        }
    }

    struct Edge{      //�߶���
        int u, v, w;
    };

    struct Star{  //��ʽǰ����
        int to, w;
        int next;
    };

    int cnt = 0;
    Edge edge[N*N];  //�߼�
    void get_edge_map() {
        printf("��Ӧ����ı߼����飺\n���-->�յ�   Ȩֵ\n");

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(mpt[i][j]) {
                    edge[cnt++] = (Edge){i, j, mpt[i][j]};
                    printf("%d-->%d   %d\n", i, j, mpt[i][j]);
                }
            }
        }
        printf("�ߵ�����Ϊ �� %d\n", cnt);
    }

    int head[N], tot;  //ͷ�ڵ�ͱ߱��
    Star e[N*N];
    void Einit() {
        for(int i = 0; i <= n+5; i++) head[i] = -1;
        tot = 0;
    }
    void addedge(int u, int v, int w) {   //�ӱ߲���
        e[tot].to = v, e[tot].w = w;
        e[tot].next = head[u];
        head[u] = tot++;
    }
    vector <Edge> E[N];

    void get_adjacency_list() {
        printf("������ģ����ڽӱ�\n");
        Einit();
        for(int i = 1; i <= n ; i++) {
            for(int j = 1; j <= n; j++) {
                if(mpt[i][j]) addedge(i, j, mpt[i][j]);
            }
        }
        for(int i = 1; i <= n; i++) {
            printf("star �� %d --> ", i);
            for(int j = head[i]; j != -1; j = e[j].next) {
                printf("[to :%d  w :%d]   ", e[j].to, e[j].w);
            }
            printf("\n");
        }

        printf("��vectorģ����ڽӱ�\n");
        for(int i = 1; i <= n ; i++) {
            for(int j = 1; j <= n; j++) {
                if(mpt[i][j]) E[i].push_back((Edge){i, j, mpt[i][j]});
            }
        }
        for(int i = 1; i <= n; i++) {
            printf("star �� %d --> ", i);
            for(int j = 0; j < E[i].size(); j++) {
                printf("[to :%d  w :%d]   ", E[i][j].v, E[i][j].w);
            }
            printf("\n");
        }
    }

}text;

int main() {
    srand(time(NULL));
    text.init();    //�����ڽӾ���
    text.get_edge_map();
    text.get_adjacency_list();
    return 0;
}
