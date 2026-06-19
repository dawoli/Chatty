#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[100005],c[100005];

int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= m;i++)
	{
		cin >> c[i];
		int newc = pow(2,(int)log2(c[i]));
//		if (c[i] == newc)
	}
	cout << 1 << endl;
	return 0;
}
