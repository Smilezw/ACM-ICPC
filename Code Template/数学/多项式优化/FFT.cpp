#include <bits/stdc++.h>
using namespace std;

typedef complex <double > cpx;

const int MAXN = 1e6 + 5;
const double PI = acos(-1);
const int INF = 0x3f3f3f3f;

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
cpx x2[MAXN];
