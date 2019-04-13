#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 505;
const int M = 505*505;
const int INF = 1 << 30;
                       //并查集
int f[N];

int Find(int x) { return f[x] == x ? x : f[x] = Find(f[x]); }

void init() { for(int i = 0; i <= N; i++) f[i] = i; }

void merge(int x, int y) { int fx = Find(x), fy = Find(y); if(fx != fy) f[fx] = fy; }

//处理maxw

int maxw[N][N];   //u到v最长边长

struct Edge { int u, v, w; };

vector <int > edge[N];
Edge G[M];

int n, m;

int cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int vis[M];
int ans;

void kruskal() {
    init();
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n; i++) {
        edge[i].clear();
        edge[i].push_back(i);
    }
    ans = 0;
    sort(G, G + m, cmp);

    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < m; i++) {
        if(cnt == n-1) break;
        int fx = Find(G[i].u);
        int fy = Find(G[i].v);

        if(fx != fy){
            sum += G[i].w;
            int lx = edge[fx].size();
            int ly = edge[fy].size();
            for(int j = 0; j < lx; j++)//修改maxw数组
                for(int k = 0; k < ly; k++) {
                    int a = edge[fx][j];
                    int b = edge[fy][k];
                    //每次合并两个等价类的之后,分别属于两个等价类的两个节点之间的最长边一定是当前加入的边
                    maxw[a][b] = maxw[b][a] = G[i].w;
                }
            //合并并查集
            for(int j = 0; j < lx; j++) edge[fy].push_back(edge[fx][j]);
            merge(fx, fy);
            cnt++;
            vis[i] = 1;
        }
    }
    ans = INF;  //次小树权值
    for(int i = 0; i < m; i++) {
        if(!vis[i]) ans = min(sum + G[i].w - maxw[G[i].u][G[i].v], ans);
    }
    if(ans > sum)
        printf("%d\n", sum);
    else
        printf("Not Unique!\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            cin >> G[i].u >> G[i].v >> G[i].w;
        }
        kruskal();
    }
    return 0;
}
