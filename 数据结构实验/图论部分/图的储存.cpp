#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;

const int N = 8;
const int W = 10;

struct Graph_theory {
    int mpt[N][N];
    int n;  //定义点数

    void init() {
        printf("随机数得到邻接矩阵\n");
        n = rand()%N;
        printf("矩阵大小： %d*%d\n矩阵如下：\n", n, n);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                mpt[i][j] = rand()%W;
                cout << mpt[i][j] << " ";
            }
            cout << endl;
        }
    }

    struct Edge{      //边定义
        int u, v, w;
    };

    struct Star{  //链式前向星
        int to, w;
        int next;
    };

    int cnt = 0;
    Edge edge[N*N];  //边集
    void get_edge_map() {
        printf("对应矩阵的边集数组：\n起点-->终点   权值\n");

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(mpt[i][j]) {
                    edge[cnt++] = (Edge){i, j, mpt[i][j]};
                    printf("%d-->%d   %d\n", i, j, mpt[i][j]);
                }
            }
        }
        printf("边的总数为 ： %d\n", cnt);
    }

    int head[N], tot;  //头节点和边标号
    Star e[N*N];
    void Einit() {
        for(int i = 0; i <= n+5; i++) head[i] = -1;
        tot = 0;
    }
    void addedge(int u, int v, int w) {   //加边操作
        e[tot].to = v, e[tot].w = w;
        e[tot].next = head[u];
        head[u] = tot++;
    }
    vector <Edge> E[N];

    void get_adjacency_list() {
        printf("用链表模拟的邻接表\n");
        Einit();
        for(int i = 1; i <= n ; i++) {
            for(int j = 1; j <= n; j++) {
                if(mpt[i][j]) addedge(i, j, mpt[i][j]);
            }
        }
        for(int i = 1; i <= n; i++) {
            printf("star ： %d --> ", i);
            for(int j = head[i]; j != -1; j = e[j].next) {
                printf("[to :%d  w :%d]   ", e[j].to, e[j].w);
            }
            printf("\n");
        }

        printf("用vector模拟的邻接表\n");
        for(int i = 1; i <= n ; i++) {
            for(int j = 1; j <= n; j++) {
                if(mpt[i][j]) E[i].push_back((Edge){i, j, mpt[i][j]});
            }
        }
        for(int i = 1; i <= n; i++) {
            printf("star ： %d --> ", i);
            for(int j = 0; j < E[i].size(); j++) {
                printf("[to :%d  w :%d]   ", E[i][j].v, E[i][j].w);
            }
            printf("\n");
        }
    }

}text;

int main() {
    srand(time(NULL));
    text.init();    //生成邻接矩阵
    text.get_edge_map();
    text.get_adjacency_list();
    return 0;
}
