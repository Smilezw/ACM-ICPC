//�ֿ�+fft
//��VΪ���ֵ  LΪ�鳤  ��ΪB�� N����
// ���Ӷ� O(BVlogV + L*L)

//�����е��� ��������� ������Ӱ��
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
    while(bin < v*2+1) bin = bin << 1;  //�����޵����

    for(int i = 1; i <= g; i++) {  //ÿһ��
        for(int j = st[i-1]; i-1 && j <= ed[i-1]; j++) L[a[j]]++;  //�����
        for(int j = st[i]; j <= ed[i]; j++) R[a[j]]--;   //���ұ�
        if(i > 1 && i < g) _fft();      //�����м�ʱ ����fft
        memset(pre, 0, sizeof(pre));
        for(int j = st[i]; j <= ed[i]; j++) { //ͳ�Ƶ�ǰ��
            int t = a[j] + a[j];
            for(int k = st[i]; k < j; k++)  //��ǰԪ��Ϊ�м�ֵ ��������������ұ����
                if(t - a[k] > 0 && t - a[k] <= v) ans = ans + R[t-a[k]];
            for(int k = j + 1;k <= ed[i]; k++)  //ͬ�� ���Ƕ��һ�����ڿ��ڵ����
                if(t - a[k] > 0 && t- a[k] <= v) ans = ans + L[t-a[k]] + pre[t-a[k]];
            if(i > 1 && i < g) ans = ans + c[t];  //����ֱ�Ӿ��
            pre[a[j]]++;
        }

    }
}

int main() {
    int n;
    len = 2000;      //�鳤
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        R[a[i]]++;  //������ȫ����¼��
        pos[i] = (i-1)/len + 1;
        v = max(v, a[i]);
    }
    g = pos[n];  //����
    for(int i = 1; i <= g; i++)
        st[i] = (i-1)*len + 1, ed[i] = i*len;
    ed[g] = min(n, ed[g]);
    solve();
    printf("%lld\n", ans);
    return 0;
}
