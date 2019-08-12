#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e5 + 5;

struct Edge {
    int u, v, w;
};

int n, k;
vector <Edge > edge[N];

vector <int > dep;

int f[N], s[N], d[N];  //最大子树  树大小  深度
int allnode, root, maxdeep;
int vis[N];

int ans;

void getroot(int u, int fa) {  //根部节点
    s[u] = 1; f[u] = 0;
    int len = edge[u].size();
    for(int i = 0; i < len; i++) {
        int to = edge[u][i].v;
        if(vis[to] || to == fa) continue;
        getroot(to, u);
        s[u] += s[to];
        f[u] = max(f[u], s[to]);
    }
    f[u] = max(f[u], allnode - s[u]); //除当前点以外的所有子树
    if(f[u] < f[root]) root = u;
}

void getdeep(int u, int f) {   //深度
    s[u] = 1;
    dep.push_back(d[u]);
    //cout << u << " " << dep[dep.size()-1] << endl;
    int len = edge[u].size();
    for(int i = 0; i < len; i++) {
        int to = edge[u][i].v;
        if(vis[to] || to == f) continue;
        d[to] = d[u] + edge[u][i].w;
        getdeep(to, u);
        s[u] += s[to];
    }
}

int cal(int now, int dd) {
    dep.clear();
    d[now] = dd;
    getdeep(now, 0);
    sort(dep.begin(), dep.end());
    int ret = 0;
    for(int l = 0, r = dep.size() - 1; l < r;) {
        //cout << "dad  " << dep[l] << " " << dep[r] << endl;
        //cout << l << " " << r << endl;
        if(dep[l] + dep[r] <= k) ret += r-l++;
        else r--;
    }
    return ret;
}

void solve(int now) {
    int u;
    ans += cal(now, 0);
    vis[now] = 1;
    for(int i = 0; i < edge[now].size(); i++) {
        int v = edge[now][i].v;
        if(vis[v] == 0) {
            ans = ans - cal(v, edge[now][i].w);
            f[0] = allnode = s[v];
            getroot(v, root = 0);
            solve(root);
        }
    }
}

int main() {
    while(scanf("%d%d", &n, &k) && n && k) {
        for(int i = 0; i <= n; i++) edge[i].clear();
        memset(vis, 0, sizeof(vis));
        ans = 0;
        for(int i = 0; i < n-1; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge[u].push_back(Edge{u, v, w});
            edge[v].push_back(Edge{v, u, w});
        }
        f[0] = allnode = n;
        getroot(1, root = 0);
        ans = 0;
        solve(root);
        cout << ans << endl;
    }
    return 0;
}
