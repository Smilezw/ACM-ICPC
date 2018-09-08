//O(nloglogn)

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


//费马小定理了解一下  a ^ (p-1) = 1 mod p (p为素数
int judge(ll x)
{
    ll a=2,b=x-1,res=1;
    while(b)
    {
        if(b&1) res=res*a%x;
        a = a*a % x;
        b=b>>1;
    }
    return res==1;
}
