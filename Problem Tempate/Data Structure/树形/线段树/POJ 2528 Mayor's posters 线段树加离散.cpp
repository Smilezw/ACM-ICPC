#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define lson x << 1
#define rson (x << 1) + 1
typedef long long ll;

const int MAXN = 5e5 + 5;

int l[MAXN];
int r[MAXN];
int h[MAXN];
int ans, cnt, n;

struct Node{
    int l, r;
    int val;
}tree[MAXN];

int num[MAXN];

void push_down(int x){
    if(tree[x].val != -1){
       tree[lson].val = tree[rson].val = tree[x].val;
       tree[x].val = -1;
    }
}

void update(int x, int l, int r, int val){
    if(l <= tree[x].l && tree[x].r <= r){
        tree[x].val = val;
        return;
    }
    push_down(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(mid >= l) update(lson, l, r, val);
    if(mid < r) update(rson, l, r, val);
}

void check(int x, int l, int r){
    if(tree[x].l == tree[x].r){
        if(tree[x].val == -1) return;
        if(num[tree[x].val] == 0) ans++;
        num[tree[x].val]++;
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    push_down(x);
    if(l <= mid) check(lson, l, r);
    if(r > mid) check(rson, l, r);
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

void init(){
    memset(num, 0, sizeof(num));
    ans = cnt = 0;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        init();
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &l[i], &r[i]);
            h[cnt++] = l[i];
            h[cnt++] = r[i];
        }
        sort(h, h + cnt);
        cnt = unique(h, h + cnt) - h;
        int t = cnt;
        for(int i = 1; i < t; i++){
            if(h[i] - h[i-1] > 1)  h[cnt++] = h[i-1] + 1;
        }
        sort(h, h + cnt);
        creat(1, 1, cnt);
        for(int i = 0; i < n; i++){
            int p1 = lower_bound(h, h + cnt, l[i]) - h + 1;
            int p2 = lower_bound(h ,h + cnt, r[i]) - h + 1;
            update(1, p1, p2, i);
        }
        check(1, 1, cnt);
        printf("%d\n", ans);
    }
    return 0;
}
