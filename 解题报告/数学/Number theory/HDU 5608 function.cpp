//积性函数入门
//迪利克雷反演变化发现规律 筛出1e6的数据
//进行杜教筛递归求解
//注意乘法溢出
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int MAXN = 1111111;

#define inv (mod+1)/3

map <int, int> m;
int f[MAXN];
int sum[MAXN];

void init(){
    for(int i = 1; i < MAXN; i++)
        f[i] = 1ll*(i-1)*(i-2)%mod;
    for(int i = 1; i < MAXN; i++){
        for(int j = i+i; j < MAXN; j = j + i){
            f[j] = f[j] - f[i];
            if(f[j] < 0) f[j] = f[j] + mod;
        }
    }
    for(int i = 2; i < MAXN; i++){
        sum[i] = sum[i-1] + f[i];
        if(sum[i] >= mod) sum[i] -= mod;
    }
}

int solve(int n){
    if(n < MAXN) return sum[n];
    if(m.find(n) != m.end()) return m[n];
    int ret = 1ll*n*(n-1) %mod *(n-2) %mod *inv %mod;
    for(int i = 2; i <= n; ){
        int next = n/(n/i);
        ret = ret - 1ll*(next - i + 1)*solve(n/i)%mod;
        if(ret < 0) ret += mod;
        i = next + 1;
    }
    return m[n] = ret;
}

int main(){
    init();
    int T;
    cin >> T;
    while(T--){
        int n;
        m.clear();
        scanf("%d", &n);
        printf("%d\n", (solve(n) + mod)%mod );
    }
    return 0;
}
