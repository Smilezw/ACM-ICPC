#include<iostream>
using namespace std;
#define ILMaxSize 100
#define MaxSize 100
using namespace std;

template<typename ElemType>
struct IndexItem {
	ElemType index;
	int start;
	int m;
};

typedef IndexItem <int> indexlist[ILMaxSize];

int Binsch(indexlist B, int m, int k)
{
	int low = 0;
	int high = m - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (k == B[mid].index)
		{
			return B[mid].start;
		}
		else if (k <   B[mid].index)
		{
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
		if (low < m) return B[mid].start;
		else return -1;
	}
}
int main()
{
	return 0;
	getchar();
}
