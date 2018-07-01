/* 
逆序数求得之后，把第一个数移到最后的逆序数是可以直接得到的。
比如原来的逆序数是ans,把a[0]移到最后后，减少逆序数a[0]，同时增加逆序数n-a[0]-1个
就是ans-a[0]+n-a[0]-1; 
类似树状数组的区间加权与求和 
*/ 
/*
线段树对逆序对的算法中， 初始化所有节点为0， 利用时效性， 每次算出比其大的个数， 
往后区间标记自己的存在，并维护线段树，统计区间内的元素个数即可  63 64 行 
*/
/*
 树的创建利用一维数组，也可以利用结构体做节点（可以少写参数） 
*/ 

//结构体树的构造 

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
    if(l <= mid) Sum(lson, l, r);   //往左走 
    if(r >= mid + 1) Sum(rson, l, r);  // 往右走 
}

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++)
		    scanf("%d", &a[i]);
        creat(1, 0, n-1);
        ans = 0;
        for(int i = 0; i < n; i++){
        	Sum(1, a[i], n-1);   //i之前比a[i]大的数 
        	add(1, a[i], 1);     //记录当前节点覆盖区间 
        /*	for(int j = 0; j < 3*n; j++){
	        	printf("%d ", tree[j].sum);
	        }
	        printf("\n");  */
        } 
       // cout << ans <<endl;
        int minn = ans;
        for(int i = 0; i < n; i++){
        	ans += n - a[i] - 1 - a[i];
        	minn = min(ans, minn);
        }
        printf("%d\n", minn);
	}
	return 0;
}