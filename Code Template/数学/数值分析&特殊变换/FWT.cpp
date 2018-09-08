//多项式的位元运算
void FWT(LL f[], int n, int op) {
    int mx = 0;
    while((1LL<<mx) < n) mx++;
    for (int i = 1; i <= mx; ++i) {
        int m = (1 << i), len = m >> 1;
        for (int r = 0; r < n; r += m) {
            int t1 = r, t2 = r + len;
            for (int j = 0; j < len; ++j, ++t1, ++t2) {
                LL x1 = f[t1], x2 = f[t2];
                if (op == 1) {   //xor
                    f[t1] = x1 + x2;
                    f[t2] = x1 - x2;
                    //if(f[t1] >= mod) f[t1] -= mod;
                    //if(f[t2] < 0) f[t2] += mod;
                }
                if (op == 2) {   //and
                    f[t1] = x1 + x2;
                    f[t2] = x2;
                    //if(f[t1] >= mod) f[t1] -= mod;
                }
                if (op == 3) {   //or
                    f[t1] = x1;
                    f[t2] = x2 + x1;
                    //if(f[t2] >= mod) f[t2] -= mod;
                }
            }
        }
    }
}

void IFWT(LL f[], int n, int op) {
    int mx = 0;
    while((1LL<<mx) < n) mx++;
    for (int i = mx; i >= 1; --i) {
        int m = (1 << i), len = m >> 1;
        for (int r = 0; r < n; r += m) {
            int t1 = r, t2 = r + len;
            for (int j = 0; j < len; ++j, ++t1, ++t2) {
                LL x1 = f[t1], x2 = f[t2];
                if (op == 1) {   //xor  带mod和不带mod
                    f[t1] = (x1 + x2) / 2;
                    f[t2] = (x1 - x2) / 2;
//                    f[t1] = (x1 + x2) * inv2;
//                    f[t2] = (x1 - x2) * inv2;
//                    if(f[t1] >= mod) f[t1] %= mod;
//                    if(f[t2] >= mod) f[t2] %= mod;
//                    if(f[t2] < 0) f[t2] = f[t2] % mod + mod;
                }
                if (op == 2) {   //and
                    f[t1] = x1 - x2;
                    f[t2] = x2;
                    //if(f[t1] < 0) f[t1] += mod;
                }
                if (op == 3) {   //or
                    f[t1] = x1;
                    f[t2] = x2 - x1;
                    //if(f[t2] < 0) f[t2] += mod;
                }
            }
        }
    }
}
