//是否存在一条线穿过所有给定线段

#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
int _max(int x, int y){
	return x > y ? x : y;
}
int _min(int x, int y){
	return x < y ? x : y;
}
const int MAXN = 100 + 5;
const double eps = 1e-8;
const double PI = acos(-1.0);

int sgn(double x) {
    if (fabs(x) < eps) return 0;
    if (x < 0) return -1;
    else return 1;
}
struct Point {
    double x, y;
    Point(){}
    Point(double _x, double _y) {
        x = _x;
        y = _y;
    }
    Point operator -(const Point &b)const {
        return Point(x - b.x, y - b.y);
    }
    double operator ^(const Point &b)const {
        return x * b.y - y * b.x;
    }

    double operator *(const Point &b)const {
        return x * b.x + y * b.y;
    }
    void transXY(double B) {
        double tx = x, ty = y;
        x = tx * cos(B) - ty * sin(B);
        y = tx * sin(B) + ty * cos(B);
    }
};
struct Line {
    Point s, e;
    Line(){}
    Line(Point _s, Point _e) {
        s = _s; e = _e;
    }
}line[MAXN];

double dist(Point a,Point b){
    return sqrt( (b - a)*(b - a) );
}

bool Seg_inter_line(Line l1, Line l2) {
    return sgn((l2.s - l1.e) ^ (l1.s - l1.e)) * sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <= 0;
}

bool check(Line l1,int n){
    if(sgn(dist(l1.s,l1.e)) == 0 )return false;
    for(int i = 0;i < n;i++)
        if(Seg_inter_line(l1,line[i]) == false)
            return false;
    return true;
}

int main() {
	int k; cin >> k;
	while(k--){
		int n; cin >> n;
		for(int i = 0; i < n; i++){
			double x, y, x2, y2;
			scanf("%lf%lf%lf%lf",&x, &y, &x2, &y2);
            line[i] = Line(Point(x,y),Point(x2,y2));
        }
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(check(Line(line[i].s,line[j].s),n) || check(Line(line[i].s,line[j].e),n)
				|| check(Line(line[i].e,line[j].s),n) || check(Line(line[i].e,line[j].e),n) ){
					ans = 1; break;
				}
			}
		}
		if(ans) cout << "Yes!" << endl;
		else cout << "No!" << endl;
	}
	return 0;
}
