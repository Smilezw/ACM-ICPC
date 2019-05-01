//筛半素数

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
const int N=1e5+5;
ll l,r,s[N],tot;vector<ll>vec[N];
int main(){
    scanf("%lld%lld",&l,&r);
    for(ll i=l;i<=r;++i)s[i-l]=i;
    for(ll i=2;i*i<=r;++i)
        for(ll j=(l+i-1)/i*i;j<=r;j+=i)
            while(s[j-l]%i==0)vec[j-l].push_back(i),s[j-l]/=i;
    for(ll i=0;i<=r-l;++i){
        if(s[i]>1)vec[i].push_back(s[i]);sort(vec[i].begin(),vec[i].end());
        if(vec[i].size()==2)++tot;
    }
    printf("%lld\n",tot);
    for(ll i=0;i<=r-l;++i)if(vec[i].size()==2)printf("%lld %lld %lld\n",i+l,vec[i][0],vec[i][1]);
    return 0;
}
