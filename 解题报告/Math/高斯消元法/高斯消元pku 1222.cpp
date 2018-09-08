//构造30*1的灯矩阵
//5*6 * 5*6的开关矩阵 提议要求的开关影响放进去
// 解方程即可
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int a[35][35],x[35];
int equ,var;//方程数和变元数

void Debug()
{
    for(int i=0;i<equ;i++)
    {
        for(int j=0;j<=var;j++)
            printf("%d ",a[i][j]);
        puts("");
    }
    cout << endl;
}

void gauss()
{
    int max_r;
    for(int i=0;i<equ;i++)
    {
        max_r=i;
        for(int j=i+1;j<equ;j++)
        {
            if(a[j][i]>a[max_r][i]) max_r=j;
        }
        if(max_r!=i)
        {
            for(int k=0;k<=var;k++)
            {
                swap(a[i][k],a[max_r][k]);
            }
        }

        for(int j=0;j<equ;j++)
        if(i!=j&&a[j][i])
        {
            for(int k=i;k<=var;k++)
            a[j][k]=a[i][k]^a[j][k];
        }
    }

    //Debug();

    for(int i=equ-1;i>=0;i--)   //解方程了解一下

    {
        int temp=a[i][var];
        for(int j=i+1;j<var;j++)
        {
            temp-=a[i][j]*x[j];
        }
        x[i]=temp/a[i][i];
    }
}


void init()
{
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));
    for(int i=0;i<5;i++)
        for(int j=0;j<6;j++){
        if(i!=0) a[i*6+j][(i-1)*6+j]=1;
        if(i!=4) a[i*6+j][(i+1)*6+j]=1;
        if(j!=0) a[i*6+j][i*6+j-1]=1;
        if(j!=5) a[i*6+j][i*6+j+1]=1;
        a[i*6+j][i*6+j]=1;
    }
}
int main()
{
    int cas;
    equ=var=30;
    scanf("%d",&cas);
    for(int ca=1;ca<=cas;ca++)
    {
        init();

        for(int i=0;i<equ;i++)
        {
            scanf("%d",&a[i][var]);
        }
        // Debug();
        gauss();
        printf("PUZZLE #%d\n",ca);
        for(int i=0;i<equ;i++)
        {
            printf("%d",x[i]);
            if(i%6==5) puts("");
            else printf(" ");
        }
    }
    return 0;
}
