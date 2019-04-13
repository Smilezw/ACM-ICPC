#include <bits/stdc++.h>
using namespace std;

const int N = 55;

struct Edge{
    int to, next;
}edge[N*N];

int head[N];
int tot;

void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}

void add(int u, int v) {
    edge[tot].to = v; edge[tot].next = head[u];
    head[u] = tot++;
}

int linker[N];
bool used[N];
int uN;

bool dfs(int u) {
    for(int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if(!used[v]) {
            used[v] = 1;
            if(linker[v] == -1 || dfs(linker[v])) {  //从匹配边找到找到未匹配边
                linker[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int hungary() {
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for(int u = 0; u < uN; u++) {
        memset(used, 0, sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}
