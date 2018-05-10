// hdu 1033 Ó¢Óï³¤ÆªÔÄ¶Á 

#include<iostream>  
using namespace std;
int main() {
	string ss;
	while (cin >> ss) {
		int len = ss.size();
		int xx = 310, yy = 420;
		char turn = 'd';
		cout << "300 420 moveto" << endl;
		cout << "310 420 lineto" << endl;
		for (int i = 0; i<len; i++) {
			switch (turn) {
			  case 'u':  
				if (ss[i] == 'A') {turn = 'r'; yy = yy + 10; break;}
				  else {turn = 'l'; yy = yy - 10; break;}
			  case 'd': 
			    if (ss[i] == 'A') {turn = 'l'; yy = yy - 10; break;}
				   else {turn = 'r';yy = yy + 10; break;}
			  case 'r': 
				if (ss[i] == 'A') {turn = 'd'; xx = xx + 10; break;}
				   else {turn = 'u'; xx = xx - 10; break;}
			  case 'l':
				if (ss[i] == 'A') {turn = 'u'; xx = xx - 10; break;}
				   else {turn = 'd';  xx = xx + 10; break;}
			}
			cout <<xx<<" "<<yy <<" lineto" << endl;
		}
		cout << "stroke" << endl;
	    cout << "showpage" << endl;
	}
	
}