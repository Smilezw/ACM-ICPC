
const int N = 500 + 5;
const int mod = 1e18;

int f[N][N];   //构造矩阵
int tot;     ///矩阵大小

int Gauss() {
    int ans = 1;
    for(int i = 1; i < tot; i ++) {
        for(int j = i + 1; j < tot; j ++)
            while(f[j][i])
            {
                int t = f[i][i] / f[j][i];
                for(int k = i; k < tot; k ++)
                    f[i][k] = (f[i][k] - t * f[j][k] + mod) % mod;
                swap(f[i], f[j]);
                ans = - ans;
            }
        ans = (ans * f[i][i]) % mod;
    }
    return (ans + mod) % mod;
}
