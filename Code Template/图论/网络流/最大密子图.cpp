// 边数/点数   最大的子图
// 对于带权图  重定义权值矩阵 为 d(u) = sum{w(u, v) }  无向图
//  足够大的U 为边权和  容量替换为w{u, v} 估值函数不变
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define V G[p].v
#define eps 1e-5
#define cl(x) memset(x,0,sizeof(x))
using namespace std;

inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}

inline void read(int &x){
    char c=nc(),b=1;
    for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
    for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
}

inline int dcmp(double a,double b){
    if (fabs(a-b)<eps) return 0;
    if (a<b) return -1; return 1;
}

namespace DINIC{
    const int N=1005;
    const int M=10005;
    struct edge{
        int u,v; double f;
        int next;
    }G[M];
    int head[N],inum=1;
    inline void add(int u,int v,double f,int p){
        G[p].u=u; G[p].v=v; G[p].f=f; G[p].next=head[u]; head[u]=p;
    }
    inline void link(int u,int v,double f){
        add(u,v,f,++inum); add(v,u,0,++inum);
    }
    int S,T;
    int dis[N];
    int Q[N],l,r;
    inline bool bfs(){
        memset(dis,-1,sizeof(dis)); l=r=-1;
        Q[++r]=S; dis[S]=1;
        while (l<r){
            int u=Q[++l];
            for (int p=head[u];p;p=G[p].next)
                if (dcmp(G[p].f,0)>0 && dis[V]==-1){
                    dis[V]=dis[u]+1; Q[++r]=V;
                    if (V==T) return 1;
                }
        }
        return 0;
    }
    int cur[N];
    double dfs(int u,double flow){
        if (u==T) return flow;
        double used=0,now;
        for (int p=cur[u];p;p=G[p].next)
        {
            cur[u]=p;
            if (dcmp(G[p].f,0)>0 && dis[V]==dis[u]+1)
            {
                now=dfs(V,min(flow-used,G[p].f));
                G[p].f-=now,G[p^1].f+=now;
                used+=now; if (dcmp(flow,used)==0) break;
            }
        }
        if (dcmp(used,0)==0) dis[u]=-1;
        return used;
    }
    double Dinic(){
        double ret=0;
        while (bfs())
            memcpy(cur,head,sizeof(cur)),ret+=dfs(S,1e40);
        return ret;
    }
    void clear(){
        cl(head); inum=1;
    }
    int tot;
    int vst[N];
    void dfs(int u){    //统计子图的一部分即可
        vst[u]=1; tot++;
        for (int p=head[u];p;p=G[p].next)
            if (dcmp(G[p].f,0)>0 && !vst[V])
                dfs(V);
    }
    inline int getans(){
        tot=-1; dfs(S);
        return tot;
    }
}

int u[1005],v[1005],deg[1005];
int n,m;

inline bool check(double mid)
{
    using namespace DINIC;
    double U=m;
    clear(); S=n+1; T=n+2;
    for (int i=1;i<=m;i++) link(u[i],v[i],1),link(v[i],u[i],1);   //建边方式
    for (int i=1;i<=n;i++) link(S,i,U);
    for (int i=1;i<=n;i++) link(i,T,U+2*mid-deg[i]);
    double ret=Dinic();
    return dcmp( (U*n-ret)/2.0,0)>0;          //估值函数  h(g) = (u*n - ret)/2
}

inline void Solve()
{
    using namespace DINIC;
    double L=0,R=m,MID;
    while (R-L>=1.0/n/n)
        if (check(MID=(L+R)/2))
            L=MID;
        else
            R=MID;
    check(L);
    int ans=getans();
    printf("%d\n",ans);
}

int main()
{
    read(n); read(m);
    if (!m) return printf("1\n"),0;
    for (int i=1;i<=m;i++)
        read(u[i]),read(v[i]),deg[u[i]]++,deg[v[i]]++;
    Solve();
    return 0;
}
