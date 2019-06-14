#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 1005;
const int M = N*N;
const int inf = 1 << 30;

struct Edee{
    ll u, v, w;
}edge[M];

ll pre[N], f[N], vis[N], l[N];  //父，记录环 ，缩点，最小入边

ll Directed_MST(int root, int n, int m) {
    ll ret = 0;
    ll u, v, cnt;
    while(1) {
        for(int i = 1; i <= n; i++) f[i] = vis[i] = 0, l[i] = inf;
        for(int i = 1; i <= m; i++) {
            u = edge[i].u;
            v = edge[i].v;
            if(l[v] > edge[i].w) pre[v] = u, l[v] = edge[i].w;
        }
        for(int i = 1; i <= n; i++)  //子图入边
            if(l[i] == inf && i != root) return -1;
        l[root] = cnt = 0;
        for(int i = 1; i <= n; i++) {
            ret += l[i];
            if(vis[i]) continue;  //缩点
            for(v = i; !vis[v] && v != root; vis[v] = i, v = pre[v]);
            if(v != root && vis[v] == i) {  //第i个点形成环
                f[v] = ++cnt;
                for(u = pre[v]; u != v; u = pre[u]) f[u] = cnt;
            }
        }
        if(!cnt) break;  //无环
        for(int i = 1; i <= n; i++) if(!f[i]) f[i] = ++cnt;
        n = cnt, cnt = 0, root = f[root];
        for(int i = 1; i <= m; i++) {
            u = edge[i].u, v = edge[i].v;
            if(f[u] != f[v]) {  //外面指向环的边
                edge[++cnt].u = f[u];
                edge[cnt].v = f[v];
                edge[cnt].w = edge[i].w - l[v];   //最后一条边减去即可
            }
        }
        m = cnt;  //新图
    }
    return ret;
}

int  n, m, X, Y, Z;

struct Node {
    ll x, y, z;
}p[N];

ll mlen(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

int main() {
    while(cin >> n >> X >> Y >> Z && n && X && Y && Z) {
        m = 0;
        for(int i = 1; i <= n; i++) scanf("%lld%lld%lld", &p[i].x, &p[i].y, &p[i].z);
        for(int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            while(k--) {
                ll v;
                scanf("%lld", &v);
                ll w = mlen(p[i], p[v])*Y;
                if(p[i].z >= p[v].z) edge[++m].w = w;
                else edge[++m].w = w+Z;
                edge[m].u = i;
                edge[m].v = v;
            }
        }
        int root = n+1;
        for(int i = 1; i <= n; i++) {
            edge[++m].w = p[i].z * X;
            edge[m].u = root;
            edge[m].v = i;
        }
        ll ans =  Directed_MST(root, n + 1, m);
        if(ans == -1) cout << "poor XiaoA" << endl;
        else cout << ans << endl;
   }
   return 0;
}
