#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

struct node{
    int s[9];
    int cur,n;//分别表示0的位置，和当前hash值（即cantor函数的值）
    int f,g,h;//即A*算法的f,g,h
    node(){}
    bool operator <(const node &a)const{
        if(a.f!=f) return a.f<f;
        return a.g<g;
    }
}o;

int fac[]={1,1,2,6,24,120,720,5040,40320};

int cantor(int s[]){//康托展开，即一个状态压缩的Hash函数
    int sum=0;
    for(int i=0;i<9;i++){
        int cnt=0;
        for(int j=i+1;j<9;j++)
            if(s[j]<s[i]) cnt++;
        sum+=cnt*fac[9-i-1];
    }
    return sum;
}

int get_h(int s[]){//A*算法的乐观估价函数，这里用的是曼哈顿距离公式
    int val=0;
    for(int i=0;i<9;i++){//这里有9个点数字需要回到目标状态
        int x=i/3,y=i%3;//数字状态当前所在坐标
        if(s[i]){
            int tx=(s[i]-1)/3,ty=(s[i]-1)%3;//数字目标状态所在坐标
            val+=abs(x-tx)+abs(y-ty);
        }
    }
    return val;
}

int vis[363000];
int d[][2]={{1,0},{-1,0},{0,-1},{0,1}};
char dir[]="dulr";
int front[363000];//记录路径
char path[363000];//记录路径的值

void disp(int n){//打印解
    if(front[n]){
        disp(front[n]);
        cout<<path[n];
    }
}

void bfs(){//A*算法也是一种层次遍历，只是把宽度变窄了，所以写作BFS应该也还好理解
    memset(vis,0,sizeof(vis));
    memset(front,0,sizeof(front));
    priority_queue<node> q;
    q.push(o);
    vis[o.n]=1;
    int ans=46233;//“123456780“的hash值
    while(!q.empty())
    {
        node tmp=q.top();
        if(tmp.n==ans){
            disp(ans);
            cout<<endl;
            return;
        }
        q.pop();
        int x=tmp.cur/3,y=tmp.cur%3;
        for(int p=0;p<4;p++){
            int tx=d[p][0]+x,ty=d[p][1]+y;
            if(tx<0 || ty<0 || tx>2 || ty>2) continue;
            node tmp2=tmp;
            tmp2.cur=tx*3+ty;
            swap(tmp2.s[tmp.cur],tmp2.s[tmp2.cur]);
            tmp2.n=cantor(tmp2.s);
            if(vis[tmp2.n]) continue;
            vis[tmp2.n]=1;
            front[tmp2.n]=tmp.n;
            path[tmp2.n]=dir[p];
            tmp2.g++;tmp2.h=get_h(tmp2.s);tmp2.f=tmp2.g+tmp2.h;
            q.push(tmp2);
        }
    }
    //cout<<"No\n";
}

int main(){
    char ch;
    while(cin>>ch){
        if(ch=='x'){
            ch='0';
            o.cur=0;
        }
        o.s[0]=ch-'0';
        for(int i=1;i<9;i++){
            cin>>ch;
            if(ch=='x'){
                ch='0';
                o.cur=i;
            }
            o.s[i]=ch-'0';
        }
        o.n=cantor(o.s);
        o.g=0;o.h=get_h(o.s);o.f=o.g+o.h;
        int cnt=0;
        for(int i=0;i<8;i++)//记录逆序数
            if(o.s[i])
                for(int j=i+1;j<9;j++)
                    if(o.s[j]<o.s[i] && o.s[j]) cnt++;
        if(cnt&1) cout<<"unsolvable\n";
        else bfs();
    }
    return 0;
}
