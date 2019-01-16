//1到n通路中，最小边的最大值

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 1e3 + 5;
const int INF = 0x3f3f3f3f;

int G[MAXN][MAXN];
int d[MAXN];
int n, m;
int vis[MAXN];

int Dijstra() {
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) {
        d[i] = G[1][i];
    }
    vis[1] = 1;
    int v;
    for(int i = 1; i <= n; i++) {
        int f = -1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && f < d[j]) {
                f = d[v = j];
            }
        }
        vis[v] = 1;
        for(int j = 1; j <= n; j++) {
            if(! vis[j]) {
                int mi = min(d[v], G[v][j]);
                if(d[j] < mi) d[j] = mi;
            }
        }
    }
    return d[n];
}

int main() {
    int T, cas = 1;
    cin >> T;
    while(T--) {
        memset(G, 0, sizeof(G));
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m ; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u][v] = G[v][u] = w;
        }
        printf("Scenario #%d:\n%d\n\n", cas++, Dijstra());
    }
    return 0;
}
