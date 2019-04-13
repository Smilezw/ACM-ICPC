#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const ll INF = 9e18;
const int N = 3e5+50;
struct edge {
    int v, w;
};
vector <edge> G[N];
int n, U, V, dep[N], Fa[N][22];

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    Fa[u][0] = fa;
    for(int i = 1; (1<<i) <= dep[u]; i++) Fa[u][i] = Fa[Fa[u][i-1]][i-1];
    for(auto &e:G[u]) {
        int v = e.v;
        if(v == fa) continue;
        dfs(v, u);
    }
}
int lca(int x,int y) {
    if(dep[x] < dep[y]) swap(x,y);
    for(int i = 20;i >= 0; i--) if((1<<i)<=dep[x]-dep[y]) x=Fa[x][i];
    if(x==y) return x;
    for(int i=20;i>=0;i--) if(Fa[x][i]!=Fa[y][i]) x=Fa[x][i],y=Fa[y][i];
    return Fa[x][0];
}

int solve(int x,int y) { return dep[x]+dep[y]-2*dep[lca(x,y)]; }
