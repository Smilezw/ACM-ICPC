#include <bits/stdc++.h>
using namespace std;
const int LMT = 1e9;
long long cnt = 0;
const int N = 1<<17;
const int MOD = N - 1;
int dig[N], a[N], T, k;
void solve(long long a, long long b, long long c)
{
    if(c > LMT) return;
    dig[ max(a, b)&MOD ] ++;
    long long aa = a<<1;
    long long bb = b<<1;
    long long cc = c<<1;
    solve(a-bb+cc, aa-b+cc, aa-bb+cc+c);
    //solve(a-(b<<1)+(c<<1), (a<<1)-b+(c<<1), (a<<1)-(b<<1)+(c<<1)+c);

    solve(a+bb+cc, aa+b+cc, aa+bb+cc+c);
    //solve(a+(b<<1)+(c<<1), (a<<1)+b+(c<<1), (a<<1)+(b<<1)+(c<<1)+c);

    solve(bb+cc-a, b+cc-aa, bb+cc+c-aa);
    //solve(-a+(b<<1)+(c<<1), -(a<<1)+b+(c<<1), -(a<<1)+(b<<1)+(c<<1)+c);
}
int main()
{
    solve(3, 4, 5);
    scanf("%d", &T);
    while(T-- && scanf("%d", &k)!=EOF)
    {
        int mod = (1<<k);
        for(int i=0;i<mod;i++)
            scanf("%d", &a[i]);
        long long ans = 0;
        for(int i=0, j=0;i<N;i++,j++)
        {
            if(j == mod)    j = 0;
            ans += dig[i] * a[j];
        }
        printf("%lld\n", ans);
    }
}
