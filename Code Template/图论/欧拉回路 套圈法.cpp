#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

const int MAXV = 100 + 7;
const int MAXE = 100 * 100 + 7;
int head[MAXV];
int V, E;

typedef struct EdgeNode
{
    int to;
    int w;
    int next;
}edgeNode;
edgeNode Edges[MAXE];

bool visit[2 * MAXE];
stack<int> stv;
queue<int> quv;//点集
queue<int> que;//边集

void EulerDFS(int now)
{
    st.push(now);//每访问一个点，就把该点压入栈
    for(int k = head[now]; k != -1; k = Edges[k].next)
    {
        if(!visit[k])
        {
            visit[k] = true;            //有向图每条边保存了两次，也要标记两次
            if(k & 1)
                visit[k + 1] = true;
            else
                visit[k - 1] = true;
            EulerDFS(Edges[k].to);
            que.push(k);//回溯时记录边
        }
    }
    quv.push(stv.top());//记录点
    stv.pop();
}

int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &V, &E);
    memset(head, -1, sizeof(head));
    for(int i = 1; i <= E; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        Edges[2 * i - 1].to = v;                //双向储存边
        Edges[2 * i - 1].w = w;
        Edges[2 * i - 1].next = head[u];
        head[u] = 2 * i - 1;
        Edges[2 * i].to = u;
        Edges[2 * i].w = w;
        Edges[2 * i].next = head[v];
        head[v] = 2 * i;
    }
    memset(visit, false, sizeof(visit));
    EulerDFS(1);
    return 0;
}
