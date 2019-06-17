//���ڶ�ά���ݳ��ϵ  ֱ���󲻺��󣬿��Ǽ�ȥ���ϵĲ������� (3^n-3)^n  (����������³���Ϊn����)
//��Ȼ���ȥ��������ͬ�Ĳ���  ��ô���Ǽ���ȥ��ʹ���ݳ��ϵ

//����i����ͬ      1. ��i��Ϊһ����ɫ���ұ�֤ÿһ�в�ֹһ��    3*c(n,i)  *  (3^(n-i) - 1)^n
//����i�и�����ͬ  2. ��i�и�����ͬ  (3^i-3)*c(n,i) * (3^(n-i))^n
//����3^(n^2)

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int MAXN = 1e6 + 5;

inline ll quickpow(ll a, ll b) {
    ll ret = 1;
    ll n = a;

    while (b) {
        if (b & 1) ret = ret * n % mod; //������������λΪ1�������x^(2^i)
        n = n * n % mod;  // ��xƽ��
        b = b >> 1;
    }
    return ret % mod;
}

ll inv[MAXN];
ll f[MAXN];

void init(){
    f[0] = inv[0] = 1;
    for(int i = 1; i < MAXN; i++){
        f[i] = 1ll*f[i-1] * i %mod;
        inv[i] = quickpow(f[i], mod - 2);
    }
}

ll cal(ll n, ll i){
    //cout << n << " " << i << " " << f[n]*inv[i]%mod*inv[n-i]%mod  << endl;
    return f[n]*inv[i]%mod*inv[n-i]%mod;
}

ll n;
int main(){
    init();
    cin >> n;
    ll ans = quickpow(3ll, n*n) - quickpow( quickpow(3ll, n) - 3, n); //ÿһ������һ����ɫ�ķ���
    for(ll i = 1; i <= n; i++){    //ö��1����ɫ�е�����
        ll now = 3*quickpow( (quickpow(3, (n-i)) - 1), n) %mod;  //������ɫ��ͬ���е���ɫ��һ��
        now += (quickpow(3,i) - 3)*quickpow(3, (n-i)*n); //������ɫ��ͬ������ɫ��һ��
        now %= mod;
        now *= cal(n, i);
        now %= mod;
        if(i&1)
            ans = (ans + now)%mod;
        else
            ans = (ans - now + mod)%mod;
    }
    cout << ans << endl;
    return 0;
}
