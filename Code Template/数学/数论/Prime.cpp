//O(nloglogn)
//到1e6
const int MAXN = 10000;
int prime[MAXN + 5];
void getPrime(){
    memset(prime, 0, sizeof(prime));
    for(int i = 2; i <= MAXN; i++){
        if(!prime[i]) prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0] && prime[j] <= MAXN /i; j++){
            prime[prime[j] * i] = 1;
            if(i%prime[j] == 0) break;
        }
    }
}

//到1e7
unsigned int prime[1000005],cnt;
bool vis[10000005];
void is_prime()
{
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=2;i<MAXN;i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
            for(int j=i+i;j<MAXN;j+=i)
            {
                vis[j]=1;
            }
        }
    }
}


//费马小定理了解一下  a ^ (p-1) = 1 mod p (p为素数
int judge(ll x)
{
    if(x == 2) return 1; 
    ll a=2,b=x-1,res=1;
    while(b)
    {
        if(b&1) res=res*a%x;
        a = a*a % x;
        b=b>>1;
    }
    return res==1;
}
