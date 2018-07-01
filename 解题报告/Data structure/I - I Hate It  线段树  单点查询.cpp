// 线段树  单点更新 hdu 1754 

#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200000 + 5;
int tree[MAXN << 2];   //树是原区间四倍长 
int n, m;
int a[MAXN];
int ans;

void creat(int x, int l, int r){       //建树 
    if(l > r) return;
    if(l == r) { tree[x] = a[l];  return;}
    int mid = (l+ r)/ 2;
    creat(x << 1, l, mid);
    creat( (x << 1) + 1, mid + 1, r);
    cout << tree[x << 1] <<"  " << tree[(x << 1) + 1] << endl;
    tree[x] = max(tree[x << 1], tree[(x << 1) + 1]);
}

void Query(int x, int L, int R, int l, int r){
    if(l <= L && r >= R) {ans = max(ans, tree[x]); return ;}  //注意时大于等于关系  l r 不变 
    int mid = (L+R)/2;
    int a = 0, b = 0;
    if(l <= mid) Query(x << 1, L, mid, l, r);
    if(r >= mid+1) Query( (x << 1) + 1, mid + 1, R, l , r);
}

void Update(int x, int L, int R, int pos, int val){
    if(L == R && L == pos) {tree[x] = val; return; }    // 端点更新 
    int mid = (L + R) / 2;
 //   cout << L << "  " <<mid << " " << R << endl;
    if(pos <= mid) Update(x << 1, L, mid, pos, val);
    if(pos > mid)  Update((x << 1) + 1, mid + 1, R, pos, val);
  //  cout << tree[x << 1] <<"  " << tree[(x << 1) + 1] << endl;
    tree[x] = max(tree[x << 1], tree[(x << 1) + 1]);
}

int main(){
    while(cin >> n >> m){
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        creat(1, 1, n);
 /*       
   for(int i = 1; i <= n*4; i++)
        printf("%d ", tree[i]);
   cout <<endl;
*/
        while(m --){
        	ans = 0;
            char o; scanf("%s", &o);
            if(o == 'Q') {
                int A, B; scanf("%d %d", &A, &B);
				Query(1, 1, n, A, B);
                cout << ans <<endl;
            }
            if(o == 'U'){
                int p, v; scanf("%d %d", &p, &v);
                Update(1, 1, n, p, v);
            }
        }
    }
    return 0;
}
