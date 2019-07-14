#pragma GCC optimize(3,"Ofast","inline")
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <ctime>
using namespace std;

const int N = 1e6 + 5;
const int M = 1e6 + 5;
const int INF = 0x3f3f3f3f;

struct DIJSTRA {
    int n, m;   //点数&&边数

    struct Node {        //弧
        int d, pos;
        bool operator < (const Node & rhs) const {
            return d > rhs.d;
        }
    };

    struct Edge {        //边
        int u, v, w;
    };

    vector <Edge > edge[N];   //邻接表

    void add(int u, int v, int w) {
        edge[u].push_back(Edge{u, v, w});
        edge[v].push_back(Edge{v, u, w});
    }

    void init() {
        for(int i = 1; i <= n; i++) edge[i].clear();
    }

    void creat() {
        cout << "--------无负环图迪杰斯特拉优化-------"  << endl;
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            add(u, v, w);
        }
    }

    int dis[N];    //弧长
    int vis[N];

    priority_queue <Node > q;     //小根堆

    void Dijstra(int s) {
        while(!q.empty()) q.pop();        //清空堆
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++) dis[i] = INF;   //弧置为最大
        dis[s] = 0;
        q.push(Node{0,s});           //起点入堆
        while(!q.empty() ) {
            Node t = q.top();        //取最小弧
            q.pop();
            int u = t.pos;
            if(vis[u]) continue;
            vis[u] = 1;
            int len = edge[u].size();
            for(int i = 0; i < len; i++) {      //拓展新弧
                int v = edge[u][i].v;
                int w = edge[u][i].w;
                if(dis[v] > dis[u] + w) {     //松弛操作
                    dis[v] = dis[u] + w;
                    q.push(Node {dis[v], v});
                }
            }
        }
    }
};

DIJSTRA text;

void output() {  //正确性检查
    cout << "图大小 n  m  "  << text.n << " " << text.m << endl;
    cout << "dis数组检查 " << endl;
    int te;
    te = (text.n <= 10 ? text.n : 10);
    while(te--){
        int t;
        t = rand()%text.n + 1;
        cout << "dis  " << t << " = " << text.dis[t] << endl;
    }
}

void solve(){
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
    /*
    freopen("C:\\Users\\ASUS\\Desktop\\in2.txt","r",stdin);
	freopen("C:\\Users\\ASUS\\Desktop\\out2.txt","w",stdout);
    */
    ///*
    freopen("C:\\Users\\ASUS\\Desktop\\in1.txt","r",stdin);
	freopen("C:\\Users\\ASUS\\Desktop\\dij + d.txt","w",stdout);
    //*/
    int T;
    cin >> T;
    int cas = 1;
    while(T--) {
        cout << "The case :  " << cas++ << endl;
        solve();
        cout << endl;
    }
    return 0;
}
