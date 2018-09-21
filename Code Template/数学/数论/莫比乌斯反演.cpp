/*
约数的莫比乌斯反演：
若：f(n)=∑d|n g(d)
则：g(n)=∑d|n μ(d)f(n/d)
倍数的莫比乌斯反演：
若：f(n)=∑n|d g(d)
则：g(n)=∑n|d μ(d/n)f(d)
*/

const int MANX = 1e6;
bool check[MAXN];
LL prime[MAXN];
LL mu[MAXN];

void Moblus(){
    memset(check,false,sizeof(check));
    mu[1] = 1;
    LL tot = 0;
    for(LL i = 2; i <= MAXN; i++){
        if( !check[i] ){
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(LL j = 0; j < tot; j++){
            if(i * prime[j] > MAXN) break;
            check[i * prime[j]] = true;
            if( i % prime[j] == 0){
                mu[i * prime[j]] = 0;
                break;
            }
            else{
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}
