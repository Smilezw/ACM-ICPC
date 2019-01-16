//树上时间节点更新，映射道线段树上更新
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
using namespace std;
#define lson x << 1
#define rson (x << 1) | 1
#define pb push_back

const int MAXN = 1e5 + 5;

struct Node {
    int l, r;
    int val;
}tree[MAXN << 2];

int lazy[MAXN << 2];

void push_down(int x){
    if(lazy[x] != -1){
        lazy[lson] = lazy[x];
        lazy[rson] = lazy[x];
        tree[lson].val = lazy[x];
        tree[rson].val = lazy[x];
        lazy[x] = -1;
    }
}

void creat(int x, int l, int r){
    tree[x].l = l, tree[x].r = r;
    if(l == r) {
        tree[x].val = -1;
        return;
    }
    int mid = (l + r) >> 1;
    creat(lson, l, mid);
    creat(rson, mid + 1, r);
}

void update(int x, int l, int r, int val){
    if(l <= tree[x].l && tree[x].r <= r){
        lazy[x] = val;
        tree[x].val = val;
        return ;
    }
    push_down(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(mid >= l) update(lson, l, r, val);
    if(mid < r) update(rson, l, r, val);
}

int ans;
void check(int x, int pos){
    if(tree[x].l == tree[x].r && tree[x].l == pos){
        ans = tree[x].val;
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    push_down(x);
    if(pos <= mid) check(lson, pos);
    if(pos > mid) check(rson, pos);
}

vector <int > edge[MAXN];
bool fa[MAXN];
int id;

struct line {
    int l, r;
}b[MAXN];

void init(int n) {
    memset(lazy, -1, sizeof(lazy));
    for(int i = 0; i <= n; i++) {
        fa[i] = 0;
        edge[i].clear();
        b[i].l = b[i].r = 0;
    }
    id = 0;
}


void dfs(int pos){
    b[pos].l = ++id;
    int len  = edge[pos].size();
    for(int i = 0; i < len; i++) {
        dfs(edge[pos][i]);
    }
    b[pos].r = id;
}

int main() {
    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d", &n);
        init(n);
        for(int i = 0; i < n-1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            edge[v].pb(u);
            fa[u] = 1;
        }
        int root;
        for(int i = 1; i <= n; i++){
            if(fa[i] == 0) {
                root = i;
                break;
            }
        }
        dfs(root);
        //for(int i = 1; i <= n; i++) printf("%d %d\n", b[i].l, b[i].r);
        creat(1, 1, n);
        scanf("%d", &m);
        printf("Case #%d:\n", cas++);
        while(m--) {
            char q[3];
            scanf("%s", q);
            if(q[0] == 'C') {
                int pos;
                scanf("%d", &pos);
                check(1, b[pos].l);
                printf("%d\n", ans);
            }
            else {
                int pos, val;
                scanf("%d%d", &pos, &val);
                update(1, b[pos].l, b[pos].r, val);
            }
        }
    }
    return 0;
}
