//D代表破坏村庄，R代表修复最后被破坏的那个村庄，Q代表询问包括x在内的最大连续区间是多少

//维护区间左边最大长  右边最大长  区间最大长
//注意左右区间长度关系

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

const int MAXN = 1e5 + 5;

struct Node {
    int l, r;
    int sl, sr, sum;
}tree[MAXN << 2];

void creat(int x, int l, int r) {
    tree[x].l = l, tree[x].r = r;
    tree[x].sl = tree[x].sr = tree[x].sum = r - l + 1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    creat(lson, l, mid);
    creat(rson, mid + 1, r);
}

void update(int x, int pos, int val) {
    if(tree[x].l == tree[x].r) {
        if(val == 1)
            tree[x].sl = tree[x].sr = tree[x].sum = 1;
        else
            tree[x].sl = tree[x].sr = tree[x].sum = 0;
        return ;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(pos <= mid)
        update(lson, pos, val);
    else
        update(rson, pos, val);
    tree[x].sl = tree[lson].sl;
    tree[x].sr = tree[rson].sr;
    int t = max(tree[lson].sum, tree[rson].sum);
    tree[x].sum = max(t, tree[lson].sr + tree[rson].sl);
    if(tree[lson].sl == tree[lson].r - tree[lson].l + 1)
        tree[x].sl += tree[rson].sl;
    if(tree[rson].sr == tree[rson].r - tree[rson].l + 1)
        tree[x].sr += tree[lson].sr;
}

int check(int x, int pos) {
    if(tree[x].l == tree[x].r || tree[x].sum == tree[x].r - tree[x].l + 1 || tree[x].sum == 0)
        return tree[x].sum;
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(pos <= mid) {
        if(pos >= tree[lson].r - tree[lson].sr + 1)
            return check(lson, pos) + check(rson, mid + 1);
        else
            return check(lson, pos);
    }
    else {
        if(pos <= tree[rson].l + tree[rson].sl - 1)
            return check(rson, pos) + check(lson, mid);
        else
            return check(rson, pos);
    }
}

stack <int > s;

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        creat(1, 1, n);
        while(!s.empty()) s.pop();
        while(m--) {
            char q[3];
            int pos;
            scanf("%s", q);
            if(q[0] == 'D') {
                scanf("%d", &pos);
                s.push(pos);
                update(1, pos, 0);
            }
            else if(q[0] == 'Q') {
                scanf("%d", &pos);
                printf("%d\n", check(1, pos) );
            }
            else {
                if(!s.empty()) {
                    pos = s.top();
                    s.pop();
                    update(1, pos, 1);
                }
            }
        }
    }
    return 0;
}
