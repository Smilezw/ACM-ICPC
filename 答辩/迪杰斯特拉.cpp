#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;

struct DIJSTRA {
    int G[N][N];
    int dis[N];
    int vis[N];

    int n, m;

    void init() {
        memset(G, 0x3f, sizeof(G));
    }

    void creat() {
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if(G[u][v] != INF && G[u][v] <= w) continue;
            G[u][v] = w;
            G[v][u] = w;
        }
    }

    void Dijstra(int s) {
        for(int i = 1; i <= n; i++) dis[i] = G[s][i];
        dis[s] = 0;
        vis[s] = 1;

        for(int i = 1; i < n; i++) {

            int pos = 0, d = INF;
            for(int j = 1; j <= n; j++) {
                if(!vis[j] && dis[j] < d) {
                    d = dis[j];
                    pos = j;
                }
            }

            vis[pos] = 1;

            for(int j = 1; j <= n; j++) {
                if(dis[j] > dis[pos] + G[pos][j])
                    dis[j] = dis[pos] + G[pos][j];
            }
        }
    }
};

DIJSTRA text;

void output() {  //正确性检查
    cout << "----邻接矩阵的迪杰斯特拉----" << endl;
    cout << "dis数组检查 " << endl;
    int te;
    te = (text.n <= 10 ? text.n : 10);
    while(te--){
        int t;
        t = rand()%text.n + 1;
        cout << "dis  " << t << " = " << text.dis[t] << endl;
    }
}

void solve() {
    double dur;
    clock_t start,end;
    start = clock();

    text.init();
    text.creat();
    text.Dijstra(1);       //算法过程  时间测试

    end = clock();
    dur = double(end - start);
    printf("Use Time: %.6gms\n",(dur/CLOCKS_PER_SEC));

    output();
}

int main() {
    freopen("C:\\Users\\ASUS\\Desktop\\in1.txt","r",stdin);
	freopen("C:\\Users\\ASUS\\Desktop\\dij.txt","w",stdout);

    int T;
    cin >> T;
    int cas = 1;
    srand(time(NULL));
    while(T--) {
        cout << "The case :  " << cas++ << endl;
        solve();
        cout << endl;
    }
    return 0;
}
