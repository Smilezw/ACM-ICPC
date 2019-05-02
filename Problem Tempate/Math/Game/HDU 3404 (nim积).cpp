#include<iostream>
#include<cstdio>
using namespace std;

int m[2][2]={0,0,0,1};
int Nim_Multi_Power(int x,int y)
{
    if(x<2)
        return m[x][y];
    int a=0;
    for(;;a++)
        if(x>=(1<<(1<<a))&&x<(1<<(1<<(a+1))))
            break;
    int m=1<<(1<<a);
    int p=x/m,s=y/m,t=y%m;
    int d1=Nim_Multi_Power(p,s);
    int d2=Nim_Multi_Power(p,t);
    return (m*(d1^d2))^Nim_Multi_Power(m/2,d1);
}

int Nim_Multi(int x,int y)
{
    if(x<y)
        return Nim_Multi(y,x);
    if(x<2)
        return m[x][y];
    int a=0;
    for(;;a++)
        if(x>=(1<<(1<<a))&&x<(1<<(1<<(a+1))))
            break;
    int  m=1<<(1<<a);
    int p=x/m,q=x%m,s=y/m,t=y%m;
    int c1=Nim_Multi(p,s);
    int c2=Nim_Multi(p,t)^Nim_Multi(q,s);
    int c3=Nim_Multi(q,t);
    return (m*(c1^c2))^c3^Nim_Multi_Power(m/2,c1);
}

int main()
{
    int t,n,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int res=0;
        while(n--)
        {
            scanf("%d%d",&x,&y);
            res^=Nim_Multi(x,y);
        }
        if(res)
            printf("Have a try, lxhgww.\n");
        else printf("Don't waste your time.\n");
    }
    return 0;
}
