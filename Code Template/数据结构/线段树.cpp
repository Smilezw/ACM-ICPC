#include <bits/stdc++.h>
using namespace std;

#define lson x << 1
#define rson (x << 1) + 1
#define Mid  (tree[x].l + tree[x].r) >> 1
typedef long long ll;
const int MAXN = 1e6 + 5;

template <class T>
inline void scan_d(T &ret) {
	char c; ret=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
}

inline void out(int x) {
   if(x>9) out(x/10);
   putchar(x%10+'0');
}

inline ll gi(){
    ll x=0,q=1; char ch=getchar(); while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
    if (ch=='-') q=-1,ch=getchar(); while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar(); return q*x;
}


struct Node {
    int l, r;
    int val;
}tree[MAXN];

int a[MAXN];
int lazy[MAXN];

int push_up(int x){
    return tree[x].val = tree[lson].val + tree[rson].val;
}

void push_down(int x){
    if(lazy[x] != -1){
		int l = tree[x].l, r = tree[x].r;
		lazy[lson] = lazy[x];
		lazy[rson] = lazy[x];
		lazy[x] = -1;
		int mid = (l + r) >> 1;
		tree[lson].val = (mid - l + 1)* lazy[lson];
		tree[rson].val = (r - mid)* lazy[rson];
	}
}

void creat(int x, int l, int r) {
    if(l > r) return ;
    tree[x].l = l, tree[x].r = r;
    if(l == r) {
        tree[x].val = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    creat(lson, l, mid);
    creat(rson, mid+1, r);
    push_up(x);
}

//区间
int updata(int x, int l, int r, int now) {
    if(tree[x].l >= l && tree[x].r <= r){
        tree[x].val = now * (tree[x].r - tree[x].l + 1);
        lazy[x] = now;
        return tree[x].val;
    }
    push_down(x);
    int mid = Mid;
    if(l <= mid) updata(lson, l, r, now);
    if(r >= mid + 1) updata(rson, l, r, now);
    return push_up(x);
}


/*
//单点
int updata(int x, int pos, int now){
    if(tree[x].l == tree[x].r) return tree[x].val = tree[x].val + now;

    int mid = Mid;

    if(pos <= mid) updata(lson, pos, now);
    if(pos >= mid + 1) updata(rson, pos, now);
    return push_up(x);
}
*/

//区间查询
int check(int x, int l, int r) {
    if(tree[x].l >= l && tree[x].r <= r) return tree[x].val;
    int mid = Mid;
    int ret = 0;
    if(l <= mid) ret += check(lson, l, r);
    if(r >= mid + 1) ret += check(rson, l, r);
    return ret;
}

int n;
int l, r, pos, val;

int main() {
    int T;
    int cas = 1;
    cin >> T;
    while(T--){
        memset(lazy, -1, sizeof(lazy));
        scanf("%d", &n);
        //for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        creat(1, 1, n);
        //char q[20];
        int q;
        scanf("%d", &q);
        while(q--){
            /*
            scanf("%s", q);
            if(q[0] == 'E') break;
            if(q[0] == 'Q'){
                scanf("%d %d", &l, &r);
                printf("%d\n", check(1, l, r));
            }
            */
            scan_d(l);
            scan_d(r);
            scan_d(val);
            //scanf("%d%d%d", &l, &r, &val);
            updata(1, l, r, val);
        }
        printf("Case %d: The total value of the hook is %d.\n", cas++, tree[1].val);
    }
    return 0;
}
