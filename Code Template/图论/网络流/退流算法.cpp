//bzoj 3532

#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define re register
#define maxn 1505
#define LL long long
#define inf 999999999
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline int read()
{
    char c=getchar();int x=0;while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-48,c=getchar();return x;
}
struct node{int a,b,c,rk;}g[maxn];
inline int cmp(node A,node B) {return A.c<B.c;}
struct E{int v,nxt,w,f;}e[maxn*maxn];
int n,num=1,S,T,Test;
int ans[maxn],cnt,id[maxn],vis[maxn];
int d[maxn],dp[maxn],head[maxn],cur[maxn],in[maxn],out[maxn];
inline void add(int x,int y,int z) {e[++num].v=y;e[num].nxt=head[x];head[x]=num;e[num].w=z;}
inline void C(int x,int y,int z) {add(x,y,z),add(y,x,0);}
inline int check(int s,int t)
{
    std::queue<int> q;
    memset(vis,0,sizeof(vis));
    q.push(s);vis[s]=1;
    while(!q.empty())
    {
        int k=q.front();q.pop();
        if(k==t) return 1;
        for(re int i=head[k];i;i=e[i].nxt)
        if(!vis[e[i].v]&&e[i].w>e[i].f) q.push(e[i].v),vis[e[i].v]=1;
    }
    return 0;
}
inline int BFS(int s,int t)
{
    std::queue<int> q;
    memcpy(cur,head,sizeof(head));
    memset(d,0,sizeof(d));
    d[s]=1,q.push(s);
    while(!q.empty())
    {
        int k=q.front();q.pop();
        for(re int i=head[k];i;i=e[i].nxt)
        if(!d[e[i].v]&&e[i].w>e[i].f)
        {
            d[e[i].v]=d[k]+1;
            if(e[i].v==t) return 1;
            q.push(e[i].v);
        }
    }
    return d[t];
}
int dfs(int x,int now,int t)
{
    if(x==t||!now) return now;
    int flow=0,ff;
    for(re int& i=cur[x];i;i=e[i].nxt)
    if(d[e[i].v]==d[x]+1)
    {
        ff=dfs(e[i].v,min(now,e[i].w-e[i].f),t);
        if(ff<=0) continue;
        now-=ff,flow+=ff;
        e[i].f+=ff,e[i^1].f-=ff;
        if(!now) break;
    }
    return flow;
}
int main()
{
    Test=read();
    while(Test--)
    {
        n=read();cnt=0;num=1;memset(head,0,sizeof(head));
        for(re int i=1;i<=n;i++) g[i].a=read(),dp[i]=1;
        for(re int i=1;i<=n;i++) g[i].b=read(),g[i].rk=i;
        for(re int i=1;i<=n;i++)
            for(re int j=1;j<i;j++) if(g[j].a<g[i].a) dp[i]=max(dp[j]+1,dp[i]);
        int tot=0;
        for(re int i=1;i<=n;i++) tot=max(tot,dp[i]);
        T=0;
        for(re int i=1;i<=n;i++) in[i]=++T;
        for(re int i=1;i<=n;i++) out[i]=++T;++T;
        for(re int i=1;i<=n;i++) C(in[i],out[i],g[i].b),id[i]=num;
        for(re int i=1;i<=n;i++) if(dp[i]==1) C(S,in[i],inf);
        for(re int i=1;i<=n;i++) if(dp[i]==tot) C(out[i],T,inf);
        for(re int i=1;i<=n;i++)
            for(re int j=1;j<i;j++) if(g[j].a<g[i].a&&dp[j]+1==dp[i]) C(out[j],in[i],inf);
        tot=0;
        while(BFS(S,T))
            tot+=dfs(S,inf,T);
        for(re int i=1;i<=n;i++) g[i].c=read();
        printf("%d ",tot);
        std::sort(g+1,g+n+1,cmp);
        for(re int i=1;i<=n;i++)
        {
            int k=g[i].rk;
            if(check(in[k],out[k])) continue;
            ans[++cnt]=k;
            while(BFS(T,out[k])) dfs(T,inf,out[k]);
            while(BFS(in[k],S)) dfs(in[k],inf,S);
            e[id[k]].w=e[id[k]^1].w=0;
            e[id[k]].f=e[id[k]^1].f=0;
        }
        printf("%d\n",cnt);
        std::sort(ans+1,ans+cnt+1);
        for(re int i=1;i<=cnt;i++) printf("%d ",ans[i]);putchar(10);
    }
    return 0;
}
