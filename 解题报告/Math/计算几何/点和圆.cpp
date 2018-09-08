//hdu 5572

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
int dcmp (double x) {
    if (fabs (x) < eps) return 0;
    return (x < 0 ? -1 : 1);
}
//*************点
struct Point {
    double x, y;
    Point (double _x = 0, double _y = 0):x(_x), y(_y) {}
    bool operator < (const Point &b) const {
        return (dcmp (x-b.x) == 0 ? dcmp (y-b.y) < 0 : x < b.x);
    }
    Point operator + (const Point &b) const {
        return Point (x+b.x, y+b.y);
    }
    Point operator - (const Point &b) const {
        return Point (x-b.x, y-b.y);
    }
    Point operator * (double a) {
        return Point (x*a, y*a);
    }
    Point operator / (double a) {
        return Point (x/a, y/a);
    }
    double len2 () {//返回长度的平方
        return x*x + y*y;
    }
    double len () {//返回长度
        return sqrt (len2 ());
    }
    Point change_len (double r) {//转化为长度为r的向量
        double l = len ();
        if (dcmp (l) == 0) return *this;//零向量返回自身
        r /= l;
        return Point (x*r, y*r);
    }
};

//计算两个向量的叉积
double cross(const Point &a,const Point &b){
    return a.x*b.y-a.y*b.x;
}
//计算两个点的点积
double dot(const Point &a,const Point &b){
    return a.x*b.x+a.y*b.y;
}

double xmult(Point p0,Point p1,Point p2) {
    return cross((p1-p0),(p2-p0));
}
//dot(p1-p0).(p2-p0)
double dmult(Point p0,Point p1,Point p2){
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}
double dis(Point a, Point b) {//两个点的距离

    Point p = b-a; return p.len ();
}

//************直线 线段
struct Line {
    Point s, e;//直线的两个点
    double k;//极角
    Line () {}
    Line (Point _s, Point _e) {
        s = _s, e = _e;
        k = atan2 (e.y - s.y,e.x - s.x);
    }
    double length () {//求线段长度
        return dis (s, e);
    }
};
//点和直线的关系
int relation (Point p, Line l) {
    //1:在左侧 2:在右侧 3:在直线上
    int c = dcmp (cross (p-l.s, l.e-l.s));
    if (c < 0) return 1;
    else if (c > 0) return 2;
    else return 3;
}
//判断点在线段上
bool point_on_seg (Point p, Line l) {
    return dcmp (cross (p-l.s, l.e-l.s)) == 0 &&
    dcmp (dot (p-l.s, p-l.e) <= 0);
    //如果忽略端点交点改成小于号就好了
}
//判断点在射线上
bool point_on_halfline (Point p, Line l) {
    int id = relation (p, l);
    if (id != 3) return 0;
    return dcmp (dot (p-l.s, l.e-l.s)) >= 0;
}
//点到直线的距离
double point_to_line (Point p, Line a) {
    return fabs (cross (p-a.s, a.e-a.s) / a.length ());
}
//点在直线上的投影
Point projection (Point p, Line a) {
    return a.s + (((a.e-a.s) * dot (a.e-a.s, p-a.s)) / (a.e-a.s).len2() );
}
//点关于直线的对称点
Point symmetry (Point p, Line a) {
    Point q = projection (p, a);
    return Point (2*q.x-p.x, 2*q.y-p.y);
}
//***************圆
struct Circle {
    //圆心 半径
    Point p;
    double r;
    Circle () {}
    Circle (Point _p, double _r) : p(_p), r(_r) {}
};
//直线和圆的关系
int relation (Line a, Circle b) {
    //0:相离 1:相切 2:相交
    double p = point_to_line (b.p, a);
    if (dcmp (p-b.r) == 0) return 1;
    return (dcmp (p-b.r) < 0 ? 2 : 0);
}
//直线和圆的交点
int line_circle_intersection (Line v, Circle u, Point &p1, Point &p2) {
    //返回交点个数 交点保存在引用中
    if (!relation (v, u)) return 0;
    Point a = projection (u.p, v);
    double d = point_to_line (u.p, v);
    d = sqrt (u.r*u.r - d*d);
    if (dcmp (d) == 0) {
        p1 = a, p2 = a;
        return 1;
    }
    p1 = a + (v.e-v.s).change_len (d);
    p2 = a - (v.e-v.s).change_len (d);
    return 2;
}
Circle c;
Point A, B;
double v1, v2;
int main(){
    int cas = 0, t;
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> c.p.x >> c.p.y >> c.r;
        cin >> A.x >> A.y >> v1 >> v2;
        cin >> B.x >> B.y;
        Point p1, p2;
        Point temp = Point(A.x + v1, A.y + v2);
        int cnt = line_circle_intersection(Line(A,temp),c,p1,p2);
        if(cnt < 2){
            if( dmult(A,temp,B) > eps && fabs( xmult(A,temp,B)) < eps ) ans = 1;  //共线  点积 > eps 叉积 < eps
        }
        else{
            Point L; //切点
            if( dis(A,p1) > dis(A,p2) ) L = p2;
            else L = p1;
            if(abs(xmult(B, A, L)) < eps && dmult(B, A, L) < -eps) ans = 1;
            else{
                Point B2 = symmetry(A, Line(L , c.p) ); //对称点
                if( abs(xmult(L ,B2, B)) < eps && dmult(L,B2,B) > eps) ans = 1;
            }
        }
        if(ans)
            printf("Case #%d: Yes\n", ++cas);
        else
            printf("Case #%d: No\n", ++cas);
    }
    return 0;
}
