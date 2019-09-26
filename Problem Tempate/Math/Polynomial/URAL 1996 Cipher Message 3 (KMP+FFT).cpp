//���þ�����ʹ���i��i+m��Hamming����
//a*b��ת ��0��ͬ��������   ��a*��b��ת ��1��ͬ��������

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

int a[MAXN], b[MAXN];
int ans[MAXN];
int S[MAXN], T[MAXN];
int _next[MAXN];

int n, m;

void init() {
    int i = 0, j = -1;
    _next[0] = -1;
    while(i < m) {
        if(T[i] == T[j] || j == -1) {
            i++; j++;
            _next[i] = j;
        }
        else j = _next[j];
    }
}

int ansx=INF, ansy;

void kmp(){
    int i = 0, j = 0;
    while(i < n) {
        if(j == -1 || S[i] == T[j]) {
             i++; j++;

             if(j == m) {
                 j = _next[j];
                 if(ansx > m - ans[i-m]) {
                     ansx = m - ans[i-m];
                     ansy = i - m;
                 }
             }
         }
        else j = _next[j];
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        a[i] = t&1;
        S[i] = t/10;
    }
    for(int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        b[i] = t&1;
        T[i] = t/10;
    }
    if(n < m) {
        printf("No\n");
        return 0;
    }

    int len = 1;
    while(len < n*2 || len < m*2) len = len << 1;

    for(int i = 0; i < n; i++) x1[i] = cpx(a[i], 0);
    for(int i = n; i < len; i++) x1[i] = cpx(0,0);
    for(int i = 0; i < m; i++) x2[i] = cpx(b[m-1-i], 0);
    for(int i = m; i < len; i++) x2[i] = cpx(0,0);
    fft(x1, len, 1);
    fft(x2, len, 1);
    for(int i = 0; i < len; i++) x1[i] = x1[i]*x2[i];
    fft(x1, len, -1);
    for(int i = 0; i < len; i++) {
        ans[i] = (int)(x1[i+m-1].real() + 0.5);
    }
    for(int i = 0; i < n; i++) x1[i] = cpx(!a[i], 0);
    for(int i = n; i < len; i++) x1[i] = cpx(0,0);
    for(int i = 0; i < m; i++) x2[i] = cpx(!b[m-1-i], 0);
    for(int i = m; i < len; i++) x2[i] = cpx(0,0);
    fft(x1, len, 1);
    fft(x2, len, 1);
    for(int i = 0; i < len; i++) {
        x1[i] = x1[i]*x2[i];
    }
    fft(x1, len, -1);
    for(int i = 0; i <= n-m; i++) {
        ans[i] += (int)(x1[i+m-1].real() + 0.5);
    }
    init();
    kmp();
    if(ansx == INF) printf("No\n");
    else {
        printf("Yes\n");
        printf("%d %d\n", ansx, ansy+1);
    }
    return 0;
}
