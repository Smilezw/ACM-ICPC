//pre数组很灵性 记录前序不必要的贡献

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100000;

int mu[maxn + 10], pcnt, prime[maxn];
bool vis[maxn + 10];
vector<int> factors[maxn + 10];
vector<int> G[maxn + 10];

void preprocess() {
    pcnt = 0;
    mu[1] = 1;
    for(int i = 2; i <= maxn; i++) {
        if(!vis[i]) {
            mu[i] = -1;
            prime[pcnt++] = i;
        }
        for(int j = 0; j < pcnt && i * prime[j] <= maxn; j++) {
            vis[i * prime[j]] = true;
            if(i % prime[j] != 0) mu[i * prime[j]] = -mu[i];
            else {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }

    for(int i = 2; i <= maxn; i++) if(mu[i])
        for(int j = i; j <= maxn; j += i) factors[j].push_back(i);
}

int val[maxn + 10];
int n;

int cnt[maxn], sz[maxn], ans[maxn];

void dfs(int u, int fa) {
    sz[u] = 1;
    vector<int> pre;
    for(int d : factors[val[u]]) {
        pre.push_back(cnt[d]);
        cnt[d]++;
    }
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    ans[u] = sz[u];
    for(int i = 0; i < factors[val[u]].size(); i++) {
        int d = factors[val[u]][i];
        int c = cnt[d] - pre[i];
        if(c) ans[u] += mu[d] * c;
    }
}

int main()
{
    preprocess();

    int kase = 1;
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; i++) G[i].clear();

        for(int u, v, i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) scanf("%d", val + i);

        memset(cnt, 0, sizeof(cnt));
        dfs(1, 0);

        printf("Case #%d:", kase++);
        for(int i = 1; i <= n; i++) printf(" %d", ans[i]);
        printf("\n");
    }

    return 0;
}
