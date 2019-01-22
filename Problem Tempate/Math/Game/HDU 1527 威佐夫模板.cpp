#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a>b)
			swap(a,b);
		double k=b-a;                           //m(k) = k * (1 + sqrt(5))/2   n(k) = m(k) + k
		double x=(1+sqrt(5.0))/2;
		int t=(k*x+k);
		if(t==b)
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}
	return 0;
}
