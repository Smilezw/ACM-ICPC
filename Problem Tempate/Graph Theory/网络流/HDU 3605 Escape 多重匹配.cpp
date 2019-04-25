//O（m*n*n）  建图小心点
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int inf = 0x3f3f3f3f;
const int N = 5000;
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
int sp, tp;
int pr[N];

typedef long long ll;

inline ll gi(){
    ll x=0,q=1; char ch=getchar(); while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
    if (ch=='-') q=-1,ch=getchar(); while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar(); return q*x;
}


int main() {
    while(scanf("%d%d", &n, &m)!=EOF) {
        init();
        sp = 0;
        memset(pr, 0, sizeof(pr));
        for(int i = 1; i <= n; i++) {
            int v = 0;
            for(int j = 0; j < m; j++) {
                int x;
                x = gi();
                if(x) v |= (1 << j);
            }
            pr[v]++;
        }
        int nn = (1 << m);
        int nt = m+1;
        for(int i = 1; i < nn; i++) {
            if(pr[i]) {
                add(sp, nt, pr[i]);
                for(int j = 0; j < m; j++) {
                    if(i & (1 << j)) add(nt, j+1, pr[i]);
                }
                nt++;
            }
        }
        tp = nt;
        for(int i = 1; i <= m; i++) {
            int w;
            w = gi();
            add(i, tp, w);
        }
        nt++;
        int ans = dinic(sp, tp, nt);
        if(ans == n) puts("YES");
        else cout << "NO"<< endl;
    }
    return 0;
}
