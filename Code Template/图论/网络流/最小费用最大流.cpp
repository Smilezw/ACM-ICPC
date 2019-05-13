//spfa

#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAXN = 1005;
const int MAXM = 1e6 + 5;
const int INF = 1e9;
int N;

struct Edge {
    int to, next, cap, flow, cost;
}edge[MAXM];

int head[MAXN], tol;
int pre[MAXN], dis[MAXN];
bool vis[MAXN];

void init(int n) {
    N = n;
    tol = 0;
    memset(head, -1, sizeof(head));
}

void add(int u, int v, int c, int cost) {
    edge[tol].to = v; edge[tol].cap = c;
    edge[tol].cost = cost; edge[tol].flow = 0;
    edge[tol].next = head[u]; head[u] = tol++;
    edge[tol].to = u; edge[tol].cap = 0;
    edge[tol].cost = -cost; edge[tol].flow = 0;
    edge[tol].next = head[v]; head[v] = tol++;
}

bool spfa(int s, int t) {
    queue <int> q;
    for(int i = 0; i < N; i++) {
        dis[i] = INF;
        vis[i] = 0;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if(edge[i].cap > edge[i].flow &&
                dis[v] > dis[u] + edge[i].cost) {
                    dis[v] = dis[u] + edge[i].cost;
                    pre[v] = i;
                    if(!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
            }
        }
    }
    //if (dis[t] > 0) return false;
    if(pre[t] == -1) return 0;
    else return 1;
}

int minCostMaxflow(int s, int t, int &cost) {
    int flow = 0;
    cost = 0;
    while(spfa(s, t)) {
        int Min = INF;
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to]) {
            if(Min > edge[i].cap - edge[i].flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to]) {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}

int sp, tp;
int n, m;
struct P{
    int x;
    int y;
};
vector <P> p1, p2;
int cal(P a, P b) {
    return abs(1.0*a.x - b. x) + abs(1.0*a.y - b.y);
}

int main() {
    while(cin >> n >> m && n && m) {
        sp = 0;
        init(1005);
        p1.clear();
        p2.clear();
        for(int i = 0; i < n; i++) {
            char q[300];
            scanf("%s", q);
            for(int j = 0; j < m; j++) {
                if(q[j] == 'H') p2.push_back(P{i, j});
                else if(q[j] == 'm') p1.push_back(P{i, j});
            }
        }
        int l1 = p1.size(), l2 = p2.size();
        tp = l1 + l2 + 1;
        for(int i = 0; i < l1; i++) {
            for(int j = 0; j < l2; j++) {
                add(i+1, j+1+l1, 1, cal(p1[i], p2[j]));
            }
        }
        for(int i = 0; i < l1; i++) add(sp, i+1, 1, 0);
        for(int i = 0; i < l2; i++) add(i+1+l1, tp, 1, 0);
        int cost = 0;
        minCostMaxflow(sp, tp, cost);
        cout << cost << endl;
    }
    return 0;
}
