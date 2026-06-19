#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[110];
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	int r = a[1];
	sort(a+1,a+(n*m)+1);
	int cnt = 1;
	for (int i = n*m;i >= 1;i--)
	{
		if (a[i] == r)
		{
			break;
		}
		cnt++;
	}
	if (cnt%n == 0)
	{
		cout << cnt/n;
		if ((cnt/n)%2 == 0)
		{
			cout << " " << 1 << endl;
		}else{
			cout << " " << n << endl;
		}
	}else{
		cout << cnt/n+1;
		if ((cnt/n+1)%2 == 0)
		{
			cout << " " << n-(cnt%n)+1 << endl;
		}else{
			cout << " " << cnt%n << endl;
		}
	}
	return 0;
}
