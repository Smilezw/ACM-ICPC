// k*m-n*m

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

struct Edge {
    int u, v, w;
};

int dis[MAXN];
bool vis[MAXN];
int cnt[MAXN];
int n, m;

vector <Edge> edge[MAXN];

queue <int > q;

int Bellman_ford(int s) {
    while(!q.empty()) q.pop();
    memset (vis, 0, sizeof(vis));
    memset (cnt, 0, sizeof(cnt));
    for(int i = 0; i <= n; i++) dis[i] = INF;
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        int len = edge[u].size();
        for(int i = 0; i < len; i++) {
            Edge & e = edge[u][i];
            if(dis[u] < INF && dis[e.v] > dis[u] + e.w) {
                dis[e.v] = dis[u] + e.w;
                if(!vis[e.v]) {
                    q.push(e.v);
                    vis[e.v] = 1;
                    if(++cnt[e.v] > n) return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    while(cin >> m >> n) {
        for(int i = 0; i <= n; i++)
            edge[i].clear();
        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            Edge t1 = {u, v, w};
            Edge t2 = {v, u, w};
            edge[u].push_back(t1);
            edge[v].push_back(t2);
        }
        Bellman_ford(1);
        cout << dis[n] << endl;
    }
    return 0;
}
