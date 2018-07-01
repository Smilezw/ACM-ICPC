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

void Bubblesort(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n-1;j++){
			if(a[j]<a[i]){
				swap(a[j],a[i]);
			}
		}
	}
} 

int main(){
	input();
	Bubblesort();  
	output();
	return 0;
} 