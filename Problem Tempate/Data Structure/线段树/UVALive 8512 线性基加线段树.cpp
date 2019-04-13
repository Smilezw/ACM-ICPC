#include <bits/stdc++.h>
using namespace std;

#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define lson x << 1
#define rson (x << 1) + 1
typedef long long ll;
const int N = 1e4 + 5;

struct LB{
    ll b[33];
    void clear(){
        rep(i,0,31) b[i]=0;
    }
    void insert(int x){
        rrep(i,31,0) if(x>>i&1){
            if(b[i]) x^=b[i];
            else{
                b[i]=x;
                //rrep(j,i-1,0) if(b[j]&&(b[i]>>j&1)) b[i]^=b[j];
                //rep(j,i+1,30) if(b[j]>>i&1) b[j]^=b[i];
                break;
            }
        }
    }
    ll rnk1(){
        ll res=0;
        rrep(i,31,0) res=max(res,res^b[i]);
        return res;
    }
};

ll a[N];
ll best;
struct Node {
	int l, r;
	LB b;
}tree[N << 2];

void merge(LB &a, LB &b) {
	for(int i = 0; i <= 31; i++) if(b.b[i]) a.insert(b.b[i]);
}

void push_up(int x){
	merge(tree[x].b, tree[lson].b);
	merge(tree[x].b, tree[rson].b);
}

void creat(int x, int l, int r) {
	tree[x].l = l, tree[x].r = r;
	if(l == r) {
		tree[x].b.insert(a[l]&best);
		return;
	}
	int mid = (l + r) >> 1;
	creat(lson, l, mid);
	creat(rson, mid + 1, r);
	push_up(x);
}

LB ans;

void check(int x, int l, int r) {
	if(l <= tree[x].l && tree[x].r <= r) {
		merge(ans, tree[x].b);
		return;
	}
	//cout << tree[x].l << " " << tree[x].r << endl;
	int mid = (tree[x].l + tree[x].r) >> 1;
    if(l <= mid) check(lson, l, mid);
    if(r > mid)  check(rson, mid+1, r);
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		ll n, q, k;
		scanf("%lld%lld%lld", &n, &q, &k);
		memset(tree, 0, sizeof(tree));
		for(int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		best = 0;
		rep(i,0,31) if(!(k>>i&1)) best|=(1ll<<i);
		creat(1, 1, n);
		while(q--) {
			int l, r;
			scanf("%d%d", &l, &r);
			for(int i = 0; i <= 31; i++) ans.b[i] = 0;
			check(1, l, r);
			printf("%lld\n", ans.rnk1()|1);
		}
	}

	return 0;
}
