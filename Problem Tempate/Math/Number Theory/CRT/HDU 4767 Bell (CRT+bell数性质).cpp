//对模数进行质因数分解
//bell[i+p] = bell[i] + bell[i+1] %p
//快速幂加速后用CRT合并
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 95041567;
const int MM = 55;
const int MAXN = 1e5 + 5;

ll m[5] = {31,37,41,43,47}, a[5];
int n;

struct Matrix {
    int mat[MM][MM];
};

Matrix multiply(Matrix a,Matrix b,int M) {
    Matrix c;
    memset(c.mat,0,sizeof(c.mat));
    for(int i=0;i<M;i++) {
        for(int j=0;j<M;j++) {
            if(a.mat[i][j]==0)continue;
            for(int k=0;k<M;k++) {
                if(b.mat[j][k]==0)continue;
                c.mat[i][k]=(c.mat[i][k]+a.mat[i][j]*b.mat[j][k])%M;
            }
        }
    }
    return c;
}

Matrix quickmod(Matrix a,int n,int M) {
    Matrix res;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++)
            res.mat[i][j]=(i==j);
    }
    while(n) {
        if(n&1) res=multiply(res,a,M);
        n>>=1;
        a=multiply(a,a,M);
    }
    return res;
}

ll Stirling[MM][MM];  //S（p，k）

void get_Stirling() {
	Stirling[0][0] = 1;
	Stirling[1][1] = 1;
	for(ll i = 2; i < MM; i++) {
		for(ll j = 1; j <= i; j++) {
			Stirling[i][j] = (Stirling[i - 1][j - 1] + j * Stirling[i - 1][j]%mod) %mod;
		}
	}
}

ll bell[MM][MM];

void init() {
    get_Stirling();
    for(int i = 0; i < 5; i++) {
        bell[i][0] = 1;
        for(int j = 1; j <= m[i]; j++) {
            bell[i][j] = 0;
            for(int k = 1; k <= j; k++) {
                bell[i][j] = (bell[i][j] + Stirling[j][k])%m[i];  //mod相应因子的bell数
            }
        }
    }
}

ll work(int n,int M,int k) {
    Matrix A;
    memset(A.mat, 0, sizeof(A.mat));
    A.mat[0][M - 1] = 1;
    for(int i = 1; i < M; i++)
        for(int j = 0; j < M; j++)
            if(i == j || i-1 == j) A.mat[i][j] = 1;
    Matrix t = quickmod(A, n/(M-1), M);   //每次往上跳p-1
    ll ans[MM];
    for(int i = 0; i < M; i++) {
        ans[i] = 0;
        for(int j = 0; j < M; j++)
            ans[i] = (ans[i] + bell[k][j]*t.mat[i][j]%M)%M;
    }
    return ans[n%(M-1)];  //答案的第n%(M-1)项
}

void extend_gcd(ll a, ll b, ll &x, ll &y, ll &d) {
    if (!b) {d = a, x = 1, y = 0;}
    else {
        extend_gcd(b, a % b, y, x, d);
        y -= a / b * x;
    }
}
//中国剩余定理 a[]存放余数 w[]存放两两互质的数
//sum{ai*ti*mi} ti*Mi % mi = 1
ll CRT(ll a[], ll w[], ll len) {
    ll d, x, y, m;
    ll ret = 0;
    ll n = 1;
    for (int i = 0; i < len; i++)
        n *= w[i];
    for (int i = 0; i < len; i++) {
        m = n / w[i];   //Mi
        extend_gcd(w[i], m, x, y, d);   // w[i] 与 m 互素
        ret = (ret + y * m * a[i]) % n;   //y*m = ti*Mi
    }
    return (n + ret % n) % n;
}

int main() {
    init();
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i < 5; i++) a[i] = work(n, m[i], i);
        ll ans = CRT(a, m, 5);
        cout << ans << endl;
    }
    return 0;
}
