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
	freopen("C:\\Users\\ASUS\\Desktop\\in1.txt","w",stdout);

    cout << 4 << endl; //4×éÊý¾Ý

    //case 1
    cout << 4 << " " << 5 << endl;
    cout << 1 << " " <<  2 << " " <<  1 << endl;
    cout << 2 << " " <<  3 << " " <<  2 << endl;
    cout << 3 << " " <<  4 << " " <<  3 << endl;
    cout << 1 << " " <<  4 << " " <<  2 << endl;
    cout << 1 << " " <<  3 << " " <<  6 << endl;

    //case 2
    cout << 4 << " " << 3 << endl;
    cout << 1 << " " <<  2 << " " <<  3 << endl;
    cout << 2 << " " <<  3 << " " <<  1 << endl;
    cout << 1 << " " <<  3 << " " <<  4 << endl;

    //case 3
    n = 100, m = 1000;
    cout << n << " " << m << endl;
    creat();

    //case 4
    n = 1000; m = 10000;
    cout << n << " " << m << endl;
    creat();
    return 0;
}
