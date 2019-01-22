//求起点到源点的所有路径中，所有最大长度边的最小值
//法一 跑最小生成树，得到的通路上的最长边满足题意
//法二 按最短路跑，但是dis记录答案，有转移公式dis[v] = min( max(dis[x], edge[x][y].w) )
//既起点到终点的路途中，更新最大边，dis存最小值

//1
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 5;

int f[MAXN];

struct Edge {
    int u, v;
    double w;
}edge[MAXN];

int father(int x) {
    return x == f[x] ? x : f[x] = father(f[x]);
}

int cmp(Edge a, Edge b) {
    return a.w < b.w;
}

struct Point {
    double x, y;
}p[MAXN];

double dir(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

vector <Edge > tree[MAXN];

bool vis[MAXN];
double ans;
bool dfs(int cur, double ddd){
    vis[cur]=1;
    if(cur==1){
       ans = ddd;
       return true;
    }
    int len = tree[cur].size();
    for(int i = 0; i < len; i++){
        int v = tree[cur][i].v;
        if(!vis[v]){
            if(ddd < tree[cur][i].w){
               if(dfs(v, tree[cur][i].w))  return true;
            }
            else if(dfs(v, ddd)) return true;
       }
    }
    return false;
}
void init() {
    for(int i = 0; i <= MAXN; i++) {
        f[i] = i;
        tree[i].clear();
    }
}

int main() {
    int n, m;
    int cas = 1;
    while(cin >> n && n) {
        init();
        m = 0;
        for(int i= 0; i < n; i++) cin >> p[i].x >> p[i].y;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                double w = dir(p[i], p[j]);
                edge[m++] = Edge {i, j, w};
                edge[m++] = Edge {j, i, w};
            }
        }
        sort(edge, edge + m, cmp);
        ans = 0;
        for(int i = 0; i < m; i++) {
            int u = edge[i].u;
            int v = edge[i].v;
            int fu = father(u);
            int fv = father(v);
            if(fu != fv) {
                tree[u].push_back(edge[i]);
                tree[v].push_back(Edge{v, u, edge[i].w});
                f[fv] = fu;
            }
        }
        memset(vis, 0, sizeof(vis));
        dfs(0, 0.0);
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", cas++, ans);
    }
    return 0;
}



//2
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <cmath>

using namespace std;

const int maxn = 220;

const double INF = 1e60;

int n;
double G[maxn][maxn], d[maxn];

struct Pos {
    int x, y;
}num[maxn];

double calc(int i, int j) {
    return (sqrt(pow((double)num[i].x-num[j].x, 2)+pow((double)num[i].y-num[j].y, 2)));
}

double dijkstra() {
    bool vis[maxn];

    memset(vis, false, sizeof(vis));

    for(int i=0; i<n; i++) {
        d[i] = G[0][i];
    }

    d[0] = 0;
    vis[0] = true;

    for(int i=0; i<n-1; i++) {
        double m = INF; int x;
        for(int y=0; y<n; y++) if(!vis[y] && m >= d[y]) m = d[x=y];
        vis[x] = true;
        for(int y=0; y<n; y++){
            if(!vis[y]) {
                double maxx = max(d[x], G[x][y]);
                if(d[y] > maxx) d[y] = maxx;
            }
        }
    }

    return d[1];
}

int main() {
    int cnt = 0;
    while(scanf("%d", &n) == 1) {
        if(n == 0) break;

        for(int i=0; i<n; i++) scanf("%d%d", &num[i].x, &num[i].y);

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                G[i][j] = G[j][i] = calc(i, j);
            }
            G[i][i] = 0;
        }

        printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++cnt, dijkstra());
    }

    return 0;
}

*/
