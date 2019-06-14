#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define db double
#define cdb const double&
const int MAXN = 504;
const double eps = 1e-8;
int n, tot;
double alpha, Mn=1145141919, Mx=-1145141919;
struct Circle
{
	double x, y, r;
	inline Circle(cdb a=0, cdb b=0, cdb c=0)
	{
		x=a,y=b,r=c;
	}
} C[MAXN];

struct Line
{
	double xa, ya, xb, yb, k, b;
	inline Line(cdb xaa=0, cdb yaa=0, cdb xbb=0, cdb ybb=0, cdb kk=0, cdb bb=0)
	{
		xa=xaa,ya=yaa,xb=xbb,yb=ybb,k=kk,b=bb;
	}
	inline bool GetEq()
	{
		if(xa==xb)return 1;
		k = (yb-ya)/(xb-xa);
		b = yb-k*xb;
		return 0;
	}
	inline double CalcY(cdb x)
	{
		return k*x+b;
	}
} L[MAXN];
inline double f(cdb x)
{
	db Ret = 0, Dist;
	for (register int i = 1; i <= n; ++i)
	{
		Dist = fabs(x - C[i].x);
		if (Dist - C[i].r > -eps) continue;
		Ret = max(Ret, 2.0 * sqrt(C[i].r*C[i].r-Dist*Dist));
	}
	for (register int i = 1; i <= tot; ++i)
	{
		if (x >= L[i].xa && x <= L[i].xb)
		{
			Ret = max(Ret, 2 * L[i].CalcY(x));
		}
	}
	return Ret;
}
inline double simpson(cdb l, cdb r)
{
	return (r-l)*(f(r)+f(l)+f((l+r)/2)*4)/6;
}
double divide(cdb L, cdb R, cdb Ans)
{
	db Mid = (L + R) / 2, l = simpson(L, Mid), r = simpson(Mid, R);
	if(fabs(l+r-Ans)<=eps*15) return l+r+(l+r-Ans)/15;
	return divide(L, Mid, l) + divide(Mid, R, r);
}
int main()
{
	scanf("%d%lf", &n, &alpha);
	{
		++n;
		register double h;
		for (register int i = 1; i <= n; ++i)
		{
			scanf("%lf", &h);
			C[i].x=C[i-1].x+h/tan(alpha);
			C[i].y=0;
		}
	}
	for (register int i = 1; i < n; ++i)
	{
		scanf("%lf", &C[i].r);
	}
	for (register int i = 1; i <= n; ++i)
	{
		Mn = min(Mn, C[i].x-C[i].r);
		Mx = max(Mx, C[i].x+C[i].r);
	}
	{
		register double Dist, Sn, Cs;
		for (register int i = 1; i < n; ++i)
		{
			Dist = C[i+1].x - C[i].x;
			if (Dist - fabs(C[i+1].r - C[i].r) < -eps) continue;
			Sn = (C[i].r - C[i+1].r) / Dist;
			Cs = sqrt(1.0 - Sn * Sn);
			L[++tot] = Line(C[i].x+Sn*C[i].r,Cs*C[i].r,C[i+1].x+Sn*C[i+1].r,Cs*C[i+1].r);
			L[tot].GetEq();
		}
	}
	printf("%.2lf", divide(Mn, Mx, simpson(Mn, Mx)));
	return 0;
}
