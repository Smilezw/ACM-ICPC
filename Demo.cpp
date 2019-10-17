// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void out(int x) { if(x>9) out(x/10); putchar(x%10+'0');}
inline ll gi(){
    ll x=0,q=1; char ch=getchar(); while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
    if (ch=='-') q=-1,ch=getchar(); while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar(); return q*x;
}

const ll mod = 1e9 + 7;
const ll INF = 1e18;
const int M = 1e6 + 5;
const int N = 5e3 + 5;

/*
struct Edge{int to,next; int w;} edge[M];
int tot, head[N];
void init() {tot = 0;for(int i=0;i<=n;i+)head[i]=-1;}
void add(int u,int v,int w) {edge[tot].to=v, edge[tot].w=w, edge[tot].next=head[u], head[u]=tot++;}
*/

struct p{ ll x, y, z; }p[N];
int vis[N], n;

ll len(int i, int j) {
    return (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y) + (p[i].z - p[j].z) * (p[i].z - p[j].z);
}

int main() {
    n = gi();
    for (int i = 1 ; i <= n ; ++i) {
        scanf ("%lld%lld%lld" , &p[i].x , &p[i].y , &p[i].z) ;
        p[i].x += 1e8 + 1 ;
        p[i].y += 1e8 + 1 ;
        p[i].z += 1e8 + 1 ;
    }
    for (int i = 1 ; i <= n; ++i) {
        if (vis[i]) continue;
        ll now = INF, g;
        for (int j = i + 1 ; j <= n ; ++j) {
            if (vis[j]) continue;
            if (len(i, j) < now){
                now =len(i, j);
                g = j ;
            }
        }
        cout << i << " " << g << endl;
        vis[i] = 1;
        vis[g] = 1;
    }
}
