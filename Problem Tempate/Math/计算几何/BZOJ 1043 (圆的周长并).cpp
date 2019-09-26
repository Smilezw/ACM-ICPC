//圆弧度的一种解法
//每个弧度都加2pi 变为正值  最后角度取负数  第一个角度多加了2pi 就是加上了最后转到0的位置
//枚举每个圆被覆盖的弧度求解
#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
const int N = 1e3 + 5;
double x[N], y[N], r[N];

struct line{double l,r;} q[1005];
bool operator<(line a,line b) {
	return a.l<b.l;
}

double dis(int a, int b) {
    return sqrt((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]));
}

double conta(int a, int b) {
    if(r[a] >= dis(a, b) + r[b]) return 1;
    return 0;
}

int top;
int n;

void inter(int a, int b) {
    double st, d, l, t;
    d = dis(a, b);
    t = (r[a]*r[a]-r[b]*r[b]+d*d)/(2*d);
    st = atan2( (x[b]-x[a]), (y[b]-y[a]));  //注意方向
    l = acos(t/r[a]);
    q[++top]=(line){(st-l),(st+l)};
}

double cal(int x) {
    for(int i = x+1; i < n; i++) if(conta(i, x)) return 0;
    top = 0;
    for(int i = x+1; i < n; i++) {
        if(!conta(x, i) && r[x]+r[i] >= dis(x, i) ) inter(x, i);
    }
    double tmp=0,now=0;
	for(int i=1;i<=top;i++)
	{
		if(q[i].l<0)q[i].l+=2*pi;
		if(q[i].r<0)q[i].r+=2*pi;
		if(q[i].l>q[i].r)
		{
			q[++top]=(line){0,q[i].r};
			q[i].r=2*pi;
		}
	}
    sort(q+1,q+top+1);
	for(int i=1;i<=top;i++)
		if(q[i].l>now)
		{
			tmp+=q[i].l-now;
			now=q[i].r;
		}
		else now=max(now,q[i].r);
    tmp+=2*pi-now;
    return r[x]*tmp;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> r[i] >> x[i] >> y[i];
    double ans = 0;
    for(int i = 0; i < n; i++)
        ans += cal(i);
    printf("%.3lf\n", ans);
    return 0;
}
