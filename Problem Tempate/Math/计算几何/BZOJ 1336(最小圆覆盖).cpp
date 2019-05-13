#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;

const int N = 1e5 + 5;
const int M = 1e4 + 5;
const int inf = 1000000;
const double eps = 1e-8;
struct Point{double x, y;};

inline double sqr(double x){return x*x;}
inline bool cmp(double a, double b) {return fabs(a-b) < eps;}
inline double dis(Point a, Point b) {return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}

Point Oc(Point a, Point b, Point c){  //三角形外心
    double a1, a2, b1, b2, c1, c2;
    Point ans;
    a1 = 2*(b.x-a.x), b1 = 2*(b.y-a.y), c1 = sqr(b.x)-sqr(a.x)+sqr(b.y)- sqr(a.y);
    a2 = 2*(c.x-a.x), b2 = 2*(c.y-a.y), c2 = sqr(c.x)-sqr(a.x)+sqr(c.y)- sqr(a.y);
    if(cmp(a1,0)) {
           ans.y=c1/b1;
           ans.x=(c2-ans.y*b2)/a2;
      }
      else if(cmp(b1,0)) {
           ans.x=c1/a1;
           ans.y=(c2-ans.x*a2)/b2;
      }
      else {
          ans.x=(c2*b1-c1*b2)/(a2*b1-a1*b2);
          ans.y=(c2*a1-c1*a2)/(b2*a1-b1*a2);
      }
      return ans;
}

int n;
Point p[N], o;
double r;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    for(int i = 0; i < n ;i++) {
        swap(p[rand()%n], p[rand()%n]);
    }
    o = p[0];
    r = 0;
    for(int i = 0; i < n; i++) {
        if(dis(o, p[i]) < r || cmp(dis(o, p[i]), 0)) continue;
        o.x = (p[i].x + p[0].x)/2;
        o.y = (p[i].y + p[0].y)/2;
        r = dis(p[i],p[0])/2;   //假设第一个点用用
        for(int j = 1; j < i; j++) {  //前i个点形成的圆
            if(dis(o, p[j]) < r || cmp(dis(o, p[j]), 0)) continue;
            o.x = (p[i].x+p[j].x)/2;
            o.y = (p[i].y+p[j].y)/2;
            r = dis(p[i],p[j])/2;
            for(int k = 0; k < j; k++) {  //前j个点形成的圆
                if(dis(o,p[k]) < r || cmp(dis(o,p[k]),r)) continue;
                o = Oc(p[i], p[j], p[k]);
                r = dis(o,p[i]);
            }
        }
    }
    printf("%.10lf\n%.10lf %.10lf", r, o.x, o.y);
	return 0;
}
