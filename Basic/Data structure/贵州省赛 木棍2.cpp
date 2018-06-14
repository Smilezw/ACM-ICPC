//离线线段树查询  利用前到后无后效性的原理
//贵州省赛木棍 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define lson x << 1
#define rson (x << 1) + 1
typedef long long ll;
const int MAXN = 30000 + 5;
struct C{
	int l, r, ci;
}c[100000 + 5];

struct Node{
	ll sum;
	int l ,r;
}tree[MAXN << 2]; 
ll a[MAXN];
ll ans[1000000 + 5];
int n;
map <ll,int> m;
int cmp(const C &a, const C &b){
	return a.r < b.r;
}

void Push_up(int x){   
	tree[x].sum = tree[lson].sum + tree[rson].sum;
}

void Creat(int x, int L, int R){
	if(L > R) return;
	tree[x].l = L; tree[x].r = R;
	if(L == R) {
		//赋值操作 
		tree[x].sum = a[L]; 
		return; 
	}
	int mid = (L + R) >> 1;
	Creat(lson, L, mid);
	Creat(rson, mid + 1, R);
	Push_up(x);
}

void Update(int x, int pos, ll val){     
	
	int L = tree[x].l, R = tree[x].r; 
    if(L == R && L == pos) {
	    tree[x].sum = val;
		return; 
	}                                          
    int mid = (L + R) >> 1;
    if(pos <= mid) Update(lson, pos, val);
    if(pos > mid)  Update(rson, pos, val);
    Push_up(x);
}

ll Query(int x, int l, int r){             
	int L = tree[x].l, R = tree[x].r;
    if(l <= L && r >= R) {
	    return tree[x].sum;
	}                                    
    int mid = (L + R) >> 1;
	ll ans = 0;
    if(l <= mid) ans += Query(lson, l, r);
    if(r >= mid+1) ans += Query(rson, l , r);
	return ans;
}


int main(){
	int t; scanf("%d", &t);
	while(t--){
		m.clear(); 
		cin >> n;
		for(int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
		}
		Creat(1, 1, n);
		int k; cin >> k;
		for(int i = 1; i <= k; i++){
			scanf("%d%d", &c[i].l, &c[i].r);
			c[i].ci = i;
		}
		sort(c + 1, c + k + 1, cmp);
		int j = 1;
		for(int i = 1; i <= k; i++){
			for(; j <= c[i].r; j++){
				if(m[a[j]] != 0) Update(1,m[a[j]],0);
					if(m[a[j]] == j) Update(1, j, a[j]);
					m[a[j]] = j;    //上一次下标
			}
			ans[c[i].ci] = Query(1, c[i].l, c[i].r);
		}
		for(int i = 1; i <=k ;i++){
			printf("%lld\n", ans[i]);
		}
	}
	return 0;
}