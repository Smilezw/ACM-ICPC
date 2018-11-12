//FFT裸题取木棍的方案数

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAXN = 4e5 + 5;
const double PI = acos(-1.0);
//复数结构体
struct complex{
    double r,i;
    complex(double _r = 0.0,double _i = 0.0){
        r = _r; i = _i;
    }
    complex operator +(const complex &b){
        return complex(r+b.r,i+b.i);
    }
    complex operator -(const complex &b){
        return complex(r-b.r,i-b.i);
    }
    complex operator *(const complex &b){
        return complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
/*
 * 进行FFT和IFFT前的反转变换。
 * 位置i和 （i二进制反转后位置）互换
 * len必须去2的幂
 */
void change(complex y[],int len){
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
/*
 * 做FFT
 * len必须为2^k形式，
 * on==1时是DFT，on==-1时是IDFT
 */
void fft(complex y[],int len,int on){
    change(y,len);
    for(int h = 2; h <= len; h <<= 1){
        complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j+=h){
            complex w(1,0);
            for(int k = j;k < j+h/2;k++){
                complex u = y[k];
                complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}
complex x1[MAXN];
int a[MAXN >> 2];
typedef long long ll;
ll cnt[MAXN], sum[MAXN];

int main(){
    int T;
    int n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        memset(cnt,0,sizeof(cnt));
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]); cnt[a[i]]++;
        }
        sort(a,a+n);
        int len1 = a[n-1] + 1;
        int len=1;
        while(len < 2*len1) len = len << 1;

        for(int i = 0; i < len1; i++)
            x1[i] = complex(cnt[i], 0);
        for(int i = len1; i < len; i++)
            x1[i] = complex(0,0);
        fft(x1, len, 1);
        for(int i = 0; i < len; i++){
            x1[i] = x1[i]*x1[i];
        }
        fft(x1, len, -1);
        for(int i = 0; i < len; i++){
            cnt[i] = (long long)(x1[i].r+0.5);
            //cout << cnt[i] << endl;
        }
        len = a[n-1]*2;
        for(int i = 0; i < n; i++){
            cnt[a[i] + a[i]]--;
        }
        for(int i = 0; i <= len; i++){
            cnt[i] = cnt[i]/2;
        }
        sum[0] = 0;
        for(int i = 1; i <= len; i++){
            sum[i] = sum[i-1]+cnt[i];
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ans += sum[len] - sum[a[i]];
            ans -= 1ll*(n-i-1)*i;
            ans -= 1ll*(n-1);
            ans -= 1ll*(n-1-i)*(n-i-2)/2;
        }
        long long tot = 1ll*n*(n-1)*(n-2)/6;
        printf("%.7lf\n", (double)ans/tot);
    }
    return 0;
}
