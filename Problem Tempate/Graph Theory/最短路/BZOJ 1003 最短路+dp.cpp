//考虑第1天到第i天所用f[i]
//f[i] = min(f[i], f[j] + cost[j+1][i] + k)
//cost 为不换路的代价

#include <bits/stdc++.h>
using namespace std;

const int N = 105;
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

int dis[N];
int vis[N];
int flag[N];

vector <Edge > edge[N];

priority_queue <Node > q;

void Dijstra(int s) {
    while(!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= N; i++) dis[i] = INF;
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
            if(dis[e.v] > dis[u] + e.w && !flag[e.v]) {
                dis[e.v] = dis[u] + e.w;
                q.push(Node {dis[e.v], e.v});
            }
        }
    }
}

int broken[N][N];
int cost[N][N];
int f[N];

int main() {
    int n, m, k, e;
    cin >> n >> m >> k >> e;
    for(int i = 0;  i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back(Edge{u, v, w});
        edge[v].push_back(Edge{v, u, w});
    }
    int d;
    cin >> d;
    for(int i = 0; i < d; i++) {
        int p, a, b;
        cin >> p >> a >> b;
        for (int j = a;j <= b; ++j) broken[p][j] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            memset(flag, 0, sizeof(flag));
            for(int k = 1; k <= m; k++)
                for(int l = i; l <= j; l++)
                    flag[k] |= broken[k][l];
            Dijstra(1);
            cost[i][j] = dis[m];   //处理不换路第i到第j天
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            if (cost[i][j] < INF) cost[i][j]*=(j-i+1);

    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++) {
        f[i] = cost[1][i];
    }
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            f[i] = min(f[i], f[j] + cost[j+1][i] + k);
    cout << f[n] << endl;
    return 0;
}
