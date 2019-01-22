#include <bits/stdc++.h>
using namespace std;

typedef complex <double > cpx;
typedef long long ll;

const int MAXN = 4e5 + 40;
const double PI = acos(-1);

void change(cpx y[],int len){
    int i,j,k;
    for(i = 1, j = len/2;i < len-1; i++){
        if(i < j) swap(y[i],y[j]);
        //交换互为小标反转的元素，i<j保证交换一次
        //i做正常的+1，j左反转类型的+1,始终保持i和j是反转的
        k = len/2;
        while( j >= k){
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}

void fft(cpx y[],int len,int on){
    change(y,len);  //二进制反转
    for(int h = 2; h <= len; h <<= 1){ //枚举长度 2^1....2^m
        cpx wn(cos(-on*2*PI/h),sin(-on*2*PI/h)); //单位长度复根
        for(int j = 0;j < len;j+=h){ //枚举每一段
            cpx w(1,0);
            for(int k = j;k < j+h/2;k++){ //枚举每个值 蝴蝶操作
                cpx u = y[k];  //偶数
                cpx t = w*y[k+h/2];  //奇数
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i] = y[i]/cpx(len, 0);
}

cpx x1[MAXN];

ll a[MAXN];
ll num[MAXN];
ll sum[MAXN];

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, len = 1;
        memset(num, 0, sizeof(num));
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            num[a[i]]++;
        }
        sort(a, a + n);
        int len1 = a[n-1] + 1;
        while(len < 2*len1) len = len << 1;
        for(int i = 0; i < len1; i++) {
            x1[i] = cpx(num[i], 0.0);
        }
        for(int i = len1; i < len; i++) {
            x1[i] = cpx(0.0, 0.0);
        }
        fft(x1, len, 1);
        for(int i = 0; i < len; i++) {
            x1[i] = x1[i]*x1[i];
        }
        fft(x1, len, -1);
        for(int i = 0; i < len; i++) {
            num[i] = (ll)(x1[i].real() + 0.5);
        }

        len = 2*a[n-1];

        for(int i = 0; i < n; i++) {  //相同选择
            num[a[i] + a[i]]--;
        }
        for(int i = 1; i <= len; i++) {  //对称选择
            num[i] = num[i]/2;
        }

        sum[0] = 0;
        for(int i = 1; i <= len; i++) {
            sum[i] = sum[i-1] + num[i];
        }

        ll ans = 0;
        //考虑最大边是a[i]时候的取法
        for(int i = 0; i < n; i++) {
            ans = ans + sum[len] - sum[a[i]];  //前两块的取法总数
            ans = ans - (n-1);   //大于自己的值n-1个取本身构成的
            ans = ans - (ll)i*(n-1-i);  //一个大以一个小于
            ans = ans - (ll)(n-1-i)*(n-i-2)/2;  //都大于
        }

        ll tot = 1ll*n*(n-1)*(n-2)/6;
        double cnt = (double)ans/tot;
        printf("%.7lf\n", cnt);
    }

    return 0;
}
