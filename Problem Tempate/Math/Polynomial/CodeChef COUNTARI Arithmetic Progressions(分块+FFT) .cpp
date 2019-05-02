//分块+fft
//令V为最大值  L为块长  分为B块 N个数
// 复杂度 O(BVlogV + L*L)

//区间中的数 区间外的数 产生的影响
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex <double > cpx;
const int MAXN = 2e5 + 5;
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

cpx x1[MAXN*3];
cpx x2[MAXN*3];

int a[MAXN];
int L[MAXN], R[MAXN];
int st[MAXN], ed[MAXN];
int n, len, g, v;
int pre[MAXN];
int pos[MAXN];
ll c[MAXN*3];
ll ans;

int bin;
void _fft() {
    for(int i = 0; i <= v; i++) {
        x1[i] = cpx(L[i], 0);
        x2[i] = cpx(R[i], 0);
    }
    for(int i = v+1; i < bin; i++) {
        x1[i] = cpx(0, 0);
        x2[i] = cpx(0, 0);
    }
    fft(x1, bin, 1);
    fft(x2, bin, 1);
    for(int i = 0; i < bin; i++) x1[i] = x1[i]*x2[i];
    fft(x1, bin, -1);
    for(int i = 0; i < bin; i++) c[i] =(ll)(x1[i].real() + 0.5);
}

void solve() {
    bin = 1;
    while(bin < v*2+1) bin = bin << 1;  //把上限调大点

    for(int i = 1; i <= g; i++) {  //每一块
        for(int j = st[i-1]; i-1 && j <= ed[i-1]; j++) L[a[j]]++;  //块左边
        for(int j = st[i]; j <= ed[i]; j++) R[a[j]]--;   //块右边
        if(i > 1 && i < g) _fft();      //块在中间时 进行fft
        memset(pre, 0, sizeof(pre));
        for(int j = st[i]; j <= ed[i]; j++) { //统计当前块
            int t = a[j] + a[j];
            for(int k = st[i]; k < j; k++)  //当前元素为中间值 块内左面与块外右边组合
                if(t - a[k] > 0 && t - a[k] <= v) ans = ans + R[t-a[k]];
            for(int k = j + 1;k <= ed[i]; k++)  //同理 但是多加一个都在块内的情况
                if(t - a[k] > 0 && t- a[k] <= v) ans = ans + L[t-a[k]] + pre[t-a[k]];
            if(i > 1 && i < g) ans = ans + c[t];  //块外直接卷积
            pre[a[j]]++;
        }

    }
}

int main() {
    int n;
    len = 2000;      //块长
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        R[a[i]]++;  //右区间全给记录上
        pos[i] = (i-1)/len + 1;
        v = max(v, a[i]);
    }
    g = pos[n];  //块数
    for(int i = 1; i <= g; i++)
        st[i] = (i-1)*len + 1, ed[i] = i*len;
    ed[g] = min(n, ed[g]);
    solve();
    printf("%lld\n", ans);
    return 0;
}
