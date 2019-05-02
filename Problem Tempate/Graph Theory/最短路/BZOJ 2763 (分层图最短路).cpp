//带堆优  n*logm

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 2e6 + 5;
const int INF = 0x3f3f3f3f;

struct Node {
    int d, pos;
    bool operator < (const Node & rhs) const {
        return d > rhs.d;
    }
};

struct Edge {
    int u, v, w;
};

int n, m, k;

int dis[MAXN];
int vis[MAXN];

vector <Edge > edge[MAXN];

priority_queue <Node > q;

void Dijstra(int s) {
    while(!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    int nn = n*(k+1) + 5;
    for(int i = 0; i <= nn; i++) dis[i] = INF;
    dis[s] = 0;
    q.push(Node{0,s});
    while(!q.empty() ) {
        Node t = q.top();
        q.pop();
        int u = t.pos;
        if(vis[u]) continue;
        vis[u] = 1;
        int len = edge[u].size();
        for(int i = 0; i < len; i++) {
            Edge &e = edge[u][i];
            if(dis[e.v] > dis[u] + e.w) {
                dis[e.v] = dis[u] + e.w;
                q.push(Node {dis[e.v], e.v});
            }
        }
    }
}

void add(int u, int v, int w) {
    edge[u].push_back(Edge{u, v, w});
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    int s, t;
    scanf("%d%d", &s, &t);
    for(int i = 0; i < m; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        add(x, y, w);
        add(y, x, w);
        for(int j = 1; j <= k; j++) {
            add(x+(j*n), y+(j*n), w);
            add(y+(j*n), x+(j*n), w);
            add(x+((j-1)*n), y+(j*n), 0);
            add(y+((j-1)*n), x+(j*n), 0);
        }
    }
    Dijstra(s);
    int ans=0x3f3f3f3f;
    for(int i = 0;i <= k;i++) {
        ans = min(ans, dis[t+i*n]);
    }
    printf("%d\n",ans);
    return 0;
}
