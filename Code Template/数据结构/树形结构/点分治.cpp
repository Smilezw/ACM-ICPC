#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

struct Edge {
    ll u, v, w;
};

ll n;
vector <Edge > edge[N];

vector <int > dep;

ll f[N], s[N], d[N];  //最大子树  树大小  深度
ll allnode, root, maxdeep;
int vis[N];

ll w[5];
ll t[5];
ll ans[5];

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
    int len = edge[u].size();
    for(int i = 0; i < len; i++) {
        int to = edge[u][i].v;
        if(vis[to] || to == f) continue;
        d[to] = d[u] + edge[u][i].w;
        getdeep(to, u);
        s[u] += s[to];
    }
}

void cal(ll now, ll dd, int com) {
    dep.clear();
    d[now] = dd;
    getdeep(now, 0);
    w[0] = w[1] = w[2] = 0;
    t[0] = t[1] = t[2] = 0;
    for(int i = 0; i < dep.size(); i++) {
        w[dep[i]%3] += dep[i];
        t[dep[i]%3]++;
    }
    if(com == 1) {
        ans[0] += (w[1]*t[2] + w[2]*t[1] + w[0] );
        ans[1] += (w[0]*t[1] + w[1]*t[0] + w[1] );
        ans[2] += (w[0]*t[2] + w[2]*t[0] + w[2] );
        if(t[0]) ans[0] = ans[0] + w[0]*(t[0]-1);
        if(t[1]) ans[2] = ans[2] + w[1]*(t[1]-1);
        if(t[2]) ans[1] = ans[1] + w[2]*(t[2]-1);
    }
    else {
        ans[0] -= (w[1]*t[2] + w[2]*t[1] + w[0] );
        ans[1] -= (w[0]*t[1] + w[1]*t[0] + w[1] );
        ans[2] -= (w[0]*t[2] + w[2]*t[0] + w[2] );
        if(t[0]) ans[0] = ans[0] - w[0]*(t[0]-1);
        if(t[1]) ans[2] = ans[2] - w[1]*(t[1]-1);
        if(t[2]) ans[1] = ans[1] - w[2]*(t[2]-1);
    }
    /*
    cout << "t[0]  " << t[0] << " " << w[0] << endl;
    cout << "t[1]  " << t[1] << " " << w[1] << endl;
    cout << "t[2]  " << t[2] << " " << w[2] << endl;
    cout << "adadad " << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    */
}

void solve(int now) {
    int u;
    cal(now, 0, 1);
    //cout << "vis  " << now << endl;
    vis[now] = 1;
    for(int i = 0; i < edge[now].size(); i++) {
        int v = edge[now][i].v;
        if(vis[v] == 0) {
            cal(v, edge[now][i].w, 0);
            f[0] = allnode = s[v];
            getroot(v, root = 0);
            solve(root);
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u++, v++;
        edge[u].push_back(Edge{u, v, w});
        edge[v].push_back(Edge{v, u, w});
    }
    f[0] = allnode = n;
    getroot(1, root = 0);
    ans[0] = ans[1] = ans[2] = 0;
    solve(root);
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    return 0;
}
