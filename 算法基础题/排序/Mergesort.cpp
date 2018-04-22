#include<iostream>
using namespace std;

const int MANX=100000;

int a[MANX];
int tmp[MANX];
int n;

void input(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
}
void output(){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void Parallel(int u,int mid,int v){   
    int pb=0; int pu=u, pm=mid+1, pv=v;
    while( pu<pm && pm<pv ){
    	if( a[pu] > a[pm] ) tmp[pb++] = a[pm++];
    	else tmp[pb++] = a[pu++];
    }
    while(pu<=mid) tmp[pb++] = a[pu++];
    while(pm<=v) tmp[pb++] = a[pm++];
    for(int i=0;i<v-u+1;i++){
    	a[u+i]=tmp[i];
    }
}

void Mergesort(int u,int v){
	if(v>u){
		int mid=u+(v-u)/2; 
	    Mergesort(u,mid);
	    Mergesort(mid+1,v);
	    Parallel(u,mid,v);
	}
}

int main(){
	input();       
	Mergesort(0,n-1);   
	output();
	return 0;
} 