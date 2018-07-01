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

void Selectsort(){
	int i,j;
	int m,now;
	for(i=0;i<n-1;i++){
		int m=a[i],now=i;
		for(j=i+1;j<n;j++){
			if(m>a[j]){
				now=j; m=a[j];
			}
		}
		swap(a[i],a[now]);
	}
} 

int main(){
	input(); 
	Selectsort();        
	output();
	return 0;
} 