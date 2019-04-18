//莫比乌斯函数前n项和
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include <tr1/unordered_map>
typedef long long ll;
using namespace std;
using namespace std::tr1;
const int MAXN=10000000;
int prime[1000000], num;
int vst[MAXN], miu[MAXN];
inline void Pre(){
    miu[1] = 1;
    for(int i = 2; i <= MAXN; i++){
        if(!vst[i]) prime[++num] = i, miu[i] = -1;
            for(int j = 1;j <= num && (ll)i*prime[j] <= MAXN; j++){
                vst[i*prime[j]]=1;
                if (i%prime[j]==0){
                    miu[i*prime[j]]=0;
                    break;
                }
                miu[i*prime[j]]=miu[i]*miu[prime[j]];
            }
    }
    for (int i=1;i<=MAXN;i++) miu[i]+=miu[i-1];
}
unordered_map<ll,int> S;

inline int Sum(ll n){
  if (n<=MAXN) return miu[n];
  if (S.find(n)!=S.end()) return S[n];
  int tem=1; ll l,r;
  for (l=2;l*l<=n;l++) tem-=Sum(n/l);  //这里的起点注意
  for (ll t=n/l;l<=n;l=r+1,t--){
    r=n/t;
    tem-=(r-l+1)*Sum(t);
  }
  return S[n]=tem;
}

int main(){
  ll l,r;
  //freopen("t.in","r",stdin);
  //freopen("t.out","w",stdout);
  Pre();
  scanf("%lld%lld",&l,&r); swap(l,r); swap(l,r);
  printf("%d\n",Sum(r)-Sum(l-1));
  return 0;
}
