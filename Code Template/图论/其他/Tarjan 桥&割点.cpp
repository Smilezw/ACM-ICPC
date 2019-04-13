#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 201
using namespace std;
vector <int> G[N];
int n,m,low[N],dfn[N];
bool is_cut[N];
int father[N];
int tim=0;
void input()
{
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);/*邻接表储存无向边*/
        G[b].push_back(a);
    }
}
void Tarjan(int i,int Father)
{
    father[i]=Father;/*记录每一个点的父亲*/
    dfn[i]=low[i]=tim++;
    for(int j=0;j<G[i].size();++j)
    {
        int k=G[i][j];
        if(dfn[k]==-1)
        {
            Tarjan(k,i);
            low[i]=min(low[i],low[k]);
        }
        else if(Father!=k)/*假如k是i的父亲的话，那么这就是无向边中的重边，有重边那么一定不是桥*/
            low[i]=min(low[i],dfn[k]);//dfn[k]可能！=low[k]，所以不能用low[k]代替dfn[k],否则会上翻过头了。
    }
}
void count()
{
    int rootson=0;
    Tarjan(1,0);
    for(int i=2;i<=n;++i)
    {
        int v=father[i];
        if(v==1)
        rootson++;/*统计根节点子树的个数，根节点的子树个数>=2,就是割点*/
        else{
            if(low[i]>=dfn[v])/*割点的条件*/
            is_cut[v]=true;
        }
    }
    if(rootson>1)
    is_cut[1]=true;
    for(int i=1;i<=n;++i)
    if(is_cut[i])
    printf("%d\n",i);
    for(int i=1;i<=n;++i)
    {
        int v=father[i];
        if(v>0&&low[i]>dfn[v])/*桥的条件*/
        printf("%d,%d\n",v,i);
    }

}
int main()
{
    input();
    memset(dfn,-1,sizeof(dfn));
    memset(father,0,sizeof(father));
    memset(low,-1,sizeof(low));
    memset(is_cut,false,sizeof(is_cut));
    count();
    return 0;
}
