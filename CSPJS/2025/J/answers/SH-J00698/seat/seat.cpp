#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,q,i = 1,k;	//³õÊ¼»¯!!! 
	cin >> n >> m;
	vector<int> a(n * m + 1,0);
	cin >> a[1];
	for (int j = 2;j <= n * m;++j)
	{
		cin >> a[j];
		if (a[j] > a[1])	++i;
	}
	p = (i - 1) / n;
	q = (i - 1) % n;
//	cout << p << " " << q << endl;
	if (p % 2 == 0)
		cout << p + 1 << " " << q + 1 << endl;
	else
		cout << p + 1 << " " << n - q << endl;
	return 0;
}
