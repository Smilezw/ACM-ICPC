// light oj 1008 - Fibsieve`s Fantabulous Birthday
// ¾ØÕóÊı×ÖÎ»ÖÃ 

#include <bits/stdc++.h>
using namespace std; 
int main()  
{  
    long long n;  
    long long cnt,x,y;  
    int t,k=1;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%lld",&n);  
        cnt=ceil(sqrt(n*1.0));  
        if(cnt*cnt-n<cnt)  
        {  
            x=cnt;  
            y=cnt*cnt-n+1;  
        }  
        else  
        {  
            y=cnt;  
            x=n-cnt*cnt+2*cnt-1;  
        }  
        if(cnt&1)  
        {  
            int num;  
            num=x;  
            x=y;  
            y=num;  
        }  
        printf("Case %d: %lld %lld\n",k++,x,y);  
    }  
    return 0;  
}  