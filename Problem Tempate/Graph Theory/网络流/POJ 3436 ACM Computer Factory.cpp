//流量判断是否使用了该机器

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
using namespace std;
#define pb push_back

const int inf = 0x3f3f3f3f;
const int N = 1005;
const int M = 1e6+5;

struct Edge{
    int to, next, cap, flow;  //容量  流量
}edge[M];

int tol;   //边编号
int head[N];

void init() {
    tol = 2;
    memset(head, -1, sizeof(head));
}

void add(int u, int v, int w, int rw = 0) {
    edge[tol].to = v; edge[tol].cap = w; edge[tol].flow = 0;
    edge[tol].next = head[u]; head[u] = tol++;
    edge[tol].to = u; edge[tol].cap = rw; edge[tol].flow = 0;
    edge[tol].next = head[v]; head[v] = tol++;
}

int Q[N];
int dep[N], cur[N], sta[N];

bool bfs(int s, int t, int n) {   //分层
    int front = 0, tail = 0;
    memset(dep, -1, sizeof(dep[0])*(n+1));
    dep[s] = 0;
    Q[tail++] = s;
    while(front < tail)  {  //模拟队列
        int u = Q[front++];
        for(int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if(edge[i].cap > edge[i].flow && dep[v] == -1) {
                dep[v] = dep[u] + 1;
                if(v == t) return 1;
                Q[tail++] = v;
            }
        }
    }
    return 0;
}

int dinic(int s, int t, int n) {
    int maxflow = 0;
    while(bfs(s, t, n) ) {
        for(int i = 0; i < n; i++) cur[i] = head[i];
        int u = s, tail = 0;
        while(cur[s] != -1) {
            if(u == t) {
                int tp = inf;
                for(int i = tail -1; i >= 0; i--)
                    tp = min(tp, edge[sta[i]].cap - edge[sta[i]].flow);
                maxflow += tp;
                for(int i = tail - 1; i >= 0; i--) {
                    edge[sta[i]].flow += tp;
                    edge[sta[i]^1].flow -= tp;
                    if(edge[sta[i]].cap - edge[sta[i]].flow == 0)
                        tail = i;
                }
                u = edge[sta[tail]^1].to;
            }
            else if(cur[u] != -1 &&
                edge[cur[u]].cap > edge[cur[u]].flow &&
                 dep[u]+1 == dep[edge[cur[u]].to] ){
                sta[tail++] = cur[u];
                u = edge[cur[u]].to;
            }
            else {
                while(u != s && cur[u] == -1)
                    u = edge[sta[--tail]^1].to;
                cur[u] = edge[cur[u]].next;
            }
        }
    }
    return maxflow;
}

int n, m;
int sp, tp;  //源点   汇点
int infw[55][15];
int ofw[55][15];

int main() {
    while(cin >> n >> m) {
        init();
        sp = 0, tp = m*2 + 1;
        for(int i = 1; i <= m; i++) {
            int c;
            scanf("%d", &c);
            add(i, i+m, c);
            int flag = 1;
            for(int j = 1; j <= n; j++) {
                scanf("%d", &infw[i][j]);
                if(infw[i][j] == 1) flag = 0;
            }
            if(flag) add(sp, i, inf);
            flag = 1;
            for(int j = 1; j <= n; j++) {
                scanf("%d", &ofw[i][j]);
                if(ofw[i][j] == 0) flag = 0;
            }
            if(flag) add(i + m, tp, inf);
            for(int j = 1; j < i; j++) {
                flag = 1;
                for(int k = 1; k <= n; k++)
                    if(infw[j][k] == 1 &&
                        ofw[i][k] == 0 ||
                        infw[j][k] == 0 &&
                        ofw[i][k] == 1){
                        flag = 0;
                        break;
                    }
                if(flag) add(i + m, j, inf);
                flag = 1;
                for(int k = 1; k <= n; k++)
                    if(infw[i][k] == 1 &&
                        ofw[j][k] == 0 ||
                        infw[i][k] == 0 &&
                        ofw[j][k] == 1) {
                        flag = 0;
                        break;
                    }
                if(flag) add(j + m, i, inf);
            }
        }
        int ans = dinic(sp, tp, 2*m+2);
        int sum = 0;
        for(int i = 1; i <= m; i++)
            for(int p = head[i+m]; p != -1; p = edge[p].next)
                //cout << edge[p].to << " " << edge[p].flow << endl;
                if(edge[p].to != i && edge[p].to != sp &&
                    edge[p].to != tp &&  edge[p].flow != 0 && edge[p].flow!= inf)
                        sum++;
        cout << ans << " " << sum << endl;
        for(int i = 1; i <= m; i++)
            for(int p = head[i+m]; p != -1; p = edge[p].next)
                //cout << edge[p].to << " " << edge[p].flow << endl;
                if(edge[p].to != i && edge[p].to != sp &&
                    edge[p].to != tp && edge[p].flow != 0 && edge[p].flow!= inf)
                    printf("%d %d %d\n", i, edge[p].to, edge[p].flow);
    }
    return 0;
}
