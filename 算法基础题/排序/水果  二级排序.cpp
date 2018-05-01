// 水果   hdu 1263 
//二级排序 c++ 
 
#include<iostream>
#include<string> 
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int n,m,now;

struct f{
	string k1,k2;
	int price;
};

f q[1000+5];

bool cmp (const f &x,const f &y ){        //二级排序 
	if(x.k2!=y.k2)  return x.k2<y.k2;
	return x.k1<y.k1;
}

void input(){
	cin>>m; now=0;
	int pay,j;
	string s1,s2;
	while(m--){
		int c = 0 ;  cin >> s1 >> s2 >> pay ;
	    for(j=0;j<now;j++){
    		if(s1==q[j].k1&&s2==q[j].k2){     //属性不同就拓宽数组 
		    	c=1;
		    	q[j].price+=pay;
		    	break;
		    }
    	}
    	if(!c) {
	    	q[now].k1 = s1;q[now].k2 = s2;q[now].price = pay;
	    	now++;
	    }
	}
}

void solve(){
	sort(q,q+now,cmp);
	string str(q[0].k2);
	for(int i=0;i<now;i++){
		cout<<str<<endl;
		for(;i<now;i++){
			if(q[i].k2!=str)  {str=q[i].k2;i--;  break; }
			cout<<"   |----"<<q[i].k1<<"("<<q[i].price<<")"<<endl;  //输出 
		}	
	}
}

int main(){
    cin>>n;
    int kn=n;
	while(kn--){
		input();
		solve();
		if(n>1&&kn)
		cout<<endl;
	}
}