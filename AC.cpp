// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void out(int x) { if(x>9) out(x/10); putchar(x%10+'0');}
inline ll gi(){
    ll x=0,q=1; char ch=getchar(); while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
    if (ch=='-') q=-1,ch=getchar(); while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar(); return q*x;
}

const ll mod = 23333333;
const ll INF = 1e18;
const int M = 1e6 + 5;
const int N = 1e6 + 5;
/*
struct Edge{int to,next; int w;} edge[M];
int tot, head[N];
void init() {tot = 0;for(int i=0;i<=n;i+)head[i]=-1;}
void add(int u,int v,int w) {edge[tot].to=v, edge[tot].w=w, edge[tot].next=head[u], head[u]=tot++;}
*/

int main(){

    return 0;
}
