//每次更新一个区间，最后有多少个区间没被重复染色且颜色什么
//舍去左端点，把线段缩成点
//注意区间长度
#include <bits/stdc++.h>
using namespace std;

#define lson x << 1
#define rson (x << 1) + 1
#define Mid  (tree[x].l + tree[x].r) >> 1
typedef long long ll;
const int MAXN = 1e5 + 5;

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
void push_down(int x){
    if(lazy[x] != -1){
		lazy[lson] = lazy[x];
		lazy[rson] = lazy[x];
		lazy[x] = -1;
		tree[lson].val = lazy[lson];
		tree[rson].val = lazy[rson];
	}
}

void creat(int x, int l, int r) {
    if(l > r) return ;
    tree[x].l = l, tree[x].r = r;
    if(l == r) {
        tree[x].val = -1;
        return ;
    }
    int mid = (l + r) >> 1;
    creat(lson, l, mid);
    creat(rson, mid+1, r);
}


//区间
int updata(int x, int l, int r, int now) {
    if(tree[x].l >= l && tree[x].r <= r){
        tree[x].val = now;
        lazy[x] = now;
        return tree[x].val;
    }
    push_down(x);
    int mid = Mid;
    if(l <= mid) updata(lson, l, r, now);
    if(r >= mid + 1) updata(rson, l, r, now);
    return now;
}
int last;
void solve(int x, int l, int r){
	if(tree[x].l == tree[x].r) {
		if(tree[x].val != -1 && tree[x].val != last)
			a[tree[x].val]++;
		last = tree[x].val;
		return ;
	}
	push_down(x);
	int mid = Mid;
    if(l <= mid) solve(lson, l, r);
    if(r >= mid + 1) solve(rson, l, r);
}

int n;
int l, r, pos, val;

int main() {
	//int T;
    //int cas = 1;
    while(scanf("%d", &n) != EOF){
        memset(lazy, -1, sizeof(lazy));
		memset(a, 0, sizeof(a));
		creat(1, 1, 8005);
        while(n--){
            scan_d(l);
            scan_d(r);
            scan_d(val);
            updata(1, l+1, r, val);
        }
		solve(1, 1, 8005);
		for(int i = 0; i <= 8005; i++){
			if(a[i]) printf("%d %d\n", i, a[i]);
		}
		cout << endl;
    }
    return 0;
}
