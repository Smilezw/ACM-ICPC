#include <bits/stdc++.h>
using namespace std;

int n , m;

void creat() {
    for(int i = 0; i < m; i++) {
        int u, v, w;
        u = rand()%n + 1;
        v = rand()%n + 1;
        w = rand()%10 + 1;
        if(u == v) v = (v + 5)%n + 1;
        cout << u << " " << v << " " << w << endl;
    }
}

int main() {
    srand(time(NULL));
	freopen("C:\\Users\\ASUS\\Desktop\\in2.txt","w",stdout);

    cout << 3 << endl; //3×éÊý¾Ý

    //case 1
    n = 10000, m = 10000;
    cout << n << " " << m << endl;
    creat();

    //case 2
    n = 100000; m = 100000;
    cout << n << " " << m << endl;
    creat();

    //case 3
    n = 100000; m = 100000;
    cout << n << " " << m << endl;
    creat();
    return 0;
}
