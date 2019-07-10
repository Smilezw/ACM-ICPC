#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Car{
	int name;
	double a[4];
	Car(){};
	Car(int _na, double _a, double _b, double _c) {
		name = _na;
		a[1] = _a, a[2] = _b, a[3] = _c, a[4] = 0;
	}
}car[5];

struct Arrive{
	int name;
	double t;
	Arrive(){};
	Arrive(int _a, double _t) : name(_a), t(_t){};
	bool operator < (const Arrive & rhs) const {
        return t > rhs.t;
    }
}a[1000];

string k[10] = {" ", "CRH2", "CRH3", "CRH5", "CRH6", " "};

void init() {
	car[1] = Car(1, 1, 2, 1.5);
	car[2] = Car(2, 0.8, 2.4, 0.5);
	car[3] = Car(3, 1.3, 2.5, 1.5);
	car[4] = Car(4, 1, 2.7, 0.3);
}

int get_ty(string t) {
	for(int i = 1; i <= 4; i++) if(t == k[i]) return i;
	return -1;
}

int n;

void input() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		string str;
		double ss, ff;
		scanf("%lf:%lf", &ss, &ff);
		cin >> str;
		double tt = ss*60 + ff;
		int name = get_ty(str);
		a[i] = Arrive(name, tt);
	}
}

int cflow[5] = {0, 3, 8, 5, 10000};
int now[5];
double ct[5] = {0, 1, 2, 1.5, 0};

double s, t;
int num;   //起始  结束   车间内的车数量
priority_queue <Arrive > q[5];

void turn(int pos, int go) {   //把上一个车间的加到这个车间  如果当前车间满了  继续找下个车间
	if(now[pos] == cflow[pos]) turn(pos+1, go);
	if(pos == 1) return;
	Arrive c = q[pos-1].top();
	if(go == 0) go = c.t;
	q[pos-1].pop();
	now[pos-1]--;
	int res;
	res = go + car[c.name].a[pos]*60;
	q[pos].push(Arrive(c.name, res) );
	now[pos]++;
	if(pos == 4) {
		if(num == 1) t = c.t;  //最后一辆车出来的时间
		num--;
	}
}

void solve() {
	//把车全进入车间
	for(int i = 1; i <= n; i++) {
		if(now[1] < cflow[1]) {   //第一个车间;
			double e = a[i].t + car[a[i].name].a[1]*60;
			q[1].push(Arrive(a[i].name, e));
			now[1]++;
			num++;
		}
		else {                         //一直往后腾空间  直到一车间有位置
			turn(2, 0);
			double e = a[i].t + car[a[i].name].a[1]*60;
			q[1].push(Arrive(a[i].name, e));
			now[1]++;
			num++;
		}
	}
	//车全部进入车间  模拟完成过程
	//清空第i个车间
	for(int i = 2; i <= 4; i++) {
		while(now[i-1] != 0) turn(i, 0);
	}
	//找到起始时间
	s = INF;
	for(int i = 1; i <= n; i++) {
		if(a[i].t < s) s = a[i].t;
	}
}

int main() {
	init();
	input();
	solve();
	cout << t-s << endl;
	return 0;
}

/*
4
00:16 CRH2
00:47 CRH5
01:22 CRH2
02:00 CRH6
*/
