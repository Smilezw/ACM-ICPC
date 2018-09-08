#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
#define lson x << 1
#define rson (x << 1) + 1

const int MAXN = 5000 + 5;
int a[MAXN];
int n, ans;
struct Node{
    int l,r;
    int sum;
}tree[MAXN*3];

void creat(int x, int l, int r){
	tree[x].l = l; tree[x].r = r;
	if(l == r) { tree[x].sum = 0; return; }
	 int mid=(l+r)>>1;
    creat(lson, l, mid);
    creat(rson, mid+1, r);
    tree[x].sum = 0;
   //  cout << tree[x].l << ' ' << tree[x].r << endl;
}

void add(int x,int pos, int val){
	tree[x].sum += val;
	if(tree[x].l == tree[x].r) return;
	int mid = (tree[x].l + tree[x].r) >> 1;
	if(mid >= pos) add(lson, pos, val);
	else add(rson, pos, val);
}

void Sum(int x, int l, int r){
    if(tree[x].l >= l && tree[x].r <= r) {
	    ans += tree[x].sum;
		return ;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
   // cout << tree[x].l << ' ' << tree[x].r << endl;
    if(l <= mid) Sum(lson, l, r);   //������
    if(r >= mid + 1) Sum(rson, l, r);  // ������
}

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++)
		    scanf("%d", &a[i]);
        creat(1, 0, n-1);
        ans = 0;
        for(int i = 0; i < n; i++){
        	Sum(1, a[i], n-1);
        	add(1, a[i], 1);
        int minn = ans;
        for(int i = 0; i < n; i++){
        	ans += n - a[i] - 1 - a[i];
        	minn = min(ans, minn);
        }
        printf("%d\n", minn);
	}
	return 0;
}
