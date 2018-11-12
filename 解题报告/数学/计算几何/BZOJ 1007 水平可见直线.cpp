//对三条直线进行讨论（类似半平面交）
//对应方程求出直线交点x的位置

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;
const double eps = 1e-8;

struct Line{
    int pos;
    double k, b;
}edge[MAXN];

bool cmp(const Line &a, const Line &b){
    if(fabs(a.k-b.k)<eps)return a.b < b.b;
    return a.k < b.k;
}


int top = 0;
Line s[MAXN];

double crossx(Line x1,Line x2){
    return (x2.b-x1.b)/(x1.k-x2.k);
}

void cut(Line x){
    while(top){
        if(fabs(s[top].k - x.k) < eps) top--;
		else if(top > 1 && crossx(x , s[top-1] ) <= crossx(s[top], s[top-1]))
			top--;
		else break;
    }
    s[++top] = x;
}
int ans[MAXN];
void solve(int n){
    for(int i = 1; i <= n; i++) cut(edge[i]);
    for(int i = 1; i <= top; i++) ans[i] = s[i].pos;
    sort(ans+1, ans+1+top);
    for(int i = 1; i <= top; i++) printf("%d ", ans[i]);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%lf %lf", &edge[i].k, &edge[i].b);
        edge[i].pos = i;
    }
    sort(edge+1, edge + n + 1, cmp);
    solve(n);
    return 0;
}
