#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
#define ls i<<1
#define rs ls | 1
#define mid ((ll+rr)>>1)
#define pii pair<int,int>
#define MP make_pair
typedef long long LL;
typedef unsigned long long ULL;
const long long INF = 1e18+1LL;
const double pi = acos(-1.0);
const int N = 3e5+20, M = 1e6+10, mod = 1e9+7,inf = 2e9;


struct Complex {
    double r , i ;
    Complex () {}
    Complex ( double r , double i ) : r ( r ) , i ( i ) {}
    Complex operator + ( const Complex& t ) const {
        return Complex ( r + t.r , i + t.i ) ;
    }
    Complex operator - ( const Complex& t ) const {
        return Complex ( r - t.r , i - t.i ) ;
    }
    Complex operator * ( const Complex& t ) const {
        return Complex ( r * t.r - i * t.i , r * t.i + i * t.r ) ;
    }
} ;

void FFT ( Complex y[] , int n , int rev ) {
    for ( int i = 1 , j , t , k ; i < n ; ++ i ) {
        for ( j = 0 , t = i , k = n >> 1 ; k ; k >>= 1 , t >>= 1 ) j = j << 1 | t & 1 ;
        if ( i < j ) swap ( y[i] , y[j] ) ;
    }
    for ( int s = 2 , ds = 1 ; s <= n ; ds = s , s <<= 1 ) {
        Complex wn = Complex ( cos ( rev * 2 * pi / s ) , sin ( rev * 2 * pi / s ) ) , w ( 1 , 0 ) , t ;
        for ( int k = 0 ; k < ds ; ++ k , w = w * wn ) {
            for ( int i = k ; i < n ; i += s ) {
                y[i + ds] = y[i] - ( t = w * y[i + ds] ) ;
                y[i] = y[i] + t ;
            }
        }
    }
    if ( rev == -1 ) for ( int i = 0 ; i < n ; ++ i ) y[i].r /= n ;
}
Complex s[N],t[N];

int vis[N],f[N],siz[N],n,allnode,root;
int P[N];
vector<int > G[N];
void init() {
    for(int i = 2; i <= 2*n; ++i) {
        if(!P[i]) {
            for(int j = i+i; j <= 2*n; j += i)
                P[j] = 1;
        }
    }
    P[1] = 1;
    for(int i = 1; i <= n; ++i) vis[i] = 0;
}
void getroot(int u,int fa) {
        f[u] = 0;
        siz[u] =  1;
        for(int i = 0; i < G[u].size(); ++i) {
            int to = G[u][i];
            if(vis[to] || to == fa) continue;
            getroot(to,u);
            siz[u] += siz[to];
            f[u] = max(f[u],siz[to]);
        }
        f[u] = max(f[u], allnode - siz[u]);
        if(f[u] < f[root]) root = u;
}

int len = 1,cnt[N],dep[N],nowcnt[N],mxdep;
LL ans = 0;
void getdeep(int u,int f) {
    siz[u] = 1;
    for(int i = 0; i < G[u].size(); ++i) {
        int to = G[u][i];
        if(vis[to] || to == f) continue;
        dep[to] = dep[u] + 1;
        getdeep(to,u);
        mxdep = max(mxdep,dep[to]);
        siz[u] += siz[to];//每个节点的大小
    }
}
void dfs(int u,int f,int p) {
    nowcnt[dep[u]]+=p;
    if(p == -1) cnt[dep[u]] += 1;
    for(int i = 0; i < G[u].size(); ++i) {
        int to = G[u][i];
        if(vis[to] || to == f) continue;
        dfs(to,u,p);
    }
}
LL cal(int u) {
    LL ret = 0;
    for(int i = 0; i <= n; ++i) cnt[i] = 0;
    cnt[0] = 1;
    dep[u] = 0;
    mxdep = -1;
    getdeep(u,0);//每个节点的深度
    len = 1;
    while(len <= 2*mxdep) len<<=1;
    for(int i = 0; i < G[u].size(); ++i) {
        int to = G[u][i];
        if(vis[to]) continue;//后面走前面来枚举
        dfs(to,u,1);
        for(int j = 0; j < len; ++j) t[j] = Complex(nowcnt[j],0);
        for(int j = 0; j < len; ++j) s[j] = Complex(cnt[j],0);

        FFT(s,len,1);FFT(t,len,1);
        for(int j = 0; j < len; ++j) s[j] = s[j] * t[j];
        FFT(s,len,-1);
        for(int j = 0;j < len; ++j) {
            LL tmp = (s[j].r+0.5);

            if(P[j]) continue;

            ret += tmp;
        }
        dfs(to,u,-1);
    }
    return ret;
}
void work(int u) {
    vis[u] = 1;
    ans += cal(u);
   // exit(0);
    for(int i = 0; i < G[u].size(); ++i) {
        int to = G[u][i];
        if(vis[to]) continue;
        allnode = siz[to];
        root = 0;
        getroot(to,0);
        work(root);
    }
}
int main() {
    scanf("%d",&n);
    while(len <= n) len<<=1;
    init();//素数筛。。

    for(int i = 1; i < n; ++i) {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    ans = 0;
    f[0] = inf;root = 0;allnode = n;
    getroot(1,0);
    work(root);
    printf("%.6f\n",(double)1.0*ans/((double)n*(n-1)/2));
    return 0;
}
