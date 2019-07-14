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
    int n, m;   //����&&����

    struct Node {        //��
        int d, pos;
        bool operator < (const Node & rhs) const {
            return d > rhs.d;
        }
    };

    struct Edge {        //��
        int u, v, w;
    };

    vector <Edge > edge[N];   //�ڽӱ�

    void add(int u, int v, int w) {
        edge[u].push_back(Edge{u, v, w});
        edge[v].push_back(Edge{v, u, w});
    }

    void init() {
        for(int i = 1; i <= n; i++) edge[i].clear();
    }

    void creat() {
        cout << "--------�޸���ͼ�Ͻ�˹�����Ż�-------"  << endl;
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            add(u, v, w);
        }
    }

    int dis[N];    //����
    int vis[N];

    priority_queue <Node > q;     //С����

    void Dijstra(int s) {
        while(!q.empty()) q.pop();        //��ն�
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++) dis[i] = INF;   //����Ϊ���
        dis[s] = 0;
        q.push(Node{0,s});           //������
        while(!q.empty() ) {
            Node t = q.top();        //ȡ��С��
            q.pop();
            int u = t.pos;
            if(vis[u]) continue;
            vis[u] = 1;
            int len = edge[u].size();
            for(int i = 0; i < len; i++) {      //��չ�»�
                int v = edge[u][i].v;
                int w = edge[u][i].w;
                if(dis[v] > dis[u] + w) {     //�ɳڲ���
                    dis[v] = dis[u] + w;
                    q.push(Node {dis[v], v});
                }
            }
        }
    }
};

DIJSTRA text;

void output() {  //��ȷ�Լ��
    cout << "ͼ��С n  m  "  << text.n << " " << text.m << endl;
    cout << "dis������ " << endl;
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
    text.Dijstra(1);       //�㷨����  ʱ�����

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
