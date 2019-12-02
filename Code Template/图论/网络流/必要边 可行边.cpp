//P4126

#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define re register
#define LL long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
const int maxn=4e3+5;
const int inf=1e9;
inline int read() {
    char c=getchar();int x=0;while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-48,c=getchar();return x;
}
std::queue<int> q;
struct E{int v,nxt,f;}e[150000];
int n,m,S,T,cnt,top,p,mid,num=1;
int dfn[maxn],low[maxn],st[maxn],f[maxn];
int head[maxn],d[maxn],cur[maxn],col[maxn];
inline void C(int x,int y,int f) {
    e[++num].v=y;e[num].nxt=head[x];
    head[x]=num;e[num].f=f;
}
int X[60005],Y[60005],id[60005];
inline void add(int x,int y,int f) {C(x,y,f),C(y,x,0);}
inline int BFS() {
    for(re int i=1;i<=n;i++) d[i]=0,cur[i]=head[i];
    d[S]=1,q.push(S);
    while(!q.empty()) {
        int k=q.front();q.pop();
        for(re int i=head[k];i;i=e[i].nxt)
        if(!d[e[i].v]&&e[i].f) d[e[i].v]=d[k]+1,q.push(e[i].v);
    }
    return d[T];
}
int dfs(int x,int now) {
    if(x==T||!now) return now;
    int flow=0,ff;
    for(re int& i=cur[x];i;i=e[i].nxt)
    if(d[e[i].v]==d[x]+1) {
        ff=dfs(e[i].v,min(e[i].f,now));
        if(now<=0) continue;
        now-=ff,flow+=ff,e[i].f-=ff,e[i^1].f+=ff;
        if(!now) break;
    }
    return flow;
}
void tarjan(int x) {
    dfn[x]=low[x]=++cnt;
    st[++top]=x;f[x]=1;
    for(re int i=head[x];i;i=e[i].nxt) {
        if(!e[i].f) continue;
        if(!dfn[e[i].v]) tarjan(e[i].v),low[x]=min(low[x],low[e[i].v]);
        else if(f[e[i].v]) low[x]=min(low[x],dfn[e[i].v]);
    }
    if(dfn[x]==low[x]) {
        ++p;
        do {
            mid=st[top--];
            f[mid]=0;
            col[mid]=p;
        }while(x!=mid);
    }
}
int main() {
    n=read(),m=read();S=read(),T=read();
    for(re int z,i=1;i<=m;i++) {
        X[i]=read(),Y[i]=read();
        z=read();id[i]=num+1;add(X[i],Y[i],z);
    }
    while(BFS()) dfs(S,inf);
    for(re int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    for(re int i=1;i<=m;i++) {
        if(col[X[i]]!=col[Y[i]]&&!e[id[i]].f) putchar('1');
            else putchar('0');
        putchar(' ');
        if(!e[id[i]].f&&col[X[i]]==col[S]&&col[Y[i]]==col[T]) putchar('1');
            else putchar('0');
        putchar(10);
    }
    return 0;
}
