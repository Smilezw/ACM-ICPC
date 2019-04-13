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
int num = 0;
map <string, int> mp;
string aa[N];

int main() {
    while(cin >> n) {
        int t = 1;
        init();
        sp = 0;
        for(int i = 1; i <= n; i++) {
            string ss;
            cin >> ss;
            aa[i] = ss;
            if(mp[ss] == 0) {
                mp[ss] = t;
                t++;
            }
        }
        cin >> m;
        for(int i = 1; i <= m; i++) {
            string a, b;
            cin >> a >> b;
            add(sp, t++, 1);
            if(mp[b] == 0) { //没有开关自己相连
                mp[b] = t;
                add(t-1, t, 1);
                t++;
            }
            else {
                add(t-1, mp[b], 1);
            }
        }
        int k;
        cin >> k;
        for(int i = 0; i < k; i++) {
            string a, b;
            cin >> a >> b;
            if(mp[a] == 0) mp[a] = t++;
            if(mp[b] == 0) mp[b] = t++;
            add(mp[a], mp[b], inf);
        }
        tp = t;
        for(int i = 1; i <= n; i++){
            add(mp[aa[i]], tp, 1);
        }
        t++;
        int ans = dinic(sp, tp, t);
        cout << m - ans << endl;
    }
    return 0;
}
