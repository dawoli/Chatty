#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("pocker.in","r",stdin);
	freopen("pocker.out","w",stdout);
	int n,sum = 10,b = 10,a[9999];
	string d,c,h,s;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];

		if (a[i] == a[i + 1] || a[i] == a[i + 2] || a[i] == a[i + 3]) 
		{
			cout << 52 - n + 1;
			break;
		}
		else if(a[i] == 52)
		{
			cout << 52;
			break;
		}
		else
		{
			cout << 52 - n;
			break;
		}
	} 
	return 0;
}
