//用于任意两点间最小割的种类数  及大小
//原图最小割   --   分为两个子图  --  最小割  ---  继续分治
//   GHtree

#include<bits/stdc++.h>
#define eps 1e-8
#define inf 1000000000
#define pa pair<int,int>
#define ll long long
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int tes,S,T;
int n,m,Q,cnt;
int a[155],tmp[155],last[155],h[155],q[155];
int ans[155][155];
bool mark[155];
struct edge{
	int to,next,v;
}e[100005];
void insert(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
}
bool bfs()
{
	int head=0,tail=1;
	memset(h,-1,sizeof(h));
	h[S]=0;q[0]=S;
	while(head!=tail)
	{
		int now=q[head];head++;
		for(int i=last[now];i;i=e[i].next)
			if(h[e[i].to]==-1&&e[i].v)
			{
				h[e[i].to]=h[now]+1;
				q[tail++]=e[i].to;
			}
	}
	return h[T]!=-1;
}
int dfs(int x,int f)
{
	if(x==T)return f;
	int w,used=0;
	for(int i=last[x];i;i=e[i].next)
		if(h[e[i].to]==h[x]+1)
		{
			w=dfs(e[i].to,min(e[i].v,f-used));
			e[i].v-=w;e[i^1].v+=w;
			used+=w;
			if(used==f)return f;
		}
	if(used==0)h[x]=-1;
	return used;
}
void dfs(int x)
{
	mark[x]=1;
	for(int i=last[x];i;i=e[i].next)
		if(e[i].v&&!mark[e[i].to])
			dfs(e[i].to);
}
int dinic()
{
	int ans=0;
	while(bfs())ans+=dfs(S,inf);
	return ans;
}
void restore()
{
	for(int i=2;i<=cnt;i+=2)
		e[i].v=e[i^1].v=(e[i].v+e[i^1].v)/2;
}
void solve(int l,int r)
{
	if(l==r)return;
	restore();S=a[l];T=a[r];
	int t=0;
	while(bfs())t+=dfs(S,inf);
    memset(mark,0,sizeof(mark));
	dfs(S);
	for(int i=1;i<=n;i++)
		if(mark[i])
			for(int j=1;j<=n;j++)
				if(!mark[j])
					ans[i][j]=ans[j][i]=min(ans[i][j],t);
	int L=l,R=r;
	for(int i=l;i<=r;i++)
		if(mark[a[i]])
			tmp[L++]=a[i];
		else tmp[R--]=a[i];
	for(int i=l;i<=r;i++)a[i]=tmp[i];
	solve(l,L-1);solve(R+1,r);
}
int main()
{
	tes=read();
	while(tes--)
	{
		cnt=1;
		memset(ans,127,sizeof(ans));
		memset(last,0,sizeof(last));
		n=read();m=read();
		for(int i=1;i<=n;i++)a[i]=i;
		for(int i=1;i<=m;i++)
		{
			int u=read(),v=read(),c=read();
			insert(u,v,c);
			insert(v,u,c);
		}
		solve(1,n);
		Q=read();
		while(Q--)
		{
			int c=read(),tot=0;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(ans[i][j]<=c)tot++;
			printf("%d\n",tot);
		}
		puts("");
	}
	return 0;
}
