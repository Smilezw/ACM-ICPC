//logm
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int f[MAXN];

struct Edge {
    int u, v, w;
}edge[MAXN];

int father(int x) {
    return x == f[x] ? x : f[x] = father(f[x]);
}

void init() {
    for(int i = 0; i <= MAXN; i++) {
        f[i] = i;
    }
}

int cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n, m;
    while(cin >> n && n) {
        cin >> m;
        init();
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edge[i] = Edge{u,v,w};
        }
        sort(edge, edge + m, cmp);
        int ans = 0;
        for(int i = 0; i < m; i++) {
            int u = edge[i].u;
            int v = edge[i].v;
            int fu = father(u);
            int fv = father(v);
            if(fu != fv) {
                f[fv] = fu;
                ans = ans + edge[i].w;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
