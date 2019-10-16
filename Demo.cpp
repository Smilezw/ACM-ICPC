#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int maxn=3e6+10;
#define Rep(i,a,b) for(register int i=a;i<=b;i++)
int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    Rep(i,1,n)
    {
        cout << "i  " << i << endl;
        int temp=i;
        int sup=n/i;
        for(register int j=1;j<=sup;j++)
        {
            int l=i*j,r=min((i+1)*j-1,n);

            ans=(ans+((1LL*(l+r)*(r-l+1))>>1)%mod*temp)%mod;
            cout << l << " " << r << " " << temp << " " << ((1LL*(l+r)*(r-l+1))>>1)%mod*temp << endl;
            temp=1LL*temp*i%mod;
        }
    }
    printf("%d\n",ans);
    return 0;
}
