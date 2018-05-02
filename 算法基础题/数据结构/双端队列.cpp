// Ë«¶Ë¶ÓÁÐ  light oj 1212 

#include <iostream>
#include <cstdio>
#include <deque>
#include <string>
using namespace std;

int main(){
    string mpt[4] = {"pushLeft", "pushRight", "popLeft", "popRight"};
    int repeat; cin >> repeat;
    for(int i = 1; i <= repeat; i++){
        int n, m, a, b, sum;
        cin >> n >> m;
        deque <int> q; sum = 0;
        printf("Case %d:\n", i);
        while(m--){
            string p; cin >> p;
            if(p == mpt[0]){
      	        cin >> a;
                if(sum < n){ 
				    printf("Pushed in left: %d\n", a); 
				    q.push_front(a); sum++;
                }
                else printf("The queue is full\n");
            }
            if(p == mpt[1]){
           	    cin >> a; 
               	if(sum < n){
              		printf("Pushed in right: %d\n", a);
				    q.push_back(a); sum++;
                }
               	else printf("The queue is full\n");
            }
            if(p == mpt[2]){
       	        if(sum == 0) printf("The queue is empty\n");
               	else {
               	    b = q.front(); q.pop_front(); printf("Popped from left: %d\n",b);
               	    sum--;
                }
            }
            if(p == mpt[3]){
           	    if(sum == 0) printf("The queue is empty\n");
               	else {
               	    b = q.back(); q.pop_back(); printf("Popped from right: %d\n",b);
               	    sum--;
                }
            } 
        }
    }
    return 0;
}
