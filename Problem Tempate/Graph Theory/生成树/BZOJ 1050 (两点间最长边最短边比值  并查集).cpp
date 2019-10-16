#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

inline void out(int x) {
   if(x>9) out(x/10);
   putchar(x%10+'0');
}

inline ll gi(){
    ll x=0,q=1; char ch=getchar(); while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
    if (ch=='-') q=-1,ch=getchar(); while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar(); return q*x;
}

const int N = 500 + 5;
const int M = 1e4 + 5;
const int inf = 1000000;

int a, b, n, m, s, t, flag;

int f[N];

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

void init() {
    for(int i = 0; i <= n; i++) f[i] = i;
}

struct Edge{
    int u, v, w;
}edge[M];

int cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

void kls(int x) {
    int t1;
    init();
    for(int i = x; i < m; i++) {
        int u = edge[i].u, v = edge[i].v;
        int fu = find(u);
        int fv = find(v);
        if(fu != fv) {
            f[fu] = fv;
            if(find(s) == find(t)) {
                flag = 1;
                t1 = i;
                break;
            }
        }
    }
    if(find(s) != find(t)) return;
    if(1.0*a/b > 1.0*edge[t1].w/edge[x].w) {
        a = edge[t1].w;
        b = edge[x].w;
    }
}

int main() {
    freopen("C:\\Users\\ASUS\\Desktop\\1in.txt", "r" ,stdin);
    freopen("C:\\Users\\ASUS\\Desktop\\1out.txt", "w" ,stdout);
    n = gi(), m = gi();
    for(int i = 0; i < m; i++) {
        int u, v, w;
        u = gi(), v = gi(), w= gi();
        edge[i] = (Edge){u, v, w};
    }
    s = gi(), t = gi();
    sort(edge, edge + m, cmp);
    a = inf, b = 1, flag = 0;
    for(int i = 0; i < m; i++) kls(i);
    int d = gcd(a, b);
    if(flag == 0) cout << "GG" << endl;
    else {
        if(b/d == 1)
            printf("%d\n", a/d);
        else
            printf("%d/%d\n", a/d, b/d);
    }
	return 0;
}
