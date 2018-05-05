// 线段树模版 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define lson x << 1
#define rson x << 1 + 1

const int MANX = 100000 + 5;
struct Node{
	int sum;
	int l ,r;
}segtree[MAXN << 2];
int lazy[MAXN << 2];   //置 -1 
int a[MAXN];

void Push_up(int x){
	segtree[x].sum = segtree[lson].sum + segtree[rson].rson;
}

void Push_down(int x, int l, int r){
	if(lazy[x] > 0){
		lazy[lson] = lazy[rson] = lazy[x];
		lazy[x] = -1;
		int mid = (l + r) >> 1;
		segtree[lson] = (mid - l + 1)* lazy[lson];
		segtree[rson] = (r - mid)* lazy[rson];
	}
}

void Creat(int x, int l, int r){
	segtree[x].l = l;  segtree[x].r = r;
	if(l == r) return;
	int mid = (l + r) >> 1;
	creat(lson, l, mid);
	creat(rson, mid +1, r);
	//Push_up(int x);
}

void Update_one(int x, int pos, int val){
	int L = segtree[x].l, R = segtree[x].r; 
    if(L == R && L == pos) {
	    tree[x] = val; 
		return; 
	}                                            // 端点更新 
    int mid = (L + R) / 2;
    if(pos <= mid) Update_one(lson, pos, val);
    if(pos > mid)  Update_one(rson, pos, val);
}

void Update_seg(int x, int l, int r, int val){
	int L = segtree[x].l, R = segtree[x].r;
	  if(L >= l && r <= R) {              //找到区间并标记 
		lazy[x] = val;
		return; 
    }                                    // 区间更新
	//Push_down(x, L, R);                //延时操作 
    int mid = (L + R) / 2;
    if(l <= mid) Update_seg(lson, l, r, val);
    if(l > mid)  Update_seg(rson, l, r, val);
    //Push_up(x);
}

void Query(int x, int l, int r){
	int L = segtree[x].l, R = segtree[x].r;
    if(l <= L && r >= R) {
    	
	    return ;
	}                                     //找到区间或子区间 
    int mid = (L + R) >> 1;
    if(l <= mid) Query(lson, l, r);
    if(r >= mid+1) Query(rson, l , r);
}

int main(){
	memset(lazy, -1, sizeof(lazy));
	
	return 0;
}