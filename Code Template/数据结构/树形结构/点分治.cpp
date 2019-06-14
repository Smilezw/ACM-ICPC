#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 10;

int siz[MAXN], f[MAXN];
int vis[MAXN];
vector <int > G[MAXN];
int n, allnode, root;

void getroot(int u, int fa) {  //根部节点
    siz[u] = 1; f[u] = 0;
    int len = G[u].size();
    for(int i = 0; i < len; i++) {
        int to = G[u][i];
        if(vis[to] || to == fa) continue;
        getroot(to, u);
        siz[u] += siz[to];
        f[u] = max(f[u], siz[to]);
    }
    f[u] = max(f[u], allnode - siz[u]); //除当前点以外的所有子树
    if(f[u] < f[root]) root = u;
}

int dep[MAXN], mxdep;
int cnt[MAXN], nowcnt[MAXN];

void getdeep(int u, int f) {   //深度
    siz[u] = 1;
    int len = G[u].size();
    for(int i = 0; i < len; i++) {
        int to = G[u][i];
        if(vis[to] || to == f) continue;
        dep[to] = dep[u] + 1;
        getdeep(to, u);
        mxdep = max(mxdep, dep[to]);
        siz[u] += siz[to];
    }
}


ll cal(int u, int val) {  //计算贡献
    ll ret = 0;

    return ret;
}

void point_Divede(int x) {
    vis[x] = 1;
    cal(x, 1);  //父节点的所有距离
    int se = G[x].size();
    for(int i = 0; i < se; i++) {
        int to = G[x][i];
        if(vis[to]) continue;
        cal(to, -1);   //减去子树所有贡献
        getroot(to, x);
        point_Divede(root);
    }
}
