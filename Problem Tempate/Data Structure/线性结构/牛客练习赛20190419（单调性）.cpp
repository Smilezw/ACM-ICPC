/*
给出n条线段，第i条线段的长度为a_i，
每次可以从第i条线段的j位置跳到第i + 1条线段的j+1位置。
如果第i+1条线段长度不到j+1，
那么就会回到第i条线段的0位置，然后继续跳。

20190419
*/

#include<algorithm>
#include<cstdio>
#define mxn 20000010
using namespace std;
int n,M,s,x,sl,fh,a[mxn];
long long ans;
int rd()
{
    sl=0;fh=1;
    char ch=getchar();
    while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
    while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
    return sl*fh;
}
unsigned int SA, SB, SC;
unsigned int Rand()
{
    SA^=SA<<16;
    SA^=SA>>5;
    SA^=SA<<1;
    unsigned int t=SA;
    SA=SB;SB=SC;SC^=t^SA;
    return SC;
}
int main()
{
    n=rd();M=rd();SA=rd();SB=rd();SC=rd();
    for(int i=1;i<=n;++i) a[i]=Rand()%M+1;
    x=a[n];
    for(int i=n-1;i;--i)  //最后一个区间往回走即可  类似单调队列
    {
        s++;x--;
        ans+=s;
        if(x>a[i]) x=a[i];
        if(!x) s++,x=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}
