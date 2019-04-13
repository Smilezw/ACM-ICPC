#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9;
int n,m,k;
int G[10][10];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
ll a[107][107];
int check(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m)    return 0;
    return G[x][y];
}
ll det()
{
    if(k==0)    return 0;
    ll res=1;
    for(int i=1;i<k;i++)
    {
        for(int j=i+1;j<k;j++)
        {
            while(a[j][i])
            {
                ll t=a[i][i]/a[j][i];
                for(int p=i;p<k;p++)
                {
                    a[i][p]=(a[i][p]-t*a[j][p]%mod+mod)%mod;
                    swap(a[i][p],a[j][p]);
                }
                res=-res;
            }
        }
        if(!a[i][i])    return 0;
        res=res*a[i][i]%mod;
    }
    return (res+mod)%mod;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>n>>m)
    {
        k=0;
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            for(int j=0;j<m;j++)
                if(s[j]=='.')   G[i][j]=++k;
                else G[i][j]=0;
        }
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int u=G[i][j];
                if(u)
                {
                    for(int k=0;k<4;k++)
                    {
                        int v=check(i+dir[k][0],j+dir[k][1]);
                        if(v)   a[u][v]=a[v][u]=-1,a[u][u]++;
                    }
                }
            }
        }
        cout<<det()<<endl;
    }
    return 0;
}
