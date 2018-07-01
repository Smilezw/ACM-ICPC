#include<iostream>
using namespace std;

const int MANX=100000;

int a[MANX];
int tmp[MANX];
int n;

void Quicksort(int u,int v){
	if(u>=v)  return;
	int k=a[u];
	int i=u,j=v;
	while(i!=j){
		while(i<j && a[j]>=k) j--;
		swap(a[i],a[j]);
		while(i<j && a[i]<=k) i++;
		swap(a[i],a[j]);
	}
	Quicksort(u,i-1);
	Quicksort(i+1,v);
}

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
int main(){
	input(); 
	Quicksort(0,n-1);
	output();
	return 0;
} 