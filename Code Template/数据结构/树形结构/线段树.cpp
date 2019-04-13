#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define lson x << 1
#define rson (x << 1) + 1
typedef long long ll;

const int MAXN = 1e6 + 5;

struct tree{
    int l, r;
    ll val;
}tree[MAXN];

int a[MAXN];
ll lazy[MAXN];

void push_up(int x){
    tree[x].val = tree[lson].val + tree[rson].val;
}

void push_down(int x){
    if(lazy[x]){
        int l = tree[x].l, r = tree[x].r;
        lazy[lson] += lazy[x];
        lazy[rson] += lazy[x];
        int mid = (l + r) >> 1;
        tree[lson].val += 1ll*(mid - l + 1)*lazy[x];
        tree[rson].val += 1ll*(r - mid)*lazy[x];
        lazy[x] = 0;
    }
}

void creat(int x, int l, int r){
    tree[x].l = l, tree[x].r = r;
    if(l == r) {
        tree[x].val = (ll)a[l];
        return;
    }
    int mid = (l + r) >> 1;
    creat(lson, l, mid);
    creat(rson, mid + 1, r);
    push_up(x);
}

/*
//单点
void updata(int x, int pos, int now){
    if(tree[x].l == tree[x].r) return tree[x].val = tree[x].val + now;

    int mid = ( tree[x].l + tree[x].r ) >> 1;

    if(pos <= mid) updata(lson, pos, now);
    if(pos >= mid + 1) updata(rson, pos, now);
    push_up(x);
}
*/

void update(int x, int l, int r, int val){
    if(l <= tree[x].l && tree[x].r <= r){
        tree[x].val += 1ll*val*(tree[x].r - tree[x].l + 1);
        lazy[x] += 1ll*val;
        return ;
    }
    push_down(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(mid >= l) update(lson, l, r, val);
    if(mid < r) update(rson, l, r, val);
    push_up(x);
}

ll check(int x, int l, int r){
    if(tree[x].l >= l && tree[x].r <= r){
        return tree[x].val;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    push_down(x);
    ll ret = 0;
    if(l <= mid) ret += check(lson, l, r);
    if(r > mid) ret += check(rson, l, r);
    return ret;
}

int l, r, val;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    creat(1, 1, n);
    while(m--) {
        char q[3];
        scanf("%s", q);
        if(q[0] == 'Q') {
            scanf("%d%d", &l, &r);
            printf("%lld\n", check(1, l, r));
        }
        else {
            scanf("%d%d%d", &l, &r, &val);
            update(1, l, r, val);
        }
    }
    return 0;
}
