//半平面交模板应用   点到直线的y轴距离

#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)

const int MAXN = 300 + 5;
const double eps = 1e-8;
const double INF = 1e18;

struct Point {
    double x,y;
    Point(){}
    Point(double _x,double _y)  {
      x = _x; y = _y;
    }
    Point operator -(const Point &b)const  {
        return Point(x - b.x, y - b.y);
    }
    double operator ^(const Point &b)const  {
       return x*b.y - y*b.x;
    }
    double operator *(const Point &b)const  {
        return x*b.x + y*b.y;
      }
};

struct Line {
    Point s,e;
    double k, c;
    Line(){}
    Line(Point _s,Point _e)  {
        s = _s; e = _e;
        k = atan2(e.y - s.y,e.x - s.x);
        c = s.y - tan(k)*s.x;
        //if(s.x > e.x) swap(s, e);
    }
    Point operator &(const Line &b)const  {
        Point res = s;
        double t = ((s - b.s)^(b.s - b.e))/((s - e)^(b.s - b.e));
        res.x += (e.x - s.x)*t;
        res.y += (e.y - s.y)*t;
        return res;
    }
};

bool HPIcmp(Line a,Line b)
{
    if(fabs(a.k - b.k) > eps) return a.k < b.k;
    return ((a.s - b.s)^(b.e - b.s)) < 0;
}
Line Q[1010];
void HPI(Line line[], int n, Point res[], int &resn)
{
    int tot = n;
    sort(line,line+n,HPIcmp);
    tot = 1;
    for(int i = 1;i < n;i++)
        if(fabs(line[i].k - line[i-1].k) > eps)
            line[tot++] = line[i];
    int head = 0, tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    resn = 0;
    for(int i = 2; i < tot; i++)
    {
        while(head < tail && (((Q[tail]&Q[tail-1]) - line[i].s)^(line[i].e-line[i].s)) > eps)
            tail--;
        while(head < tail && (((Q[head]&Q[head+1]) - line[i].s)^(line[i].e-line[i].s)) > eps)
            head++;
        Q[++tail] = line[i];
    }
    while(head < tail && (((Q[tail]&Q[tail-1]) - Q[head].s)^(Q[head].e-Q[head].s)) > eps)
        tail--;
    while(head < tail && (((Q[head]&Q[head-1]) - Q[tail].s)^(Q[tail].e-Q[tail].e)) > eps)
        head++;
    //if(tail <= head + 1)return;
    for(int i = head; i < tail; i++)
        res[resn++] = Q[i]&Q[i+1];
    if(head < tail - 1)
        res[resn++] = Q[head]&Q[tail];
}

Point p[MAXN];
Line edge[MAXN];
Point pp[MAXN];//记录分割后的点
int n;
int resn;

double up(double x){   //上到下
    rep(i, 1, n)
        if(p[i].x >= x){
            Line t = Line(p[i], p[i-1] );
            return tan(t.k)*x + t.c;
        }
    return 0;
}

double down(double x){   //下到上
    double ret = 0;
    int r = resn;
    if(r == 1) r++;
    rep(i, 0, r) {
        ret = max(ret, tan(Q[i].k)*x + Q[i].c);
    }
    return ret;
}

int main(){
    cin >> n;
        rep(i, 0, n) cin >> p[i].x;
        rep(i, 0, n) cin >> p[i].y;
        //reverse(p,p+n);  //顺时针给点
        rep(i, 0, n-1) {
            edge[i] = Line(p[i], p[i + 1]);
        }
        HPI(edge, n-1, pp, resn);
        double ans = INF;

        /*
        cout << "Line : " << endl;
        rep(i, 0, resn) cout << Q[i].s.x << "  "  << Q[i].s.y << "   "  << Q[i].e.x << "  "  << Q[i].e.y << endl;
        cout << "Point : " << endl;
        rep(i, 0, resn) cout << pp[i].x << " " << pp[i].y << endl;
        cout << "Union : " << endl;
        rep(i, 0, resn) {
            Point t = Q[i] & Q[ (i+1)%resn ];
            cout << t.x << " " << t.y << endl;
        }
        */
        //点比边少一  （边的交点）
        //resn

        if(resn == 1) ans = min(ans, pp[0].y - up(pp[0].x) );

        rep(i, 1, resn){
            Point t = Q[i] & Q[i-1];
            ans = min(ans, t.y - up(t.x) );
        }

        rep(i, 0, n){
            ans = min(ans, down(p[i].x) - p[i].y);
        }
        printf("%.3lf\n", ans);

    return 0;
}
