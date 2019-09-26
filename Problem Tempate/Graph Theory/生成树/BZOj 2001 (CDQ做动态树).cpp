#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long
#define MAX 50050
#define inf 1e9
inline int read()
{
    int x=0;bool t=false;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=true,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return t?-x:x;
}

struct Line {int u,v,w,id;} E[MAX],St[MAX],e[30][MAX],tmp[MAX];

bool operator<(Line a,Line b){return a.w<b.w;}

struct Query{int x,w;}q[MAX];

int n,m,Q;ll ans[MAX];
int f[MAX],c[MAX],cnt;
int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}
void init(int x)
{
    for(int i=1;i<=x;++i)f[tmp[i].u]=tmp[i].u;
    for(int i=1;i<=x;++i)f[tmp[i].v]=tmp[i].v;
}

int W[MAX],size[50];
void Contraction(int &z,ll &Ans)
{
    init(z);sort(&tmp[1],&tmp[z+1]);int top=0;
    for(int i=1;i<=z;++i)
        if(getf(tmp[i].u)!=getf(tmp[i].v))
            f[getf(tmp[i].u)]=getf(tmp[i].v),St[++top]=tmp[i];
    for(int i=1;i<=top;++i)f[St[i].u]=St[i].u,f[St[i].v]=St[i].v;
    for(int i=1;i<=top;++i)//Get the edge must be used
        if(St[i].w>-inf)
            f[getf(St[i].u)]=getf(St[i].v),Ans+=St[i].w;
    top=0;
    for(int i=1;i<=z;++i)
        if(getf(tmp[i].u)!=getf(tmp[i].v))//Get the edge may be used
        {
            St[++top]=tmp[i];
            c[tmp[i].id]=top;
            St[top].u=getf(tmp[i].u);
            St[top].v=getf(tmp[i].v);
        }
    z=top;for(int i=1;i<=top;++i)tmp[i]=St[i];
}
void Reduction(int &z)
{
    init(z);sort(&tmp[1],&tmp[z+1]);int top=0;
    for(int i=1;i<=z;++i)//Delete the edge will
        if(getf(tmp[i].u)!=getf(tmp[i].v))
            f[getf(tmp[i].u)]=getf(tmp[i].v),St[++top]=tmp[i],c[tmp[i].id]=top;
        else if(tmp[i].w>=inf)St[++top]=tmp[i],c[tmp[i].id]=top;
    z=top;for(int i=1;i<=top;++i)tmp[i]=St[i];
}
void CDQ(int l,int r,int dep,ll Ans)
{
    if(l==r)W[q[l].x]=q[l].w;//modify
    int z=size[dep],mid=(l+r)>>1;        //Õº¥Û–°
    for(int i=1;i<=z;++i)e[dep][i].w=W[e[dep][i].id];
    for(int i=1;i<=z;++i)tmp[i]=e[dep][i],c[tmp[i].id]=i;
    if(l==r)//Get MST
    {
        init(z);sort(&tmp[1],&tmp[z+1]);
        for(int i=1;i<=z;++i)
            if(getf(tmp[i].u)!=getf(tmp[i].v))
                f[getf(tmp[i].u)]=getf(tmp[i].v),Ans+=tmp[i].w;
        ans[l]=Ans;return;
    }
    for(int i=l;i<=r;++i)tmp[c[q[i].x]].w=-inf;
    Contraction(z,Ans);
    for(int i=l;i<=r;++i)tmp[c[q[i].x]].w=+inf;
    Reduction(z);
    for(int i=1;i<=z;++i)e[dep+1][i]=tmp[i];size[dep+1]=z;
    CDQ(l,mid,dep+1,Ans);CDQ(mid+1,r,dep+1,Ans);
}
int main()
{
    n=read();m=read();Q=read();
    for(int i=1;i<=m;++i)E[i].u=read(),E[i].v=read(),E[i].w=read(),E[i].id=i;
    for(int i=1;i<=Q;++i)q[i].x=read(),q[i].w=read();
    for(int i=1;i<=m;++i)W[i]=E[i].w;
    for(int i=1;i<=m;++i)e[0][i]=E[i];
    size[0]=m;CDQ(1,Q,0,0);
    for(int i=1;i<=Q;++i)printf("%lld\n",ans[i]);
    return 0;
}
