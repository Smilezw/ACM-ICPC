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
        //������ΪС�귴ת��Ԫ�أ�i<j��֤����һ��
        //i��������+1��j��ת���͵�+1,ʼ�ձ���i��j�Ƿ�ת��
        k = len/2;
        while( j >= k){
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}

void fft(cpx y[],int len,int on){
    change(y,len);  //�����Ʒ�ת
    for(int h = 2; h <= len; h <<= 1){ //ö�ٳ��� 2^1....2^m
        cpx wn(cos(-on*2*PI/h),sin(-on*2*PI/h)); //��λ���ȸ���
        for(int j = 0;j < len;j+=h){ //ö��ÿһ��
            cpx w(1,0);
            for(int k = j;k < j+h/2;k++){ //ö��ÿ��ֵ ��������
                cpx u = y[k];  //ż��
                cpx t = w*y[k+h/2];  //����
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

int main() {
}
