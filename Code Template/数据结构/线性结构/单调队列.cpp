//顺序给出柱状图的长  高
//求最大矩形面积
//算当前高度左右最远扩大范围即可
#pragma GCC optimize(3,"Ofast","inline")  //优化  无限精度
#include <bits/stdc++.h>
#define pb push_back
#define Rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=0x3f3f3f3f;
const ll INF=9e18;
const int N=1e6+50;
ll a[N],h[N],l[N],r[N];
int top=0;
int s[N];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
    for(int i=1;i<=n;i++) {
        while(top>0&&h[s[top]]>=h[i]) top--;
        if(top==0) l[i]=0;
        else l[i]=s[top];
        s[++top]=i;
    }
    top=0;
    for(int i=n;i>=1;i--) {
        while(top>0&&h[s[top]]>=h[i]) top--;
        if(top==0) r[i]=n;
        else r[i]=s[top]-1;
        s[++top]=i;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,h[i]*(a[r[i]]-a[l[i]]));
    printf("%lld\n",ans);
    return 0;
}
