//º∏÷÷≈≈–ÚÀ„∑® 
#include<iostream>
using namespace std;

const int MANX=100000;

int seedA[MANX];
int TT[MANX];
int n;

void Bubblesort(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n-1;j++){
			if(seedA[j]<seedA[i]){
				swap(seedA[j],seedA[i]);
			}
		}
	}
}

void Selectsort(){
	int i,j;
	int m,now;
	for(i=0;i<n-1;i++){
		int m=seedA[i],now=i;
		for(j=i+1;j<n;j++){
			if(m>seedA[j]){
				now=j; m=seedA[j];
			}
		}
		swap(seedA[i],seedA[now]);
	}
}
/*void Parallel(int u,int mid,int v){   //TT[MANX]
    int n=0;int uu=u,vv=v;
    while(n<v){
    	if(seedA[uu]<seedA[vv])
    	TT[n++]=seedA[uu++];
    	else TT[n++]=seedA[vv--];
    }
    for(int i=u,j=0;i<v;i++){
    	seedA[i]=TT[j++];
    }
}

void Mergesort(int u,int v){
	if(u==v)
	return ;
	int mid=u+(v-u)/2; 
	Mergesort(u,mid);
	Mergesort(mid+1,v);
	Parallel(u,mid,v);
}*/

void input(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>seedA[i];
	}
}

/*void Quicksort(int u,int v){
	if(u==v)
	return ;
	else {
		int mid=u+(v-u)/2;  
		int midn=seedA[mid];
		while(u!=v){
			if(seedA[u]>midn) {
				if()
			}
		}
		Quicksort(u,mid);
		Quicksort(mid+1,v);
		
	}
}*/

void output(){
	for(int i=0;i<=n;i++){
		cout<<seedA[i]<<" ";
	}
	cout<<endl;
}

int main(){
	input();
	//Bubblesort();
	//Selectsort();
	Mergesort(0,n);
	//Quicksort(0,n);
	output();
} 